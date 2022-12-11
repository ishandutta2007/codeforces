#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define pb push_back
#define sz(a) (int)(a).size()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef long double ld;
typedef unsigned int uint;
typedef unsigned long long ull;

const int mod = 1e9 + 7;

void add(int& a, int b) {
    a += b;
    if (a >= mod) {
        a -= mod;
    }
}

void mul(int& a, int b) {
    ll c = ll(a) * b;
    if (c >= mod) {
        c %= mod;
    }
    a = c;
}

const int nmax = 100500;
const int xmax = 12;

vector<int> g[nmax];
int m;
int dp[nmax][xmax][3];
int k, x;

int tmp[xmax];
int nx[xmax];

void dfs(int v, int p) {
    for (int to : g[v]) {
        if (to == p) {
            continue;
        }
        dfs(to, v);
    }
    memset(tmp, 0, sizeof(tmp));
    tmp[1] = 1;
    for (int to : g[v]) {
        if (to == p) {
            continue;
        }
        memset(nx, 0, sizeof(nx));
        for (int a = 0; a <= x; ++a) {
            for (int b = 0; a + b <= x; ++b) {
                int val = tmp[a];
                mul(val, dp[to][b][2]);
                add(nx[a + b], val);
            }
        }
        memcpy(tmp, nx, sizeof(tmp));
    }
    for (int a = 0; a <= x; ++a) {
        dp[v][a][1] = tmp[a];
    }

    memset(tmp, 0, sizeof(tmp));
    tmp[0] = k - 1;
    for (int to : g[v]) {
        if (to == p) {
            continue;
        }
        memset(nx, 0, sizeof(nx));
        for (int a = 0; a <= x; ++a) {
            for (int b = 0; a + b <= x; ++b) {
                int val = dp[to][b][0];
                add(val, dp[to][b][1]);
                add(val, dp[to][b][2]);
                mul(val, tmp[a]);
                add(nx[a + b], val);
            }
        }
        memcpy(tmp, nx, sizeof(tmp));
    }
    for (int a = 0; a <= x; ++a) {
        dp[v][a][2] = tmp[a];
    }

    memset(tmp, 0, sizeof(tmp));
    tmp[0] = m - k;
    for (int to : g[v]) {
        if (to == p) {
            continue;
        }
        memset(nx, 0, sizeof(nx));
        for (int a = 0; a <= x; ++a) {
            for (int b = 0; a + b <= x; ++b) {
                int val = dp[to][b][0];
                add(val, dp[to][b][2]);
                mul(val, tmp[a]);
                add(nx[a + b], val);
            }
        }
        memcpy(tmp, nx, sizeof(tmp));
    }
    for (int a = 0; a <= x; ++a) {
        dp[v][a][0] = tmp[a];
    }
}

int main() {

    //ifstream cin("input.txt");
    //freopen("defend.out", "w", stdout);
    //ifstream cin("input.txt");

    ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

    int n;
    cin >> n >> m;
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        g[u].pb(v);
        g[v].pb(u);
    }

    cin >> k >> x;

    dfs(0, 0);

    int ans = 0;

    for (int a = 0; a <= x; ++a) {
        for (int i = 0; i < 3; ++i) {
            add(ans, dp[0][a][i]);
        }
    }

    cout << ans << "\n";

}