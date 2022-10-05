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


void solve() {
    int f,i,j,k,l, x,y,N;
    int X[10000];
    
    cin>>N;
    FOR(i,N) cin>>X[i];
    int ng=0;
    FOR(x,N-1) FOR(y,N-1) {
        if(x==y) continue;
        if(min(X[x],X[x+1])<min(X[y],X[y+1]) && min(X[y],X[y+1])<max(X[x],X[x+1]) 
            && max(X[x],X[x+1])<max(X[y],X[y+1])) ng=1;
    }
    
    if(ng) _P("yes\n");
    else _P("no\n");
    
}


int main(int argc,char** argv){
    if(argc>1) freopen(argv[1], "r", stdin);
    solve();
    return 0;
}