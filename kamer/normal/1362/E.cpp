#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;

const ll BIG = 10000000;
const ll MOD = 1000000007;

ll expo(ll p, ll k) {
    if (k == 0) return 1;
    if (k == 1) return p;
    ll e = expo(p, k / 2);
    e = (e * e) % MOD;
    if (k % 2 == 1) return (e * p) % MOD;
    else            return e;
}


ll boundedExpo(ll p, ll k) {
    if (k == 0) return 1;
    if (k == 1) return p;
    ll e = boundedExpo(p, k / 2);
    e = e * e;
    if (e > BIG) return BIG;
    if (k % 2 == 0) return e;
    e = e * p;
    if (e > BIG) return BIG;
    return e;
}

int main(void) {
   ios::sync_with_stdio(0);
   cin.tie(0);
   ll t;
   cin >> t;
   ll T = t;
   while (t--) {
        ll n, p;
        cin >> n >> p;
        vector<ll> k(n);
        for (ll i = 0; i < n; i++) cin >> k[i];
        sort(k.begin(), k.end());
        ll lastValue;
        ll expoValue;
        ll count = 0;
        ll diff = 0;
        ll pInverse = expo(p, MOD - 2);
        for (int i = n - 1; i >= 0; i--) {
            if (i == n - 1) {
                lastValue = k[i];
                expoValue = expo(p, lastValue);
            }
            
            count = min(count * boundedExpo(p, lastValue - k[i]), BIG);
            expoValue = (expoValue * expo(pInverse, lastValue - k[i])) % MOD;
            lastValue = k[i];
            if (count == 0) {
                diff = (diff + expoValue) % MOD;
                count = 1;
            } else {
                diff = (diff - expoValue + MOD) % MOD;
                count--;
            }
        }
            cout << diff << "\n";
   }
}