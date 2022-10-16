#include<bits/stdc++.h>
#define MAX   100100
#define FOR(i,a,b) for (int i=(a),_b=(b);i<=_b;i=i+1)
#define REP(i,n) for (int i=0,_n=(n);i<_n;i=i+1)
#define fi   first
#define se   second
using namespace std;
int deg[MAX],sum[MAX];
int n;
void init(void) {
    scanf("%d",&n);
    REP(i,n) scanf("%d%d",&deg[i],&sum[i]);
}
void process(void) {
    vector<pair<int,int> > res;
    set<pair<int,int> > s;
    REP(i,n) s.insert(make_pair(deg[i],i));
    while (!s.empty()) {
        int u=s.begin()->se;s.erase(s.begin());
        assert(deg[u]<2);
        if (deg[u]==0) continue;
        int v=sum[u];
        res.push_back(make_pair(u,v));
        s.erase(make_pair(deg[v],v));
        deg[v]--;
        sum[v]^=u;
        s.insert(make_pair(deg[v],v));
    }
    printf("%d\n",(int)res.size());
    REP(i,res.size()) printf("%d %d\n",res[i].fi,res[i].se);
}
int main(void) {
    init();
    process();
    return 0;
}