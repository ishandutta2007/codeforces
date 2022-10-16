#include<bits/stdc++.h>
#define MAX   1000100
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
using namespace std;
template<class X,class Y>
    void minimize(X &x,const Y &y) {
        if (x>y) x=y;
    }
template<class X,class Y>
    void maximize(X &x,const Y &y) {
        if (x<y) x=y;
    }
const int rate=100;
int v[MAX],c[MAX],best[MAX],n,m;
double prob[MAX];
void init(void) {
    scanf("%d%d",&n,&m);
    FOR(i,1,n) scanf("%d",&v[i]);
    FOR(i,1,n) scanf("%d",&c[i]);
}
void process(void) {
    deque<int> dqV,dqC;
    int j=0;
    FOR(i,1,n) {
        while (!dqV.empty() && dqV.front()<i) dqV.pop_front();
        while (!dqC.empty() && dqC.front()<i) dqC.pop_front();
        if (j<i) {
            dqV.push_back(i);
            dqC.push_back(i);
            j=i;
        }
        best[i]=min(rate*v[dqV.front()],c[dqC.front()]);
        while (j<n && rate*v[dqV.front()]<c[dqC.front()]) {
            j++;
            while (!dqV.empty() && v[dqV.back()]<=v[j]) dqV.pop_back();
            dqV.push_back(j);
            while (!dqC.empty() && c[dqC.back()]>=c[j]) dqC.pop_back();
            dqC.push_back(j);
            maximize(best[i],min(rate*v[dqV.front()],c[dqC.front()]));
        }
    }
    sort(best+1,best+n+1);
    prob[1]=1;
    FOR(i,2,n-m+1) prob[i]=prob[i-1]*(n-i+2-m)/(n-i+2);
    double res=0;
    FOR(i,1,n-m+1) res+=(prob[i]-prob[i+1])*best[i];
    printf("%.7lf\n",res);
}
int main(void) {
    init();
    process();
    return 0;
}