#include <bits/stdc++.h>

#define re register

#define REP(u) for(re int i=p[u]; i>=0; i=p[ver[i]]) 

using namespace std;

const int mm=1111111;//fff
const int mn=111111;
const int oo=1e9;

int node,src,dest,edge;

int head[mm],qwq[mm],ver[mm],flow[mm],cost[mm],nxt[mm],dist[mm];

int p[mm],q[mm];

inline void prepare(int _n,int _s,int _d) {
    node=_n,src=_s,dest=_d;
    for(re int i=0; i<node; ++i) head[i]=-1,qwq[i]=0;
    edge=0;
}

inline void add(int u,int v,int f,int c) {
    ver[edge]=v,flow[edge]=f,cost[edge]=c,nxt[edge]=head[u],head[u]=edge++;
    ver[edge]=u,flow[edge]=0,cost[edge]=-c,nxt[edge]=head[v],head[v]=edge++;
}

inline bool spfa() {
    int u,v,i,r=0,tmp;
    for(re int i=0; i<node; ++i) dist[i]=oo;
    dist[q[r++]=src]=0;
    p[dest]=p[src]=-1;
    for(re int l=0; l!=r; (++l>=mn)?l=0:l) {
        for(i=head[u=q[l]],qwq[u]=0; i>=0; i=nxt[i]) {
            if(flow[i]&&dist[v=ver[i]]>(tmp=dist[u]+cost[i])) {
                dist[v]=tmp;
                p[v]=i^1;
                if(qwq[v]) continue;
                qwq[q[r++]=v]=1;
                if(r>mn) r=0;
            }
        }
    }
    return (p[dest]>=0);
}

inline int work2() {
    int ret=0,qaq;
    while(spfa()) {
        qaq=oo;
        REP(dest){
            if(flow[i^1]<qaq) qaq=flow[i^1];
        }
        REP(dest){
            flow[i]+=qaq,flow[i^1]-=qaq;
        }
        ret+=qaq*dist[dest];
    }
    return (ret);
}

int a[111][111];
int n,m=0,an,u,v;

inline void init() {
    cin>>n>>m;
	for(int i=1;i<=n;++i)
		for(int j=1;j<=n;++j)
			if(i!=j)
				a[i][j]=2;
    for(re int i=1; i<=m; ++i) {
		scanf("%d %d",&u,&v);
     a[u][v]=1;
		a[v][u]=0;
    }
	for(re int i=1; i<=n; ++i) {
        for(re int j=1; j<=n; ++j) {
            if(i<j&&a[i][j]>1) ++m;
        }
    }
}

inline void print() {
    for(re int i=1; i<=n; ++i) {
        for(re int j=1; j<=n; ++j) {
            cout<<a[i][j];
        }
        cout<<'\n';
    }
}

inline void work1() {
    int k=0;
    prepare(m+n+2,0,m+n+1);
    for(re int i=1; i<=n; ++i) {
        for(re int j=i+1; j<=n; ++j) {
            if(a[i][j]<2) {
                if(a[i][j]) add(src,m+j,1,0);
                else add(src,m+i,1,0);
            } 
            else {
                ++k;
                add(src,k,1,0);
                add(k,m+i,1,0);
                add(k,m+j,1,0);
            }
        }
    }
    for(re int i=1; i<=n; ++i) {
        for(re int j=1; j<=n; ++j) {
            add(m+i,dest,1,j*2-1);
        }
    }
    an=n*(n-1)*(n-2)/3+n*(n-1)/2;
    an=(an-work2())/2;k=0;
    for(re int i=1; i<=n; ++i) {
        for(re int j=i+1; j<=n; ++j) {
            if(a[i][j]>1) {
                for(re int l=head[++k]; l>=0; l=nxt[l]) { 
                    if(!flow[l]) {
                        if(ver[l]-m==i) a[j][i]=1,a[i][j]=0;
                        else a[i][j]=1,a[j][i]=0;
                    }
                }
            }
        }
    }
    print();
    return;
}

int main() {
    init();
    work1();
    return 0;
}