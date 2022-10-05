#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define FORR(x,arr) for(auto& x:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

template<class V> class MaxFlow_dinic {
public:
    struct edge { int to,reve;V cap;};
    static const int MV = 12000;
    vector<edge> E[MV];
    int itr[MV],lev[MV];
    
    void add_edge(int x,int y,V cap,bool undir=false) {
        E[x].push_back((edge){y,(int)E[y].size(),cap});
        E[y].push_back((edge){x,(int)E[x].size()-1,undir?cap:0});
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
        for(;itr[from]<E[from].size();itr[from]++) {
            edge* e=&E[from][itr[from]];
            if(e->cap>0 && lev[from]<lev[e->to]) {
                V f=dfs(e->to,to,min(cf,e->cap));
                if(f>0) {
                    e->cap-=f;
                    E[e->to][e->reve].cap += f;
                    return f;
                }
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

int N,M;
int A[101],B[101],C[101],ma;
int L[101],R[101];

MaxFlow_dinic<ll> mf;

int id(int cur, int val) { return (cur+1)*205+val-(L[cur]-1); }

void solve() {
    int i,j,k,l,r,x,y; string s;
    
    cin>>N>>M;
    FOR(i,N) cin>>A[i]>>B[i]>>C[i];
    FOR(i,N) {
        cin>>L[i]>>R[i];
        mf.add_edge(0,id(i,L[i]-1),1LL<<60);
        mf.add_edge(id(i,R[i]),11000,1LL<<60);
        for(x=L[i];x<=R[i];x++) mf.add_edge(id(i,x-1),id(i,x),(1<<30)-(A[i]*x*x+B[i]*x+C[i]));
    }
    FOR(i,M) {
        cin>>x>>y>>r;
        x--,y--;
        for(j=L[x]-1;j<=R[x];j++) {
            k=j-r;
            if(k>=L[y]-1 && k<=R[y]) mf.add_edge(id(x,j),id(y,k),1LL<<60);
        }
    }
    cout<<((1LL*N)<<30) - mf.maxflow(0,11000)<<endl;
}


int main(int argc,char** argv){
    string s;int i;
    if(argc==1) ios::sync_with_stdio(false);
    FOR(i,argc-1) s+=argv[i+1],s+='\n';
    FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
    solve(); return 0;
}