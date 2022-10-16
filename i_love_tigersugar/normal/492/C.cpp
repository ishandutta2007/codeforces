#include<bits/stdc++.h>
#define MAX   100100
#define FOR(i,a,b) for (int i=(a),_b=(b);i<=_b;i=i+1)
#define REP(i,n) for (int i=0,_n=(n);i<_n;i=i+1)
#define fi   first
#define se   second
using namespace std;
typedef long long ll;
pair<ll,ll> a[MAX];
int n;
ll lim,goal;
void init(void) {
    cin>>n>>lim>>goal;
    goal*=n;
    FOR(i,1,n) cin>>a[i].se>>a[i].fi;
    sort(a+1,a+n+1);
}
void process(void) {
    ll cur=0;
    FOR(i,1,n) cur+=a[i].se;
    ll res=0;
    FOR(i,1,n) {
        ll req=max(0LL,goal-cur);
        ll get=min(req,lim-a[i].se);
        res+=get*a[i].fi;
        cur+=get;
    }
    cout<<res<<"\n";
}
int main(void) {
    ios::sync_with_stdio(false);cin.tie(NULL);
    init();
    process();
    return 0;
}