#include <bits/stdc++.h>

using namespace std;

#define int long long

const int maxn = 1e5 + 5;
const int maxcnt = 12;
const int mod = 1e9 + 7;

int n, m, k, x;
vector<int> graph[maxn];
int next_brother[maxn];
int first_son[maxn];
int dp[maxn][3][maxcnt];
vector<int> order;

void dfs(int v, int p) {
    order.push_back(v);
    int last_child = 0;
    for (auto to: graph[v]) {
        if (to == p) continue;
        if (last_child != 0) {
            next_brother[last_child] = to;
        }
        last_child = to;
        if (!first_son[v]) {
            first_son[v] = to;
        }
        dfs(to, v);
    }
}

void recalc(int v, int tp, int cnt) {
    for (int our = 0; our < 3; ++our) {
        if (tp == 1 && our != 0) continue;
        if (tp == 2 && our == 1) continue;
        if (cnt == 0 && our == 1) continue;
        int rest = (our == 1) ? cnt - 1: cnt;
        int val;
        if (our == 0) val = k - 1;
        else if (our == 1) val = 1;
        else val = m - k;
        int bro = next_brother[v];
        int son = first_son[v];
        //cerr << v << ' ' << bro << ' ' << son << endl;
        if (bro && son) {
            int bro = next_brother[v], son = first_son[v];
            for (int k = 0; k <= rest; ++k) {
                dp[v][tp][cnt] += val * dp[son][our][k] % mod * dp[bro][tp][rest - k];
                dp[v][tp][cnt] %= mod;
            }
        } else if (bro) {
            dp[v][tp][cnt] += val * dp[bro][tp][rest];
            dp[v][tp][cnt] %= mod;
        } else if (son) {
            dp[v][tp][cnt] += val * dp[son][our][rest];
            dp[v][tp][cnt] %= mod;
        } else if (rest == 0) {
            dp[v][tp][cnt] += val;
            dp[v][tp][cnt] %= mod;
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    cin >> n >> m;
    for (int i = 1; i < n; ++i) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    cin >> k >> x;
    dfs(1, -1);
    reverse(order.begin(), order.end());
    for (int cnt = 0; cnt <= x; ++cnt) {
        for (auto v: order) {
            for (int tp = 0; tp < 3; ++tp) {
                recalc(v, tp, cnt);
            }
        }
    }

    int ans = 0;
    for (int i = 0; i <= x; ++i) {
        ans += dp[1][0][i];
        ans %= mod;
    }
    cout << ans << '\n';
}