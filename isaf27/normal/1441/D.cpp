//#pragma GCC optimize("O3")
//#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>

using namespace std;

//defines
typedef long long ll;
typedef long double ld;
#define TIME clock() * 1.0 / CLOCKS_PER_SEC
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
const int two = 2;
const ld eps = 1e-10;
const ll INF = (ll)(2e18 + 239);
const int BIG = (int)(1e9 + 239);
const int MOD = 998244353;
const ll MOD2 = (ll)MOD * (ll)MOD;

//random
#ifdef ONPC
mt19937_64 rnd(239);
#else
mt19937_64 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
#endif

//constants
const int M = (int)(2e5 + 239);
const int N = (int)(2e3 + 10);
const int L = 20;
const int T = (1 << 20) + 239;
const int B = 510;
const int X = 3010;

int n, a[M];
int dp[2][M];
vector<int> v[M];

void dfs(int p, int pr) {
    for (int i : v[p]) {
        if (i != pr) {
            dfs(i, p);
        }
    }
    for (int c = 0; c < 2; c++) {
        if (a[p] > 0 && a[p] - 1 != c) {
            dp[c][p] = n + 1;
            continue;
        }
        dp[c][p] = 0;
        int cnt = 0;
        for (int i : v[p]) {
            if (i != pr) {
                cnt++;
                dp[c][p] = max(dp[c][p], min(dp[c][i], dp[1 - c][i] + 1));
            }
        }
        if (cnt == 0) {
            dp[c][p] = 1;
        }
    }
}

int ans;
int up[2][M];

void dfs_down(int p, int pr) {
    int to[2];
    to[0] = up[0][p];
    to[1] = up[1][p];
    for (int c = 0; c < 2; c++) {
        if (a[p] > 0 && a[p] - 1 != c) {
            up[c][p] = n + 1;
            continue;
        }
        up[c][p] = min(to[c], to[1 - c] + 1);
    }
    //cerr << p + 1 << " " << up[0][p] << " " << up[1][p] << " up\n";
    //cerr << p + 1 << " " << dp[0][p] << " " << dp[1][p] << " dp\n";
    ans = min(ans, min(max(up[0][p], dp[0][p]), max(up[1][p], dp[1][p])));
    vector<int> go;
    for (int i : v[p]) {
        if (i != pr) {
            go.emplace_back(i);
        }
    }
    if (go.empty())
        return;
    for (int c = 0; c < 2; c++) {
        for (int i = 0; i < (int)go.size(); i++) {
            int t = go[i];
            up[c][t] = up[c][p];
        }
        if (a[p] > 0 && a[p] - 1 != c) {
            continue;
        }
        int curmax = 0;
        for (int i = 0; i < (int)go.size(); i++) {
            int t = go[i];
            up[c][t] = max(up[c][t], curmax);
            curmax = max(curmax, min(dp[c][t], dp[1 - c][t] + 1));
        }
        curmax = 0;
        for (int i = (int)go.size() - 1; i >= 0; i--) {
            int t = go[i];
            up[c][t] = max(up[c][t], curmax);
            curmax = max(curmax, min(dp[c][t], dp[1 - c][t] + 1));
        }
    }
    for (int i : go)
        dfs_down(i, p);
}

void solve() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        v[i].clear();
    }
    for (int i = 0; i < n - 1; i++) {
        int s, f;
        cin >> s >> f;
        s--, f--;
        v[s].push_back(f);
        v[f].push_back(s);
    }
    ans = n;
    dfs(0, -1);
    up[0][0] = 1;
    up[1][0] = 1;
    dfs_down(0, -1);
    cout << ans << "\n";
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