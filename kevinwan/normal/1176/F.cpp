#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int>pii;
typedef long long ll;
const int mn=2e5+10;
const ll mod=998244353;
ll dp[mn][10];
vector<ll>v[4];
int main(){
    int n;
    scanf("%d",&n);
    memset(dp,0xc0,sizeof(dp));
    dp[0][0]=0;
    for(int i=1;i<=n;i++){
        int k;
        scanf("%d",&k);
        v[1].clear(),v[2].clear(),v[3].clear();
        v[1].push_back(-1e15),v[1].push_back(-1e15),v[1].push_back(-1e15),v[2].push_back(-1e15),v[3].push_back(-1e15);
        while(k--){
            int a,b;
            scanf("%d%d",&a,&b);
            v[a].push_back(b);
        }
        for(int j=1;j<=3;j++)sort(v[j].begin(),v[j].end(),greater<ll>());
        for(int j=0;j<10;j++){
            dp[i][j]=max(dp[i][j],dp[i-1][j]);
            ll vesh=max(v[1][0],max(v[2][0],v[3][0]));
            if(j==9)vesh*=2;
            dp[i][(j+1)%10]=max(dp[i][(j+1)%10],dp[i-1][j]+vesh);
            if(j>=8){
                vesh=max(v[1][0]+v[2][0]+max(v[1][0],v[2][0]),
                        v[1][0]+v[1][1]+max(v[1][0],v[1][1]));
            }
            else vesh=max(v[1][0]+v[2][0],v[1][0]+v[1][1]);
            dp[i][(j+2)%10]=max(dp[i][(j+2)%10],dp[i-1][j]+vesh);
            vesh=v[1][0]+v[1][1]+v[1][2];
            if(j>=7){
                vesh+=max(v[1][0],max(v[1][1],v[1][2]));
            }
            dp[i][(j+3)%10]=max(dp[i][(j+3)%10],dp[i-1][j]+vesh);
        }
    }
    ll ans=0;
    for(int i=0;i<10;i++)ans=max(ans,dp[n][i]);
    printf("%lld",ans);
}