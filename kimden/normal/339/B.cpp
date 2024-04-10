#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;

int main()
{
    ll n, m;
    cin >> n >> m;
    ll prev = 0;
    ll ans = 0;
    ll a;
    for(ll i = 0; i < m; i++){
        cin >> a;
        a += n - 1;
        a %= n;
        ans += (a - prev + n) % n;
        prev = a;
    }
    cout << ans << endl;
    return 0;
}