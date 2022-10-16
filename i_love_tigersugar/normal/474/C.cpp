#include<bits/stdc++.h>
#define FOR(i,a,b) for (int i=(a),_b=(b);i<=_b;i=i+1)
#define REP(i,n) for (int i=0,_n=(n);i<_n;i=i+1)
using namespace std;
typedef long long ll;
struct Point {
    int x,y;
    Point() {
        x=y=0;
    }
    Point(int _x,int _y) {
        x=_x;y=_y;
    }
    void input(void) {
        scanf("%d%d",&x,&y);
    }
    Point operator + (const Point &a) const {
        return (Point(x+a.x,y+a.y));
    }
    Point operator - (const Point &a) const {
        return (Point(x-a.x,y-a.y));
    }
    Point rotate(const Point &a) const {
        return (Point(-a.y,a.x));
    }
    ll modul(void) const {
        return (1LL*x*x+1LL*y*y);
    }
    bool operator < (const Point &a) const {
        return (x==a.x?y<a.y:x<a.x);
    }
    bool operator == (const Point &a) const {
        return (x==a.x && y==a.y);
    }
};
bool isSquare(const vector<Point> &v) {
    if ((v[1]-v[0]).modul()!=(v[2]-v[1]).modul()) return (false);
    if ((v[2]-v[1]).modul()!=(v[3]-v[2]).modul()) return (false);
    if ((v[3]-v[2]).modul()!=(v[0]-v[3]).modul()) return (false);
    if ((v[2]-v[0]).modul()!=2*(v[1]-v[0]).modul()) return (false);
    if ((v[3]-v[1]).modul()!=2*(v[1]-v[0]).modul()) return (false);
    return (true);
}
bool check(const vector<Point> &v) {
    vector<Point> tmp=v;
    sort(tmp.begin(),tmp.end());
    REP(i,(int)tmp.size()-1) if (tmp[i]==tmp[i+1]) return (false);
    do if (isSquare(tmp)) return (true); while (next_permutation(tmp.begin(),tmp.end()));
    return (false);
}
Point rotation(const Point &cen,const Point &p,int t) {
    Point res=p;
    REP(zz,t) res=cen+cen.rotate(res-cen);
    return (res);
}
void process(void) {
    Point cen[4],pnt[4];
    REP(i,4) {
        pnt[i].input();
        cen[i].input();
    }
    int res=100;
    REP(a,4) REP(b,4) REP(c,4) REP(d,4) {
        vector<Point> v;
        v.push_back(rotation(cen[0],pnt[0],a));
        v.push_back(rotation(cen[1],pnt[1],b));
        v.push_back(rotation(cen[2],pnt[2],c));
        v.push_back(rotation(cen[3],pnt[3],d));
        if (check(v)) res=min(res,a+b+c+d);
    }
    if (res<100) printf("%d\n",res); else printf("-1\n");
}
int main(void) {
    int t;
    scanf("%d",&t);
    REP(zz,t) process();
    return 0;
}