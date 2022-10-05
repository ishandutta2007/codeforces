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
    int f,i,j,k,l,x,y;
    int N;
    
    cin>>N;
    
    if(N==5) {
        _P("1 2 2\n");
        _P("1 3 1\n");
        _P("2 4 1\n");
        _P("4 5 1\n");
        _P("3 4\n");
        _P("3 5\n");
        return;
    }
    
    FOR(i,N/2) _P("%d %d %d\n",i+1,i+1+N/2,1);
    for(i=N/2;i<N-1;i++) _P("%d %d %d\n",i+1,i+2,2*(i-(N/2))+1);
    FOR(i,N/2-1) _P("%d %d\n",i+1,i+2);
    _P("1 3\n");
}


int main(int argc,char** argv){
    string s;
    if(argc==1) ios::sync_with_stdio(false);
    for(int i=1;i<argc;i++) s+=argv[i],s+='\n';
    for(int i=s.size()-1;i>=0;i--) ungetc(s[i],stdin);
    solve();
    return 0;
}