#include<bits/stdc++.h>
#define ll long long 
#define eb emplace_back
#define fi first
#define se second
#define pii pair<int,int>
using namespace std;
const int mod=998244353;
int kpow(int x,int y,int rex=1){
    for(;y;y>>=1,x=1ll*x*x%mod)if(y&1)rex=1ll*x*rex%mod;
    return rex;
}
int exgcd(int a,int b,int &x,int &y){
    int t=b?exgcd(b,a%b,y,x):a;
    if(!b)x=1,y=0;
    else y-=a/b*x;
    return t;
}
const int M=2e5+9;
int n;
char s[2][M];
int dp[M][2];
void work(){
    scanf("%d%s%s",&n,s[0]+1,s[1]+1);
    int l,r;
    for(int i=1;i<=n;++i)if(s[0][i]=='*'||s[1][i]=='*')r=i;
    for(int i=n;i>=1;--i)if(s[0][i]=='*'||s[1][i]=='*')l=i;
    dp[l][0]=dp[l][1]=0;
    if(s[0][l]==s[1][l])dp[l][0]=dp[l][1]=1;
    if(s[0][l]=='.')dp[l][0]=1;
    if(s[1][l]=='.')dp[l][1]=1;
    for(int i=l+1;i<=r;++i){
        if(s[1][i]=='.')dp[i][0]=min(dp[i-1][0]+1,dp[i-1][1]+2);
        else{
            dp[i][0]=min(dp[i-1][0]+2,dp[i-1][1]+2);
        }
        if(s[0][i]=='.')dp[i][1]=min(dp[i-1][1]+1,dp[i-1][0]+2);
        else{
            dp[i][1]=min(dp[i-1][1]+2,dp[i-1][0]+2);
        }
    }
    printf("%d\n",min(dp[r][0],dp[r][1]));
}
int main(){
    int T;
    scanf("%d",&T);
    while(T--)work();
    return 0;
}
/*
1
2
*.
..
*/