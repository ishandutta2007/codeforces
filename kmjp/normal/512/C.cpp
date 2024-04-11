#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

int N;
int A[1010];

const int prime_max = 100000;
int NP,prime[100000],divp[prime_max];

void cprime() {
    for(int i=2;i<prime_max;i++) if(divp[i]==0) {
        prime[NP++]=i;
        for(int j=i;j<prime_max;j+=i) divp[j]=i;
    }
}

template<class V> class MaxFlow_dinic {
public:
    struct edge { int to,reve;V cap;};
    static const int MV = 1100;
    vector<edge> E[MV];
    int itr[MV],lev[MV];
    
    void add_edge(int x,int y,V cap) {
        E[x].push_back((edge){y,(int)E[y].size(),cap});
        E[y].push_back((edge){x,(int)E[x].size()-1,0}); // directed
    }
    
    void bfs(int cur) {
        MINUS(lev);
        queue<int> q;
        lev[cur]=0;
        q.push(cur);
        while(q.size()) {
            int v=q.front(); q.pop();
            ITR(e,E[v]) if(e->cap>0 && lev[e->to]<0) lev[e->to]=lev[v]+1, q.push(e->to);
        }
    }
    
    V dfs(int from,int to,V cf) {
        if(from==to) return cf;
        ITR(e,E[from]) if(e->cap>0 && lev[from]<lev[e->to]) {
            V f=dfs(e->to,to,min(cf,e->cap));
            if(f>0) {
                e->cap-=f;
                E[e->to][e->reve].cap += f;
                return f;
            }
        }
        return 0;
    }
    
    V maxflow(int from, int to) {
        V fl=0,tf;
        while(1) {
            bfs(from);
            if(lev[to]<0) return fl;
            ZERO(itr);
            while((tf=dfs(from,to,numeric_limits<V>::max()))>0) fl+=tf;
        }
    }
};

vector<int> EE[201];
vector<vector<int> > V;
int vis[201];

vector<int> dfs(int cur,int pre) {
    vector<int> v;
    vis[cur]=1;
    
    if(EE[cur][0]!=pre && vis[EE[cur][0]]==0) v=dfs(EE[cur][0],cur);
    else if(EE[cur][1]!=pre && vis[EE[cur][1]]==0) v=dfs(EE[cur][1],cur);
    
    v.push_back(cur);
    return v;
}

void solve() {
    int i,j,k,l,r,x,y; string s;
    
    cprime();
    cin>>N;
    FOR(i,N) cin>>A[i];
    
    MaxFlow_dinic<int> mf;
    FOR(x,N) {
        if(A[x]%2) mf.add_edge(0,1+x,2);
        if(A[x]%2==0) mf.add_edge(1+x,300,2);
    }
    FOR(x,N) FOR(y,N) if(A[x]%2 && divp[A[x]+A[y]]==A[x]+A[y]) mf.add_edge(1+x,1+y,1);
    if(mf.maxflow(0,300)!=N) return _P("Impossible\n");
    
    FOR(x,N) if(A[x]%2) {
        FOR(y,mf.E[1+x].size()) {
            int to=mf.E[1+x][y].to-1;
            if(mf.E[1+x][y].cap==0 && divp[A[x]+A[to]]==A[x]+A[to]) {
                EE[x].push_back(to);
                EE[to].push_back(x);
            }
        }
    }
    FOR(x,N) if(vis[x]==0) V.push_back(dfs(x,-1));
    
    _P("%d\n",V.size());
    FOR(i,V.size()) {
        _P("%d",V[i].size());
        FOR(j,V[i].size()) _P(" %d",V[i][j]+1);
        _P("\n");
    }
}


int main(int argc,char** argv){
    string s;int i;
    if(argc==1) ios::sync_with_stdio(false);
    FOR(i,argc-1) s+=argv[i+1],s+='\n';
    FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
    solve(); return 0;
}