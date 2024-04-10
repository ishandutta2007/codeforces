#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int>pii;
mt19937 rng(423978);
typedef long long ll;
typedef pair<ll,ll>pll;
const ll mod=998244353;
const int mn=1e5+10;
ll key[3][4]={{0,1,2,3},
              {0,2,3,1},
              {0,3,1,2}};
int main(){
    int tc;
    scanf("%d",&tc);
    while(tc--){
        ll n;
        scanf("%lld",&n);
        ll lev=__lg(n)/2;
        n-=1LL<<(2*lev);
        ll ind=n/3,pos=n%3;
        ll ans=(pos+1)<<(2*lev);
        for(ll i=0;i<lev;i++){
            ll mo=(ind>>(2*i))&3;
            ans+=key[pos][mo]<<(2*i);
        }
        printf("%lld\n",ans);
    }
}