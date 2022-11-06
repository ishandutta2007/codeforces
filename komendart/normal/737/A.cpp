#include <bits/stdc++.h>

using namespace std;

#define int long long

const int maxn = 2e5 + 40;

int n, k, s, t;
int c[maxn];
int v[maxn];
vector<int> len;

bool f(int x) {
    int time = 0;
    for (auto i: len) {
        if (x < i) return false;
        int a = x - i;
        a = min(a, i);
        int b = i - a;
        time += a + 2 * b;
    }
    return time <= t;
}

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    cin >> n >> k >> s >> t;
    for (int i = 0; i < n; i++) {
        cin >> c[i];
        cin >> v[i];
    }
    vector<int> g(k);
    for (int i = 0; i < k; i++) {
        cin >> g[i];
    }
    sort(g.begin(), g.end());
    int prev = 0;
    for (int i = 0; i < k; i++) {
        len.push_back(g[i] - prev);
        prev = g[i];
    }
    len.push_back(s - prev);

    int left = 0, right = 1e15;
    while (right - left > 1) {
        int mid = (left + right) / 2;
        if (f(mid)) {
            right = mid;
        } else {
            left = mid;
        }
    }
    int ans = 1e15;
    for (int i = 0; i < n; i++) {
        if (v[i] >= right) ans = min(ans, c[i]);
    }
    if (ans == 1e15) cout << -1 << endl;
    else cout << ans << endl;
}