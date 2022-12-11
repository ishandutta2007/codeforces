#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXN=100005;

int a[MAXN],c[MAXN];

int main()
{
    int n,m,k;
    scanf("%d%d%d",&n,&m,&k);
    for (int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        c[a[i]]=i;
    }
    long long cnt=0;
    while (m--)
    {
        int b;
        scanf("%d",&b);
        int x=c[b];
        cnt+=(x-1)/k+1;
        if (x>1)
        {
            int t=a[x-1];
            swap(a[x],a[x-1]);
            swap(c[t],c[b]);
        }
    }
    printf("%I64d",cnt);
    return 0;
}