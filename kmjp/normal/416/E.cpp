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

int N,M;
ll mat[501][501];
ll mat2[501][501];
ll use[501][501];
ll tot[501][501];
void solve() {
    int f,i,j,k,l,x,y,x2,y2;
    
    cin>>N>>M;
    FOR(x,N) FOR(y,N) mat[x][y]=2000000;
    FOR(x,N) mat[x][x]=0;
    FOR(i,M) {
        cin>>x>>y>>l;
        mat[x-1][y-1]=mat[y-1][x-1]=l;
    }
    
    FOR(x,N) FOR(y,N) mat2[x][y]=mat[x][y];
    FOR(l,N) FOR(x,N) FOR(y,N) mat2[x][y]=min(mat2[x][y],mat2[x][l]+mat2[l][y]);
    
    FOR(x,N) FOR(y,N) FOR(l,N) 
        use[x][y] += (x!=y && l!=x && mat[x][l]==mat2[x][l] && mat2[x][l]+mat2[l][y]==mat2[x][y] && mat2[y][x]<2000000);
        
    FOR(x,N) for(y=x+1;y<N;y++) FOR(l,N) if(l!=y && mat2[x][l]+mat2[l][y]==mat2[x][y] && mat2[y][x]<2000000) tot[x][y]+=use[l][y];
    
    FOR(x,N) for(y=x+1;y<N;y++) _P("%lld ",tot[x][y]);
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