#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const ll N = 1 << 20;
const ll mod = 1e9 + 7;
const double dinf = 1e99;
const int inf = 0x3f3f3f3f;
const ll linf = 0x3f3f3f3f3f3f3f3f;

int a[N];
int b[N];

int main() {
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++) cin >> a[i];
        b[1] = b[n] = 0;
        for (int i = 2; i < n; i++) {
            if (a[i] > a[i - 1] && a[i] > a[i + 1]) b[i] = 1;
            else if (a[i] < a[i - 1] && a[i] < a[i + 1]) b[i] = 1;
            else b[i] = 0;
        }
        int cnt = 0;
        for (int i = 1; i <= n; i++) if (b[i]) cnt++;
        int ans = cnt;
        for (int i = 2; i < n; i++) {
            int now, tmp;
            now = b[i - 1] + b[i] + b[i + 1];
            tmp = min(a[i - 1], a[i + 1]);
            if (i != 2 && a[i - 1] > a[i - 2] && a[i - 1] > tmp) now--;
            if (i != 2 && a[i - 1] < a[i - 2] && a[i - 1] < tmp) now--;
            if (i != n - 1 && a[i + 1] > a[i + 2] && a[i + 1] > tmp) now--;
            if (i != n - 1 && a[i + 1] < a[i + 2] && a[i + 1] < tmp) now--;
            ans = min(ans, cnt - now);
            now = b[i - 1] + b[i] + b[i + 1];
            tmp = max(a[i - 1], a[i + 1]);
            if (i != 2 && a[i - 1] > a[i - 2] && a[i] > tmp) now--;
            if (i != 2 && a[i - 1] < a[i - 2] && a[i - 1] < tmp) now--;
            if (i != n - 1 && a[i + 1] > a[i + 2] && a[i + 1] > tmp) now--;
            if (i != n - 1 && a[i + 1] < a[i + 2] && a[i + 1] < tmp) now--;
            ans = min(ans, cnt - now);
        }
        if (n > 2) {
            ans = min(ans, cnt - b[2]);
            ans = min(ans, cnt - b[n - 1]);
        }
        cout << ans << endl;
    }
}