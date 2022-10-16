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
const int mod=(int)1e9+7;
int inverse(int x) {
    int res=1;
    int mul=x;
    int k=mod-2;
    while (k>0) {
        if (k&1) res=1LL*res*mul%mod;
        mul=1LL*mul*mul%mod;
        k>>=1;
    }
    return (res);
}
const int INF=(int)1e9+7;
int a[MAX],n;
void process(void) {
    scanf("%d",&n);
    FOR(i,1,n) scanf("%d",&a[i]);
    int res=0;
    int last=0;
    FOR(i,1,n) {
        if (i>2) {
            int oldLim=i==2?a[1]-1:min(a[i-1],a[i-2])-1;
            int newLim=min(oldLim,a[i]-1);
            last=1LL*last*inverse(oldLim)%mod*newLim%mod;
            int curLim=min(a[i],a[i-1])-1;
            last=1LL*last*curLim%mod;
            res=(res+last)%mod;
        }
        if (i>1) {
            int tmp=SQR(min(a[i],a[i-1])-1)%mod;
            last=(last+tmp)%mod;
            res=(res+tmp)%mod;
        }
        res=(res+a[i]-1)%mod;
    }
    printf("%d\n",res);
}
int main(void) {
    process();
    return 0;
}