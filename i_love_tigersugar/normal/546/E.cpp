#include<bits/stdc++.h>
#define MAX   227
#define FOR(i,a,b) for (int i=(a),_b=(b);i<=_b;i=i+1)
#define REP(i,n) for (int i=0,_n=(n);i<_n;i=i+1)
using namespace std;
const int INF=(int)1e9+7;
const char yes[]="YES";
const char no[]="NO";
class DinicFlow {
private:
    vector<int> dist,head,q,work;
    vector<int> point,capa,flow,next;
    int n,m;
public:
    DinicFlow() {
        n=0;m=0;
    }
    DinicFlow(int n) {
        this->n=n;m=0;
        dist.assign(n+7,0);
        head.assign(n+7,-1);
        q.assign(n+7,0);
        work.assign(n+7,0);
    }
    int addEdge(int u,int v,int c1,int c2) {
        //printf("Add %d %d %d %d\n",u,v,c1,c2);
        point.push_back(v);capa.push_back(c1);flow.push_back(0);next.push_back(head[u]);head[u]=m++;
        point.push_back(u);capa.push_back(c2);flow.push_back(0);next.push_back(head[v]);head[v]=m++;
        return (m-2);
    }
    bool bfs(int s,int t) {
        FOR(i,1,n) dist[i]=-1;
        int sz=0;
        q[sz++]=s;dist[s]=0;
        for (int x=0;x<sz;x=x+1) {
            int u=q[x];
            for (int i=head[u];i>=0;i=next[i])
                if (dist[point[i]]<0 && flow[i]<capa[i]) {
                    dist[point[i]]=dist[u]+1;
                    q[sz++]=point[i];
                }
        }
        return (dist[t]>=0);
    }
    int dfs(int s,int t,int f) {
        if (s==t) return (f);
        for (int &i=work[s];i>=0;i=next[i])
            if (dist[point[i]]==dist[s]+1 && flow[i]<capa[i]) {
                int d=dfs(point[i],t,min(f,capa[i]-flow[i]));
                if (d>0) {
                    flow[i]+=d;
                    flow[i^1]-=d;
                    return (d);
                }
            }
        return (0);
    }
    int maxFlow(int s,int t) {
        int totflow=0;
        while (bfs(s,t)) {
            FOR(i,1,n) work[i]=head[i];
            while (true) {
                int d=dfs(s,t,INF);
                if (d<=0) break;
                totflow+=d;
            }
        }
        return (totflow);
    }
    int traceFlow(int id) const {
        return (flow[id]);
    }
};
int a[MAX],b[MAX];
bool adj[MAX][MAX];
int edgeID[MAX][MAX];
int n,m;
void loadGraph(void) {
    scanf("%d%d",&n,&m);
    FOR(i,1,n) scanf("%d",&a[i]);
    FOR(i,1,n) scanf("%d",&b[i]);
    REP(love,m) {
        int u,v;
        scanf("%d%d",&u,&v);
        adj[u][v]=adj[v][u]=true;
    }
    FOR(i,1,n) adj[i][i]=true;
}
void process(void) {
    DinicFlow df(2*n+2);
    int src=2*n+1;
    int snk=2*n+2;
    FOR(i,1,n) df.addEdge(src,i,a[i],0);
    FOR(i,1,n) df.addEdge(n+i,snk,b[i],0);
    FOR(i,1,n) FOR(j,1,n) if (adj[i][j]) edgeID[i][j]=df.addEdge(i,n+j,INF,0);
    int sumA=0;
    int sumB=0;
    FOR(i,1,n) sumA+=a[i];
    FOR(i,1,n) sumB+=b[i];
    int tmp=df.maxFlow(src,snk);
    if (tmp!=sumA || tmp!=sumB) {
        printf("%s\n",no);
        return;
    }
    printf("%s\n",yes);
    FOR(i,1,n) {
        FOR(j,1,n) printf("%d ",adj[i][j]?df.traceFlow(edgeID[i][j]):0);
        printf("\n");
    }
}
int main(void) {
    loadGraph();
    process();
    return 0;
}