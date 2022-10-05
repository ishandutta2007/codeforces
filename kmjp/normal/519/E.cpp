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

int N,M;
vector<int> E[101000];
int num[101000];
int id;
int P[21][100005],D[100005];

int dfs(int cur,int pre) {
    int un=-1,i;
    num[cur]=1;
    FORR(tar,E[cur]) if(tar!=pre) D[tar]=D[cur]+1, P[0][tar]=cur, num[cur] += dfs(tar,cur);
    return num[cur];
}
int getpar(int cur,int up) {
    int i;
    FOR(i,20) if(up&(1<<i)) cur=P[i][cur];
    return cur;
}

int lca(int a,int b) {
    int ret=0,i,aa=a,bb=b;
    if(D[aa]>D[bb]) swap(aa,bb);
    for(i=19;i>=0;i--) if(D[bb]-D[aa]>=1<<i) bb=P[i][bb];
    for(i=19;i>=0;i--) if(P[i][aa]!=P[i][bb]) aa=P[i][aa], bb=P[i][bb];
    return (aa==bb)?aa:P[0][aa];               // vertex
}

void solve() {
    int i,j,k,l,r,x,y; string s;
    
    cin>>N;
    FOR(i,N-1) {
        cin>>x>>y;
        E[x-1].push_back(y-1);
        E[y-1].push_back(x-1);
    }
    dfs(0,-1);
    FOR(i,19) FOR(x,N) P[i+1][x]=P[i][P[i][x]];

    cin>>M;
    while(M--) {
        cin>>x>>y;
        x--,y--;
        if(x==y) {
            cout<<N<<endl;
            continue;
        }
        if(D[x]>D[y]) swap(x,y);
        int lc=lca(x,y);
        int dist=D[x]-D[lc]+D[y]-D[lc];
        if(dist%2) {
            cout<<0<<endl;
            continue;
        }
        int ret;
        if(D[x]==D[y]) ret = N-num[getpar(x,D[x]-D[lc]-1)]-num[getpar(y,D[y]-D[lc]-1)];
        else ret = num[getpar(y,dist/2)]-num[getpar(y,dist/2-1)];
        cout<<ret<<endl;
    }
    
}


int main(int argc,char** argv){
    string s;int i;
    if(argc==1) ios::sync_with_stdio(false);
    FOR(i,argc-1) s+=argv[i+1],s+='\n';
    FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
    solve(); return 0;
}