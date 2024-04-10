/*
This code includes functions to
    Determine intersection points of two lines
    Determine intersection points of two segments
    Determine whether two simple polygons have a common point
Notes
    The constant maxC is the maximum value of points' coordinates, and should be changed
*/
#include<bits/stdc++.h>
#define MAX   100100
#define FOR(i,a,b) for (int i=(a),_b=(b);i<=_b;i=i+1)
#define FORD(i,b,a) for (int i=(b),_a=(a);i>=_a;i=i-1)
#define REP(i,n) for (int i=0,_n=(n);i<_n;i=i+1)
#define FORE(i,v) for (__typeof((v).begin()) i=(v).begin();i!=(v).end();i++)
#define ALL(v) (v).begin(),(v).end()
#define fi   first
#define se   second
#define MASK(i) (1LL<<(i))
#define BIT(x,i) (((x)>>(i))&1)
#define isNAN(x) (std::isnan(x))
#define isINF(x) (std::isinf(x))
#define next   ___next
#define prev   ___prev
#define left   ___left
#define right   ___right
using namespace std;
const double eps=1e-9;
const double PI=acos(-1.0);
const double maxC=10000;
template<class X,class Y>
    void minimize(X &x,const Y &y) {
        if (x>y) x=y;
    }
template<class X,class Y>
    void maximize(X &x,const Y &y) {
        if (x<y) x=y;
    }
double Abs(double x) {
    return (x<0?-x:x);
}
struct Point {
    double x,y;
    Point() {
        x=y=0;
    }
    Point(double _x,double _y) {
        x=_x;y=_y;
    }
    Point operator + (const Point &a) const {
        return (Point(x+a.x,y+a.y));
    }
    Point operator - (const Point &a) const {
        return (Point(x-a.x,y-a.y));
    }
    void input(void) {
        scanf("%lf%lf",&x,&y);
    }
    double modul(void) const {
        return (sqrt(x*x+y*y));
    }
};
//Special points
const Point pNAN=Point(NAN,NAN);
const Point pINF=Point(INFINITY,INFINITY);
struct Line {
    double a,b,c; //Line equation: a*x+b*y+c=0
    Line() {
        a=b=c=0;
    }
    Line(const Point &m,const Point &n) { //Line through two points m and n
        a=m.y-n.y;
        b=n.x-m.x;
        c=-(a*m.x+b*m.y);
    }
//Determines intersection point of this line and line e, returns pNAN in case of no points, and pINF in case of infinite points
    Point intersect(const Line &e) const {
        double a1=a;
        double b1=b;
        double c1=-c;
        double a2=e.a;
        double b2=e.b;
        double c2=-e.c;
        double d=a1*b2-a2*b1;
        double dx=c1*b2-c2*b1;
        double dy=a1*c2-a2*c1;
        if (Abs(d)<=eps) {
            if (Abs(dx)>eps || Abs(dy)>eps) return (pNAN);
            return (pINF);
        } else return (Point(dx/d,dy/d));
    }
};
Line perpen(const Point &O,const Line &d) {
    Line e;
    e.a=d.b;
    e.b=-d.a;
    e.c=-(e.a*O.x+e.b*O.y);
    return (e);
}
bool between(const Point &A,const Point &B,const Point &C) { //Determines if C is between A and B. A,B,C are guaranteed to be collinear
    double minAB=min(A.x,B.x);
    double maxAB=max(A.x,B.x);
    if (minAB>C.x+eps || maxAB+eps<C.x) return (false);
    minAB=min(A.y,B.y);
    maxAB=max(A.y,B.y);
    if (minAB>C.y+eps || maxAB+eps<C.y) return (false);
    return (true);
}
bool intersectSegment(const Point &A,const Point &B,const Point &C,const Point &D) { //Determines if two segment AB and CD have a common point
    Line AB(A,B);
    Line CD(C,D);
    Point P=AB.intersect(CD);
    if (isNAN(P.x)) return (false);
    if (isINF(P.x)) {
        if (between(A,B,C)) return (true);
        if (between(A,B,D)) return (true);
        if (between(C,D,A)) return (true);
        if (between(C,D,B)) return (true);
        return (false);
    }
    return (between(A,B,P) && between(C,D,P));
}
bool insidePolygon(const vector<Point> &v,const Point &p) { //Determines if a point is inside a simple polygon
    int cnt=0;
    Point q(maxC,p.y+1);
    REP(i,v.size()) if (intersectSegment(v[i],v[(i+1)%v.size()],p,q)) cnt++;
    return (cnt%2==1);
}
bool intersectPolygon(const vector<Point> &a,const vector<Point> &b) { //Determines if polygon a and b have a common point
    FORE(it,b) if (insidePolygon(a,*it)) return (true);
    FORE(it,a) if (insidePolygon(b,*it)) return (true);
    REP(i,a.size()) REP(j,b.size())
        if (intersectSegment(a[i],a[(i+1)%a.size()],b[j],b[(j+1)%b.size()])) return (true);
    return (false);
}
Point a[MAX],p;
int n;
double getMinDis(const Point &a,const Point &b,const Point &c) {
    double res=min((a-b).modul(),(a-c).modul());
    Line d(b,c);
    Line e=perpen(a,d);
    Point P=d.intersect(e);
    if (between(b,c,P)) return ((a-P).modul()); else return (res);
}
void init(void) {
    scanf("%d",&n);
    p.input();
    REP(i,n) a[i].input();
    REP(i,n) a[i]=a[i]-p;
    double maxDis=0.0;
    double minDis=getMinDis(Point(0,0),a[0],a[1]);
    REP(i,n) minimize(minDis,getMinDis(Point(0,0),a[i],a[(i+1)%n]));
    REP(i,n) maximize(maxDis,a[i].modul());
    printf("%.9lf\n",PI*maxDis*maxDis-PI*minDis*minDis);
}
int main(void) {
    init();
    return 0;
}