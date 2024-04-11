#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> l_l;

#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))
const ll mod = 998244353;

int main() {
    //cout.precision(10);
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll n;
    cin >> n;
    vector<ll> a(n), b(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++) cin >> b[i];
    for(ll i = 0; i < n; i++) {
        a[i] *= (i + 1) * (n - i);
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end(), greater<ll>());
    ll ans = 0;
    for(int i = 0; i < n; i++) {
        ans += (a[i] % mod) * b[i] % mod;
        ans %= mod;
    }
    cout << ans << endl;
    return 0;
}