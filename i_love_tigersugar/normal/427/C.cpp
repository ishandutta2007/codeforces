#include<bits/stdc++.h>
#define MAX   100100
#define FOR(i,a,b) for (int i=(a);i<=(b);i=i+1)
#define REP(i,n) for (int i=0;i<(n);i=i+1)
#define FORE(i,v) for (__typeof((v).begin()) i=(v).begin();i!=(v).end();i++)
#define fi   first
#define se   second
using namespace std;
const int mod=(int)1e9+7;
typedef pair<int,int> ii;
vector<int> g[MAX];
int low[MAX],num[MAX],cost[MAX];
ii best[MAX];
int n,m,nc,cnt;
stack<int> st;
bool fre[MAX];
void update(ii &x,int y) {
    if (x.fi>y) {
        x=ii(y,1);
        return;
    }
    if (x.fi==y) x.se++;
}
void minimize(int &x,const int &y) {
    if (x>y) x=y;
}
void loadgraph(void) {
    scanf("%d",&n);
    FOR(i,1,n) {
        best[i]=ii(mod,0);
        scanf("%d",&cost[i]);
        fre[i]=true;
    }
    scanf("%d",&m);
    REP(zz,m) {
        int u,v;
        scanf("%d%d",&u,&v);
        g[u].push_back(v);
    }
}
void visit(int u) {
    low[u]=num[u]=++cnt;
    st.push(u);
    FORE(it,g[u]) if (fre[*it]) {
        int v=*it;
        if (num[v]==0) {
            visit(v);
            minimize(low[u],low[v]);
        }
        else minimize(low[u],num[v]);
    }
    if (low[u]==num[u]) {
        int v;
        nc++;
        do {
            v=st.top();st.pop();
            fre[v]=false;
            update(best[nc],cost[v]);
        }
        while (v!=u);
    }
}
void tarjan(void) {
    FOR(i,1,n) if (num[i]==0) visit(i);
    long long sum=0;
    int cnt=1;
    FOR(i,1,nc) {
        sum+=best[i].fi;
        cnt=1LL*cnt*best[i].se%mod;
    }
    cout<<sum<<" "<<cnt;
}
int main(void) {
    loadgraph();
    tarjan();
    return 0;
}