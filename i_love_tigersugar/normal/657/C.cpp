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
#define next   ___next
#define prev   ___prev
#define left   ___left
#define right   ___right
#define __builtin_popcount __builtin_popcountll
using namespace std;
const long long INF=(long long)1e18+7LL;
template<class X,class Y>
    void minimize(X &x,const Y &y) {
        if (x>y) x=y;
    }
template<class X,class Y>
    void maximize(X &x,const Y &y) {
        if (x<y) x=y;
    }
int n,req,bigTime,smallTime;
int a[MAX];
long long sum[MAX];
void init(void) {
    scanf("%d%d%d%d",&n,&req,&bigTime,&smallTime);
    FOR(i,1,n) scanf("%d",&a[i]);
}
void easyCase(void) {
    sort(a+1,a+n+1);
    FOR(i,1,n) sum[i]=sum[i-1]+a[i];
    long long res=INF;
    FOR(i,req,n) {
        long long all=1LL*req*a[i]-(sum[i]-sum[i-req]);
        minimize(res,all*smallTime);
    }
    cout<<res<<endl;
}
long long modCase(int mod) {
    priority_queue<long long> q;
    long long res=INF;
    long long sumQueue=0;
    FOR(i,1,n) {
        long long tmp=a[i];
        long long cost=0;
        while ((tmp-mod)%5!=0) {
            tmp++;
            cost+=smallTime;
        }
        q.push(5*cost-bigTime*tmp);
        sumQueue+=5*cost-bigTime*tmp;
        while (q.size()>req) {
            sumQueue-=q.top();q.pop();
        }
        if (q.size()>=req) minimize(res,bigTime*tmp*req+sumQueue);
    }
    return (res);
}
void hardCase(void) {
    sort(a+1,a+n+1);
    long long res=INF;
    REP(i,5) minimize(res,modCase(i)/5);
    cout<<res<<endl;
}
int main(void) {
    init();
    if (bigTime>=5*smallTime) easyCase(); else hardCase();
    return 0;
}