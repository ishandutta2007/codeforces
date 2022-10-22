#include<bits/stdc++.h>

using namespace std;

const int mod = 1e9 + 7;
const int N = 1e5;
int n, k, ans = 0, res[N];
vector<int> g[N];
vector<int> dp[N];

vector<int> merge(const vector<int>& a, const vector<int>& b) {
    vector<int> res(min(k + 1, (int) a.size() + (int) b.size() - 1));
    for (int i = 0; i < (int) a.size(); i++) {
        for (int j = 0; j < (int) b.size(); j++) {
            if (i + j >= (int) res.size()) {
                break;
            }
            res[i + j] = (res[i + j] + a[i] * 1ll * b[j]) % mod;
        }
    }
    return res;
}

void dfs(int v, int p) {
    dp[v] = {2};
    for (auto x : g[v]) {
        if (x != p) {
            dfs(x, v);
            dp[v] = merge(dp[v], dp[x]);
            for (int i = 0; i < min(k + 1, (int) dp[x].size()); i++) {
                res[i] = (res[i] - dp[x][i] + mod) % mod;
            }
        }
    }
    dp[v].push_back(0);
    for (int i = 0; i < min(k + 1, (int) dp[v].size()); i++) {
        res[i] = (res[i] + dp[v][i]) % mod;
    }
    for (int i = (int) dp[v].size() - 1; i > 0; i--) {
        dp[v][i] = (dp[v][i] + dp[v][i - 1]) % mod;
    }
    dp[v][1] = (dp[v][1] + mod - 1) % mod;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> k;
    for (int i = 0; i + 1 < n; i++) {
        int x, y;
        cin >> x >> y;
        x--, y--;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    dfs(0, -1);
    vector<vector<int>> num(k + 1, vector<int> (k + 1));
    num[0][0] = 1;
    for (int i = 1; i <= k; i++) {
        for (int j = 1; j <= i; j++) {
            num[i][j] = (j * 1ll * (num[i - 1][j - 1] + num[i - 1][j])) % mod;
        }
    }
    for (int i = 1; i <= k; i++) {
        ans = (ans + res[i] * 1ll * num[k][i]) % mod;
    }
    cout << ans;
}