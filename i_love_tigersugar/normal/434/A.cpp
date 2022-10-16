#include<bits/stdc++.h>
#define MAX   100100
#define FOR(i,a,b) for (int i=(a);i<=(b);i=i+1)
#define REP(i,n) for (int i=0;i<(n);i=i+1)
#define fi   first
#define se   second
using namespace std;
typedef long long ll;
typedef pair<int,ll> ii;
vector<ii> v[MAX];
int a[MAX];
int n,m;
ll val[MAX],best;
inline int Abs(int x) {
    return (x<0?-x:x);
}
void init(void) {
    scanf("%d%d",&n,&m);
    FOR(i,1,n) v[i].push_back(ii(0,0));
    FOR(i,1,m) {
        scanf("%d",&a[i]);
        if (i>1 && a[i]!=a[i-1]) {
            v[a[i]].push_back(ii(a[i-1],0));
            v[a[i-1]].push_back(ii(a[i],0));
            val[a[i]]+=Abs(a[i]-a[i-1]);
            val[a[i-1]]+=Abs(a[i]-a[i-1]);
            best+=Abs(a[i]-a[i-1]);
        }
    }
    FOR(i,1,n) sort(v[i].begin(),v[i].end());
    FOR(i,1,n) FOR(j,1,v[i].size()-1) v[i][j].se=v[i][j-1].se+v[i][j].fi;
}
ll sumabs(int x,int y) {
    int id=upper_bound(v[x].begin(),v[x].end(),ii(y,1LL*MAX*MAX+7))-v[x].begin()-1;
    assert(id>=0 && id<v[x].size());
    return (v[x].back().se-2*v[x][id].se-1LL*y*((int)v[x].size()-1-2*id));
}
void process(void) {
    ll sum=best;
    FOR(i,1,n) FOR(j,1,v[i].size()-1) best=min(best,sum+sumabs(i,v[i][j].fi)-val[i]);
    cout<<best;
}
int main(void) {
#ifndef ONLINE_JUDGE
    freopen("tmp.txt","r",stdin);
#endif
    init();
    process();
    return 0;
}