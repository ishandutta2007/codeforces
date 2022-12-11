#include <cstdio>
#include <cmath>

const int MAXN=5005;

struct song
{
    double p;
    int t;
}a[MAXN];

double f[MAXN][MAXN],t[MAXN];

int main()
{
    int n,T;
    scanf("%d%d",&n,&T);
    for (int i=0;i<n;i++)
    {
        scanf("%lf%d",&a[i].p,&a[i].t);
        a[i].p/=100;
    }
    f[0][0]=1;
    for (int j=0;j<n;j++)
    {
        double pt=pow(1-a[j].p,a[j].t);
        for (int i=0;i<T;i++) t[i]=f[j][i];
        for (int i=0;i<T;i++)
        {
            f[j+1][i+1]+=a[j].p*f[j][i];
            f[j][i+1]+=(1-a[j].p)*f[j][i];
            if (i+a[j].t<=T)
            {
                f[j+1][i+a[j].t]+=pt*t[i];
                f[j][i+a[j].t]-=pt*t[i];
            }
        }
    }
    double ans=0;
    for (int i=1;i<T;i++) ans+=f[n][i]*n;
    for (int i=1;i<=n;i++) ans+=f[i][T]*i;
    printf("%.6f",ans);
    return 0;
}