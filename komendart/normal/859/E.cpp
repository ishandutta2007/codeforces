#include <bits/stdc++.h>

using namespace std;

#define int long long

const int mod = 1e9 + 7;
const int maxn = 2e5 + 5;

int n;
int a[maxn];
vector<int> graph[maxn];
char used[maxn];

int dfs1(int v) {
    used[v] = true;
    int ans = 1;
    for (auto to: graph[v]) {
        ans += dfs1(to);
    }
    return ans % mod;
}

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        a[x] = y;
        graph[y].push_back(x);
    }

    int ans = 1;
    for (int i = 1; i <= 2 * n; ++i) {
        if (a[i] == 0) {
            ans *= dfs1(i);
            ans %= mod;
        }
    }

    for (int i = 1; i <= 2 * n; ++i) {
        if (used[i]) continue;
        int j;
        for (j = i; !used[j]; j = a[j]) {
            used[j] = 2;
        }
        if (used[j] == 2 && a[j] != j) {
            ans *= 2;
            ans %= mod;
        }
        for (int j = i; used[j] == 2; j = a[j]) {
            used[j] = true;
        }
    }
    cout << ans << '\n';
}