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


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            int tmp;
            cin >> tmp;
            if (i > k && tmp <= k) ans++;
        }
        cout << ans << endl;
    }
}