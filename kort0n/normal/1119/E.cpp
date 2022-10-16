#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> l_l;

#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))
//const ll mod = 1000000007;
ll n;
ll a[300050];

int main() {
    //cout.precision(10);
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> n;
    for(ll i = 1; i <= n; i++) cin >> a[i];
    ll ans = 0;
    ll rest = 0;
    for(int i = 1; i <= n; i++) {
        ll val = min(rest, a[i] / 2);
        rest -= val;
        ans += val;
        a[i] -= val * 2;
        ans += a[i] / 3;
        rest += a[i] % 3;
    }
    cout << ans << endl;
    return 0;
}