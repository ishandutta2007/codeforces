#include<bits/stdc++.h>
#define MAX   555
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
const int INF=(int)1e9+7;
template<class X,class Y>
    void minimize(X &x,const Y &y) {
        if (x>y) x=y;
    }
template<class X,class Y>
    void maximize(X &x,const Y &y) {
        if (x<y) x=y;
    }
int a[MAX],n;
int dpF[MAX][MAX],dpG[MAX][MAX];
int g(int l,int r);
int f(int l,int r) {
    if (l>r) return (0);
    if (l==r || l+1==r) return (1);
    return (g(l+1,r-1));
}
int g(int l,int r) {
    if (l>r) return (0);
    if (dpG[l][r]<INF) return (dpG[l][r]);
    int &res=dpG[l][r];
    FOR(i,l,r) if (a[l]==a[i]) minimize(res,f(l,i)+g(i+1,r));
    return (res);
}
void init(void) {
    scanf("%d",&n);
    FOR(i,1,n) scanf("%d",&a[i]);
}
void process(void) {
    memset(dpF,0x3f,sizeof dpF);
    memset(dpG,0x3f,sizeof dpG);
    printf("%d\n",g(1,n));
}
int main(void) {
    init();
    process();
    return 0;
}