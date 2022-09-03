#include<cstdio>
#include<algorithm>

int d[5002][5002];

int main()
{
    int mod=1e9+7;
    int i,j,n,m,a,b;
    scanf("%d%d%d%d",&n,&a,&b,&m);
    d[0][a]=1;
    d[0][a+1]=-1;
    for(i=0;i<m;i++)
    {
        for(j=1;j<=n;j++)
        {
            (d[i][j]+=d[i][j-1])%=mod;
            if(j!=b)
            {
                (d[i+1][std::max(1,j-std::abs(j-b)+1)]+=d[i][j])%=mod;
                (d[i+1][j]+=mod-d[i][j])%=mod;
                (d[i+1][j+1]+=d[i][j])%=mod;
                (d[i+1][std::min(n,j+std::abs(j-b)-1)+1]+=mod-d[i][j])%=mod;
            }
        }
    }
    i=0;
    for(j=1;j<=n;j++)(i+=(d[m][j]+=d[m][j-1])%=mod)%=mod;
    printf("%d",i);
}