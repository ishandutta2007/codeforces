#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;

//defines
typedef long long ll;
typedef double ld;
#define TIME clock() * 1.0 / CLOCKS_PER_SEC
#define prev _prev
#define y0 y00

//permanent constants
const ld pi = acos(-1.0);
const int day[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
const int digarr[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
const int dx[4] = {0, 1, 0, -1};
const int dy[4] = {1, 0, -1, 0};
const int dxo[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
const int dyo[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
const int alf = 26;
const int dig = 10;
const int two = 2;
const int th = 3;
const ll prost = 239;
const ll bt = 30;
const ld eps = 1e-7;
const ll INF = (ll)(1e18 + 239);
const int BIG = (int)(2e9 + 239);
const int MOD = 998244353;
const ll MOD2 = (ll)MOD * (ll)MOD;

//random
mt19937 rnd(239); //(chrono::high_resolution_clock::now().time_since_epoch().count());

//constants
const int M = (int)(1e5 + 239);
const int N = (int)(2e3 + 239);
const int L = 20;
const int T = (1 << 20);
const int B = (int)sqrt(M);
const int X = 1e4 + 239;

int cur[N];
vector<pair<int, int> > v[N];
vector<tuple<int, int, int> > ans;
vector<int> st;

bool dfs(int p, int pr, int nd)
{
    if (p == nd) return true;
    for (pair<int, int> t : v[p])
        if (t.first != pr)
        {
            st.push_back(t.second);
            if (dfs(t.first, p, nd))
                return true;
            st.pop_back();
        }
    return false;
}

void upd(int s, int f, int w)
{
    if (w == 0) return;
    ans.push_back(make_tuple(s, f, w));
    st.clear();
    dfs(s, -1, f);
    for (int x : st)
        cur[x] -= w;
}

int n, lf[N];

void dfs_leaf(int p, int pr)
{
    for (pair<int, int> t : v[p])
        if (t.first != pr)
        {
            dfs_leaf(t.first, p);
            lf[p] = lf[t.first];
            return;
        }
    lf[p] = p;
}

void dfs_ans(int p, int pr)
{
    for (pair<int, int> t : v[p])
        if (t.first != pr)
        {
            vector<int> to;
            for (pair<int, int> u : v[p])
                if (u.first != t.first)
                {
                    to.push_back(u.first);
                    if ((int)to.size() == 2)
                        break;
                }
            dfs_leaf(t.first, p);
            dfs_leaf(to[0], p);
            dfs_leaf(to[1], p);
            int x1 = lf[t.first];
            int x2 = lf[to[0]];
            int x3 = lf[to[1]];
            int w = cur[t.second];
            upd(x1, x2, w / 2);
            upd(x1, x3, w / 2);
            upd(x2, x3, -(w / 2));
            dfs_ans(t.first, p);
        }
}

int32_t main()
{
#ifdef ONPC
    freopen("input.txt", "r", stdin);
#endif
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 0; i < n - 1; i++)
    {
        int s, f, w;
        cin >> s >> f >> w;
        s--, f--;
        cur[i] = w;
        v[s].push_back(make_pair(f, i));
        v[f].push_back(make_pair(s, i));
    }
    if (n == 2)
    {
        cout << "YES\n1\n1 2 " << cur[0];
        return 0;
    }
    for (int i = 0; i < n; i++)
        if ((int)v[i].size() == 2)
        {
            cout << "NO";
            return 0;
        }
    int root = 0;
    for (int i = 0; i < n; i++)
        if ((int)v[i].size() != 1)
        {
            root = i;
            break;
        }
    cout << "YES\n";
    dfs_ans(root, -1);
    cout << (int)ans.size() << "\n";
    for (tuple<int, int, int> t : ans)
        cout << get<0>(t) + 1 << " " << get<1>(t) + 1 << " " << get<2>(t) << "\n";
    return 0;
}