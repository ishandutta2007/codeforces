#include <cstdio>
#include <climits>
#include <algorithm>
using namespace std;

const int MAXN=100005;

int a[MAXN],b[MAXN];

int main()
{
    int n;
    scanf("%d",&n);
    for (int i=0;i<n;i++) scanf("%d",&a[i]);
    for (int i=1;i<n;i++) scanf("%d",&b[i]);
    b[0]=INT_MAX;
    sort(a,a+n);sort(b,b+n);
    for (int i=0;i<n;i++) if (a[i]!=b[i]) { printf("%d\n",a[i]); break; }
    for (int i=2;i<n;i++) scanf("%d",&a[i]);
    a[0]=a[1]=INT_MAX;
    sort(a,a+n);
    for (int i=0;i<n;i++) if (b[i]!=a[i]) { printf("%d",b[i]); break; }
    return 0;
}