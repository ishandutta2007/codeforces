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
using namespace std;
template<class X,class Y>
    void minimize(X &x,const Y &y) {
        if (x>y) x=y;
    }
template<class X,class Y>
    void maximize(X &x,const Y &y) {
        if (x<y) x=y;
    }
const int INF=(int)1e9+7;
bool ok(int t,int n,int m) {
    int cntN=t/2-t/6;
    int cntM=t/3-t/6;
    int cntAll=t/6;
    int leftN=max(0,n-cntN);
    int leftM=max(0,m-cntM);
    return (leftN+leftM<=cntAll);
}
int process(void) {
    int n,m;
    cin>>n>>m;
    int L=0;
    int R=INF;
    while (true) {
        if (L==R) return (R);
        if (R-L==1) return (ok(L,n,m)?L:R);
        int M=(L+R)>>1;
        if (ok(M,n,m)) R=M; else L=M+1;
    }
}
int main(void) {
    cout<<process()<<endl;
    return 0;
}