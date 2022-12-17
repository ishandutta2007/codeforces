#include <bits/stdc++.h>
using namespace std;
const int N = 2e5;

long double E[N];

int main() {
    int i, j, k, n, u, l;
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> u;
    for (i = 0; i < n; ++i)
        cin >> E[i];
    long double ans = -1;
    l = n;
    for (i = n - 1; i >= 0; --i) {
        while (l > 0 && E[i] - E[l - 1] <= u) {
            --l;
            if (l < i - 1)
                ans = max(ans, (E[i] - E[l + 1]) / (E[i] - E[l]));
        }
    }
    if (ans < 0)
        cout << -1;
    else
    cout << fixed << setprecision(10) << ans;
}