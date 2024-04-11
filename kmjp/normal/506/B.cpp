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

class SCC {
public:
    static const int MV = 101000;
    vector<vector<int> > SC; int NV,GR[MV];
private:
    vector<int> E[MV], RE[MV], NUM; int vis[MV];
public:
    void init(int NV) { this->NV=NV; for(int i=0;i<MV;i++) { E[i].clear(); RE[i].clear();}}
    void add_edge(int x,int y) { E[x].push_back(y); RE[y].push_back(x); }
    void dfs(int cu) { vis[cu]=1; for(int i=0;i<E[cu].size();i++) if(!vis[E[cu][i]]) dfs(E[cu][i]); NUM.push_back(cu); }
    void revdfs(int cu, int ind) { int i; vis[cu]=1; GR[cu]=ind; SC[ind].push_back(cu);
        FOR(i,RE[cu].size()) if(!vis[RE[cu][i]]) revdfs(RE[cu][i],ind);}
    void scc() {
        int c=0; SC.clear(); SC.resize(MV); NUM.clear();
        ZERO(vis); for(int i=0;i<NV;i++) if(!vis[i]) dfs(i);
        ZERO(vis); for(int i=NUM.size()-1;i>=0;i--) if(!vis[NUM[i]]){
            SC[c].clear(); revdfs(NUM[i],c); sort(SC[c].begin(),SC[c].end()); c++;
        }
        SC.resize(c);
    }
};

class UF {
    public:
    static const int ufmax=100052;
    int ufpar[ufmax],ufrank[ufmax],ufcnt[ufmax];
    UF() { int i; FOR(i,ufmax) { ufpar[i]=i; ufrank[i]=0; ufcnt[i]=1; } }
    int operator[](int x) {return (ufpar[x]==x)?(x):(ufpar[x] = operator[](ufpar[x]));}
    int count(int x) { return ufcnt[operator[](x)];}
    void unite(int x,int y) {
        x = operator[](x); y = operator[](y);
        if(x==y) return;
        if(ufrank[x]<ufrank[y]) ufpar[x]=y, ufcnt[y]+=ufcnt[x];
        else {ufpar[y]=x; ufcnt[x]+=ufcnt[y]; if(ufrank[x]==ufrank[y]) ufrank[x]++;}
    }
};

int N,M;
int A[101000],B[101000],C[101000];
vector<int> E[101000];
SCC sc;
int ret;
UF uf;
void solve() {
    int i,j,k,l,r,x,y; string s;
    
    cin>>N>>M;
    sc.init(N);
    FOR(i,M) {
        cin>>A[i]>>B[i];
        sc.add_edge(A[i]-1,B[i]-1);
        uf.unite(A[i]-1,B[i]-1);
    }
    
    FOR(i,N) if(uf[i]!=i) ret++;
    
    sc.scc();
    FOR(i,sc.SC.size()) {
        if(sc.SC[i].size()>1 && C[uf[sc.SC[i][0]]]==0) {
            ret++;
            C[uf[sc.SC[i][0]]]=1;
        }
    }
    cout<<ret<<endl;
    
    
}


int main(int argc,char** argv){
    string s;int i;
    if(argc==1) ios::sync_with_stdio(false);
    FOR(i,argc-1) s+=argv[i+1],s+='\n';
    FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
    solve(); return 0;
}