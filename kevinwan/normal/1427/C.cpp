#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int>pii;
typedef long long ll;
typedef pair<ll,ll> pll;
typedef __int128 lll;
typedef vector<int> vi;
typedef vector<ll> vl;
mt19937 rng(chrono::system_clock::now().time_since_epoch().count());
const int mn=2e5+10;
const ll inf=0x3f3f3f3f3f3f3f3f;
const ll mod=1e9+7;
const ll half=(mod+1)/2;
const double PI=acos(-1);
int t[mn],a[mn],b[mn],dp[mn],pm[mn];
int main(){
#ifdef LOCAL_PROJECT
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    freopen("error.txt","w",stderr);
#else
#endif
    cin.tie(0);
    cin.sync_with_stdio(0);
    int r,n;
    cin>>r>>n;
    memset(dp,0xc0,sizeof(dp));
    a[0]=b[0]=1,dp[0]=0;

    for(int i=1;i<=n;i++){
        cin>>t[i]>>a[i]>>b[i];
        for(int j=i-1;j>=0;j--){
            if(t[i]-t[j]>=2*r){
                //cerr<<i<<endl;
                dp[i]=max(pm[j]+1,dp[i]);
                break;
            }
            if(abs(a[i]-a[j])+abs(b[i]-b[j])<=t[i]-t[j])dp[i]=max(dp[i],dp[j]+1);
        }
        //cerr<<dp[i]<<endl;
        pm[i]=max(pm[i-1],dp[i]);
    }
    printf("%d\n",pm[n]);
}