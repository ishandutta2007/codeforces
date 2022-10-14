#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef long double ld;

ll fact[300000];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n, m, ans = 0;
    cin >> n >> m;
    fact[0] = 1;
    for(ll i = 1; i < 300000; i++) fact[i] = (fact[i - 1] * i) % m;
    for(ll l = 1; l <= n; l++)
        ans = (ans + fact[n - l] * fact[l] % m * (n - l + 1) % m * (n - l + 1) % m) % m;
    cout << ans << endl;
}