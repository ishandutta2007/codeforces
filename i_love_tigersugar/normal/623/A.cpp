#include<bits/stdc++.h>
#define MAX   555
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
const char yes[]="Yes";
const char no[]="No";
vector<int> adj[MAX];
char res[MAX];
bool haveEdge[MAX][MAX];
bool vst[MAX];
int n,m;
void loadGraph(void) {
    scanf("%d%d",&n,&m);
    REP(love,m) {
        int u,v;
        scanf("%d%d",&u,&v);
        adj[u].push_back(v);
        adj[v].push_back(u);
        haveEdge[u][v]=haveEdge[v][u]=true;
    }
}
void bfs(int s) {
    queue<int> q;
    q.push(s);
    vst[s]=true;
    res[s]='a';
    while (!q.empty()) {
        int u=q.front();q.pop();
        FOR(v,1,n) if (adj[v].size()!=n-1 && !vst[v] && !haveEdge[u][v]) {
            vst[v]=true;
            res[v]='a'^'c'^res[u];
            q.push(v);
        }
    }
}
void process(void) {
    FOR(i,1,n) if (adj[i].size()==n-1) res[i]='b';
    FOR(i,1,n) if (adj[i].size()!=n-1 && !vst[i]) bfs(i);
    FOR(i,1,n) FOR(j,1,n) if (i!=j) {
        bool exp=res[i]==res[j] || res[i]=='b' || res[j]=='b';
        bool tmp=haveEdge[i][j];
        if (exp!=tmp) {
            printf("%s\n",no);
            return;
        }
    }
    printf("%s\n",yes);
    FOR(i,1,n) printf("%c", res[i]); printf("\n");
}
int main(void) {
    loadGraph();
    process();
    return 0;
}