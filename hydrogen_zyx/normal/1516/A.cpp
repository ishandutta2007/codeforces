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

int main() {
    ios::sync_with_stdio(false),
            cin.tie(nullptr),
            cout.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        for (int i = 1; i <= n; i++) cin >> a[i];
        int now = 0;
        for (int i = 1; i <= n; i++) {
            now += min(k, a[i]);
            int add = min(k, a[i]);
            k -= add;
            a[i] -= add;
        }
        a[n] += now;
        for (int i = 1; i <= n; i++) cout << a[i] << ' ';
        cout << endl;
    }
}