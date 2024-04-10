#include <cstdio>
#include <algorithm>
using namespace std;
const int MAXN=200000;
int b[MAXN];
int main()
{
    int n;
    scanf("%d",&n);
    for (int i=0;i<n;i++) scanf("%d",&b[i]);
    sort(b,b+n);
    int x1=b[0],x2=b[n-1];
    if (x1!=x2)
    {
        long long cnt1=0,cnt2=0;
        for (int i=0;;i++) if (b[i]==x1) cnt1++;else break;
        for (int i=n-1;;i--) if (b[i]==x2) cnt2++;else break;
        printf("%d %lld",x2-x1,cnt1*cnt2);
    }
    else printf("0 %I64d",(long long)n*(n-1)/2);
    return 0;
}