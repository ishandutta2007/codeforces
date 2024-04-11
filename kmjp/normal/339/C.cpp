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
void _fill_ll(ll* p,ll val,int rep) {int i; FOR(i,rep) p[i]=val;}
#define MINUS(a) _fill_int((int*)a,-1,sizeof(a)/4)
#define MINUSL(a) _fill_ll((ll*)a,-1LL,sizeof(a)/8)
ll GETi() { ll i;scanf("%lld",&i); return i;}
//-------------------------------------------------------

string S;
int M;
int dp[1001][11];

void solve() {
    int f,i,j,k,l, x,y;
    
    cin>>S>>M;
    for(y=1;y<=10;y++) if(S[y-1]=='1') dp[0][y]=1<<y;
    
    for(i=1;i<M;i++) {
        for(x=1;x<=10;x++) for(y=1;y<=10;y++) {
            if(S[y-1]=='0') continue;
            if(x>=y) continue;
            if((dp[i-1][x] & ~(1<<y)) == 0) continue;
            dp[i][y-x] |= 1<<y;
        }
        //FOR(x,10) _P("%x ",dp[i][x]);
        //_P("\n");
    }
    
    int R[1001];
    FOR(x,11) {
        j=0;
        if(dp[M-1][x]) {
            for(y=M-1;y>=0;y--) {
                //_P("%x %d %d\n",dp[y][x],x,j);
                for(i=1;i<=10;i++) if((y==0 || i!=j) && dp[y][x] & (1<<i)) break;
                //_P("%d ::\n",i);
                R[y]=j=i;
                x=i-x;
            }
            _P("YES\n");
            FOR(i,M) _P("%d ",R[i]);
            _P("\n");
            return;
        }
    }
    _P("NO\n");
    
}


int main(int argc,char** argv){
    if(argc>1) freopen(argv[1], "r", stdin);
    solve();
    return 0;
}