#pragma GCC target("avx2")
#pragma GCC optimize("O3,unroll-loops")

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef long double ld;
typedef pair<ll, ll> pl;
typedef vector<ll> vl;

#define G(x) ll x; cin >> x;
#define F(i, l, r) for(ll i = l; i < (r); i++)
#define all(a) begin(a), end(a)
#define K first
#define V second

#define NN  300010

ll a[2][NN], sm[NN], dloop[2*NN], uloop[2*NN], pu[2*NN], pd[2*NN];

int main(){
    cin.tie(0)->sync_with_stdio(0);

    ll n; cin>>n;
    for (ll i=0; i<2; ++i)
        for (ll j=0; j<n; ++j) cin>>a[i][j];

    for (ll i=n-1; i>=0; --i)
        sm[i] = sm[i+1] + a[0][i] + a[1][i];
    
    for (ll i=0; i<n; ++i) uloop[i] = i*a[0][i];
    for (ll i=0; i<n; ++i) uloop[i+n] = (i+n)*a[1][n-1-i];

    for (ll i=0; i<n; ++i) dloop[i] = i*a[1][i];
    for (ll i=0; i<n; ++i) dloop[i+n] = (i+n)*a[0][n-1-i];

    partial_sum(uloop, uloop+2*n, pu+1);
    partial_sum(dloop, dloop+2*n, pd+1);

    ll ans = 0;
    ll curi=0, curj=0, tim=0;
    ll curval = 0;
    while (curj<n) {
        {
            auto loop = (curi==0 ? pu : pd);
            ll cur = curval + loop[2*n-1-curj+1] - loop[curj] + curj * sm[curj];
            ans = max(ans, cur);
        }
        curval += tim * a[curi][curj] + (tim+1) * a[curi^1][curj];
        curi^=1;
        curj++;
        tim+=2;
    }
    ans = max(ans, curval);
    cout<<ans<<endl;
}