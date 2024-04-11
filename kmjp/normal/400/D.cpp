#include <cstdlib>
#include <cstring>
#include <memory>
#include <cstdio>
#include <fstream>
#include <iostream>
#include <cmath>
#include <string>
#include <sstream>
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
#define FILL_INT(a,val) _fill_int((int*)a,val,sizeof(a)/4)
#define MINUS(a) _fill_int((int*)a,-1,sizeof(a)/4)
ll GETi() { ll i;scanf("%lld",&i); return i;}
//-------------------------------------------------------

const int ufmax=1000001;
int ufpar[ufmax],ufrank[ufmax];
void UF_init(){int i; FOR(i,ufmax) { ufpar[i]=i; ufrank[i]=0; } }
int UF_find(int x) {    return (ufpar[x]==x)?(x):(ufpar[x] = UF_find(ufpar[x]));}
void UF_unite(int x,int y) {
    x = UF_find(x); y = UF_find(y);
    if(x==y) return;
    if(ufrank[x]<ufrank[y]) ufpar[x]=y;
    else {ufpar[y]=x; if(ufrank[x]==ufrank[y]) ufrank[x]++;}
}

int N,M,K;
int C[1000],S[1000],E[1000];
int T[100001];
vector<int> SE[100001];
ll mat[501][501];
int vis[100001];


void solve() {
    int f,i,j,k,l,x,y;
    
    cin>>N>>M>>K;
    l=0;
    FOR(i,K) {
        cin>>C[i];
        S[i]=l;
        FOR(j,C[i]) T[l++]=i;
        E[i]=l;
    }
    FOR(x,K) FOR(y,K) mat[x][y]=1LL<<50;
    FOR(x,K) mat[x][x]=0;
    UF_init();
    
    FOR(i,M) {
        cin>>x>>y>>j;
        if(j==0) UF_unite(x-1,y-1);
        if(T[x-1]!=T[y-1]) {
            mat[T[x-1]][T[y-1]] = min(mat[T[x-1]][T[y-1]],(ll)j);
            mat[T[y-1]][T[x-1]] = min(mat[T[y-1]][T[x-1]],(ll)j);
        }
    }
    
    FOR(i,K) {
        for(j=S[i];j<E[i];j++) if(UF_find(j)!=UF_find(S[i])) return _P("No\n");
    }
    
    FOR(j,K) FOR(x,K) FOR(y,K) mat[x][y]=min(mat[x][y],mat[x][j]+mat[j][y]);
    FOR(x,K) FOR(y,K) if(mat[x][y]==1LL<<50) mat[x][y]=-1;
    _P("Yes\n");
    FOR(x,K) {
        FOR(y,K) _P("%lld ",mat[x][y]);
        _P("\n");
    }
    
}


int main(int argc,char** argv){
    string s;
    if(argc==1) ios::sync_with_stdio(false);
    for(int i=1;i<argc;i++) s+=argv[i],s+='\n';
    for(int i=s.size()-1;i>=0;i--) ungetc(s[i],stdin);
    solve();
    return 0;
}