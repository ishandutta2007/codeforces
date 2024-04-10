#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,k,m,dp[1100][110],pw[1100];
int solve(int now,int val){
    if (!val) return 1;
    if (now==-1) return 0;
    if (~dp[now][val]) return dp[now][val];
    int res=0;
    for (int i=(now==n-1);i<=9;i++)
        res=(res+solve(now-1,(val+1ll*(k-pw[now])*i)%k))%m;
    dp[now][val]=res; return res;
}
int main(){
    memset(dp,-1,sizeof(dp));
    scanf("%d%d%d",&n,&k,&m);
    if (m==1){ puts("0"); return 0;}
    int ans=9; pw[0]=1;
    for (int i=1;i<n;i++){
        pw[i]=10ll*pw[i-1]%k;
        ans=10ll*ans%m;
    }
    for (int i=1;i<k;i++) ans=(ans-solve(n-1,i)+m)%m;
    printf("%d\n",ans);
    return 0;
}