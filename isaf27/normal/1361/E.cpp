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
const int MOD = 1e9 + 7;

//random
#ifdef ONPC
mt19937_64 rnd(239);
#else
mt19937_64 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
#endif

//constants
const int M = (int)(2e5 + 239);
const int N = (int)(2e3 + 239);
const int L = 19;
const int T = (1 << 18) + 239;
const int B = 500;
const int X = (1 << 20) + 239;

const int IT = 100;

int n, m, root;
int used[M], cnt_used;
vector<int> v[M];
pair<int, int> want[M];
int k;
int tin[M], tout[M], timer;

int a[M];
ll sum[M];
bool good[M];

void dfs_check(int p)
{
    tin[p] = timer++;
    used[p] = cnt_used;
    for (int i : v[p])
    {
        if (used[i] != cnt_used)
            dfs_check(i);
        else
            want[k++] = make_pair(p, i);
    }
    tout[p] = timer;
}

bool upper(int s, int f)
{
    return tin[s] <= tin[f] && tout[f] <= tout[s];
}

bool check(int p)
{
    k = 0;
    cnt_used++;
    timer = 0;
    dfs_check(p);
    for (int i = 0; i < k; i++)
        if (!upper(want[i].second, want[i].first))
            return false;
    return true;
}

void dfs_calc(int p)
{
    used[p] = cnt_used;
    for (int i : v[p])
        if (used[i] != cnt_used)
        {
            dfs_calc(i);
            a[p] += a[i];
            sum[p] += sum[i];
        }
}

bool dfs_fnd(int p)
{
    if (used[p] == cnt_used)
        return good[p];
    used[p] = cnt_used;
    if (a[p] > 1)
    {
        good[p] = false;
        return false;
    }
    int to = want[sum[p]].second;
    good[p] = dfs_fnd(to);
    return good[p];
}

void solve()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        v[i].clear();
    for (int i = 0; i < m; i++)
    {
        int s, f;
        cin >> s >> f;
        s--, f--;
        v[s].push_back(f);
    }
    root = -1;
    for (int i = 0; i < IT; i++)
    {
        int p = rnd() % n;
        if (check(p))
        {
            root = p;
            break;
        }
    }
    if (root == -1)
    {
        cout << "-1\n";
        return;
    }
    for (int i = 0; i < n; i++)
    {
        a[i] = 0;
        sum[i] = 0;
    }
    for (int i = 0; i < k; i++)
    {
        int s = want[i].second;
        int f = want[i].first;
        a[s]--;
        a[f]++;
        sum[f] += i;
        sum[s] -= i;
    }
    cnt_used++;
    dfs_calc(root);
    cnt_used++;
    used[root] = cnt_used;
    good[root] = true;
    for (int i = 0; i < n; i++)
        dfs_fnd(i);
    vector<int> ans;
    for (int i = 0; i < n; i++)
        if (good[i])
            ans.push_back(i);
    if (5 * (int)ans.size() < n)
    {
        cout << "-1\n";
        return;
    }
    for (int i : ans)
        cout << i + 1 << " ";
    cout << "\n";
#ifdef ONPC
    /*cerr << root + 1 << "\n";
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << "\n";*/
#endif
}

int32_t main()
{
#ifdef ONPC
    freopen("input", "r", stdin);
#endif
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}