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
void answerNo(void) {
    printf("-1\n");
    exit(0);
}
int main(void) {
    int n,d,h;
    scanf("%d%d%d",&n,&d,&h);
    if (d==h) {
        if (d==1) {
            if (n>2) answerNo();
            else printf("1 2\n");
        } else {
            FOR(i,1,h) printf("%d %d\n",i,i+1);
            FOR(i,h+2,n) printf("2 %d\n",i);
        }
    } else if (d<=2*h) {
        FOR(i,1,h) printf("%d %d\n",i,i+1);
        printf("1 %d\n",h+2);
        FOR(i,h+2,d) printf("%d %d\n",i,i+1);
        FOR(i,d+2,n) printf("1 %d\n",i);
    } else answerNo();
    return 0;
}