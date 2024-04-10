#include<bits/stdc++.h>
#define MAX   5050
#define FOR(i,a,b) for (int i=(a),_b=(b);i<=_b;i=i+1)
#define FORD(i,b,a) for (int i=(b),_a=(a);i>=_a;i=i-1)
#define REP(i,n) for (int i=0,_n=(n);i<_n;i=i+1)
#define FORE(i,v) for (__typeof((v).begin()) i=(v).begin();i!=(v).end();i++)
#define ALL(v) (v).begin(),(v).end()
#define fi   first
#define se   second
#define MASK(i) (1LL<<(i))
#define BIT(x,i) (((x)>>(i))&1)
#define div   ___div
#define next   ___next
#define prev   ___prev
#define left   ___left
#define right   ___right
#define __builtin_popcount __builtin_popcountll
using namespace std;
template<class X,class Y>
    void minimize(X &x,const Y &y) {
        if (x>y) x=y;
    }
template<class X,class Y>
    void maximize(X &x,const Y &y) {
        if (x<y) x=y;
    }
template<class T>
    T Abs(const T &x) {
        return (x<0?-x:x);
    }
const int INF=(int)1e9+7;
int ceil(int b,int a) {
    while (a==0) cout<<"FUCK"<<endl;
    if (a<0) return (ceil(-b,-a));
    if (b>=0) return (b/a+(b%a!=0));
    if (b%a==0) return (b/a);
    return (-((-b)/a));
}
class ConvexHull {
    private:
    struct Segment {
        int x,a,b;
        Segment() {
            x=a=b=0;
        }
        Segment(int _x,int _a,int _b) {
            x=_x;a=_a;b=_b;
        }
        long long y(void) const {
            return (1LL*a*x+b);
        }
    };
    int findSegment(int p,int q) const {
        if (q<0) return (findSegment(-p,-q));
        int L=0;
        int R=segments.size()-1;
        while (true) {
            if (L==R) return (R);
            if (R-L==1) return (1LL*segments[R].x*q<=p?R:L);
            int M=(L+R)>>1;
            if (1LL*segments[M].x*q<=p) L=M; else R=M-1;
        }
    }
    vector<Segment> segments;
    public:
    void addLine(int a,int b) {
        while (!segments.empty() && segments.back().y()<=1LL*a*segments.back().x+b)
            segments.pop_back();
        if (segments.empty()) {
            segments.push_back(Segment(-INF,a,b));
            return;
        }
        long long x=ceil(b-segments.back().b,segments.back().a-a);
        if (x>INF) return;
        segments.push_back(Segment(x,a,b));
    }
    long long query(int p,int q) const {
        int id=findSegment(p,q);
        int a=segments[id].a;
        int b=segments[id].b;
        return (1LL*a*p+1LL*b*q);
    }
};
struct Point {
    int x,y;
    Point() {
        x=y=0;
    }
    Point(int _x,int _y) {
        x=_x;y=_y;
    }
    Point operator + (const Point &a) const {
        return (Point(x+a.x,y+a.y));
    }
    Point operator - (const Point &a) const {
        return (Point(x-a.x,y-a.y));
    }
    bool operator < (const Point &a) const {
        return (x==a.x?y<a.y:x<a.x);
    }
};
ConvexHull minCV,maxCV;
Point points[MAX];
int n,minX,minY,maxX,maxY;
void init(void) {
    long long s; cin>>n>>s;
    FOR(i,1,n) cin>>points[i].x>>points[i].y;
    sort(points+1,points+n+1);
    FOR(i,1,n) maxCV.addLine(points[i].x,points[i].y);
    FORD(i,n,1) minCV.addLine(-points[i].x,-points[i].y);
    minX=maxX=points[1].x;
    minY=maxY=points[1].y;
    FOR(i,1,n) {
        minimize(minX,points[i].x);
        minimize(minY,points[i].y);
        maximize(maxX,points[i].x);
        maximize(maxY,points[i].y);
    }
}
long long findBest(int p,int q) {
    if (p==0 && q==0) return (0);
    if (p==0) return (q>0?1LL*maxY*q:1LL*minY*q);
    if (q==0) return (p>0?1LL*maxX*p:1LL*minX*p);
    if (q>0) return (maxCV.query(p,q));
    return (-minCV.query(p,q));
}
long long maxArea(const Point &a,const Point &b) {
    long long AB=1LL*(a.x-b.x)*(a.y+b.y)+1LL*b.x*b.y-1LL*a.x*a.y;
    int p=a.y-b.y;
    int q=b.x-a.x;
    return (AB+findBest(p,q));
}
long long getArea(const Point &a,const Point &b,const Point &c) {
    long long AB=1LL*(a.x-b.x)*(a.y+b.y);
    long long BC=1LL*(b.x-c.x)*(b.y+c.y);
    long long CA=1LL*(c.x-a.x)*(c.y+a.y);
    long long s=AB+BC+CA;
    return (Abs(s));
}
void process(void) {
    int bestI=-1;
    int bestJ=-1;
    long long bestArea=-1;
    FOR(i,1,n) FOR(j,1,n) {
        long long tmp=maxArea(points[i],points[j]);
        if (bestArea<tmp) {
            bestArea=tmp;
            bestI=i;
            bestJ=j;
        }
    }
    int bestK=-1;
    FOR(k,1,n) if (getArea(points[bestI],points[bestJ],points[k])==bestArea) bestK=k;
    Point A=points[bestJ]+points[bestK]-points[bestI];
    Point B=points[bestK]+points[bestI]-points[bestJ];
    Point C=points[bestI]+points[bestJ]-points[bestK];
    cout<<A.x<<" "<<A.y<<endl;
    cout<<B.x<<" "<<B.y<<endl;
    cout<<C.x<<" "<<C.y<<endl;
}
int main(void) {
    init();
    process();
    return 0;
}