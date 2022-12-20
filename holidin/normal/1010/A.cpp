#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 1;

long double k, a[N], b[N], k1;

int main() {
    int i, j, n;
   // freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> k;
    k1 = k;
    for (i = 0; i < n; ++i)
        cin >> a[i];
    for (i = 0; i < n; ++i)
        cin >> b[i];
    for (i = n - 1; i >= 0; --i) {
        if (a[i] == 1 || b[i] == 1) {
            cout << -1;
            return 0;
        }
        k += k / (b[i] - 1);
        k += k / (a[i] - 1);
    }
    cout << fixed << setprecision(7) << k - k1;
}