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
string S;
ll mo=1000000007;
ll dp[2010][2010],sum[2010][2010];

void solve() {
    int f,i,j,k,l,x,y;
    
    cin>>N>>K>>S;
    dp[0][0]=sum[0][0]=1;
    FOR(i,S.size()) {
        FOR(x,K+1) {
            dp[i+1][x] = sum[i][x]*(S[i]-'a')%mo;
            FOR(y,K+1) {
                j=x-(1+y)*(S.size()-i);
                if(j<0 || i-y<0) break;
                dp[i+1][x] = (dp[i+1][x]+dp[i-y][j]*('z'-S[i]))%mo;
            }
            sum[i+1][x]=(sum[i][x]+dp[i+1][x])%mo;
        }
    }
    y=0;
    FOR(i,S.size()+1) y=(y+dp[i][K])%mo;
    _P("%d\n",y);
    
}


int main(int argc,char** argv){
    if(argc>1) freopen(argv[1], "r", stdin);
    solve();
    return 0;
}