#include<bits/stdc++.h>
#define FOR(i,a,b) for (int i=(a),_b=(b);i<=_b;i=i+1)
#define FORD(i,b,a) for (int i=(b),_a=(a);i>=_a;i=i-1)
#define REP(i,n) for (int i=0,_n=(n);i<_n;i=i+1)
#define FORE(i,v) for (__typeof((v).begin()) i=(v).begin();i!=(v).end();i++)
#define ALL(v) (v).begin(),(v).end()
#define fi   first
#define se   second
#define MASK(i) (1LL<<(i))
#define BIT(x,i) (((x)>>(i))&1)
#define next   ___next
#define prev   ___prev
#define left   ___left
#define right   ___right
#define y1 fjdsal
#define SQR(x) (1.0*(x)*(x))
using namespace std;
const double INF=1e9;
template<class X,class Y>
    void minimize(X &x,const Y &y) {
        if (x>y) x=y;
    }
template<class X,class Y>
    void maximize(X &x,const Y &y) {
        if (x<y) x=y;
    }
int x1,x2,y1,y2,limV,t,vx,vy,wx,wy;
bool ok(double dur) {
    double moveX=dur<=t?vx*dur:1.0*vx*t+wx*(dur-t);
    double moveY=dur<=t?vy*dur:1.0*vy*t+wy*(dur-t);
    double tarX=x2-moveX-x1;
    double tarY=y2-moveY-y1;
    return (limV*dur>=sqrt(SQR(tarX)+SQR(tarY)));
}
void process(void) {
    cin>>x1>>y1>>x2>>y2>>limV>>t>>vx>>vy>>wx>>wy;
    double L=0;
    double R=INF;
    REP(love,227) {
        double M=(L+R)/2;
        if (ok(M)) R=M; else L=M;
    }
    printf("%.9lf\n",(L+R)/2);
}
int main(void) {
    process();
    return 0;
}