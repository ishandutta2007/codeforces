#include<bits/stdc++.h>
#define fi   first
#define se   second
#define SQR(x) (1.0*(x)*(x))
using namespace std;
const double eps=1e-9;
double Abs(double x) {
    return (x<0?-x:x);
}
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
        return (sqrt(SQR(x)+SQR(y)+eps));
    }
    Point unit(void) const {
        return (*this/modul());
    }
    Point perpen(void) const {
        return (Point(-y,x));
    }
};
struct Line {
    double a,b,c;
    Line() {
        a=b=c=0;
    }
    Line(double _a,double _b,double _c) {
        a=_a;b=_b;c=_c;
    }
    Line(const Point &m,const Point &n) {
        a=m.y-n.y;
        b=n.x-m.x;
        c=-(a*m.x+b*m.y);
    }
    double distance(const Point &p) const {
        return (Abs(a*p.x+b*p.y+c)/sqrt(SQR(a)+SQR(b)+eps));
    }
    Point direct(void) const {
        return (Point(-b,a));
    }
    pair<Point,Point>* intersect(const Line &l) const {
        double a1=a,b1=b,c1=-c;
        double a2=l.a,b2=l.b,c2=-l.c;
        double d=a1*b2-a2*b1;
        double dx=c1*b2-c2*b1;
        double dy=a1*c2-a2*c1;
        if (Abs(d)<=eps) return (NULL);
        else return (new pair<Point,Point>(Point(dx/d,dy/d),Point(dx/d,dy/d)));
    }
};
struct Circle {
    Point center;
    double radius;
    Circle() {
        radius=0.0;
    }
    Circle(const Point &c,double r) {
        center=c;radius=r;
    }
    Line* sameDistance(const Circle &cir) const {
        double a=2*(cir.center.x-center.x);
        double b=2*(cir.center.y-center.y);
        double c=SQR(center.x)-SQR(cir.center.x)+SQR(center.y)-SQR(cir.center.y)-SQR(radius)+SQR(cir.radius);
        return (new Line(a,b,c));
    }
    Circle* sameAngle(const Circle &cir) const {
        double alpha=SQR(radius/cir.radius);
        Point newCenter((center.x-alpha*cir.center.x)/(1-alpha),(center.y-alpha*cir.center.y)/(1-alpha));
        double tmp=(SQR(center.x)-alpha*SQR(cir.center.x)+SQR(center.y)-alpha*SQR(cir.center.y))/(1-alpha);
        double newRadius=sqrt(SQR(newCenter.x)+SQR(newCenter.y)-tmp+eps);
        return (new Circle(newCenter,newRadius));
    }
    pair<Point,Point>* intersect(const Line &l) const {
        if (l.distance(center)>radius+eps) return (NULL);
        Point O=center;
        Point H=O+l.direct().perpen();
        H=l.intersect(Line(H,O))->fi;
        double AH=sqrt(SQR(radius)-SQR((H-O).modul())+eps);
        Point A=H+l.direct().unit()*AH;
        Point B=H-l.direct().unit()*AH;
        return (new pair<Point,Point>(A,B));
    }
    pair<Point,Point>* intersect(const Circle &cir) const {
        Point O1=center;
        Point O2=cir.center;
        double R1=radius;
        double R2=cir.radius;
        double O1O2=(O2-O1).modul();
        if (O1O2>R1+R2+eps) return (NULL);
        if (R1>O1O2+R2+eps) return (NULL);
        if (R2>R1+O1O2+eps) return (NULL);
        double O1H=(SQR(R1)-SQR(R2)+SQR(O1O2))/(2*O1O2);
        Point H=O1+(O2-O1).unit()*O1H;
        double AH=sqrt(SQR(R1)-SQR(O1H)+eps);
        Point A=H+(O2-O1).unit().perpen()*AH;
        Point B=H-(O2-O1).unit().perpen()*AH;
        return (new pair<Point,Point>(A,B));
    }
};
istream& operator >> (istream &is,Point &p) {
    return (is>>p.x>>p.y);
}
istream& operator >> (istream &is,Circle &c) {
    return (is>>c.center>>c.radius);
}
ostream& operator << (ostream &os,const Point &p) {
#ifdef SKY
    return (os<<setprecision(6)<<"("<<p.x<<" "<<p.y<<")");
#else
    return (os<<setprecision(12)<<p.x<<" "<<p.y);
#endif // SKY
}
ostream& operator << (ostream &os,const Line &l) {
    return (os<<setprecision(3)<<"("<<l.a<<" "<<l.b<<" "<<l.c<<")");
}
ostream& operator << (ostream &os,const Circle &c) {
    return (os<<setprecision(3)<<"["<<c.center<<" "<<c.radius<<"]");
}
Circle A,B,C;
void process(void) {
    cin>>A>>B>>C;
    Line *ab=NULL;
    Line *ac=NULL;
    Circle *AB=NULL;
    Circle *AC=NULL;
    if (Abs(A.radius-B.radius)<=eps) ab=A.sameDistance(B); else AB=A.sameAngle(B);
    if (Abs(A.radius-C.radius)<=eps) ac=A.sameDistance(C); else AC=A.sameAngle(C);
    if (ab!=NULL) cerr<<"Line ab: "<<*ab<<endl;
    if (ac!=NULL) cerr<<"Line ac: "<<*ac<<endl;
    if (AB!=NULL) cerr<<"Circle AB: "<<*AB<<endl;
    if (AC!=NULL) cerr<<"Circle AC: "<<*AC<<endl;
    pair<Point,Point> *inter=NULL;
    if (ab!=NULL && ac!=NULL) inter=ab->intersect(*ac);
    if (ab!=NULL && AC!=NULL) inter=AC->intersect(*ab);
    if (AB!=NULL && ac!=NULL) inter=AB->intersect(*ac);
    if (AB!=NULL && AC!=NULL) inter=AB->intersect(*AC);
    if (inter==NULL) return;
    if ((inter->fi-A.center).modul()<(inter->se-A.center).modul()) cout<<inter->fi<<endl; else cout<<inter->se<<endl;
}
int main(void) {
    process();
    return 0;
}