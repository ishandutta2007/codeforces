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

int N,K;
vector<int> E[100100];
int P[21][100005],D[100005];
int L[100005],id;
ll cost;
map<int,int> M;

int lca(int a,int b) {
    int ret=0,i,aa=a,bb=b;
    if(D[aa]>D[bb]) swap(aa,bb);
    for(i=19;i>=0;i--) if(D[bb]-D[aa]>=1<<i) bb=P[i][bb];
    for(i=19;i>=0;i--) if(P[i][aa]!=P[i][bb]) aa=P[i][aa], bb=P[i][bb];
    return (aa==bb)?aa:P[0][aa];               // vertex
}

void dfs(int cur) {
    L[cur]=id++;
    ITR(it,E[cur]) if(*it!=P[0][cur]) D[*it]=D[cur]+1, P[0][*it]=cur, dfs(*it);
}

int add(int v) {
    if(M.empty()) return 1;
    
    map<int,int>::iterator l=M.lower_bound(L[v]);
    map<int,int>::iterator r=l--;
    if(r==M.begin() || r==M.end()) l=M.begin(),r=M.end(),r--;
    return D[v]-D[lca(l->second,v)]-D[lca(r->second,v)]+D[lca(l->second,r->second)];
}


void solve() {
    int i,j,k,l,r,x,y; string s;
    
    cin>>N>>K;
    FOR(i,N-1) {
        cin>>x>>y;
        E[x-1].push_back(y-1);
        E[y-1].push_back(x-1);
    }
    FOR(i,N) sort(E[i].begin(),E[i].end());
    dfs(0);
    FOR(i,19) FOR(x,N) P[i+1][x]=P[i][P[i][x]];
    
    int ma=1;
    y=0;
    M[L[0]]=0;
    cost=1;
    FOR(x,N) {
        while(y<N && cost<=K) cost+=add(++y),M[L[y]]=y;
        ma=max(ma,y-x);
        M.erase(L[x]);
        cost-=add(x);
    }
    
    cout<<ma<<endl;
    
    
}


int main(int argc,char** argv){
    string s;int i;
    if(argc==1) ios::sync_with_stdio(false);
    FOR(i,argc-1) s+=argv[i+1],s+='\n';
    FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
    solve(); return 0;
}