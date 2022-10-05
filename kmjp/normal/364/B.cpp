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

int N,D;
int C[100];
int DP[500020];

void solve() {
    int f,i,j,k,l,x,y;
    
    cin>>N>>D;
    FOR(i,N) cin>>C[i];
    
    DP[0]=1;
    FOR(i,N) for(x=500000-C[i];x>=0;x--) DP[x+C[i]] |= DP[x];
    
    x=y=0;
    while(1) {
        j=0;
        for(j=0,i=1;i<=D&&(x+i)<=500000;i++) if(DP[x+i]) j=i;
        if(j==0) break;
        x+=j;
        y++;
    }
    
    _P("%d %d\n",x,y);
    
}


int main(int argc,char** argv){
    if(argc>1) freopen(argv[1], "r", stdin);
    solve();
    return 0;
}