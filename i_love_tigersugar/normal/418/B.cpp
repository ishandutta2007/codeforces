#include<bits/stdc++.h>
#define MAXN   111
#define MAXM   20
#define FOR(i,a,b) for (int i=(a);i<=(b);i=i+1)
#define REP(i,n) for (int i=0;i<(n);i=i+1)
#define MASK(i) (1<<(i))
using namespace std;
typedef long long ll;
const ll INF=(ll)4e18+7;
inline void minimize(ll &x,const ll &y) {
    if (x>y) x=y;
}
struct help {
    int x,s,r;
    help() {
        x=s=r=0;
    }
    void input(void) {
        x=s=r=0;
        int k;
        scanf("%d%d%d",&x,&r,&k);
        REP(zz,k) {
            int v;
            scanf("%d",&v);
            v--;
            s|=MASK(v);
        }
    }
    bool operator < (const help &a) const {
        return (r<a.r);
    }
};
ll f[MASK(MAXM)+7];
help a[MAXN];
int n,m,b;
void init(void) {
    scanf("%d%d%d",&n,&m,&b);
    FOR(i,1,n) a[i].input();
    sort(a+1,a+n+1);
}
void process(void) {
    REP(i,MASK(m)) f[i]=INF;
    f[0]=0;
    ll res=INF;
    FOR(i,1,n) {
        ll cost=1LL*b*a[i].r;
        REP(j,MASK(m)) if (f[j]<INF) minimize(f[j|a[i].s],f[j]+a[i].x);
        minimize(res,f[MASK(m)-1]+cost);
    }
    if (res<INF) cout<<res; else cout<<-1;
}
int main(void) {
    init();
    process();
    return 0;
}