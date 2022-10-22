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
const int mn=5e5+10;
const ll mod=1e9+7;

ll a[mn];
ll num[60];
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
        int n;
        cin>>n;
        for(int i=0;i<n;i++)cin>>a[i];
        memset(num,0,sizeof(num));
        for(int i=0;i<n;i++)for(int j=0;j<60;j++)if((a[i]>>j)&1)
            num[j]+=1LL<<j,num[j]%=mod;
        ll ans=0;
        for(int i=0;i<n;i++){
            ll sa=0,sb=0;
            for(int j=0;j<60;j++){
                if((a[i]>>j)&1){
                    sa+=num[j],sa%=mod;
                    sb+=(lll(n)<<j)%mod,sb%=mod;
                }
                else sb+=num[j],sb%=mod;
            }
            ans+=sa*sb,ans%=mod;
        }
        printf("%lld\n",ans);
    }
}