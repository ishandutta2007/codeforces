#pragma GCC target("avx2")
#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pl;
typedef vector<ll> vl;

#define G(x) ll x; cin>>x;
#define F(i, l, r) for (ll i=l i<(r); ++i)
#define all(a) begin(a), end(a)
#define K first
#define V second

constexpr ll M = 1e9+7;

ll phi(ll n) {
        ll a=n;
        for (ll p=2; p*p<=a; ++p) {
                if (a%p==0) {
                        while (a%p==0) a/=p;
                        n = n/p * (p-1);
                }
        }
        if (a!=1) {
                n = n/a * (a-1);
        }
        return n;
}

int main() {
        cin.tie(0)->sync_with_stdio(0);

        ll n, k; cin>>n>>k;
        for (ll i=1; i<=k; i+=2) {
                if (n==1) {
                        cout<<1<<endl;
                        return 0;
                }
                n = phi(n);
        }
        cout<<n%M<<endl;
}