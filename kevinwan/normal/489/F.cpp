#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mn=510;
ll dp[2][mn][mn];
ll mod;
string s[mn];
int main(){
    int n,m,i,j,k;
    scanf("%d%d%lld",&n,&m,&mod);
    for(i=0;i<m;i++){
        cin>>s[i];
        int tot=0;
        for(j=0;j<n;j++)tot+=s[i][j]-'0';
        if(tot>2){
            printf("0");
            return 0;
        }
    }
    int a=0,b=0;
    for(i=0;i<n;i++){
        int num=0;
        for(j=0;j<m;j++){
            num+=s[j][i]-'0';
        }
        if(num>3){
            printf("0");
            return 0;
        }
        if(num==0)a++;
        if(num==1)b++;
    }
    dp[m&1][a][b]=1;
    for(i=m+1;i<=n;i++){
        memset(dp[i&1],0,sizeof(dp[i&1]));
        for(j=0;j<=n;j++){
                k=2*(n-(i-1))-2*j;
                dp[i&1][j][k]+=dp[i&1^1][j][k];
                if(j)dp[i&1][j-1][k+1]+=dp[i&1^1][j][k]*j%mod;
                if(k)dp[i&1][j][k-1]+=dp[i&1^1][j][k]*k%mod;
                if(j>=2)dp[i&1][j-2][k+2]+=dp[i&1^1][j][k]*(j*(j-1)/2%mod)%mod;
                if(k>=2)dp[i&1][j][k-2]+=dp[i&1^1][j][k]*(k*(k-1)/2%mod)%mod;
                if(j&&k)dp[i&1][j-1][k]+=dp[i&1^1][j][k]*(j*k%mod)%mod;
        }
        for(j=0;j<=n;j++)for(k=0;j+k<=n;j++)dp[i&1][j][k]%=mod;
    }
    printf("%lld",dp[n&1][0][0]);
}