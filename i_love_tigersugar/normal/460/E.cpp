#include<algorithm>
#include<cstdio>
#include<vector>
#define FOR(i,a,b) for (int i=(a);i<=(b);i=i+1)
#define REP(i,n) for (int i=0;i<(n);i=i+1)
#define FORE(i,v) for (__typeof((v).begin()) i=(v).begin();i!=(v).end();i++)
#define SQR(x) ((x)*(x))
using namespace std;
inline int nextInt(void) {
    int x;
    scanf("%d",&x);
    return (x);
}
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
    int operator ^ (const Point &a) const {
        return (x*a.y-a.x*y);
    }
    bool operator < (const Point &a) const {
        return (y==a.y?x<a.x:y<a.y);
    }
};
inline int ccw(const Point &a,const Point &b,const Point &c) {
    int t=(b-a)^(c-a);
    return ((t>0)-(t<0));
}
Point root;
bool cmp(const Point &a,const Point &b) {
    int t=ccw(root,a,b);
    return (t!=0?t>0:a.y<b.y);
}
int n,r,best;
vector<Point> CH;
Point cur[10],res[10];
void init(void) {
    n=nextInt();
    r=nextInt();
    best=-1;
}
void getConvexHull(void) {
    vector<Point> v;
    FOR(x,-r,r) FOR(y,-r,r) if (SQR(x)+SQR(y)<=SQR(r)) v.push_back(Point(x,y));
    sort(v.begin(),v.end());
    root=v[0];
    sort(v.begin()+1,v.end(),cmp);
    FORE(it,v) {
        while (CH.size()>1 && ccw(CH[CH.size()-2],CH[CH.size()-1],*it)<=0) CH.pop_back();
        CH.push_back(*it);
    }
}
void backtrack(int id,int cnt,int sdis,int sqx,int sqy,int sx,int sy) {
    FOR(i,id,CH.size()-1) {
        cur[cnt]=CH[i];
        int ndis=sdis+sqx+sqy-2*CH[i].x*sx-2*CH[i].y*sy+(cnt-1)*(SQR(CH[i].x)+SQR(CH[i].y));
        if (cnt==n) {
            if (ndis>best) {
                best=ndis;
                FOR(i,1,n) res[i]=cur[i];
            }
        }
        else backtrack(i,cnt+1,ndis,sqx+SQR(CH[i].x),sqy+SQR(CH[i].y),sx+CH[i].x,sy+CH[i].y);
    }
}
void process(void) {
    backtrack(0,1,0,0,0,0,0);
    printf("%d\n",best);
    FOR(i,1,n) printf("%d %d\n",res[i].x,res[i].y);
}
int main(void) {
    init();
    getConvexHull();
    process();
    return 0;
}