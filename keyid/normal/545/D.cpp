#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXN=100005;

int a[MAXN];

int main()
{
    int n;
    scanf("%d",&n);
    for (int i=0;i<n;i++) scanf("%d",&a[i]);
    sort(a,a+n);
    int cnt=0,time=0;
    for (int i=0;i<n;i++)
        if (time<=a[i])
        {
            time+=a[i];
            cnt++;
        }
    printf("%d",cnt);
    return 0;
}