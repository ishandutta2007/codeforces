#include<bits/stdc++.h>
#define MAX   1010
#define FOR(i,a,b) for (int i=(a),_b=(b);i<=_b;i=i+1)
#define REP(i,n) for (int i=0,_n=(n);i<_n;i=i+1)
#define fi   first
#define se   second
using namespace std;
struct Point {
    int x,y;
    Point() {
        x=y=0;
    }
    Point(int _x,int _y) {
        x=_x;y=_y;
    }
    Point operator - (const Point &a) const {
        return (Point(x-a.x,y-a.y));
    }
    long long operator % (const Point &a) const {
        return (1LL*x*a.y-1LL*a.x*y);
    }
    int area(void) const {
        if (x>0 && y==0) return (0);
        if (x>0 && y>0) return (1);
        if (x==0 && y>0) return (2);
        if (x<0 && y>0) return (3);
        if (x<0 && y==0) return (4);
        if (x<0 && y<0) return (5);
        if (x==0 && y<0) return (6);
        if (x>0 && y<0) return (7);
    }
    bool operator < (const Point &p) const {
        int a=area();
        int pa=p.area();
        if (a!=pa) return (a<pa);
        long long tmp=*this%p;
        if (tmp!=0) return (tmp>0);
        return (y<p.y);
    }
};
istream& operator >> (istream &is,Point &p) {
    return (is>>p.x>>p.y);
}
Point red[MAX],blue[MAX];
pair<Point,int> cur[MAX];
int nRed,nBlue,res;
void init(void) {
    cin>>nRed>>nBlue;
    FOR(i,1,nRed) cin>>red[i];
    FOR(i,1,nBlue) cin>>blue[i];
}
bool betweenRay(const Point &a,const Point &b,const Point &c) {
    long long dirA=b%a;
    long long dirC=b%c;
    if (dirA<0 && dirC>0) return (true);
    if (dirA>0 && dirC<0) return (true);
    return (false);
}
void countTriangle(int id) {
    //printf("Count %d\n",id);
    Point A=red[id];
    int n=0;
    FOR(i,id+1,nRed) cur[n++]=make_pair(red[i]-A,i);
    FOR(i,1,nBlue) cur[n++]=make_pair(blue[i]-A,-i);
    sort(cur,cur+n);
    REP(i,n) if (cur[i].se>0) {
        Point B=cur[i].fi;
        Point *D=NULL;
        Point lim=Point()-B;
        int j=(i+1)%n;
        REP(love,n) {
            if (lim%cur[j].fi>=0) break;
            Point C=cur[j].fi;
            if (cur[j].se>0) {
                if (D==NULL || !betweenRay(Point()-B,*D-B,C-B)) {
                    res++;
                    //printf("Triangle: %d %d %d\n",id,cur[i].se,cur[j].se);
                }
            } else {
                if (D==NULL) D=new Point(C);
                else if (betweenRay(Point()-B,C-B,*D-B)) *D=C;
            }
            j=(j+1)%n;
        }
    }
    //printf("OK %d\n",id);
}
void process(void) {
    FOR(i,1,nRed-2) countTriangle(i);
    cout<<res<<endl;
}
int main(void) {
#ifdef SKY
    freopen("tmp.txt","r",stdin);
#endif // SKY
    init();
    process();
    return 0;
}