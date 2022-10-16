#include<bits/stdc++.h>
#define MAX   111
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
const long long INF=(long long)1e18+7LL;
long long f[MAX][MAX][MAX];
int cost[MAX][MAX],sta[MAX];
int numTree,numColor,numSeg;
void init(void) {
    scanf("%d%d%d",&numTree,&numColor,&numSeg);
    FOR(i,1,numTree) scanf("%d",&sta[i]);
    FOR(i,1,numTree) FOR(j,1,numColor) scanf("%d",&cost[i][j]);
}
void optimize(void) {
    memset(f,0x3f,sizeof f);
    FOR(i,1,numColor) if (sta[1]==0 || sta[1]==i) minimize(f[1][i][1],sta[1]==0?cost[1][i]:0);
    FOR(curTree,1,numTree-1) FOR(lastColor,1,numColor) FOR(curSeg,1,numSeg)
        if (f[curTree][lastColor][curSeg]<INF) FOR(nextColor,1,numColor)
            if (sta[curTree+1]==0 || sta[curTree+1]==nextColor) {
                int newSeg=curSeg+(nextColor!=lastColor);
                int newCost=sta[curTree+1]==0?cost[curTree+1][nextColor]:0;
                minimize(f[curTree+1][nextColor][newSeg],
                    f[curTree][lastColor][curSeg]+newCost);
            }
    long long res=INF;
    FOR(i,1,numColor) minimize(res,f[numTree][i][numSeg]);
    cout<<(res<INF?res:-1)<<endl;
}
int main(void) {
    init();
    optimize();
    return 0;
}