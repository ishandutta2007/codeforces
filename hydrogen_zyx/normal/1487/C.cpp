#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const ll N = 1 << 20;
const ll mod = 1e9 + 7;
const double dinf = 1e99;
const int inf = 0x3f3f3f3f;
const ll linf = 0x3f3f3f3f3f3f3f3f;

int a[N];

int main() {
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--) {
        int n;;
        cin >> n;
        for (int i = 1; i <= n; i++) {
            for (int j = i + 1; j <= n; j++) {
                if (n % 2 == 1) {
                    cout << ((i + j) % 2 == 0 ? -1 : 1) << ' ';
                    continue;
                }
                if (n % 2 == 0 && i + j == n + 1) cout << 0 << ' ';
                else {
                    int ans = ((i + j) % 2 == 0 ? -1 : 1);
                    if (i + j > n + 1) ans = -ans;
                    cout << ans << ' ';
                }

            }
        }
        cout << endl;
    }
}