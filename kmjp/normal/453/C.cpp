#include <cstdlib>
#include <cstring>
#include <memory>
#include <cstdio>
#include <iostream>
#include <cmath>
#include <string>
#include <stack>
#include <queue>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)

#define FOR(x,to) for(x=0;x<to;x++)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ZERO(a) memset(a,0,sizeof(a))
void _fill_int(int* p,int val,int rep) {int i;  FOR(i,rep) p[i]=val;}
#define MINUS(a) _fill_int((int*)a,-1,sizeof(a)/4)
//-------------------------------------------------------

int N,M;
int P[100001],HP[100001];
vector<int> E[100001];
class UF {
    public:
    static const int ufmax=100002;
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

int vis[100001];
vector<int> V;

int dfs(int cur) {
    int i,r,num=0;
    vis[cur]=1;
    
    V.push_back(cur);
    P[cur]^=1;
    
    FOR(i,E[cur].size()) {
        int tar=E[cur][i];
        if(vis[tar]) continue;
        r=dfs(tar);
        V.push_back(cur);
        P[cur]^=1;
        if(r) {
            V.push_back(tar);
            V.push_back(cur);
            P[cur]^=1;
        }
    }
    return P[cur];
}

void solve() {
    int f,i,j,k,l,x,y;
    UF uf;
    cin>>N>>M;
    FOR(i,M) {
        cin>>x>>y;
        E[x-1].push_back(y-1);
        E[y-1].push_back(x-1);
        uf.unite(x-1,y-1);
    }
    FOR(i,N) cin>>P[i];
    
    FOR(i,N) HP[uf[i]] += P[i];
    x=0,y=-1;
    FOR(i,N) if(HP[i]) x++, y=i;
    if(x==0) return _P("0\n");
    if(x>1) return _P("-1\n");
    
    x=dfs(y);
    if(x) V.erase(V.begin());
    _P("%d\n",V.size());
    FOR(i,V.size()) _P("%d ",V[i]+1);
    _P("\n");
    
}


int main(int argc,char** argv){
    string s;
    if(argc==1) ios::sync_with_stdio(false);
    for(int i=1;i<argc;i++) s+=argv[i],s+='\n';
    for(int i=s.size()-1;i>=0;i--) ungetc(s[i],stdin);
    solve();
    return 0;
}