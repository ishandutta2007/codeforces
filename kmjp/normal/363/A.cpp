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

int N,K;

void solve() {
    int f,i,j,k,l,x,y;
    
    cin>>N;
    if(N==0) return _P("O-|-OOOO\n");
    while(N) {
        i=N%10;
        if(i==0) _P("O-|-OOOO\n");
        if(i==1) _P("O-|O-OOO\n");
        if(i==2) _P("O-|OO-OO\n");
        if(i==3) _P("O-|OOO-O\n");
        if(i==4) _P("O-|OOOO-\n");
        if(i==5) _P("-O|-OOOO\n");
        if(i==6) _P("-O|O-OOO\n");
        if(i==7) _P("-O|OO-OO\n");
        if(i==8) _P("-O|OOO-O\n");
        if(i==9) _P("-O|OOOO-\n");
        N/=10;
    }
    
    
}


int main(int argc,char** argv){
    if(argc>1) freopen(argv[1], "r", stdin);
    solve();
    return 0;
}