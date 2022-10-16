#include<bits/stdc++.h>
#define MAX   227
#define MAXV   100100
#define FOR(i,a,b) for (int i=(a),_b=(b);i<=_b;i=i+1)
#define REP(i,n) for (int i=0,_n=(n);i<_n;i=i+1)
#define FORE(i,v) for (__typeof((v).begin()) i=(v).begin();i!=(v).end();i++)
using namespace std;
const char imp[]="Impossible";
const int INF=(int)1e9+7;
int edgeID[MAX][MAX];
vector<int> dist,head,q,work;
vector<int> point,capa,flow,next;
int n,m;
int a[MAX];
bool notPrime[MAXV];
bool vst[MAX];
void eratosthene(void) {
    REP(i,2) notPrime[i]=true;
    FOR(i,2,MAXV-1) if (!notPrime[i])
        for (int j=2*i;j<MAXV;j=j+i) notPrime[j]=true;
}
void noAnswer(void) {
    printf("%s\n",imp);
    exit(0);
}
void init(void) {
    scanf("%d",&n);
    FOR(i,1,n) scanf("%d",&a[i]);
    int cnt=0;
    FOR(i,1,n) if (a[i]%2==0) cnt++; else cnt--;
    if (cnt!=0) noAnswer();
}
int addEdge(int u,int v,int c) {
    int res=capa.size();
    point.push_back(v);capa.push_back(c);flow.push_back(0);next.push_back(head[u]);head[u]=m++;
    point.push_back(u);capa.push_back(0);flow.push_back(0);next.push_back(head[v]);head[v]=m++;
    return (res);
}
bool bfs(int s,int t) {
    FOR(i,1,n+2) dist[i]=-1;
    dist[s]=0;
    int sz=0;
    q[sz++]=s;
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
    int totFlow=0;
    while (bfs(s,t)) {
        FOR(i,1,n+2) work[i]=head[i];
        //int tmp=totFlow;
        while (true) {
            int d=dfs(s,t,INF);
            if (d==0) break;
            totFlow+=d;
        }
    }
    return (totFlow);
}
vector<int> findCycle(int s) {
    vector<int> res(1,s);
    int u=s;
    while (true) {
        vst[u]=true;
        bool cont=false;
        FOR(i,1,n) if (!notPrime[a[u]+a[i]] && !vst[i] && flow[edgeID[u][i]]>0) {
            res.push_back(i);
            u=i;
            cont=true;
            break;
        }
        if (!cont) break;
    }
    return (res);
}
void process(void) {
    dist.assign(n+7,0);
    head.assign(n+7,-1);
    q.assign(n+7,0);
    work.assign(n+7,0);
    int src=n+1;
    int snk=n+2;
    FOR(i,1,n) if (a[i]%2==0) addEdge(src,i,2);
    FOR(i,1,n) if (a[i]%2==1) addEdge(i,snk,2);
    FOR(i,1,n) FOR(j,1,n) if (a[i]%2==0 && a[j]%2==1 && !notPrime[a[i]+a[j]])
        edgeID[i][j]=edgeID[j][i]=addEdge(i,j,1);
    if (maxFlow(src,snk)<n) noAnswer();
    cerr<<"YES"<<endl;
    vector<vector<int> > allCyc;
    FOR(i,1,n) if (!vst[i]) allCyc.push_back(findCycle(i));
    printf("%d\n",(int)allCyc.size());
    FORE(it,allCyc) {
        printf("%d",(int)it->size());
        FORE(jt,*it) printf(" %d",*jt);
        printf("\n");
    }
}
int main(void) {
#ifdef SKY
    freopen("tmp.txt","r",stdin);
#endif // SKY
    eratosthene();
    init();
    process();
    return 0;
}