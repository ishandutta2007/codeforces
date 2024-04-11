#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

int N,M;
vector<int> T;
vector<int> QQ[100000];
vector<int> E[100001];
int D[100001];
int Q[100001][3];
int P[20][100001];
int res[100001];

class UF {
    public:
    static const int ufmax=100052;
    int ufpar[ufmax],ufrank[ufmax],ufcnt[ufmax];
    UF() { init();}
    void init(){int i; FOR(i,ufmax) { ufpar[i]=i; ufrank[i]=0; ufcnt[i]=1; } }
    int find(int x) {   return (ufpar[x]==x)?(x):(ufpar[x] = find(ufpar[x]));}
    int operator[](int x) {return find(x);}
    int count(int x) {return ufcnt[x];}
    void unite(int x,int y) {
        x = find(x); y = find(y);
        if(x==y) return;
        if(ufrank[x]<ufrank[y]) ufpar[x]=y, ufcnt[y]+=ufcnt[x];
        else {ufpar[y]=x; ufcnt[x]+=ufcnt[y]; if(ufrank[x]==ufrank[y]) ufrank[x]++;}
    }
};

void dfs(int cur,int d) {
    int i;
    D[cur]=d;
    FOR(i,E[cur].size()) dfs(E[cur][i],d+1);
}

void solve() {
    int i,j,k,l,r,x,y; string s;
    int pa=0;
    
    cin>>N>>M;
    FOR(i,N) P[0][i]=i;
    FOR(i,M) {
        cin>>j>>x;
        Q[i][0]=j;
        Q[i][1]=--x;
        if(j==1 || j==3) cin>>Q[i][2], Q[i][2]--;
        if(j==1) P[0][x]=Q[i][2], E[Q[i][2]].push_back(x);
        if(j==3) QQ[Q[i][2]].push_back(i);
    }
    FOR(x,19) FOR(i,N) P[x+1][i]=P[x][P[x][i]];
    FOR(i,N) if(P[x][i]==i) dfs(i,0);
    
    UF uf;
    int hoge=0;
    FOR(i,M) {
        if(Q[i][0]==1) uf.unite(Q[i][1],Q[i][2]);
        if(Q[i][0]==3)  _P(res[i]?"YES\n":"NO\n");
        if(Q[i][0]==2) {
            FOR(j,QQ[hoge].size()) {
                int v=Q[QQ[hoge][j]][1];
                if(uf[v]!=uf[Q[i][1]]) continue;
                if(D[v]>D[Q[i][1]]) continue;
                
                int cur=Q[i][1];
                y=D[Q[i][1]]-D[v];
                FOR(x,17) if(y&(1<<x)) cur=P[x][cur];
                res[QQ[hoge][j]]=cur==v;
            }
            hoge++;
        }
    }
}


int main(int argc,char** argv){
    string s;int i;
    if(argc==1) ios::sync_with_stdio(false);
    FOR(i,argc-1) s+=argv[i+1],s+='\n';
    FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
    solve(); return 0;
}