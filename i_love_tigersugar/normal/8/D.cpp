#include<bits/stdc++.h>
#define REP(i,n) for (int i=0,_n=(n);i<_n;i=i+1)
#define SQR(x)(1.0*(x)*(x))
#define fi   first
#define se   second
using namespace std;
const double eps=1e-11;
struct Point {
    double x,y;
    Point() {
        x=y=0.0;
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
    Point operator * (double k) const {
        return (Point(x*k,y*k));
    }
    Point operator / (double k) const {
        return (Point(x/k,y/k));
    }
    double modul(void) const {
        return (sqrt(x*x+y*y));
    }
    Point unit(void) const {
        return (*this/modul());
    }
    Point perpen(void) const {
        return (Point(-y,x));
    }
};
struct Circle {
    Point center;
    double radius;
    Circle() {
        radius=0.0;
    }
    Circle(Point _center,double _radius) {
        center=_center;radius=_radius;
    }
    bool inside(const Point &p) const {
        return ((center-p).modul()<=radius);
    }
    bool inside(const Circle &c) const {
        return (c.radius+(center-c.center).modul()<=radius);
    }
    pair<Point,Point>* intersect(const Circle &c) const {
        Point O1=center;
        Point O2=c.center;
        double R1=radius;
        double R2=c.radius;
        double O1O2=(O2-O1).modul();
        if (O1O2>R1+R2+eps) return (NULL);
        if (R1>O1O2+R2+eps) return (NULL);
        if (R2>R1+O1O2+eps) return (NULL);
        double sum=(SQR(R1)-SQR(R2))/O1O2;
        double O1H=(sum+O1O2)/2;
        double O2H=(sum-O1O2)/2;
        //printf("R1 = %.13lf\n",R1);
        //printf("O1H = %.13lf\n",O1H);
        Point H=O1+(O2-O1).unit()*O1H;
        double HA=sqrt(SQR(R1)-SQR(O1H-eps));
        //printf("HA = %.3lf\n",HA);
        Point A=H+(O2-O1).unit().perpen()*HA;
        Point B=H-(O2-O1).unit().perpen()*HA;
        return (new pair<Point,Point>(A,B));
    }
    bool haveSamePoint(const Circle &c) const {
        if (inside(c)) return (true);
        if (c.inside(*this)) return (true);
        return (intersect(c)!=NULL);
    }
};
istream& operator >> (istream &is,Point &p) {
    return (is>>p.x>>p.y);
}
ostream& operator << (ostream &os,const Point &p) {
    return (os<<"("<<p.x<<","<<p.y<<")");
}
double allowAlen,allowBob;
Point c,s,h;
void init(void) {
    cin>>allowAlen>>allowBob>>c>>h>>s;
    allowAlen+=(c-s).modul()+(s-h).modul();
    allowBob+=(c-h).modul();
    cerr<<setprecision(3)<<allowAlen<<" "<<allowBob<<endl;
}
bool intersect(const Circle &c1,const Circle &c2,const Circle &c3) {
    //printf("Check %.3lf %.3lf %.3lf\n",c1.radius,c2.radius,c3.radius);
    if (c1.inside(c2) || c1.inside(c3)) return (c2.haveSamePoint(c3));
    if (c2.inside(c3) || c2.inside(c1)) return (c3.haveSamePoint(c1));
    if (c3.inside(c1) || c3.inside(c2)) return (c1.haveSamePoint(c2));
    //printf("XXX\n");
    pair<Point,Point> *inter;
    inter=c1.intersect(c2);
    if (inter==NULL) return (false);
    //cerr<<inter->fi<<endl<<inter->se<<endl;
    if (c3.inside(inter->fi) || c3.inside(inter->se)) return (true);
    inter=c2.intersect(c3);
    if (inter==NULL) return (false);
    if (c1.inside(inter->fi) || c1.inside(inter->se)) return (true);
    inter=c3.intersect(c1);
    if (inter==NULL) return (false);
    if (c2.inside(inter->fi) || c2.inside(inter->se)) return (true);
    return (false);
}
bool ok(double d) {
    if (d+(s-h).modul()<=allowAlen && d<=allowBob) {
        Circle C(c,d);
        Circle S(s,allowAlen-d-(s-h).modul());
        Circle H(h,allowBob-d);
        if (intersect(C,S,H)) return (true);
    }
    if ((c-s).modul()<=d && d<=allowBob && d<=allowAlen) {
        Circle C(c,d);
        Circle S(s,d-(c-s).modul());
        Circle H(h,min(allowBob-d,allowAlen-d));
        if (intersect(C,S,H)) return (true);
    }
    return (false);
}
void process(void) {
    double L=0;
    double R=100000;
    REP(love,722) {
        double M=(L+R)/2;
        if (ok(M)) L=M; else R=M;
    }
    printf("%.9lf\n",(L+R)/2);
}
int main(void) {
#ifdef SKY
    freopen("tmp.txt","r",stdin);
#endif // SKY
    init();
    process();
    //assert(ok(4.1));
    return 0;
}