// Retired?
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = long unsigned long;
using ld = double long;

int main() {
    ios::sync_with_stdio(!cin.tie(0));

    ll n;
    double p;
    cin >> n >> p;

    ll pint = round(p * 10000);
    ll pz = pint * n * (n-1) * (n-2);

    for (ll x=0; x<=n; x++) {
        ll prob = 0;
        
        // x(x-1)(x-2)/6   /   n(n-1)(n-2)/6
        ll p3 = x*(x-1)*(x-2);
        prob += p3;

        // x(x-1)(n-x)/2   /   n(n-1)(n-2)/6
        ll p2 = x*(x-1)*(n-x)*3;
        prob += p2;

        // x(n-x)(n-x-1)/2   /   n(n-1)(n-2)/6
        ll p1 = x*(n-x)*(n-x-1)*3;
        prob += p1 / 2;

        if (prob * 10000 >= pz) {
            cout << x << '\n';
            return 0;
        }
    }
}