#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<ll, ll>;
using vi = vector<ll>;
#define pb push_back
#define mp make_pair

ll mod = 1e9+7;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    
    ll pow = 1;
    for (ll i = 0; i < n-1; i++) {
        pow *= 2;
        pow %= mod;
    }

    ll fac = 1;
    for (ll i = 1; i <= n; i++) {
        fac *= i;
        fac %= mod;
    }
    fac -= pow;
    fac %= mod;
    fac += mod;
    fac %= mod;
    cout << fac << endl;
}