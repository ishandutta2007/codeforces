#include<bits/stdc++.h>
#define MAX   200200
#define FOR(i,a,b) for (int i=(a),_b=(b);i<=_b;i=i+1)
#define FORD(i,b,a) for (int i=(b),_a=(a);i>=_a;i=i-1)
#define REP(i,n) for (int i=0,_n=(n);i<_n;i=i+1)
#define FORE(i,v) for (__typeof((v).begin()) i=(v).begin();i!=(v).end();i++)
#define ALL(v) (v).begin(),(v).end()
#define fi   first
#define se   second
#define MASK(i) (1LL<<(i))
#define BIT(x,i) (((x)>>(i))&1)
#define next   ___next
#define prev   ___prev
#define left   ___left
#define right   ___right
using namespace std;
template<class X,class Y>
    void minimize(X &x,const Y &y) {
        if (x>y) x=y;
    }
template<class X,class Y>
    void maximize(X &x,const Y &y) {
        if (x<y) x=y;
    }
const int INF=(int)1e9+7;
vector<int> adj[MAX];
int farIn[MAX],farOut[MAX],numChs[MAX],numEdge[MAX];
bool chs[MAX];
int n,m;
void loadTree(void) {
    scanf("%d%d",&n,&m);
    REP(love,n-1) {
        int u,v;
        scanf("%d%d",&u,&v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    REP(love,m) {
        int x;
        scanf("%d",&x);
        chs[x]=true;
    }
}
void firstDFS(int u,int p) {
    if (chs[u]) {
        farIn[u]=0;
        numChs[u]=1;
    }
    FORE(it,adj[u]) if (*it!=p) {
        int v=*it;
        firstDFS(v,u);
        maximize(farIn[u],farIn[v]+1);
        numChs[u]+=numChs[v];
    }
}
void secondDFS(int u,int p) {
    pair<int,int> bestChild(-INF,-INF);
    FORE(it,adj[u]) if (*it!=p) {
        if (farIn[*it]>bestChild.fi) {
            bestChild.se=bestChild.fi;
            bestChild.fi=farIn[*it];
        } else maximize(bestChild.se,farIn[*it]);
    }
    FORE(it,adj[u]) if (*it!=p) {
        int v=*it;
        int oldState=numChs[v]>0;
        int newState=numChs[v]<m;
        numEdge[v]=numEdge[u]-oldState+newState;
        maximize(farOut[v],farOut[u]+1);
        if (chs[u]) maximize(farOut[v],1);
        maximize(farOut[v],(farIn[v]==bestChild.fi?bestChild.se:bestChild.fi)+2);
        secondDFS(v,u);
    }
}
int chooseNode(int u) {
    return (numEdge[u]*2-max(farIn[u],farOut[u]));
}
void process(void) {
    memset(farIn,-0x3f,sizeof farIn);
    memset(farOut,-0x3f,sizeof farOut);
    firstDFS(1,-1);
    FOR(i,2,n) if (numChs[i]>0) numEdge[1]++;
    secondDFS(1,-1);
    int best=1;
    FOR(i,1,n) if (chooseNode(i)<chooseNode(best)) best=i;
    cout<<best<<endl<<chooseNode(best)<<endl;
}
int main(void) {
    loadTree();
    process();
    return 0;
}