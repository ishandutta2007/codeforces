#include <cstdio>

const int MAXN=2005;

double a[MAXN];

int main()
{
    int n,t;
    double p;
    scanf("%d%lf%d",&n,&p,&t);
    for (int i=1;i<=n;i++) a[i]=1;
    for (int i=1;i<=t;i++)
        for (int j=n;j>=1;j--)
            a[j]=a[j-1]+(a[j]-a[j-1])*(1-p);
    double ans=n;
    for (int i=1;i<=n;i++) ans-=a[i];
    printf("%.8f",ans);
    return 0;
}