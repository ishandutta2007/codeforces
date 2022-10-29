#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const ll N = 1 << 20;
const ll N2 = 5005;
const ll mod = 1e9 + 7;
const double dinf = 1e99;
const int inf = 0x3f3f3f3f;
const ll linf = 0x3f3f3f3f3f3f3f3f;
int tag[N];

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n, k, m;
        cin >> n >> k >> m;
        for (int i = 1; i <= n; i++) tag[i] = 0;
        for (int i = 1; i <= m; i++) {
            int a;
            cin >> a;
            tag[a] = 1;
        }
        int l = 0, r = n - m;
        bool ok = 0;
        for (int i = 1; i <= n; i++) {
            if (tag[i]) {
                int ll = l - k / 2;
                int rr = r - k / 2;
                if (ll >= 0 && rr >= 0 && (ll + rr) % (k - 1) == 0) ok = 1;
            } else {
                l++;
                r--;
            }
        }
        cout << (ok ? "YES" : "NO") << endl;
    }
}