#include<bits/stdc++.h>
#define MAX   5050
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
int a[MAX],res[MAX],cnt[MAX][MAX],n;
void init(void) {
    scanf("%d",&n);
    FOR(i,1,n) scanf("%d",&a[i]);
    FOR(i,1,n) {
        FOR(j,1,n) cnt[i][j]=cnt[i-1][j];
        cnt[i][a[i]]++;
    }
}
bool better(const pair<int,int> &a,const pair<int,int> &b) {
    if (a.fi!=b.fi) return (a.fi>b.fi);
    return (a.se<b.se);
}
void update(pair<int,int> &a,const pair<int,int> &b) {
    if (better(b,a)) a=b;
}
void process(void) {
    FOR(i,1,n) {
        pair<int,int> best=make_pair(1,a[i]);
        res[a[i]]++;
        FOR(j,i+1,n) {
            int tmp=a[j];
            update(best,make_pair(cnt[j][tmp]-cnt[i-1][tmp],tmp));
            res[best.se]++;
        }
    }
    FOR(i,1,n) printf("%d ",res[i]); printf("\n");
}
int main(void) {
    init();
    process();
    return 0;
}