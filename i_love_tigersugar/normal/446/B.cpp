#include<bits/stdc++.h>
#define MAX   1111
#define MAXK   1111111
#define FOR(i,a,b) for (int i=(a);i<=(b);i=i+1)
#define REP(i,n) for (int i=0;i<(n);i=i+1)
using namespace std;
typedef long long ll;
const ll INF=(ll)1e18+7LL;
int sr[MAX],sc[MAX];
int m,n,r,p;
ll scr[MAXK],scc[MAXK],res;
inline void maximize(ll &x,const ll &y) {
    if (x<y) x=y;
}
void init(void) {
    scanf("%d%d%d%d",&m,&n,&r,&p);
    FOR(i,1,m) FOR(j,1,n) {
        int t;
        scanf("%d",&t);
        sr[i]+=t;
        sc[j]+=t;
    }
}
void getchoose(int s[],int n,int m,ll sc[]) {
    priority_queue<ll> q;
    FOR(i,1,n) q.push(s[i]);
    FOR(i,1,r) {
        ll t=q.top();
        q.pop();
        q.push(t-1LL*p*m);
        sc[i]=sc[i-1]+t;
    }
}
void process(void) {
    getchoose(sr,m,n,scr);
    getchoose(sc,n,m,scc);
    res=-INF;
    //FOR(i,1,r) cout<<scr[i]<<" "; cout<<endl;
    //FOR(i,1,r) cout<<scc[i]<<" "; cout<<endl;
    //FOR(i,0,r) cout<<scr[i]+scc[r-i]-1LL*p*i<<" "; cout<<endl;
    //FOR(i,0,r) cout<<scc[i]+scr[r-i]-1LL*p*i<<" "; cout<<endl;
    FOR(i,0,r) maximize(res,scr[i]+scc[r-i]-1LL*p*i*(r-i));
    FOR(i,0,r) maximize(res,scc[i]+scr[r-i]-1LL*p*i*(r-i));
    cout<<res;
}
int main(void) {
    init();
    process();
    return 0;
}