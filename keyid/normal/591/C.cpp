#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXN=500005,INF=0x3f3f3f3f;

int a[MAXN];
bool ini[MAXN];

int main()
{
    int n;
    scanf("%d",&n);
    for (int i=1;i<=n;i++) scanf("%d",&a[i]);
    ini[1]=ini[n]=true;
    for (int i=2;i<n;i++)
        if (a[i]==a[i-1]||a[i]==a[i+1])
            ini[i]=true;
    int ans=0;
    for (int l=1,r;l<=n;l=r)
    {
        while (l<=n&&ini[l]) l++;
        if (l>n) break;
        r=l;
        while (r<=n&&!ini[r]) r++;
        if (a[l-1]==a[r])
            for (int i=l;i<r;i++)
                a[i]=a[r];
        else
        {
            int head=l,tail=r-1;
            while (head<=tail)
            {
                a[head++]=a[l-1];
                a[tail--]=a[r];
            }
        }
        ans=max(ans,r-l+1);
    }
    printf("%d\n",ans/2);
    for (int i=1;i<=n;i++) printf("%d ",a[i]);
    return 0;
}