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
#define div   ___div
#define next   ___next
#define prev   ___prev
#define left   ___left
#define right   ___right
#define __builtin_popcount __builtin_popcountll
#define SQR(x) (1LL*(x)*(x))
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
const double eps=1e-7;
const double PI=acos(-1.0);
int x[MAX],y[MAX],r[MAX],n;
long long dis;
void init(void) {
    int sx,sy,speed,lim; scanf("%d%d%d%d",&sx,&sy,&speed,&lim);
    dis=1LL*speed*lim;
    scanf("%d",&n);
    FOR(i,1,n) {
        scanf("%d%d%d",&x[i],&y[i],&r[i]);
        x[i]-=sx;y[i]-=sy;
        if (SQR(x[i])+SQR(y[i])<=SQR(r[i])) {
            printf("1.0\n");
            exit(0);
        }
    }
    if (dis==0) {
        printf("0.0\n");
        exit(0);
    }
}
pair<double,double> angle(int x,int y,int r) {
    double R=dis;
    double d=sqrt(SQR(x)+SQR(y));
    double mid=atan2(y,x);
    if (mid<0) mid+=2.0*PI;
    if (dis+r<d) return (make_pair(-100,-100));
    if (dis-r>=d) {
        double delta=asin(r/d);
        return (make_pair(mid-delta,mid+delta));
    }
    double delta=acos((SQR(R)+SQR(d)-SQR(r))/2.0/R/d);
    if (sqrt(SQR(d)-SQR(r))<=R) maximize(delta,asin(r/d));
    return (make_pair(mid-delta,mid+delta));
}
void process(void) {
    vector<pair<double,double> > segment;
    FOR(i,1,n) {
        pair<double,double> tmp=angle(x[i],y[i],r[i]);
        if (tmp.fi<-99) continue;
        if (tmp.fi<0) {
            segment.push_back(make_pair(tmp.fi+2.0*PI,2.0*PI));
            segment.push_back(make_pair(0.0,tmp.se));
        } else if (tmp.se>2.0*PI) {
            segment.push_back(make_pair(tmp.fi,2.0*PI));
            segment.push_back(make_pair(0.0,tmp.se-2.0*PI));
        } else {
            assert(tmp.fi>-eps);
            assert(tmp.se<2.0*PI+eps);
            segment.push_back(tmp);
        }
    }
    sort(ALL(segment));
    double sum=0;
    double L=-1.0;
    double R=-1.0;
    FORE(it,segment) {
        if (it->fi>R) {
            sum+=R-L;
            L=it->fi;
            R=it->se;
        } else maximize(R,it->se);
    }
    sum+=R-L;
    printf("%.9lf\n",sum/2.0/PI);
}
int main(void) {
#ifdef SKY
    freopen("tmp.txt","r",stdin);
#endif // SKY
    init();
    process();
    return 0;
}