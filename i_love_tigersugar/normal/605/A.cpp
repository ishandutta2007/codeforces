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
int pos[MAX],n;
void init(void) {
    scanf("%d",&n);
    FOR(i,1,n) {
        int x;
        scanf("%d",&x);
        pos[x]=i;
    }
}
void process(void) {
    int res=1;
    int j=1;
    FOR(i,1,n) {
        maximize(j,i);
        while (j<n && pos[j+1]>pos[j]) j++;
        maximize(res,j-i+1);
    }
    printf("%d\n",n-res);
}
int main(void) {
    init();
    process();
    return 0;
}