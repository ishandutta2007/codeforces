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
using namespace std;
template<class X,class Y>
    void minimize(X &x,const Y &y) {
        if (x>y) x=y;
    }
template<class X,class Y>
    void maximize(X &x,const Y &y) {
        if (x<y) x=y;
    }
const int watchTime=1;
int n,rotateTime,moveTime,allow;
char dir[MAX];
long long left[MAX],right[MAX];
void process(void) {
    scanf("%d%d%d%d",&n,&moveTime,&rotateTime,&allow);
    scanf("%s",dir+1);
    FOR(i,1,n) dir[n+i]=dir[i];
    int res=0;
    long long used=0;
    FOR(i,1,n) {
        if (dir[i]=='w') used+=rotateTime;
        used+=watchTime;
        left[i]=used;
        used+=moveTime;
    }
    used=0;
    FORD(i,n+1,2) {
        if (dir[i]=='w') used+=rotateTime;
        used+=watchTime;
        right[n+2-i]=used;
        used+=moveTime;
    }
    FOR(i,1,n) if (left[i]<=allow || right[i]<=allow) maximize(res,i);
    FOR(i,1,n) {
        long long need=left[i]+1LL*moveTime*(i-1);
        int j=upper_bound(right+1,right+n+1,allow-need+left[1])-right-1;
        if (j>0) maximize(res,min(i+j-1,n));
        need=right[i]+1LL*moveTime*(i-1);
        j=upper_bound(left+1,left+n+1,allow-need+right[1])-left-1;
        if (j>0) maximize(res,min(i+j-1,n));
    }
    printf("%d\n",res);
}
int main(void) {
    process();
    return 0;
}