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
const int mn=1e6+10;
const ll mod=1e9+7;

int sf[mn],num[mn],a[mn];

int main(){
#ifdef LOCAL
    freopen("input.txt","r",stdin);
freopen("output.txt","w",stdout);
freopen("error.txt","w",stderr);
#endif
    cin.tie(0);
    cin.sync_with_stdio(0);
    iota(sf,sf+mn,0);
    for(int i=2;i*i<mn;i++)for(int j=i*i;j<mn;j+=i*i)while(sf[j]%(i*i)==0)sf[j]/=i*i;
    int tc;
    cin>>tc;
    while(tc--){
        int n;
        cin>>n;
        for(int i=0;i<n;i++){
            cin>>a[i];
            num[sf[a[i]]]++;
        }
        int q;
        cin>>q;
        ll ans=0;
        ll a1=0;
        for(int i=0;i<n;i++){
            ans=max(ans,(ll)num[sf[a[i]]]);
            if(num[sf[a[i]]]%2==0)a1+=num[sf[a[i]]];
            else if(sf[a[i]]==1)a1+=num[1];
            num[sf[a[i]]]=0;
        }
        while(q--){
            ll t;
            cin>>t;
            if(t)printf("%lld\n",max(ans,a1));
            else printf("%lld\n",ans);
        }
    }
}