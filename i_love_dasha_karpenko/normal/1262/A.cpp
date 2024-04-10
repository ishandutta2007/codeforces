#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll,ll> pp;
typedef unsigned long long ull;
typedef pair<ull,ll> upp;
const ll DIM = 200000+7;
const ll INF = 10e16;
#define pb push_back
#define forn(i,n) for(ll i = 1;i<=n;++i)
#define fi first
#define sc second
#define po(x) (1<<x)


int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll t; cin>>t;
    forn(query,t){
        ll n,mi = INF,mx = -INF;
        cin>>n;
        forn(i,n){
            ll x,y; cin>>x>>y;
            if (x>y)swap(x,y);
            mx = max(x,mx);
            mi = min(mi,y);
        }
        cout<<max(0ll,mx-mi)<<endl;
    }
    return 0;
}