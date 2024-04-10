#include <bits/stdc++.h>
#define PI 3.141592653589793238462
#define EPS 0.00000000015
using namespace std;

struct point{
long double x, y;
}a, p[100019];
long long n;
long double dmin=1e19;
long double dmax=0.;

long double dist(point a, point b)
{
    return sqrt((a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y));
}

long double distSeg(point a, point b, point c)
{
    point p;

    if(b.x==c.x)
    {
        p.x=b.x;
        p.y=a.y;
        if(p.y<=max(b.y, c.y)&&p.y>=min(c.y, b.y))
            return dist(p, a);
        else return min(dist(p, b), dist(p, c));
    }


    if(b.y==c.y)
    {
        p.y=b.y;
        p.x=a.x;
        if(p.x<=max(b.x, c.x)&&p.x>=min(c.x, b.x))
            return dist(p, a);
        else return min(dist(p, b), dist(p, c));
    }

    long double m = (c.y-b.y)/(c.x-b.x);
    long double n = b.y-(b.x*(c.y-b.y)/(c.x-b.x));

    long double m2 = -1./m;
    long double n2 = a.y-a.x*m2;

    long double y = (n*m2-n2*m)/(m2-m);
    long double x = (y-n2)/m2;

    p.x=x;
    p.y=y;

    if(x<=max(c.x, b.x) && x>=min(c.x, b.x) && y<=max(c.y, b.y) && y>=min(c.y, b.y))
        return dist(p, a);
        else
            return min(dist(a, c), dist(a, b));
}

double area(point a, point b, point c)
{
    return abs(a.x*b.y+b.x*c.y+c.x*a.y-c.x*b.y-b.x*a.y-a.x*c.y);
}



double Get_Min_Seg_Dist(point P,point A,point B) {
    double a=dist(P,A);
    double b=dist(P,B);
    double c=dist(A,B);

    if(a*a>=b*b+c*c || b*b>=a*a+c*c || abs(c)<EPS) return min(a,b); // teorema cos, 90..180 cos negativ..

    return area(P,A,B)/c;
}

int main()
{
cin>>n;
cin>>a.x>>a.y;

for(long long i=1;i<=n;i++)
{
    cin>>p[i].x>>p[i].y;
    long double d=dist(p[i], a);
    if(d>dmax)
        dmax=d;
}

p[n+1]=p[1];
p[n+2]=p[2];
p[n+3]=p[3];

for(long long i=1;i<=n;i++)
{
    //long double d=distSeg(a, p[i], p[i+1]);
    long double d=Get_Min_Seg_Dist(a, p[i], p[i+1]);
    if(d<dmin)
        dmin=d;
}



//printf("%.10lf\n", PI*(dmax*dmax-dmin*dmin));
cout<<setprecision(10)<<fixed<<PI*(dmax*dmax-dmin*dmin)<<'\n';
    return 0;
}