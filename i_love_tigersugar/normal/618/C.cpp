#include<bits/stdc++.h>
#define MAX   100100
#define FOR(i,a,b) for (int i=(a),_b=(b);i<=_b;i=i+1)
#define FORD(i,b,a) for (int i=(b),_a=(a);i>=_a;i=i-1)
#define REP(i,n) for (int i=0,_n=(n);i<_n;i=i+1)
#define FORE(i,v) for (__typeof((v).begin()) i=(v).begin();i!=(v).end();i++)
#define ALL(v) (v).begin(),(v).end()
#define fi   first
#define se   second
#define MASK(i) (1LL<<(i))
#define BIT(x,i) (((x)>>(i))&1)
#define SQR(x) (1LL*(x)*(x))
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
    void input(void) {
        scanf("%d%d",&x,&y);
    }
};
Point point[MAX];
int n;
long long dis(const Point &a,const Point &b) {
    return (SQR(a.x-b.x)+SQR(a.y-b.y));
}
long long disLine(const Point &m,const Point &n,const Point &p) {
    int a=m.y-n.y;
    int b=n.x-m.x;
    long long c=-(1LL*a*m.x+1LL*b*m.y);
    long long res=1LL*a*p.x+1LL*b*p.y+c;
    return (max(res,-res));
}
void init(void) {
    scanf("%d",&n);
    FOR(i,1,n) point[i].input();
    int j=2;
    FOR(i,2,n) if (dis(point[1],point[i])<dis(point[1],point[j])) j=i;
    int k=-1;
    FOR(i,2,n) if (i!=j && disLine(point[1],point[j],point[i])>0 &&
        (k<0 || disLine(point[1],point[j],point[i])<disLine(point[1],point[j],point[k])))
            k=i;
    printf("%d %d %d\n",1,j,k);
}
int main(void) {
    init();
    return 0;
}