#include <cstdio>

const int MAXN=500001;

long long sum[MAXN]={0};

int s[MAXN],a[MAXN];
int main()
{
    int n;
    scanf("%d",&n);
    for (int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        sum[i]=sum[i-1]+a[i];
    }
    if (sum[n]%3) printf("0");
    else 
    {
        long long t1=sum[n]/3*2,t2=sum[n]/3,ans=0;
        for (int i=n-1;i>=1;i--)
        {
            s[i]=sum[i]==t1?s[i+1]+1:s[i+1];
        }
        for (int i=1;i<n;i++) if (sum[i]==t2) ans+=s[i+1];
        printf("%I64d",ans);
    }
    \
    return 0;
}