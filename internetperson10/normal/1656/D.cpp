#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

set<ll> ps, primes;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    for(int i = 2; i <= 1000; i++) {
        bool ok = true;
        for(int p : ps) {
            if(i%p == 0) {
                ok = false;
                break;
            }
        }
        if(ok) {
            ps.insert(i);
            primes.insert(i);
        }
    }
    ll lastPrime;
    for(int i = 1000; i <= 50000; i++) {
        bool ok = true;
        for(int p : ps) {
            if(i%p == 0) {
                ok = false;
                break;
            }
        }
        if(ok) {
            primes.insert(i);
            lastPrime = i;
        }
    }
    primes.erase(2);
    int t;
    cin >> t;
    while(t--) {
        ll n;
        cin >> n;
        ll pow2 = 2;
        while(!(n%2)) {
            n /= 2;
            pow2 *= 2;
        }
        if((pow2 + 1) <= n) {
            cout << pow2 << '\n';
            continue;
        }
        if(n == 1) {
            cout << "-1\n";
            continue;
        }
        if(n+1 <= pow2 && n > 1) {
            cout << n << '\n';
            continue;
        }
    }
}