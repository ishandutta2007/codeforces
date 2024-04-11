#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))

int main() {
    //cout.precision(10);
    ll n;
    cin >> n;
    ll ans = 0;
    for(ll i = 2; i <= n; i++){
        ll out = n / i;
        if(out == 1) break;
        ans += (out * (out + 1) / 2 - 1) * 4;
    }
    cout << ans << endl;
    return 0;
}