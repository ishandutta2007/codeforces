#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef pair<int, int> pii;
 
#define all(x) (x).begin(), (x).end()
#define l first
#define r second
 
const int INF = 1e9 + 1;
const int N = 202000;
 
const ll MOD1 = 998244391;
const ll M1 = 1e6 + 3;
int deg1[N];
 
vector<int> lcp(vector<int> &s, vector<int> &sa, vector<int> &pos)
{
    int n = s.size();
    vector<int> L(n);
    int k = 0;
    for (int i = 0; i < n; i++)
    {
        if (k > 0) k--;
        if (pos[i] == n - 1)
            L[n - 1] = -1, k = 0;
        else
        {
            int j = sa[pos[i] + 1];
            while (max(i + k, j + k) < n && s[i + k] == s[j + k])
                k++;
            L[pos[i]] = k;
        }
    }
    return L;
}
 
 
int H[N];
int sp[20][N];
 
int get(int l, int r)
{
    int j = H[r - l + 1];
    return min(sp[j][l], sp[j][r - (1 << j) + 1]);
}
 
void buildsa(vector<int> &s, vector<int> &sa, vector<int> &pos)
{
    map<int, int> mm;
    for (int i = 0; i < (int)s.size(); i++)
        mm[s[i]] = -1;
    int x = 0;
    for (int c = 0; c <= s.size(); c++)
    {
        if (mm.find(c) != mm.end())
            mm[c] = x++;
    }
    for (int i = 0; i < (int)s.size(); i++)
    {
        pos[i] = mm[s[i]];
    }
    vector<pair<pii, int> > p(s.size());
    for (int j = 1; (1 << j) <= 2 * (int)s.size(); j++)
    {
        for (int i = 0; i < (int)s.size(); i++)
        {
            p[i] = {{pos[i], pos[(i + (1 << j) / 2) % s.size()]}, i};
        }
        sort(p.begin(), p.end());
        int x = 0;
        pos[p[0].second] = x;
        for (int i = 1; i < (int)p.size(); i++)
        {
            if (p[i].first != p[i - 1].first) x++;
            pos[p[i].second] = x;
        }
    }
    for (int i = 0; i < (int)s.size(); i++)
    {
        sa[pos[i]] = i;
    }
}
 
vector<int> msep(vector<int> &s, vector<int> &sa, vector<int> &pos)
{
    vector<int> res(s.size());
 
    int n = s.size();
    int ri = 0;
    int pi = INF;
 
    set<array<int, 3> > waitlist;
    set<array<int, 3> > waitlist_sorted;
 
    auto emplace = [&](int z) { 
        pi = min(pi, z);
        if (pi != INF && pi < z && get(pi, z - 1) >= ri - sa[z])
        {
            waitlist.insert({sa[z] + get(pi, z - 1), z, sa[z]});
            waitlist_sorted.insert({-sa[z], sa[z] + get(pi, z - 1), z});
        }
    };
 
    while (ri < n)
    {
        ri++;
        while (waitlist.size())
        {
            array<int, 3> it = *waitlist.begin();
            int z = it[1];
            if (it[0] >= ri) break;
            waitlist.erase(it);
            waitlist_sorted.erase({-it[2], it[0], it[1]});
        }
        emplace(pos[ri - 1]);
 
        if (waitlist_sorted.size())
        {
            res[ri - 1] = -(*waitlist_sorted.begin())[0];
        }
        else
        {
            res[ri - 1] = sa[pi];
        }
    }
    return res;
}
 
double precomputation_time = 0;
 
vector<int> fast_op(vector<int> s)
{
    double st = clock();
 
    s.push_back(0);
    vector<int> sa(s.size());
    vector<int> pos(s.size());
    buildsa(s, sa, pos);
    vector<int> L = lcp(s, sa, pos);
 
    for (int i = 0; i < (int)s.size(); i++) sp[0][i] = L[i];
    for (int j = 0; j < 20; j++)
        for (int i = 0; i + (1 << j) - 1 < (int)s.size(); i++)
            sp[j][i] = get(i, i + (1 << j) - 1);
 
    s.pop_back();
 
    auto cmp = [&](int l1, int l2, int len)
    {
        if (get(min(pos[l1], pos[l2]), max(pos[l1], pos[l2]) - 1) >= len)
            return 1;
        return 0;
    };
 
    vector<int> min_suf_each_pref = msep(s, sa, pos);
    vector<int> kek_suf_each_pref(s.size());
    for (int i = 0; i < s.size(); i++)
    {
        int len = i + 1 - min_suf_each_pref[i];
        kek_suf_each_pref[i] = min_suf_each_pref[i];
        int j = 0;
        for (j = 0; j < 20; j++)
        {
            ll nc = kek_suf_each_pref[i] - (1ll << j) * len;
            if (nc >= 0 && cmp(nc, kek_suf_each_pref[i], (1ll << j) * len))
                kek_suf_each_pref[i] = nc;
            else
                break;
        }
        for (; j >= 0; j--)
        {
            ll nc = kek_suf_each_pref[i] - (1ll << j) * len;
            if (nc >= 0 && cmp(nc, kek_suf_each_pref[i], (1ll << j) * len))
                kek_suf_each_pref[i] = nc;
        }
    }
 
    precomputation_time += 1.0 * (clock() - st) / CLOCKS_PER_SEC;
 
    deque<pair<int, int> > h;
 
    struct SegTree{
        struct Node
        {
            int l, r;
            ll len;
            ll h1;
        };
 
        vector<Node> tree;
        vector<Node> hashes;
        int pnt;
 
        SegTree(vector<int> s)
        {
            tree.resize(4 * s.size());
            hashes.resize(s.size());
            hashes[0].h1 = s[0];
            for (int i = 1; i < s.size(); i++)
            {
                hashes[i].h1 = (hashes[i - 1].h1 * M1 + s[i]) % MOD1;
            }
            pnt = s.size();
        }
        Node Get(int l, int r)
        {
            Node res;
            res.l = l;
            res.r = r;
            res.len = r - l + 1;
            res.h1 = (hashes[r].h1 - (l ? hashes[l - 1].h1 : 0) * deg1[r - l + 1]) % MOD1;
            res.h1 = (res.h1 + MOD1) % MOD1;
            return res;
        }
        Node Merge(Node L, Node R)
        {
            if (L.len + R.len < N) L.h1 = (L.h1 * deg1[R.len] + R.h1) % MOD1;
            L.len += R.len;
            return L;
        }
        void Set(int pos, Node X, int L, int R, int V)
        {
            if (L + 1 == R)
            {
                tree[V] = X;
                return;
            }
            int M = (L + R) / 2;
            if (pos < M) Set(pos, X, L, M, 2 * V + 1);
            else Set(pos, X, M, R, 2 * V + 2);
            tree[V] = Merge(tree[2 * V + 1], tree[2 * V + 2]);
        }
        void push_front(int l, int r)
        {
            pnt--;
            Set(pnt, Get(l, r), 0, tree.size() / 4, 0);
        }
        Node Get(int chars, int L, int R, int V)
        {
            if (L + 1 == R)
            {
                return Get(tree[V].l, tree[V].l + chars - 1);
            }
            int M = (L + R) / 2;
            if (tree[2 * V + 1].len >= chars)
                return Get(chars, L, M, 2 * V + 1);
            return Merge(tree[2 * V + 1], Get(chars - tree[2 * V + 1].len, M, R, 2 * V + 2));
        }
        Node Get(int chars)
        {
            return Get(chars, 0, tree.size() / 4, 0);
        }
    };
 
    SegTree TT(s);
    for (int i = 1; i <= s.size(); i++)
    {
        int pos1 = min_suf_each_pref[s.size() - i];
        int pos2 = kek_suf_each_pref[s.size() - i];
        int len = s.size() - i + 1 - pos1;
 
        if (pos1 == pos2)
        {
            int LL = min_suf_each_pref[s.size() - i];
            int RR = min((int)s.size() - i, min_suf_each_pref[s.size() - i] + i - 1);
            h.push_front({LL, RR});
            TT.push_front(LL, RR);
            continue;
        }
        int t2 = -1;
        int aval = s.size() - i + 1 - pos2 - len;
 
        aval = min(aval, i);
        if (TT.Get(aval).h1 != TT.Get(pos2 + len, pos2 + len + aval - 1).h1)
            t2 = 1;
 
        int shL = aval, shR = i;
        while (t2 == -1 && shL + 1 < shR)
        {
            int sh = (shL + shR) / 2;
            int x1 = TT.Get(sh).h1;
            int x2 = TT.Merge(TT.Get(pos2 + len, s.size() - i), TT.Get(sh - aval)).h1;
            if (x1 != x2)
                shR = sh;
            else
                shL = sh;
        }
 
        if (t2 == -1 && shR < i)
        {
            int x1 = TT.Get(shR).h1;
            int x2 = TT.Merge(TT.Get(pos2 + len, s.size() - i), TT.Get(shR - aval)).h1;
            if (x1 != x2)
            {
                if ((x1 - x2 + MOD1) % MOD1 < MOD1 / 2)
                {
                    t2 = 2;
                }
                else
                {
                    t2 = 1;
                }
            }
        }
 
        if (t2 == 1)
        {
            int LL = min_suf_each_pref[s.size() - i];
            int RR = min((int)s.size() - i, min_suf_each_pref[s.size() - i] + i - 1);
            h.push_front({LL, RR});
            TT.push_front(LL, RR);
        }
        else
        {
            int LL = kek_suf_each_pref[s.size() - i];
            int RR = min((int)s.size() - i, kek_suf_each_pref[s.size() - i] + i - 1);
            h.push_front({LL, RR});
            TT.push_front(LL, RR);
        }
    }
    vector<int> s2;
    for (int j = 0; j < h.size(); j++)
    {
        for (int k = h[j].l; k <= h[j].r; k++)
        {
            s2.push_back(s[k]);
            if (s2.size() == s.size())
                break;
        }
        if (s2.size() == s.size())
            break;
    }
    return s2;
}
 
vector<int> op(vector<int> s)
{
    for (int i = 1; i < s.size(); i++)
    {
        vector<int> h = {INF};
        for (int j = 0; j + i <= s.size(); j++)
        {
            vector<int> t;
            for (int k = 0; k < i; k++)
                t.push_back(s[j + k]);
            h = min(h, t);
        }
        for (int j = 0; j < i; j++)
        {
            s[s.size() - i + j] = h[j];
        }
    }
    return s;
}
 
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    deg1[0] = 1;
    for (int i = 1; i < N; i++)
        deg1[i] = deg1[i - 1] * M1 % MOD1;
    for (int i = 3; i < N; i++)
        H[i] = (((i - 1) & (i - 2)) == 0) + H[i - 1];
 
    int n;
    cin >> n;
    vector<vector<int> > b(7, vector<int>(n));
    for (int i = 0; i < n; i++) cin >> b[0][i];
    // b[1] - 2
    // b[2] - 5
    // b[3] - 20
    // b[4] - 230
    // b[5] - 26795
    // b[6] - stable
    for (int i = 1; i < 6; i++) b[i] = fast_op(b[i - 1]);
    int pos = 0;
    while (pos + 1 < n && b[0][pos + 1] <= b[0][pos]) pos++;
    for (int i = 0; i < pos; i++) b[6][i] = b[0][i];
    for (int i = pos; i < n; i++) b[6][i] = b[0][pos];
    int q;
    cin >> q;
    while (q--)
    {
        int i, j;
        cin >> i >> j;
        j--;
        i = min(i, 6);
        cout << b[i][j] << "\n";
    }
    return 0;
 
}