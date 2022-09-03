/*
    Author: isaf27 (Ivan Safonov)
*/

#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;

//defines
typedef long long ll;
typedef long double ld;

//constants
const int M = 2e5 + 239;
const int N = (2 * M);
const int L = 19;
const int T = (1 << 19);
const int B = trunc(sqrt(M)) + 1;
const int X = 110;

pair<int, int> dp[L][N];
vector<int> et;
int gl[M], first[N], how[N], k, tin[M], tout[M], timer;
vector<int> v[M];

inline void dfs_lca(int p, int f)
{
    tin[p] = timer++;
    first[p] = et.size();
    et.push_back(p);
    gl[p] = f;
    for (int i : v[p])
    {
        dfs_lca(i, f + 1);
        et.push_back(p);
    }
    tout[p] = timer;
}

inline int lca(int s, int f)
{
    if (first[s] > first[f]) swap(s, f);
    s = first[s];
    f = first[f];
    int len = f - s + 1;
    int e = how[len];
    pair<int, int> ans = min(dp[e][s], dp[e][f + 1 - (1 << e)]);
    return ans.second;
}

inline void init_lca()
{
    dfs_lca(0, 0);
    k = et.size();
    for (int i = 0; i < k; i++) dp[0][i] = make_pair(gl[et[i]], et[i]);
    for (int i = 1; i < L; i++)
        for (int j = 0; j < k; j++)
        {
            int st = (1 << (i - 1));
            if (st + j >= k)
            {
                dp[i][j] = dp[i - 1][j];
                continue;
            }
            dp[i][j] = min(dp[i - 1][j], dp[i - 1][st + j]);
        }
    how[1] = 0;
    for (int i = 2; i <= k; i++)
    {
        how[i] = how[i - 1];
        if ((1 << (how[i] + 1)) == i)
            how[i]++;
    }
}

inline bool upper(int s, int f)
{
    return (tin[s] <= tin[f] && tout[f] <= tout[s]);
}

inline bool on_way(int s, int f, int c)
{
    if (s == f) return (s == c);
    if (s == c || f == c) return true;
    if (!(upper(c, s) || upper(c, f))) return false;
    int x = lca(s, f);
    if (!upper(x, c)) return false;
    return true;
}

int ls[T], rs[T];

inline void upd(int i, int l, int r, int x, int nw)
{
    if (r <= x || x < l) return;
    if (r - l == 1)
    {
        ls[i] = nw;
        rs[i] = nw;
        return;
    }
    int mid = (l + r) >> 1;
    if (x < mid)
        upd(2 * i + 1, l, mid, x, nw);
    else
        upd(2 * i + 2, mid, r, x, nw);
    if (ls[2 * i + 1] == -1 || ls[2 * i + 2] == -1)
    {
        ls[i] = -1;
        return;
    }
    vector<int> pt;
    pt.push_back(ls[2 * i + 1]);
    pt.push_back(rs[2 * i + 1]);
    pt.push_back(ls[2 * i + 2]);
    pt.push_back(rs[2 * i + 2]);
    sort(pt.begin(), pt.end());
    pt.resize(unique(pt.begin(), pt.end()) - pt.begin());
    if ((int)pt.size() == 1)
    {
        ls[i] = pt[0];
        rs[i] = pt[0];
        return;
    }
    if ((int)pt.size() == 2)
    {
        ls[i] = pt[0];
        rs[i] = pt[1];
        return;
    }
    vector<int> in;
    for (int i = 0; i < (int)pt.size(); i++)
    {
        bool bad = false;
        for (int j = 0; j < (int)pt.size() && !bad; j++)
            if (j != i)
                for (int h = j + 1; h < (int)pt.size() && !bad; h++)
                    if (h != i)
                        if (on_way(pt[j], pt[h], pt[i]))
                            bad = true;
        if (!bad) in.push_back(pt[i]);
    }
    if ((int)in.size() > 2)
    {
        ls[i] = -1;
        return;
    }
    ls[i] = in[0];
    rs[i] = in[1];
}

vector<int> way;

inline int getans(int i, int l, int r)
{
    if (r - l == 1) return l;
    int mid = (l + r) >> 1;
    if (ls[2 * i + 1] == -1) return getans(2 * i + 1, l, mid);
    vector<int> pt;
    if (!way.empty())
    {
        pt.push_back(way[0]);
        pt.push_back(way[1]);
    }
    pt.push_back(ls[2 * i + 1]);
    pt.push_back(rs[2 * i + 1]);
    sort(pt.begin(), pt.end());
    pt.resize(unique(pt.begin(), pt.end()) - pt.begin());
    if ((int)pt.size() == 1)
    {
        way.resize(2);
        way[0] = pt[0];
        way[1] = pt[0];
        return getans(2 * i + 2, mid, r);
    }
    if ((int)pt.size() == 2)
    {
        way.resize(2);
        way[0] = pt[0];
        way[1] = pt[1];
        return getans(2 * i + 2, mid, r);
    }
    vector<int> in;
    for (int i = 0; i < (int)pt.size(); i++)
    {
        bool bad = false;
        for (int j = 0; j < (int)pt.size() && !bad; j++)
            if (j != i)
                for (int h = j + 1; h < (int)pt.size() && !bad; h++)
                    if (h != i)
                        if (on_way(pt[j], pt[h], pt[i]))
                            bad = true;
        if (!bad) in.push_back(pt[i]);
    }
    if ((int)in.size() > 2) return getans(2 * i + 1, l, mid);
    way.resize(2);
    way[0] = in[0];
    way[1] = in[1];
    return getans(2 * i + 2, mid, r);
}

void show(int i, int l, int r)
{
    if (ls[i] == -1)
        cout << l << " " << r << ": fail\n";
    else
        cout << l << " " << r << ": " << ls[i] + 1 << " " << rs[i] + 1 << "\n";
    if (r - l == 1) return;
    int mid = (l + r) >> 1;
    show(2 * i + 1, l, mid);
    show(2 * i + 2, mid, r);
}

int n, p[M];

int main()
{
    #ifdef ONPC
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> p[i];
    for (int i = 1; i < n; i++)
    {
        int pr;
        cin >> pr;
        pr--;
        v[pr].push_back(i);
    }
    init_lca();
    //cerr << on_way(1, 4, 2) << "!\n";
    //for (int i = 0; i < n; i++)
    //    for (int j = i; j < n; j++)
    //        cerr << lca(i, j) + 1 << "(" << i + 1 << ", " << j + 1 << ")\n";
    memset(ls, 0, sizeof(ls));
    memset(rs, 0, sizeof(rs));
    for (int i = 0; i < n; i++)
        upd(0, 0, n, p[i], i);
    //show(0, 0, n);
    //return 0;
    int q;
    cin >> q;
    for (int z = 0; z < q; z++)
    {
        int t;
        cin >> t;
        if (t == 1)
        {
            int s, f;
            cin >> s >> f;
            s--, f--;
            if (s == f) continue;
            upd(0, 0, n, p[s], f);
            upd(0, 0, n, p[f], s);
            swap(p[s], p[f]);
        }
        else
        {
            if (ls[0] != -1)
            {
                cout << n << "\n";
                continue;
            }
            way.clear();
            cout << getans(0, 0, n) << "\n";
        }
    }
    return 0;
}