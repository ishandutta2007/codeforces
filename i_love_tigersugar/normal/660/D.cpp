#include<bits/stdc++.h>
#define MAX   2207
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
pair<int,int> a[MAX];
map<pair<int,int>,int> cnt;
int n;
long long COMB2(int x) {
    return (x<2?0:1LL*x*(x-1)/2);
}
void process(void) {
    scanf("%d",&n);
    FOR(i,1,n) scanf("%d%d",&a[i].fi,&a[i].se);
    FOR(i,1,n) FOR(j,i+1,n) cnt[make_pair(a[i].fi+a[j].fi,a[i].se+a[j].se)]++;
    long long res=0;
    FORE(it,cnt) res+=COMB2(it->se);
    cout<<res<<endl;
}
int main(void) {
    process();
    return 0;
}