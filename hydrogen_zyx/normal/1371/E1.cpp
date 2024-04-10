#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll mod;
ll a[3000];
int main() {
    ios::sync_with_stdio(false);
    ll n;
    cin >> n >> mod;
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a, a + n);
    vector<ll> ans;
    for (int x = 1; x <= a[n - 1]; x++) {
        ll cnt = 0, p = 0;
        ll sum = 1;
        for (int i = 0; i < n; i++) {
            while (p < n && a[p] <= x + i) {
                ++p;
                ++cnt;
            }
            if (cnt == 0) {
                sum = 0;
                break;
            }
            sum = (sum * cnt) % mod;
            cnt--;
        }
        if (sum) ans.push_back(x);
    }
    cout << ans.size() << endl;
    for (auto x : ans) {
        cout << x << ' ';
    }
}