#include <bits/stdc++.h>
using namespace std;

vector<bool> visited;
int vis = 1;
int m, a, b;

void dfs(int cur, int limit) {
    visited[cur] = true;
    vis++;
    if (cur - b >= 0 && !visited[cur - b])
        dfs(cur - b, limit);

    if (cur + a <= limit && !visited[cur + a])
        dfs(cur + a, limit);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> m >> a >> b;
    long long ans = 1;

    int g = gcd(a, b);
    auto f = [&g](int n) {
        int x = n / g;
        long long res = (1 + x) * (long long)x / 2 * g;
        res += (n - x*g + 1) * (x + 1);
        return res;
    };

    visited.assign(10'000'000, false);
    visited[0] = true;
    for (int i = 1; i <= m; i++) {
        if (i == 10'000'000) {
            ans += f(m);
            ans -= f(i - 1);
            break;
        }
        if (i - a >= 0 && visited[i-a])
            dfs(i, i);
        ans += vis;
    }
    cout << ans << '\n';
    // g = 3;
    // cout << f(8) << endl;
    // cout << f(9) << endl;
    // cout << f(10) << endl;
}