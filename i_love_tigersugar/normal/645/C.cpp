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
char s[MAX];
int cnt[MAX],n,m;
void init(void) {
    scanf("%d%d",&n,&m);
    scanf("%s",s+1);
    FOR(i,1,n) cnt[i]=cnt[i-1]+(s[i]=='0');
}
bool ok(int x) {
    FOR(i,1,n) if (s[i]=='0') {
        int L=max(i-x,1);
        int R=min(i+x,n);
        if (cnt[R]-cnt[L-1]-1>=m) return (true);
    }
    return (false);
}
int process(void) {
    int L=0;
    int R=MAX;
    while (true) {
        if (L==R) return (R);
        if (R-L==1) return (ok(L)?L:R);
        int M=(L+R)>>1;
        if (ok(M)) R=M; else L=M+1;
    }
}
int main(void) {
    init();
    cout<<process()<<endl;
    return 0;
}