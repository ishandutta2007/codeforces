#include<bits/stdc++.h>
#define MAX   500500
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
template<class X,class Y>
    void minimize(X &x,const Y &y) {
        if (x>y) x=y;
    }
template<class X,class Y>
    void maximize(X &x,const Y &y) {
        if (x<y) x=y;
    }
const int INF=(int)1e9+7;
int a[MAX],n,m;
long long sum;
void init(void) {
    scanf("%d%d",&n,&m);
    FOR(i,1,n) scanf("%d",&a[i]);
    sort(a+1,a+n+1);
    FOR(i,1,n) sum+=a[i];
}
bool canMin(int x) {
    if (sum<1LL*n*x) return (false);
    long long need=0;
    FOR(i,1,n) need+=max(0,x-a[i]);
    return (need<=m);
}
bool canMax(int x) {
    if (sum>1LL*n*x) return (false);
    long long need=0;
    FOR(i,1,n) need+=max(0,a[i]-x);
    return (need<=m);
}
int findMin(void) {
    int L=a[1];
    int R=INF;
    while (true) {
        if (L==R) return (R);
        if (R-L==1) return (canMin(R)?R:L);
        int M=(L+R)>>1;
        if (canMin(M)) L=M; else R=M-1;
    }
}
int findMax(void) {
    int L=0;
    int R=a[n];
    while (true) {
        if (L==R) return (L);
        if (R-L==1) return (canMax(L)?L:R);
        int M=(L+R)>>1;
        if (canMax(M)) R=M; else L=M+1;
    }
}
void process(void) {
    printf("%d\n",max(0,findMax()-findMin()));
}
int main(void) {
    init();
    process();
    return 0;
}