#include <cstdio>
#include <cmath>
#include <cfloat>
#include <algorithm>
using namespace std;

typedef long long LL;

const int MAXN=100005;
const double EPS=1e-9;

struct Point
{
    int x,y;

    Point operator - (const Point &b)
    {
        return (Point){x-b.x,y-b.y};
    }
}a[MAXN];

inline LL sqr(int a,int b)
{
    return (LL)a*a+(LL)b*b;
}

inline double dis(const Point &p)
{
    return sqrt(sqr(p.x,p.y));
}

inline double dot(const Point &a,const Point &b)
{
    return (double)a.x*b.x+(double)a.y*b.y;
}

inline double cross(const Point &a,const Point &b)
{
    return (double)a.x*b.y-(double)a.y*b.x;
}

inline int dcmp(const double &x)
{
    if (fabs(x)<EPS) return 0;
    return x<0?-1:1;
}

int main()
{
    int n;
    Point p;
    scanf("%d%d%d",&n,&p.x,&p.y);
    double rmax=0,rmin=DBL_MAX;
    for (int x,y,i=0;i<n;i++)
    {
        scanf("%d%d",&a[i].x,&a[i].y);
        double l=dis(p-a[i]);
        rmax=max(rmax,l);
        rmin=min(rmin,l);
    }
    a[n]=a[0];
    for (int i=1;i<=n;i++)
        if (dcmp(dot(a[i]-a[i-1],p-a[i-1]))>=0&&dcmp(dot(a[i-1]-a[i],p-a[i]))>=0)
            rmin=min(rmin,fabs(cross(p-a[i-1],p-a[i]))/dis(a[i]-a[i-1]));
    printf("%.9f",(rmax*rmax-rmin*rmin)*M_PI);
    return 0;
}