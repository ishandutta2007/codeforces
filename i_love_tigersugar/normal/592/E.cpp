#include<bits/stdc++.h>
#define MAX   500500
#define FOR(i,a,b) for (int i=(a),_b=(b);i<=_b;i=i+1)
#define FORD(i,b,a) for (int i=(b),_a=(a);i>=_a;i=i-1)
#define REP(i,n) for (int i=0,_n=(n);i<_n;i=i+1)
#define FORE(i,v) for (__typeof((v).begin()) i=(v).begin();i!=(v).end();i++)
#define ALL(v) (v).begin(),(v).end()
#define SQR(x) (1LL*(x)*(x))
#define fi   first
#define se   second
#define MASK(i) (1LL<<(i))
#define BIT(x,i) (((x)>>(i))&1)
#define next   ___next
#define prev   ___prev
#define left   ___left
#define right   ___right
using namespace std;
template<class X,class Y>
    void minimize(X &x,const Y &y) {
        if (x>y) x=y;
    }
template<class X,class Y>
    void maximize(X &x,const Y &y) {
        if (x<y) x=y;
    }
struct Point {
    int x,y;
    Point() {
        x=y=0;
    }
    Point(int _x,int _y) {
        x=_x;y=_y;
    }
    int getArea(void) const {
        assert(x!=0 || y!=0);
        if (x>0 && y==0) return (0);
        if (x>0 && y>0) return (1);
        if (x==0 && y>0) return (2);
        if (x<0 && y>0) return (3);
        if (x<0 && y==0) return (4);
        if (x<0 && y<0) return (5);
        if (x==0 && y<0) return (6);
        return (7);
    }
    long long operator % (const Point &a) const {
        return (1LL*x*a.y-1LL*y*a.x);
    }
};
bool CompCCW(const Point &a,const Point &b) {
    int ta=a.getArea();
    int tb=b.getArea();
    if (ta!=tb) return (ta<tb);
    return (a%b>0);
}
bool inARay(const Point &a,const Point &b) {
    return (a.getArea()==b.getArea() && a%b==0);
}
Point a[MAX];
int n;
long long comb2(int x) {
    return (x<2?0:1LL*x*(x-1)/2);
}
long long comb3(int x) {
    return (x<3?0:1LL*x*(x-1)*(x-2)/6);
}
void init(void) {
    int c,d;
    scanf("%d%d%d",&n,&c,&d);
    FOR(i,1,n) {
        int x,y;
        scanf("%d%d",&x,&y);
        a[i]=Point(x-c,y-d);
    }
    sort(a+1,a+n+1,CompCCW);
}
long long countTriangle(void) {
    vector<pair<Point,int> > v;
    FOR(i,1,n) {
        if (!v.empty() && inARay(a[i],v.back().fi)) v.back().se++;
        else v.push_back(make_pair(a[i],1));
    }
    REP(i,v.size()) v.push_back(v[i]);
    long long res=0;
    long long sum=0;
    long long sumSQR=0;
    int j=0;
    REP(i,v.size()/2) {
        while (j+1<i+v.size()/2 && v[i].fi%v[j+1].fi>0) {
            j++;
            sum+=v[j].se;
            sumSQR+=SQR(v[j].se);
        }
        res+=(SQR(sum)-sumSQR)/2*v[i].se;
        if (j>i) {
            sum-=v[i+1].se;
            sumSQR-=SQR(v[i+1].se);
        } else j++;
    }
    return (res);
}
long long countLine(void) {
    vector<Point> tmp;
    FOR(i,1,n) {
        if (a[i].y>0 || (a[i].y==0 && a[i].x>0)) tmp.push_back(a[i]);
        else tmp.push_back(Point(-a[i].x,-a[i].y));
    }
    sort(ALL(tmp),CompCCW);
    vector<pair<Point,int> > v;
    FORE(it,tmp) {
        if (!v.empty() && inARay(*it,v.back().fi)) v.back().se++;
        else v.push_back(make_pair(*it,1));
    }
    long long res=0;
    FORE(it,v) res+=comb3(it->se)+comb2(it->se)*(n-it->se);
    return (res);
}
void process(void) {
    cout<<comb3(n)-countTriangle()-countLine()<<endl;
}
int main(void) {
    init();
    process();
    return 0;
}