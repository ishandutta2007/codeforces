#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> l_l;

#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))
//const ll mod = 1000000007;
ll n;
ll a[200500];

int main() {
    //cout.precision(10);
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];
    ll ans = 0;
    ll before = 2e9;
    for(ll i = n; i >= 1; i--) {
        a[i] = min(a[i], before - 1);
        a[i] = max(a[i], (ll)0);
        ans += a[i];
        before = a[i];
    }
    cout << ans << endl;
    return 0;
}