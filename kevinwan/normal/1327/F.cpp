#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int>pii;
typedef long long ll;
const ll mod=998244353;
const int mn=5e5+10;
int one[30][mn];
int rm[30][mn];
ll dp[mn];
int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    int n,k,m;
    cin>>n>>k>>m;
    memset(rm,-1,sizeof(rm));
    for(int i=0;i<m;i++){
        int l,r,a;
        cin>>l>>r>>a;
        for(int j=0;j<k;j++){
            if((a>>j)&1){
                one[j][l]++,one[j][r+1]--;
            }
            else rm[j][r]=max(rm[j][r],l-1);
        }
    }
    for(int i=0;i<k;i++)for(int j=1;j<=n;j++)one[i][j]+=one[i][j-1];
    for(int j=0;j<k;j++)for(int i=1;i<=n;i++)rm[j][i]=max(rm[j][i],rm[j][i-1]);
    dp[0]=1;
    ll ans=1;
    for(int i=0;i<k;i++){
        for(int j=1;j<=n;j++){
            dp[j]=dp[j-1];
            if(one[i][j])continue;
            dp[j]+=dp[j-1]-((rm[i][j-1]<0)?0:dp[rm[i][j-1]]);
            dp[j]%=mod;
        }
        ans*=dp[n]-((rm[i][n]<0)?0:dp[rm[i][n]]);
        ans%=mod;
    }
    if(ans<0)ans+=mod;
    printf("%lld",ans);
}