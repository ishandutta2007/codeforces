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
using namespace std;
template<class X,class Y>
    void minimize(X &x,const Y &y) {
        if (x>y) x=y;
    }
template<class X,class Y>
    void maximize(X &x,const Y &y) {
        if (x<y) x=y;
    }
int res[MAX],n,q;
void process(void) {
    scanf("%d%d",&n,&q);
    int goWith0=0;
    int goWith1=1;
    REP(love,q) {
        int t; scanf("%d",&t);
        if (t==1) {
            int x; scanf("%d",&x);
            int tmp=x%2!=0?1:0;
            goWith0=((goWith0-x+tmp)%n+n)%n;
            goWith1=((goWith1-x+tmp)%n+n)%n;
            if (tmp==1) {
                int xxx=(goWith1-2+n)%n;
                goWith1=goWith0;
                goWith0=xxx;
            }
        } else if (t==2) swap(goWith0,goWith1);
    }
    REP(i,n/2) res[2*i]=(goWith0+2*i)%n;
    REP(i,n/2) res[2*i+1]=(goWith1+2*i)%n;
    REP(i,n) printf("%d ",res[i]+1); printf("\n");
}
int main(void) {
    process();
    return 0;
}