//This solution is based on R_R_'s solution
#define NDEBUG
#include<bits/stdc++.h>
#define FOR(i,a,b) for (int i=(a);i<=(b);i=i+1)
#define REP(i,n) for (int i=0;i<(n);i=i+1)
#define DEB   (false)
typedef double ld;
const ld INF=1e9;
const ld eps=1e-5;
const ld PI=acos(-1.0);
inline ld Fabs(ld x) {
    return (x<0?-x:x);
}
inline void minimize(ld &x,const ld &y) {
    if (x>y) x=y;
}
struct point {
    ld x,y;
    point() {
        x=y=0.0;
    }
    point(ld _x,ld _y) {
        x=_x;y=_y;
    }
    void input(void) {
        scanf("%lf %lf",&x,&y);
    }
    point operator + (const point &a) const {
        return (point(x+a.x,y+a.y));
    }
    point operator - (const point &a) const {
        return (point(x-a.x,y-a.y));
    }
    point operator * (ld k) const {
        return (point(x*k,y*k));
    }
    point operator / (ld k) const {
        return (point(x/k,y/k));
    }
    point rotate(ld ang) const {
        return (point(x*cos(ang)-y*sin(ang),x*sin(ang)+y*cos(ang)));
    }
    ld abs(void) const {
        return (x*x+y*y);
    }
    bool operator == (const point &a) const {
        return (Fabs(x-a.x)<=eps && Fabs(y-a.y)<=eps);
    }
    bool operator != (const point &a) const {
        return (!(*this==a));
    }
    void debug(void) const {
        printf("%.11lf %.11lf\n",x,y);
    }
};
struct line {
    ld a,b,c;
    line() {
        a=b=c=0.0;
    }
    line(ld _a,ld _b,ld _c) {
        a=_a;b=_b;c=_c;
    }
    line(const point &m,const point &n) {
        a=n.y-m.y;
        b=m.x-n.x;
        c=-(a*m.x+b*m.y);
    }
};
point intersect(const line &d1,const line &d2) {
    ld a1=d1.a,b1=d1.b,c1=-d1.c;
    ld a2=d2.a,b2=d2.b,c2=-d2.c;
    ld d=a1*b2-a2*b1;
    ld dx=c1*b2-c2*b1;
    ld dy=a1*c2-a2*c1;
    return (point(dx/d,dy/d));
}
line perpen(const point &a,const point &b) {
    point m=(a+b)/2.0;
    line d=line(a,b);
    line p;
    p.a=-d.b;
    p.b=d.a;
    p.c=-p.a*m.x-p.b*m.y;
    return (p);
}
point center (const point &a,const point &b,const point &c) {
    line d1=perpen(a,b);
    line d2=perpen(b,c);
    return (intersect(d1,d2));
}
point a,b,c,o;
ld R;
bool ok(int x) {
    if (DEB) printf("xxx\n");
    bool okb=false;
    bool okc=false;
    point p=a;
    REP(zz,x) {
        if (DEB) p.debug();
        p=o+(p-o).rotate(2.0*PI/x);
        if (p==b) okb=true;
        if (p==c) okc=true;
    }
    if (DEB) printf("end\n");
    return (okb && okc);
}
void process(void) {
    a.input();b.input();c.input();
    assert(a!=b && b!=c);
    o=center(a,b,c);
    //o.debug();
    R=(o-a).abs();
    //printf("%.11lf\n",R);
    ld res=INF;
    FOR(i,3,111) if (ok(i)) minimize(res,R*sin(2.0*PI/i)*i/2.0);
    printf("%.11lf",res);
}
int main(void) {
#ifndef ONLINE_JUDGE
    freopen("tmp.txt","r",stdin);
#endif
    process();
    return 0;
}