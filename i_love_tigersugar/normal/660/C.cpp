#include<bits/stdc++.h>
#define MAX   300300
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
int a[MAX],n,lim,cnt[MAX];
void process(void) {
    scanf("%d%d",&n,&lim);
    FOR(i,1,n) scanf("%d",&a[i]);
    FOR(i,1,n) cnt[i]=cnt[i-1]+1-a[i];
    pair<int,int> best(1,0);
    int j=1;
    FOR(i,1,n) {
        while (j<i) j++;
        while (j<=n && cnt[j]-cnt[i-1]<=lim) j++;
        if (j-i>best.se-best.fi+1) best=make_pair(i,j-1);
    }
    printf("%d\n",best.se-best.fi+1);
    FOR(i,1,n) printf("%d ",best.fi<=i && i<=best.se?1:a[i]);
    printf("\n");
}
int main(void) {
    process();
    return 0;
}