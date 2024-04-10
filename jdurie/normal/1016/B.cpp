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

#define NN 1010

ll good[NN], ps[NN];

int main(){
    cin.tie(0)->sync_with_stdio(0);

    ll n, m, q; cin>>n>>m>>q;
    string s; cin>>s;
    string t; cin>>t;
    for (ll i=0; i+m<=n; ++i) {
        if (s.substr(i, m) == t) good[i]=1;
        else good[i]=0;
    }
    partial_sum(good, good+n, ps+1);

    while (q--) {
        ll l, r; cin>>l>>r;
        --l;
        r = r-m+1;
        if (r<=l) {
            cout<<0<<'\n';
            continue;
        }
        cout<<ps[r] - ps[l]<<'\n';
    }
}