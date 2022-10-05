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

string S[8];

void solve() {
    int f,i,j,k,l,x,y,jj,xx[2],yy[2];
    cin>>f;
    FOR(jj,f) {
        FOR(x,8) cin>>S[x];
        xx[0]=yy[0]=-1;
        FOR(y,8) FOR(x,8) {
            if(S[y][x]=='K') {
                if(xx[0]==-1) xx[0]=x,yy[0]=y;
                else xx[1]=x,yy[1]=y;
            }
        }
        
        if(abs(xx[0]-xx[1])%4 || abs(yy[0]-yy[1])%4) _P("NO\n");
        else _P("YES\n");
    }
}


int main(int argc,char** argv){
    if(argc>1) freopen(argv[1], "r", stdin);
    solve();
    return 0;
}