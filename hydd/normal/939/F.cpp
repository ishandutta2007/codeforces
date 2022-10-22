#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int n,k,dp[110][110000];
int head,tail,que[110000];
struct node{
    int l,r;
    bool operator<(const node &x) const{ return r<x.r;}
} a[110];
int main(){
    scanf("%d%d",&n,&k);
    for (int i=1;i<=k;i++) scanf("%d%d",&a[i].l,&a[i].r);
    sort(a+1,a+k+1);
    memset(dp,0x3f,sizeof(dp));
    dp[0][0]=0;
    for (int i=1;i<=k;i++){
        int l=a[i].l,r=a[i].r;
        head=1; tail=0; 
        for (int j=0;j<=r;j++) dp[i][j]=dp[i-1][j];
        for (int j=0;j<=r;j++){
            while (head<=tail&&dp[i-1][que[tail]]>=dp[i-1][j]) tail--;
            que[++tail]=j;
            while (head<=tail&&que[head]<j-(r-l)) head++;
            dp[i][j]=min(dp[i][j],dp[i-1][que[head]]+2);
        }
        head=1; tail=0;
        for (int j=r;j>=0;j--){
            while (head<=tail&&dp[i-1][que[tail]]>=dp[i-1][r-j]) tail--;
            que[++tail]=r-j;
            while (head<=tail&&que[head]<l-j) head++;
            dp[i][j]=min(dp[i][j],dp[i-1][que[head]]+1);
        }
    }
    if (dp[k][n]<=10000) printf("Full\n%d\n",dp[k][n]);
    else puts("Hungry");
    return 0;
}