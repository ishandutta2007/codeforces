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

ll fir[DIM];
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll t; cin>>t;
    forn(query,t){
        ll n;
        cin>>n;
        forn(i,n){fir[i] = -1;}
        ll res = INF;
        forn(i,n){
            ll x; cin>>x;
            if (fir[x]==-1){
                fir[x] = i;
            }
            else{
                res = min(res,i-fir[x]+1);
                fir[x] = i;
            }
        }
        if (res==INF)cout<<"-1\n";
        else
        cout<<res<<endl;
    }
    return 0;
}