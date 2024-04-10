#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pll = pair<ll, ll>;



int main() {
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<ll> primes;
    vector<ll> lp(n + 1, 0);
    for(ll i = 2; i <= n; ++i){
        if(lp[i] == 0){
            lp[i] = i;
            primes.push_back(i);
            for(ll j = i * i; j <= n; j += i){
                if(lp[j] == 0){
                    lp[j] = i;
                }
            }
        }
    }
    ll cur = 2;
    for(ll i = 1; i <= n; ++i) {
        map<ll, int> mp;
        ll z = i;
        while (z > 1) {
            ++mp[lp[z]];
            z /= lp[z];
        }
        ll least_square = 1;
        ll sqrt_least_square = 1;
        for (auto &p: mp) {
            if (p.second % 2 == 1) {
                ++p.second;
            }
            for (int j = 0; j < p.second; ++j) {
                least_square *= p.first;
                if (j & 1) {
                    sqrt_least_square *= p.first;
                }
            }
        }
        ll lsq_div_i = least_square / i;
        ll sth = (ll) ceill(sqrtl(cur / ((i + 1.) * (i + 1.) * least_square)));
        ll delta = sth * sth * lsq_div_i * (i + 1) * (i + 1) - cur / i;
        cout << (long long) delta << endl;
        cur = sth * sqrt_least_square * (i + 1);
    }
}