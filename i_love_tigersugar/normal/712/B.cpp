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
char s[MAX];
int cntUp,cntDown,cntLeft,cntRight;
int main(void) {
    scanf("%s",s);
    int n=strlen(s);
    if (n%2!=0) {
        printf("-1\n");
        return 0;
    }
    REP(i,n) {
        if (s[i]=='L') cntLeft++;
        if (s[i]=='R') cntRight++;
        if (s[i]=='U') cntUp++;
        if (s[i]=='D') cntDown++;
    }
    int res=MAX;
    FOR(i,0,n/2) {
        int LR=i;
        int UD=n/2-i;
        int tmp=0;
        if (cntLeft>LR) tmp+=cntLeft-LR;
        if (cntRight>LR) tmp+=cntRight-LR;
        if (cntUp>UD) tmp+=cntUp-UD;
        if (cntDown>UD) tmp+=cntDown-UD;
        minimize(res,tmp);
    }
    printf("%d\n",res);
    return 0;
}