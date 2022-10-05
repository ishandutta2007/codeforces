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

template<class V> class MaxFlow_dinic {
public:
    struct edge { int to,reve;V cap;};
    static const int MV = 1100;
    vector<edge> E[MV];
    int itr[MV],lev[MV];
    
    void add_edge(int x,int y,V cap) {
        E[x].push_back((edge){y,(int)E[y].size(),cap});
        E[y].push_back((edge){x,(int)E[x].size()-1,0}); // directed
        //E[y].push_back((edge){x,(int)E[x].size()-1,cap}); // undirect
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
    
    int dfs(int from,int to,V cf) {
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

vector<ll> enumdiv(ll n) {
    vector<ll> V;
    for(ll i=2;i*i<=n;i++) {
        if(n%i==0) V.push_back(i);
        while(n%i==0) n/=i;
    }
    if(n>1) V.push_back(n);
    return V;
}

int N,M;
ll A[1020];
int I[1020],J[1020];
ll G[1020];
set<ll> S;

ll dodo(ll val) {
    int i,j;
    MaxFlow_dinic<int> mf;
    FOR(i,N) {
        int n=0;
        ll g=A[i];
        while(g%val==0) n++, g/=val;
        if(i%2==0 && n) mf.add_edge(0,i+10,n);
        if(i%2==1 && n) mf.add_edge(i+10,120,n);
    }
    FOR(i,M) mf.add_edge(I[i]+10,J[i]+10,100);
    return mf.maxflow(0,120);
    
    
}

void solve() {
    int i,j,k,l,r,x,y; string s;
    cin>>N>>M;
    FOR(i,N) cin>>A[i];
    FOR(i,M) {
        cin>>I[i]>>J[i], I[i]--,J[i]--;
        if(I[i]%2) swap(I[i],J[i]);
        G[i]=__gcd(A[I[i]],A[J[i]]);
        vector<ll> V=enumdiv(G[i]);
        ITR(it,V) S.insert(*it);
    }
    
    ll ret=0;
    ITR(it,S) ret += dodo(*it);
    cout<<ret<<endl;
    
    
}


int main(int argc,char** argv){
    string s;int i;
    if(argc==1) ios::sync_with_stdio(false);
    FOR(i,argc-1) s+=argv[i+1],s+='\n';
    FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
    solve(); return 0;
}