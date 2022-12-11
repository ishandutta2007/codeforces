#include <cstdio>
#include <algorithm>
using namespace std;

int main()
{
    int v1,v2,t,d,a[105],b[105];
    scanf("%d%d%d%d",&v1,&v2,&t,&d);
    a[1]=v1;
    b[t]=v2;
    for (int i=2;i<=t;i++) a[i]=a[i-1]+d;
    for (int i=t-1;i>=1;i--) b[i]=b[i+1]+d;
    int ans=0;
    for (int i=1;i<=t;i++) ans+=min(a[i],b[i]);
    printf("%d",ans);
    return 0;
}