#include "bits/stdc++.h"
using namespace std;
typedef pair<int,int>pii;
typedef long long ll;
typedef pair<ll,ll> pll;
typedef __int128 lll;
typedef vector<int> vi;
typedef vector<ll> vl;
mt19937 rng(chrono::system_clock::now().time_since_epoch().count());
const ll inf=0x3f3f3f3f3f3f3f3f;

ll hail(ll p,ll f,ll i){
    while(p%f==0)p/=i;
    return p;
}
int main(){
#ifdef LOCAL
    freopen("input.txt","r",stdin);
freopen("output.txt","w",stdout);
freopen("error.txt","w",stderr);
#endif
    cin.tie(0);
    cin.sync_with_stdio(0);
    int tc;
    cin>>tc;
    while(tc--){
        ll p,q,h;
        cin>>p>>q;
        h=q;
        ll ans=-inf;
        for(ll i=2;i*i<=h;i++){
            if(h%i==0){
                ll f=1;
                while(h%i==0)h/=i,f*=i;
                ans=max(ans,hail(p,f,i));
            }
        }
        if(h!=1)ans=max(ans,hail(p,h,h));
        printf("%lld\n",ans);
    }
}
/*
Always remember to add the \n at the end
Don't get stuck on a problem

*/