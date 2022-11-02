#include <bits/stdc++.h>
using namespace std;

const int N = 200005;

int n, h, t, p[N];

int solve() {
    int ans = 0;
    cin >> h >> n;
    for (int i = 1; i <= n; i++) {
        cin >> p[i];
    }
    p[n + 1] = 0;
    for (int i = 2; i <= n; i++) {
        if (p[i] - 1 > p[i + 1]) {
            ans++;
        } else {
            i++;
        }
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t;
    while (t--) {
        cout << solve() << '\n';
    }
}