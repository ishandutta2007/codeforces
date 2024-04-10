#include<bits/stdc++.h>

using namespace std;

#define pii pair<ll,ll>
#define fi first
#define se second
#define de(x) cout<< #x << ' ' << x << endl;
typedef long long ll;
const ll N = 1e6 + 5;
const ll mod = 1e9 + 7;
const ll inf = 0x3f3f3f3f3f3f3f3f;

int a[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);


    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        for (int i = 0; i < n; i++) cin >> a[i];
        int ans = -0x3f3f3f3f;
        for (int i = 0; i < n; i++) ans = max(ans, a[i] - a[(i + 1) % n]);
        for (int i = 1; i < n - 1; i++) {
            ans = max(ans, a[i] - a[0]);
            ans = max(ans, a[n - 1] - a[i]);
        }
        cout << ans << endl;
    }
}