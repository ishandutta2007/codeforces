#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
const int N = 2e5 + 1;
const long long mod = 1e9 + 7;
vector <int> e[N];
bool use[N];

long long bp(long long x, int st) {
    if (st == 0)
        return 1;
    else if (st % 2 == 0)
            return bp((x * x) % mod, st / 2);
        else
            return (bp((x * x) % mod, st / 2) * x) % mod;
}

int dfs(int u) {
    use[u] = 1;
    int ans = 1;
    for (int i = 0; i < e[u].size(); ++i)
    if (!use[e[u][i]])
        ans += dfs(e[u][i]);
    return ans;
}



int main() {
    int i, j, k, l, r, n, a, b;
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> k;
    for (i = 1; i < n; ++i) {
        cin >> a >> b >> j;
        if (j == 0) {
            e[a].push_back(b);
            e[b].push_back(a);
        }
    }
    long long ans = bp(n, k);
    for (i = 1; i <= n; ++i)
    if (!use[i]) {
        int cnt = dfs(i);
        ans = (ans + mod - bp(cnt, k)) % mod;
    }
    if (ans < 0)
        ans = (ans + mod * mod) % mod;
    cout << ans;
}