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

int M,N;
int T[500001][6];
ll TT[500001][6];

void solve() {
    int f,i,j,k,l,x,y;
    cin>>M>>N;
    FOR(y,M) FOR(x,N) cin>>T[y][x];
    
    FOR(y,M) {
        FOR(x,N) {
            TT[y][x]=max(TT[y][x],((x>0)?TT[y][x-1]:0)+(ll)T[y][x]);
            TT[y][x]=max(TT[y][x],((y>0)?TT[y-1][x]:0)+(ll)T[y][x]);
        }
        _P("%lld ",TT[y][N-1]);
    }
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