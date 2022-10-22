#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int>pii;
mt19937 rng(423978);
typedef long long ll;
typedef pair<ll,ll>pll;
const ll mod=1e9+7;
const int mn=1e5+10;
ll a[3][mn];
ll dp[2][8];
int b[8];
int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<3;i++)for(int j=1;j<=n;j++)scanf("%lld",&a[i][j]);
    memset(dp,0xc0,sizeof(dp));
    dp[0][1]=0;
    for(int i=1;i<=n;i++){
        for(int j=0;j<256;j++){
            for(int k=0;k<8;k++)b[k]=(j>>k)&1;
            int u0=b[0]+b[3]+b[6];
            int u1=b[1]+b[4]+b[6]+b[7];
            int u2=b[2]+b[5]+b[7];
            if(u0&1)continue;
            if(u1==4||(u1&1))continue;
            if(u2&1)continue;
            if(b[0]+b[1]+b[2]==0||b[3]+b[4]+b[5]==0)continue;
            ll v=0;
            if(u0)v+=a[0][i];
            if(u1)v+=a[1][i];
            if(u2)v+=a[2][i];
            int fr=b[0]|(b[1]<<1)|(b[2]<<2);
            int to=b[3]|(b[4]<<1)|(b[5]<<2);
            dp[1][to]=max(dp[1][to],dp[0][fr]+v);
        }
        memcpy(dp[0],dp[1],sizeof(dp[0]));
        memset(dp[1],0xc0,sizeof(dp[1]));
    }
    printf("%lld",dp[0][4]);
}