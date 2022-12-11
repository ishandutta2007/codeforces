#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long LL;

const int MAXN=200005;

int a[MAXN],b[MAXN];
LL sum1[MAXN],sum2[MAXN];

int main()
{
    int n,k;
    scanf("%d%d",&n,&k);
    for (int i=0;i<n;i++) scanf("%d",&a[i]);
    for (int i=0;i<n;i++) b[i]=a[i];
    sort(b,b+n);
    int cnt=unique(b,b+n)-b;
    LL ans=0;
    for (int i=0;i<n;i++)
    {
        int t0=lower_bound(b,b+cnt,a[i])-b;
        if (a[i]%k==0)
        {
            int t=lower_bound(b,b+cnt,a[i]/k)-b;
            if (b[t]==a[i]/k)
            {
                ans+=sum2[t];
                sum2[t0]+=sum1[t];              
            }           
        }
        sum1[t0]++;
    }
    printf("%I64d",ans);
    return 0;
}