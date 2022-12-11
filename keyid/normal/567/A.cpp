#include <cstdio>
#include <climits>
#include <algorithm>
using namespace std;

const int MAXN=100005;

struct city
{
    int x,id;
}a[MAXN];

int ansmin[MAXN],ansmax[MAXN];

bool cmp(const city& a,const city& b)
{
    return a.x<b.x;
}

int main()
{
    int n;
    scanf("%d",&n);
    for (int i=0;i<n;i++)
    {
        scanf("%d",&a[i].x);
        a[i].id=i;
    }
    sort(a,a+n,cmp);
    for (int i=0;i<n;i++)
    {
        int _min=INT_MAX;
        if (i>0) _min=min(_min,a[i].x-a[i-1].x);
        if (i<n-1) _min=min(_min,a[i+1].x-a[i].x);
        ansmin[a[i].id]=_min;
        ansmax[a[i].id]=max(a[i].x-a[0].x,a[n-1].x-a[i].x);
    }
    for (int i=0;i<n;i++) printf("%d %d\n",ansmin[i],ansmax[i]);
    return 0;
}