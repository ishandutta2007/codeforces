#include<cstdio>
#include<vector>
#define MAX   55
#define FOR(i,a,b) for (int i=(a),_b=(b);i<=_b;i=i+1)
#define REP(i,n) for (int i=0,_n=(n);i<_n;i=i+1)
using namespace std;
const int INF=(int)1e9+7;
const int MAXV=(int)11e6;
class DinicFlow {
    private:
    int n,m;
    vector<int> dist,head,q,work;
    vector<int> next,capa,flow,point;
    public:
    DinicFlow() {
        n=0;
    }
    DinicFlow(int n) {
        this->n=n;
        this->m=0;
        dist.assign(n+7,0);
        head.assign(n+7,-1);
        q.assign(n+7,0);
        work.assign(n+7,0);
    }
    void addedge(int u,int v,int c1,int c2) {
        point.push_back(v);capa.push_back(c1);flow.push_back(0);next.push_back(head[u]);head[u]=m++;
        point.push_back(u);capa.push_back(c2);flow.push_back(0);next.push_back(head[v]);head[v]=m++;
    }
    bool bfs(int s,int t) {
        FOR(i,1,n) dist[i]=-1;
        int sz=0;
        q[sz++]=s;
        dist[s]=0;
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
    int maxflow(int s,int t) {
        int totflow=0;
        while (bfs(s,t)) {
            FOR(i,1,n) work[i]=head[i];
            while (true) {
                int d=dfs(s,t,INF);
                if (d==0) break;
                totflow+=d;
            }
        }
        return (totflow);
    }
};
struct var {
    int a,b,c,l,r;
    var() {
        a=b=c=l=r=0;
    }
    int val(int x) const {
        return (a*x*x+b*x+c);
    }
};
inline int nextInt(void) {
    int x;
    scanf("%d",&x);
    return (x);
}
var v[MAX];
DinicFlow DF;
int n,m,s[MAX];
inline int nodeid(int x,int k) {
    return (s[x-1]+k-v[x].l+2);
}
void process(void) {
    n=nextInt();
    m=nextInt();
    FOR(i,1,n) {
        v[i].a=nextInt();
        v[i].b=nextInt();
        v[i].c=nextInt();
    }
    FOR(i,1,n) {
        v[i].l=nextInt();
        v[i].r=nextInt();
        s[i]=s[i-1]+v[i].r-v[i].l+2;
    }
    DF=DinicFlow(s[n]+2);
    int src=s[n]+1;
    int snk=s[n]+2;
    FOR(i,1,n) {
        DF.addedge(src,nodeid(i,v[i].l-1),INF,0);
        DF.addedge(nodeid(i,v[i].r),snk,INF,0);
        FOR(j,v[i].l-1,v[i].r-1) DF.addedge(nodeid(i,j),nodeid(i,j+1),MAXV-v[i].val(j+1),0);
    }
    REP(zz,m) {
        int x=nextInt();
        int y=nextInt();
        int d=nextInt();
        FOR(i,v[x].l-1,v[x].r) {
            int t=i-d;
            if (v[y].l-1<=t && t<=v[y].r) DF.addedge(nodeid(x,i),nodeid(y,t),INF,0);
        }
    }
    printf("%d",MAXV*n-DF.maxflow(src,snk));
}
int main(void) {
    process();
    return 0;
}