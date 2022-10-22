#include<bits/stdc++.h>
#define ll long long 
using namespace std;

const int Mod=998244353;
const int maxn=1010;
int a[maxn],dp[maxn],sum[maxn];
int c[maxn][maxn],ans;

int main()
{
    int N,i,j;
    scanf("%d",&N);
    for(i=0;i<=N;i++) c[i][0]=1,c[i][1]=i,c[i][i]=1;
    for(i=1;i<=N;i++) for(j=1;j<=N;j++) c[i][j]=(c[i-1][j]+c[i-1][j-1])%Mod;
    for(i=1;i<=N;i++) scanf("%d",&a[i]); 
    for(i=N;i>=1;i--)
	{
        if(a[i]>0&&i+a[i]<=N)
            for(j=i+a[i];j<=N;j++)
                (dp[i]+=(ll)c[j-i-1][a[i]-1]*(1+sum[j+1])%Mod)%=Mod;
        sum[i]=(sum[i+1]+dp[i])%Mod;
    }
    printf("%d\n",sum[1]);
    return 0;
}