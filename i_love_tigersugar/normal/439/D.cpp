#include<bits/stdc++.h>
#define MAX   100100
#define FOR(i,a,b) for (int i=(a);i<=(b);i=i+1)
#define REP(i,n) for (int i=0;i<(n);i=i+1)
using namespace std;
typedef long long ll;
const ll INF=(ll)1e18+7LL;
int n,m;
int a[MAX],b[MAX];
ll sa[MAX],sb[MAX];
inline void minimize(ll &x,const ll &y) {
    if (x>y) x=y;
}
void init(void) {
    scanf("%d%d",&n,&m);
    FOR(i,1,n) scanf("%d",&a[i]);
    FOR(i,1,m) scanf("%d",&b[i]);
    sort(a+1,a+n+1);
    sort(b+1,b+m+1,greater<int>());
    FOR(i,1,n) sa[i]=sa[i-1]+a[i];
    FOR(i,1,m) sb[i]=sb[i-1]+b[i];
}
ll uses(int x) {
    int ia=lower_bound(a+1,a+n+1,x)-a-1;
    int ib=lower_bound(b+1,b+m+1,x,greater<int>())-b-1;
    return (1LL*ia*x-sa[ia]+sb[ib]-1LL*ib*x);
}
void process(void) {
    ll best=INF;
    FOR(i,1,n) minimize(best,uses(a[i]));
    FOR(i,1,m) minimize(best,uses(b[i]));
    minimize(best,uses(1));
    minimize(best,uses((int)1e9));
    cout<<best;
}
int main(void) {
    init();
    process();
    return 0;
}