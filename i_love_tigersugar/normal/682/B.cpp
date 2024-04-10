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
int a[MAX],n;
bool ok(int x) {
    int j=1;
    FOR(i,1,x) {
        while (j<=n && a[j]<i) j++;
        if (j>n) return (false);
        j++;
    }
    return (true);
}
int process(void) {
    int L=0;
    int R=n;
    while (true) {
        if (L==R) return (R);
        if (R-L==1) return (ok(R)?R:L);
        int M=(L+R)>>1;
        if (ok(M)) L=M; else R=M-1;
    }
}
int main(void) {
    scanf("%d",&n);
    FOR(i,1,n) scanf("%d",&a[i]);
    sort(a+1,a+n+1);
    printf("%d\n",process()+1);
    return 0;
}