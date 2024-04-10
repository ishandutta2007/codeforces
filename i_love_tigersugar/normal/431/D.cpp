#include<bits/stdc++.h>
#define NB   61
#define FOR(i,a,b) for (int i=(a);i<=(b);i=i+1)
#define REP(i,n) for (int i=0;i<(n);i=i+1)
#define BIT(x,i) (((x)>>(i))&1)
using namespace std;
typedef long long ll;
const ll INF=(ll)1e18+7LL;
ll f[NB+7][NB+7][2];
ll n;
int c;
ll count(ll x) {    
    memset(f,0,sizeof f);
    f[0][0][1]=1;
    REP(i,NB) REP(j,c+1) REP(k,2) if (f[i][j][k]>0)
        REP(l,2) f[i+1][j+l][l<BIT(x,i) || (l==BIT(x,i) && k)]+=f[i][j][k];
    return (f[NB][c][1]);
}
void process(void) {
    cin>>n>>c;
    if (n==0) {
        assert(c!=1);
        cout<<1;
        return;
    }
    ll l=0;
    ll r=INF;
    while (true) {
        if (l==r) {
            cout<<r;
            return;
        }
        if (r-l==1) {
            if (count(2*l)-count(l)>=n) cout<<l;
            else cout<<r;
            return;
        }
        ll m=(l+r)>>1;
        if (count(2*m)-count(m)>=n) r=m;
        else l=m+1;
    }
}
int main(void) {
    process();
    return 0;
}