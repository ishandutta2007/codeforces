#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int>pii;
mt19937 rng(chrono::system_clock::now().time_since_epoch().count());
typedef long long ll;
const int mn=2e5+10;

int main(){
    int tc;
    scanf("%d",&tc);
    while(tc--){
        ll d,m;
        scanf("%lld%lld",&d,&m);
        ll ans=1;
        for(ll i=1;i<=d;i<<=1){
            if(d>=2*i)ans*=i+1,ans%=m;
            else ans*=d-i+2,ans%=m;
        }
        ans--;
        if(ans<0)ans+=m;
        printf("%lld\n",ans);
    }
}