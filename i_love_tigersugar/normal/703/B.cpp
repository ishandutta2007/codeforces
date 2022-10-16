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
int val[MAX];
bool good[MAX];
int n,m;
void init(void) {
    scanf("%d%d",&n,&m);
    REP(i,n) scanf("%d",&val[i]);
    REP(love,m) {
        int x; scanf("%d",&x);
        good[x-1]=true;
    }
}
void process(void) {
    long long res=0;
    long long sumVal=0,sumGoodVal=0,sumGoodSQR=0;
    REP(i,n) sumVal+=val[i];
    REP(i,n) if (good[i]) res+=1LL*val[i]*(sumVal-val[i]);
    REP(i,n) if (good[i]) sumGoodVal+=val[i];
    REP(i,n) if (good[i]) sumGoodSQR+=SQR(val[i]);
    res-=(SQR(sumGoodVal)-sumGoodSQR)/2;
    REP(i,n) if (!good[i] && !good[(i+1)%n]) res+=1LL*val[i]*val[(i+1)%n];
    cout<<res<<endl;
}
int main(void) {
    init();
    process();
    return 0;
}