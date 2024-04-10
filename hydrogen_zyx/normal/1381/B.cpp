#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const ll N = 1 << 20;
const ll N2 = 5005;
const ll mod = 1e9 + 7;
const double dinf = 1e99;
const double PI = cos(-1.0);
const int inf = 0x3f3f3f3f;
const ll linf = 0x3f3f3f3f3f3f3f3f;
int a[N];
int dp[N];
int b[N], tot;

int main() {
    ios::sync_with_stdio(false),
            cin.tie(nullptr),
            cout.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        for (int i = 1; i <= 2 * n; i++) cin >> a[i];
        tot = 0;
        int now = a[1];
        int len = 1;
        for (int i = 2; i <= 2 * n; i++) {
            if (a[i] > now) {
                b[++tot] = len;
                len = 1;
                now = a[i];
            } else {
                len++;
            }
        }
        b[++tot] = len;
        for (int i = 0; i <= n; i++) dp[i] = 0;
        dp[0] = 1;
        for (int i = 1; i <= tot; i++) {
            for (int j = n; j > 0; j--) {
                if (j >= b[i]) {
                    dp[j] |= dp[j - b[i]];
                }
            }
        }
        if (dp[n]) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}