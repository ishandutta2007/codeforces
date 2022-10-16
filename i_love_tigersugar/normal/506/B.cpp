#include<bits/stdc++.h>
#define MAX   100100
#define FOR(i,a,b) for (int i=(a),_b=(b);i<=_b;i=i+1)
#define REP(i,n) for (int i=0,_n=(n);i<_n;i=i+1)
#define FORE(i,v) for (__typeof((v).begin()) i=(v).begin();i!=(v).end();i++)
using namespace std;
vector<int> adj[MAX];
int low[MAX],num[MAX],compID[MAX],compSZ[MAX];
int n,m,cnt,nComp;
stack<int> st;
int lab[MAX];
bool spe[MAX];
void loadgraph(void) {
    scanf("%d%d",&n,&m);
    REP(zz,m) {
        int u,v;
        scanf("%d%d",&u,&v);
        adj[u].push_back(v);
    }
}
void visit(int u) {
    low[u]=num[u]=++cnt;
    st.push(u);
    FORE(it,adj[u]) if (compID[*it]==0) {
        int v=*it;
        if (num[v]==0) {
            visit(v);
            low[u]=min(low[u],low[v]);
        } else low[u]=min(low[u],num[v]);
    }
    if (low[u]==num[u]) {
        nComp++;
        int v;
        do {
            v=st.top();st.pop();
            compID[v]=nComp;
            compSZ[nComp]++;
        } while (v!=u);
    }
}
int find(int x) {
    if (lab[x]<0) return (x);
    lab[x]=find(lab[x]);
    return (lab[x]);
}
bool join(int a,int b) {
    int x=find(a);
    int y=find(b);
    if (x==y) return (false);
    if (lab[x]>lab[y]) swap(x,y);
    lab[x]+=lab[y];
    lab[y]=x;
    return (true);
}
void process(void) {
    FOR(i,1,n) if (num[i]==0) visit(i);
    FOR(i,1,n) lab[i]=-1;
    FOR(u,1,n) FORE(it,adj[u]) join(u,*it);
    FOR(i,1,n) if (compSZ[compID[i]]>1) spe[find(i)]=true;
    int res=0;
    FOR(i,1,n) if (find(i)==i) {
        if (spe[i]) res+=-lab[i];
        else res+=-lab[i]-1;
    }
    printf("%d\n",res);
}
int main(void) {
    loadgraph();
    process();
    return 0;
}