#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN=5001;

long long dp[MAXN][MAXN];

int main()
{
    int n,m,k,a[MAXN];
    long long sum[MAXN];
    memset(sum,0,sizeof(sum));
    scanf("%d%d%d",&n,&m,&k);
    for (int i=1;i<=n;i++) scanf("%d",&a[i]);
    for (int i=1;i<=m;i++) sum[1]+=a[i];
    for (int i=2;i<=n-m+1;i++) sum[i]=sum[i-1]-a[i-1]+a[i+m-1];
    for (int i=m;i<=n;i++)
    {
        int st=min(k,i/m);
        for (int j=st;j>0;j--) dp[i][j]=max(dp[i-1][j],dp[i-m][j-1]+sum[i-m+1]);
    }
    printf("%I64d",dp[n][k]);
    return 0;
}