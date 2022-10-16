#include<bits/stdc++.h>
#define MAX   100100
#define FOR(i,a,b) for (int i=(a),_b=(b);i<=_b;i=i+1)
#define REP(i,n) for (int i=0,_n=(n);i<_n;i=i+1)
#define FORE(i,v) for (__typeof((v).begin()) i=(v).begin();i!=(v).end();i++)
#define fi   first
#define se   second
using namespace std;
typedef long long ll;
vector<pair<int,int> > adj[MAX];
int par[MAX],sta[MAX],fin[MAX];
ll disRoot[MAX],disSubLeaf[MAX],disFarLeaf[MAX];
int n,q,root,center,cnt;
vector<int> pathFromRoot,longestPath;
int cntRem[MAX],cntJoin[MAX];
void loadTree(void) {
    scanf("%d",&n);
    REP(love,n-1) {
        int u,v,c;
        scanf("%d%d%d",&u,&v,&c);
        adj[u].push_back(make_pair(v,c));
        adj[v].push_back(make_pair(u,c));
    }
}
void dfs(int u) {
    sta[u]=++cnt;
    FORE(it,adj[u]) if (it->fi!=par[u]) {
        int v=it->fi;
        par[v]=u;
        disRoot[v]=disRoot[u]+it->se;
        dfs(v);
        disSubLeaf[u]=max(disSubLeaf[u],disSubLeaf[v]+it->se);
    }
    fin[u]=cnt;
}
bool isParent(int u,int v) {
    return (sta[u]<=sta[v] && sta[v]<=fin[u]);
}
int parInPath(int u) {
    int L=0;
    int R=longestPath.size()-1;
    while (true) {
        if (L==R) return (longestPath[R]);
        if (R-L==1) return (isParent(longestPath[R],u)?longestPath[R]:longestPath[L]);
        int M=(L+R)>>1;
        if (isParent(longestPath[M],u)) L=M; else R=M-1;
    }
}
void findLongestPath(void) {
    FOR(i,1,n) if (adj[i].size()>1) root=i;
    dfs(root);
    int leaf=-1;
    FOR(i,1,n) if (disRoot[i]==disSubLeaf[root]) leaf=i;
    while (true) {
        longestPath.push_back(leaf);
        if (leaf==root) break;
        leaf=par[leaf];
    }
    reverse(longestPath.begin(),longestPath.end());
    ll secondWay=0;
    FORE(it,longestPath) {
        int u=*it;
        disFarLeaf[u]=disSubLeaf[root]-disRoot[u];
        if (u==root) continue;
        int p=par[u];
        FORE(it,adj[p]) if (it->fi!=u && it->fi!=par[p]) {
            int v=it->fi;
            secondWay=max(secondWay,disSubLeaf[v]+it->se);
        }
        secondWay+=disRoot[u]-disRoot[p];
        disFarLeaf[u]=max(disFarLeaf[u],secondWay);
    }
    FOR(i,1,n) if (disFarLeaf[i]==0) {
        int p=parInPath(i);
        disFarLeaf[i]=disFarLeaf[p]+disRoot[i]-disRoot[p];
    }
    center=-1;
    FOR(i,1,n) if (center<0 || disFarLeaf[i]<disFarLeaf[center]) center=i;
    /*printf("Center: %d\n",center);
    FOR(i,1,n) cerr<<"Dis of "<<i<<" is "<<disFarLeaf[i]<<endl;
    printf("Longest path:");
    FORE(it,longestPath) printf(" %d",*it); printf("\n");*/
}
int findRemove(const vector<int> &v,ll dis) {
    if (disFarLeaf[center]>=dis) return (0);
    int L=0;
    int R=v.size()-1;
    while (true) {
        if (L==R) return (v[R]);
        if (R-L==1) return (disFarLeaf[v[R]]<dis?v[R]:v[L]);
        int M=(L+R)>>1;
        if (disFarLeaf[v[M]]<dis) L=M; else R=M-1;
    }
}
void dfsTree(int u,int p,ll lim) {
    pathFromRoot.push_back(u);
    cntRem[findRemove(pathFromRoot,disFarLeaf[u]-lim)]++;
    //printf("Node %d will be removed at %d\n",u,findRemove(pathFromRoot,disFarLeaf[u]-lim));
    FORE(it,adj[u]) if (it->fi!=p) {
        int v=it->fi;
        dfsTree(v,u,lim);
        assert(disFarLeaf[v]>=disFarLeaf[u]);
        cntJoin[u]+=cntJoin[v];
    }
    cntJoin[u]++;
    cntJoin[u]-=cntRem[u];
    pathFromRoot.pop_back();
}
void process(void) {
    scanf("%d",&q);
    REP(love,q) {
        ll lim;
        cin>>lim;
        memset(cntJoin,0,sizeof cntJoin);
        memset(cntRem,0,sizeof cntRem);
        pathFromRoot.clear();
        dfsTree(center,-1,lim);
        int ans=0;
        FOR(i,1,n) ans=max(ans,cntJoin[i]);
        printf("%d\n",ans);
    }
}
int main(void) {
#ifdef SKY
    freopen("D.in","r",stdin);
#endif // SKY
    loadTree();
    findLongestPath();
    process();
    return 0;
}