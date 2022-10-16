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
const int start=4;
const int numDay[]={31,29,31,30,31,30,31,31,30,31,30,31};
int countWeek(int x) {
    int res=0;
    int cur=start;
    REP(love,366) {
        if (cur==x) res++;
        cur=(cur+1)%7;
    }
    return (res);
}
int countMonth(int x) {
    int res=0;
    REP(i,12) if (numDay[i]>=x) res++;
    return (res);
}
char s[3][100];
int main(void) {
    int x;
    scanf("%d",&x);
    REP(i,2) scanf("%s",s[i]);
    printf("%d\n",strlen(s[1])==4?countWeek(x-1):countMonth(x));
    return 0;
}