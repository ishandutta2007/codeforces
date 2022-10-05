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

int mat[51][51];
int ok[51],vis[51];
int N,M;
void solve() {
    int f,i,j,k,l,x,y;
    cin>>N>>M;
    FOR(i,M) cin>>x>>y, mat[x-1][y-1]=mat[y-1][x-1]=1;
    
    ll ret=1;
    FOR(i,N) {
        x=-1;
        FOR(j,N) if(vis[j]==0 && (x==-1 || ok[x]<ok[j])) x=j;
        vis[x]=1;
        if(ok[x]) ret*=2;
        FOR(j,N) if(mat[x][j]) ok[j]=1;
    }
    cout << ret << endl;
}


int main(int argc,char** argv){
    string s;
    if(argc==1) ios::sync_with_stdio(false);
    for(int i=1;i<argc;i++) s+=argv[i],s+='\n';
    for(int i=s.size()-1;i>=0;i--) ungetc(s[i],stdin);
    solve();
    return 0;
}