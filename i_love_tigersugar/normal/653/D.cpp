#include<bits/stdc++.h>
#define MAX   1111
#define FOR(i,a,b) for (int i=(a),_b=(b);i<=_b;i=i+1)
#define REP(i,n) for (int i=0,_n=(n);i<_n;i=i+1)
using namespace std;
const double eps=1e-8;
template<class X,class Y>
    void minimize(X &x,const Y &y) {
        if (x>y) x=y;
    }
class DinicFlow {
private:
    static const int INF=(int)1e9+7;
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
    void addEdge(int u,int v,int c1,int c2) {
        //printf("Add %d %d %d %d\n",u,v,c1,c2);
        point.push_back(v);capa.push_back(c1);flow.push_back(0);next.push_back(head[u]);head[u]=m++;
        point.push_back(u);capa.push_back(c2);flow.push_back(0);next.push_back(head[v]);head[v]=m++;
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
};
struct Edge {
    int u,v,c;
    Edge() {
        u=v=c=0;
    }
    void input(void) {
        scanf("%d%d%d",&u,&v,&c);
    }
};
Edge edge[MAX];
int n,m,k;
void init(void) {
    scanf("%d%d%d",&n,&m,&k);
    FOR(i,1,m) edge[i].input();
}
bool ok(double x) {
    DinicFlow df(n);
    FOR(i,1,m) {
        double tmp=edge[i].c/x+eps;
        minimize(tmp,1e9);
        df.addEdge(edge[i].u,edge[i].v,(int)tmp,0);
    }
    return (df.maxFlow(1,n)>=k);
}
void process(void) {
    double L=0;
    double R=1e7;
    REP(love,100) {
        double M=(L+R)/2.0;
        if (ok(M)) L=M; else R=M;
    }
    printf("%.11lf\n",k*(L+R)/2.0);
}
int main(void) {
    init();
    process();
    return 0;
}