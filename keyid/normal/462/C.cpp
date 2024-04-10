#include <cstdio>
#include <algorithm>
using namespace std;

int main()
{
    const int MAXN=300000;
    int n,a[MAXN];
    long long ans=0;
    scanf("%d",&n);
    for (int i=0;i<n;i++) scanf("%d",&a[i]);
    sort(a,a+n);
    for (int i=0;i<n;i++) ans+=(long long)(i+2)*a[i];
    ans-=a[n-1];
    printf("%I64d",ans);
    return 0;
}