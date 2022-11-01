#include <bits\stdc++.h>

using namespace std;

    const int maxn=(1<<24)+100;
    int n,sx,sy;
    int full;
    const int inf=2e9;
    int dp[maxn],par[maxn];
    int itemsx[25],itemsy[25];
    int dist(int x1,int y1,int x2,int y2)
    {
        return (x1-x2)*(x1-x2)+(y1-y2)*(y1-y2);
    }
int main()
{
    scanf("%d %d",&sx,&sy);
    scanf("%d",&n);

    itemsx[n]=sx;
    itemsy[n]=sy;

     for (int i=0;i<n;i++)
    {
        scanf("%d %d",&itemsx[i],&itemsy[i]);
    }

    full=(1<<n)-1;
    dp[0]=0;
    for(int i=1;i<(1<<n);i++)
        dp[i]=inf;

    for(int i=0;i<(1<<n);i++)
    if (dp[i]!=inf){
        for (int j=0;j<n;j++)
            if (!(i>>j&1))
        {
            for (int k=j; k<n; k++)
                if (!(i>>k&1))
            {
                int got=1<<j|1<<k;
                int _nev=i|got;
                int len=dp[i]+dist(itemsx[n],itemsy[n],itemsx[j],itemsy[j])+dist(itemsx[k],itemsy[k],itemsx[j],itemsy[j])+dist(itemsx[k],itemsy[k],itemsx[n],itemsy[n]);
                if (dp[_nev]>len) {
                        dp[_nev]=len;
                        par[_nev]=i;
                }
            }
            break;
        }
    }

    printf("%d\n0",dp[full]);
    int i=full;
    while (i>0)
    {
        int j=i^par[i];
        while (j>0)
        {
            printf(" %d",int(log2(j&-j)+(1e-8+1)));
            j-=j&-j;
        }
        printf(" 0");
        i=par[i];
    }
    return 0;
}