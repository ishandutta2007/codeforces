#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int>pii;
typedef long long ll;
const ll mod=1e9+7;
const int mn=4e2+10;
ll a[mn],dp[mn][mn];
int ind[mn];
vector<pii>v[mn][mn];
int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=0;i<m;i++){
        int a,b,c,d;
        cin>>a>>b>>c>>d;
        v[a][b].push_back({d+1,c});
    }
    ll ans=0;
    for(int i=1;i<=n;i++){
        memset(dp,0x3f,sizeof(dp));
        memset(dp[i],0,sizeof(dp[i]));
        fill(ind,ind+mn,i);
        for(int j=i+1;j<=n;j++){
            for(int k=1;k<=n+1;k++){
                while(max(a[j]-a[ind[j]],dp[ind[j]][k-1])>max(a[j]-a[ind[j]+1],dp[ind[j]+1][k-1]))ind[j]++;
                dp[j][k]=max(a[j]-a[ind[j]],dp[ind[j]][k-1]);
            }
            for(auto p:v[i][j]){
                ans=max(ans,dp[j][p.first]*p.second);
            }
        }
    }
    printf("%lld",ans);
}