#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

struct point
{
    int x,y;
}p1,p2;

double isc(int a,int b,int c,point p)
{
    return (double)((long long)a*p.x+(long long)b*p.y+c);
}

int main()
{
    int n,ans=0;
    scanf("%d%d%d%d",&p1.x,&p1.y,&p2.x,&p2.y);
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        if(isc(a,b,c,p1)*isc(a,b,c,p2)<0) ans++;
    }
    printf("%d",ans);
    return 0;
}