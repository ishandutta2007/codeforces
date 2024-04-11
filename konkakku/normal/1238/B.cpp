#include <bits/stdc++.h>
using namespace std;

const int N = 100005;

int n, r, t, a[N];

int solve() {
    cin >> n >> r;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    sort(a + 1, a + n + 1, greater<int>());
    n = distance(a + 1, unique(a + 1, a + n + 1));
    for (int i = 1; i <= n; i++) {
        if (a[i] - 1LL * (i - 1) * r <= 0) {
            return i - 1;
        }
    }
    return n;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t;
    while (t--) {
        cout << solve() << '\n';
    }
}