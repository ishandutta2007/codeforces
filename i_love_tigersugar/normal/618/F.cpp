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
int a[MAX],b[MAX],n;
long long sumA[MAX],sumB[MAX];
void init(void) {
    scanf("%d",&n);
    FOR(i,1,n) scanf("%d",&a[i]);
    FOR(i,1,n) scanf("%d",&b[i]);
    FOR(i,1,n) sumA[i]=sumA[i-1]+a[i];
    FOR(i,1,n) sumB[i]=sumB[i-1]+b[i];
}
void process(void) {
    map<int,pair<int,int> > mp;
    FOR(i,0,n) {
        int j=upper_bound(sumB,sumB+n+1,sumA[i])-sumB-1;
        if (mp.find(sumA[i]-sumB[j])!=mp.end()) {
            int k=mp[sumA[i]-sumB[j]].fi;
            int l=mp[sumA[i]-sumB[j]].se;
            printf("%d\n",i-k);
            FOR(x,k+1,i) printf("%d ",x); printf("\n");
            printf("%d\n",j-l);
            FOR(y,l+1,j) printf("%d ",y); printf("\n");
            exit(0);
        } else mp[sumA[i]-sumB[j]]=make_pair(i,j);
    }
    assert(false);
}
int main(void) {
    init();
    process();
    return 0;
}