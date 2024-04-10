#include<iostream>
#include<cstdio>
using namespace std;
const int maxn=2e6+5,maxm=10,inf=1e9;
int dp[maxm][maxm][maxm];
char s[maxn];
void make(int x,int y,int dp[]){
    int i,j;
    for (i=1;i<maxm;i++) dp[i]=inf;
    dp[0]=0;
    for (i=0;i<maxm;i++) for (j=0;j<maxm;j++){
        dp[(j+x)%10]=min(dp[(j+x)%10],dp[j]+1);
        dp[(j+y)%10]=min(dp[(j+y)%10],dp[j]+1);
    }
    dp[0]=inf; if (x==0||y==0) dp[0]=1;
    for (i=1;i<maxm;i++){
        dp[(i+x)%10]=min(dp[(i+x)%10],dp[i]+1);
        dp[(i+y)%10]=min(dp[(i+y)%10],dp[i]+1);
    }
}
inline void add(int &x,int y){ x=min(inf,x+y); }
int main(){
    int i,j,k;
    int ans;
    scanf("%s",s);
    for (i=0;i<10;i++) for (j=0;j<10;j++) make(i,j,dp[i][j]);
    for (i=0;i<10;i++){
        for (j=0;j<10;j++){
            ans=0;
            for (k=1;s[k];k++) add(ans,dp[i][j][(s[k]+10-s[k-1])%10]-1);
            if (ans>=inf-100) printf("%d%c",-1,j<9?' ':'\n');
            else printf("%d%c",ans,j<9?' ':'\n');
        }
    }
    return 0;
}