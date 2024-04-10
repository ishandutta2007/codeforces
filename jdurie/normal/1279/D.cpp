#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#include <bits/stdc++.h>
 
using namespace std;
typedef long long int ll;
typedef long double ld;
#define M 998244353
#define N 1000010
ll inv(ll a, ll b = M) { return 1 < a ? b - inv(b % a, a) * b / a : 1; } //inv a mod b

ll n, m, k[N];
vector<ll> kids[N];

int main() {
    cin >> n;
    for(ll i = 1; i <= n; ++i) {
        cin >> k[i];
        for(ll j = 1; j <= k[i]; ++j) {
            ll y; cin >> y;
            kids[y].push_back(i);
        }
    }
    ll ans = 0;
    for(ll y = 1; y <= N; ++y) {
        ll probYChosen = 0;
        ll probZWantsY = 0;
        for(ll x : kids[y]) {
            probYChosen = (probYChosen + inv(n) * inv(k[x]) % M) % M;
            probZWantsY = (probZWantsY + inv(n)) % M;
        }
        ans = (ans + probYChosen * probZWantsY % M) % M;
    }
    cout << ans << '\n';
}