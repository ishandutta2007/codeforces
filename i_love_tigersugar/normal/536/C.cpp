#include<bits/stdc++.h>
#define MAX   200200
#define FOR(i,a,b) for (int i=(a),_b=(b);i<=_b;i=i+1)
#define REP(i,n) for (int i=0,_n=(n);i<_n;i=i+1)
#define FORE(i,v) for (__typeof((v).begin()) i=(v).begin();i!=(v).end();i++)
#define ALL(v) (v).begin(),(v).end()
using namespace std;
struct Point {
    int x,y;
    Point() {
        x=y=0;
    }
    void input(void) {
        scanf("%d%d",&x,&y);
    }
    bool operator < (const Point &a) const {
        return (y==a.y?x>a.x:y>a.y);
    }
    bool operator == (const Point &a) const {
        return (x==a.x && y==a.y);
    }
};
Point a[MAX],O;
int n;
void init(void) {
    scanf("%d",&n);
    FOR(i,1,n) a[i].input();
}
bool CompX(const Point &a,const Point &b) {
    return (a.x==b.x?a.y>b.y:a.x>b.x);
}
bool CompY(const Point &a,const Point &b) {
    return (a.y==b.y?a.x>b.x:a.y>b.y);
}
int CCW(const Point &O,const Point &a,const Point &b) {
    long long A=1LL*(O.x-a.x)*(O.y-b.y)*a.y*b.x;
    long long B=1LL*(O.y-a.y)*(O.x-b.x)*a.x*b.y;
    return ((A>B)-(A<B));
}
bool CompCCW(const Point &a,const Point &b) {
    int t=CCW(O,a,b);
    if (t!=0) return (t>0);
    return (a.y>b.y);
}
vector<Point> convexHull(vector<Point> point) {
    sort(ALL(point));
    point.resize(unique(ALL(point))-point.begin());
    int idMin=0;
    REP(i,point.size()) if (point[i]<point[idMin]) idMin=i;
    swap(point[0],point[idMin]);
    O=point[0];
    sort(point.begin()+1,point.end(),CompCCW);
    vector<Point> CH;
    FORE(it,point) {
        while (CH.size()>1 && CCW(CH[CH.size()-2],*it,CH[CH.size()-1])>0) CH.pop_back();
        CH.push_back(*it);
    }
    int idLeft=0;
    int idDown=0;
    REP(i,CH.size()) if (CompX(CH[i],CH[idLeft])) idLeft=i;
    REP(i,CH.size()) if (CompY(CH[i],CH[idDown])) idDown=i;
    bool allInLine=true;
    FORE(it,CH) if (CCW(CH[idLeft],*it,CH[idDown])!=0) allInLine=false;
    if (allInLine && CH[idLeft].y<CH[idDown].y && CH[idLeft].x>CH[idDown].x) return (CH);
    int i=idLeft;
    vector<Point> res;
    while (true) {
        res.push_back(CH[i]);
        if (i==idDown) return (res);
        i=(i+1)%CH.size();
    }
}
void process(void) {
    vector<Point> res=convexHull(vector<Point>(a+1,a+n+1));
    sort(ALL(res));
    FOR(i,1,n) if (binary_search(ALL(res),a[i])) printf("%d ",i); printf("\n");
}
int main(void) {
#ifdef SKY
    freopen("tmp.txt","r",stdin);
#endif // SKY
    init();
    process();
    return 0;
}