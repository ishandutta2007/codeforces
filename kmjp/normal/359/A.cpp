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

int H,W;
int mat[51][51];

void solve() {
    int f,i,j,k,l, x,y,N;
    
    cin>>H>>W;
    FOR(y,H) FOR(x,W) cin>>mat[y][x];
    FOR(y,H) if(mat[y][0]) return _P("2\n");
    FOR(y,H) if(mat[y][W-1]) return _P("2\n");
    FOR(x,W) if(mat[0][x]) return _P("2\n");
    FOR(x,W) if(mat[H-1][x]) return _P("2\n");
    FOR(y,H) FOR(x,W) if(mat[y][x]) return _P("4\n");
    
}


int main(int argc,char** argv){
    if(argc>1) freopen(argv[1], "r", stdin);
    solve();
    return 0;
}