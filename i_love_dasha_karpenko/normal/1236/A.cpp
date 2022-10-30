#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pp;
#define forn(i,n) for(ll i = 0;i<n;i++)
int main() {
    ll t;
    cin>>t;
    forn(query,t){
        ll a,b,c; cin>>a>>b>>c;
        ll res = 0,r1;
        r1 = min(c/2,b);
        res+=r1*3;
        b-=r1;
        r1 = min(b/2,a);
        res+=r1*3;
        cout<<res<<endl;
    }
}