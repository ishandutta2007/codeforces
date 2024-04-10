#include<bits/stdc++.h>
#define MAX   200200
#define FOR(i,a,b) for (int i=(a),_b=(b);i<=_b;i=i+1)
#define FORD(i,b,a) for (int i=(b),_a=(a);i>=_a;i=i-1)
#define REP(i,n) for (int i=0,_n=(n);i<_n;i=i+1)
#define FORE(i,v) for (__typeof((v).begin()) i=(v).begin();i!=(v).end();i++)
#define ALL(v) (v).begin(),(v).end()
#define fi   first
#define se   second
#define MASK(i) (1LL<<(i))
#define BIT(x,i) (((x)>>(i))&1)
#define left    ___left
#define right    ___right
using namespace std;
const double eps=1e-9;
const double INF=1e6+7;
template<class X,class Y>
    void minimize(X &x,const Y &y) {
        if (x>y) x=y;
    }
template<class X,class Y>
    void maximize(X &x,const Y &y) {
        if (x<y) x=y;
    }
bool Abs(double x) {
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
    double modul(void) const {
        return (1.0*x*x+1.0*y*y);
    }
    double operator % (const Point &a) const {
        return (1.0*x*a.y-1.0*a.x*y);
    }
    bool operator == (const Point &a) const {
        return (Abs(x-a.x)<=eps && Abs(y-a.y)<=eps);
    }
};
bool CompY(const Point &a,const Point &b) {
    return (Abs(a.y-b.y)<=eps?a.x+eps<b.x:a.y+eps<b.y);
}
bool CompX(const Point &a,const Point &b) {
    return (Abs(a.x-b.x)<=eps?a.y+eps<b.y:a.x+eps<b.x);
}
bool CompCCW(const Point &a,const Point &b) {
    double t=a%b;
    return (Abs(t)<=eps?a.modul()+eps<b.modul():t>eps);
}
vector<Point> convexHull(vector<Point> v) {
    sort(ALL(v),CompY);
    v.resize(unique(ALL(v))-v.begin());
    int centerID=0;
    REP(i,v.size()) if (CompY(v[i],v[centerID])) centerID=i;
    Point center=v[centerID];
    FORE(it,v) *it=*it-center;
    swap(v[0],v[centerID]);
    sort(v.begin()+1,v.end(),CompCCW);
    vector<Point> CH;
    FORE(it,v) {
        while (CH.size()>1 && (*it-CH[CH.size()-2])%(CH[CH.size()-1]-CH[CH.size()-2])>=-eps) CH.pop_back();
        CH.push_back(*it);
    }
    FORE(it,CH) *it=*it+center;
    return (CH);
}
pair<int,int> a[MAX];
int n,reqX,reqY,maxX,maxY;
void init(void) {
    scanf("%d%d%d",&n,&reqX,&reqY);
    maxX=maxY=1;
    FOR(i,1,n) {
        int x,y;
        scanf("%d%d",&x,&y);
        a[i]=make_pair(x,y);
        if (a[i].fi>a[maxX].fi) maxX=i;
        if (a[i].se>a[maxY].se) maxY=i;
    }
}
bool ok(double t) {
    vector<Point> v;
    FOR(i,1,n) if (a[i].fi*t>=reqX-eps && a[i].se*t>=reqY-eps) return (true);
    FOR(i,1,n) v.push_back(Point(a[i].fi*t,a[i].se*t));
    v.push_back(Point(0,0));
    v.push_back(Point(0,a[maxY].se*t));
    v.push_back(Point(a[maxX].fi*t,0));
    v.push_back(Point(reqX,reqY));
    vector<Point> u=convexHull(v);
    FORE(it,u) if (Abs(it->x-reqX)<=eps && Abs(it->y-reqY)<=eps) return (false);
    return (true);
}
void process(void) {
    double L=0;
    double R=INF;
    REP(love,50) {
        double M=(L+R)/2;
        if (ok(M)) R=M; else L=M;
    }
    printf("%.9lf\n",(L+R)/2);
}
int main(void) {
    init();
    process();
    //assert(!ok(0.6));
    return 0;
}