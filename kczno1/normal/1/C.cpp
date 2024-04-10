//by kcz 1552920354@qq.com
#include<bits/stdc++.h>
using namespace std;

template <typename T> void chmin(T&x,const T &y)
{
    if(x>y)x=y;
}
template <typename T> void chmax(T &x,const T &y)
{
    if(x<y)x=y;
}
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned short us;
typedef unsigned int ui;
#define rep(i,l,r) for(int i=l;i<=r;++i)
#define per(i,r,l) for(int i=r;i>=l;--i)
const double pi=acos(-1),eps=1e-2;
double sqr(const double &x)
{
    return x*x;
}
struct point
{
    double x,y;
};
point operator -(const point &p1,const point &p2)
{
    return (point){p1.x-p2.x,p1.y-p2.y};
}
double dis(const point &p1,const point &p2)
{
    return sqr(p1.x-p2.x)+sqr(p1.y-p2.y);
}
double disO(const point &p)
{
    return sqr(p.x)+sqr(p.y);
}
void read(point &p)
{
    scanf("%lf%lf",&p.x,&p.y);
}
point O;double r2,r;
double getj(const point &p)
{
    return (p.y>=0)?acos(p.x/r):2*pi-acos(p.x/r);
}
double gcd(double x,double y)
{
    while(y>eps)swap(x=fmod(x,y),y);
    return x;
}

int main()
{
//	freopen("1.in","r",stdin);//freopen("1.out","w",stdout);
    point p1,p2,p3;
    read(p1);read(p2);read(p3);
#define get(a,b,c,p1,p2) double a=-2*(p1.x-p2.x),b=-2*(p1.y-p2.y),c=disO(p1)-disO(p2);
    get(a1,b1,c1,p1,p2)
    get(a2,b2,c2,p2,p3)
#undef get
#define get(y,a1,b1,a2,b2) y=-(c1*a2-c2*a1)/(b1*a2-b2*a1);
    get(O.y,a1,b1,a2,b2)
    get(O.x,b1,a1,b2,a2)
#undef get
    r2=dis(O,p1);
    r=sqrt(r2);
    double j1=getj(p1-O),
    j2=getj(p2-O),
    j3=getj(p3-O);
    double d1=abs(j1-j2),d2=abs(j2-j3);
    double j=gcd(gcd(d1,d2),2*pi);
    printf("%f\n",pi*r2*sin(j)/j);
}