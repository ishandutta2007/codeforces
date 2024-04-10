//#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;

//defines
typedef long long ll;
typedef long double ld;
#define TIME clock() * 1.0 / CLOCKS_PER_SEC
#define prev _prev
#define y0 _y0
#define kill _kill

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
const ll btc = 30;
const ld eps = 1e-8;
const ll INF = (ll)(1e18 + 239);
const int BIG = (int)(1e9 + 239);
const int MOD = 998244353; //1e9 + 7;

//random
mt19937 rnd(239); //(chrono::high_resolution_clock::now().time_since_epoch().count());

//constants
const int M = (int)(2e5 + 239);
const int N = (int)(2e3 + 239);
const int L = 20;
const int T = (1 << 18) + 239;
const int B = 500;
const int X = 1010;

int ask(int i, int j)
{
    cout << "? " << i + 1 << " " << j + 1 << endl;
    int r;
    cin >> r;
    if (r == -1)
        exit(0);
    return r - 1;
}

void answer(int p)
{
    cout << "! " << p + 1 << endl;
    exit(0);
}

vector<pair<int, int>> edges;
int used[X], cnt;
vector<int> v[X];

int sz[X];

void dfs(int p, int pr)
{
    sz[p] = 1;
    for (int i : v[p])
        if (i != pr)
        {
            dfs(i, p);
            sz[p] += sz[i];
        }
}

void dfs_comp(int p, int pr, vector<int>& now)
{
    now.push_back(p);
    for (int i : v[p])
        if (i != pr)
            dfs_comp(i, p, now);
}

void solve(vector<int> id)
{
    if (id.size() == 1)
        answer(id[0]);
    if (id.size() == 2)
        answer(ask(id[0], id[1]));
    cnt++;
    for (int i : id)
    {
        used[i] = cnt;
        v[i].clear();
    }
    for (pair<int, int> t : edges)
        if (used[t.first] == cnt && used[t.second] == cnt)
        {
            v[t.first].push_back(t.second);
            v[t.second].push_back(t.first);
        }
    int root = -1;
    for (int i : id)
        if ((int)v[i].size() >= 2)
        {
            root = i;
            break;
        }
    dfs(root, -1);
    int good = -1;
    for (int i : v[root])
        if (sz[i] >= 2)
        {
            good = i;
            break;
        }
    if (good != -1)
    {
        int to = ask(good, root);
        if (to == good)
            swap(good, root);
        vector<int> tov;
        dfs_comp(root, good, tov);
        solve(tov);
    }
    for (int i = 0; i < (int)id.size(); i++)
        if (id[i] == root)
        {
            swap(id[i], id[0]);
            break;
        }
    int res = ask(id.back(), id[(int)id.size() - 2]);
    if (res == id.back())
        answer(id.back());
    if (res == id[(int)id.size() - 2])
        answer(id[(int)id.size() - 2]);
    id.pop_back();
    id.pop_back();
    solve(id);
}

int32_t main()
{
#ifdef ONPC
    //freopen("input", "r", stdin);
#endif
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n - 1; i++)
    {
        int s, f;
        cin >> s >> f;
        s--, f--;
        edges.push_back(make_pair(s, f));
    }
    vector<int> al;
    for (int i = 0; i < n; i++)
        al.push_back(i);
    cnt = 1;
    memset(used, 0, sizeof(used));
    solve(al);
    return 0;
}