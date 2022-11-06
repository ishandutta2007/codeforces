#include <bits/stdc++.h>

using namespace std;

const int maxn = 2e5 + 5;

int n;
int p[maxn];
int b[maxn];
char used[maxn];

void dfs(int v) {
    if (used[v]) return;
    used[v] = true;
    dfs(p[v]);
}

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> p[i]; --p[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
    }

    int ans = 0;
    for (int i = 0; i < n; ++i) {
        if (!used[i]) {
            ++ans;
            dfs(i);
        }
    }
    if (ans == 1) ans = 0;

    ans += 1 - accumulate(b, b + n, 0) % 2;
    cout << ans << '\n';
}