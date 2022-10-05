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

int N,K,D;
ll mo=1000000007;
ll dp[102][101][2];

void solve() {
    int f,i,j,k,l,x,y;
    cin>>N>>K>>D;
    ZERO(dp);
    dp[0][0][0]=1;
    FOR(i,N+1) {
        FOR(j,101) {
            for(x=1;x<=K;x++) {
                if(j+x>N) continue;
                if(x>=D) {
                    dp[i+1][j+x][1]+=dp[i][j][0]+dp[i][j][1];
                    dp[i+1][j+x][1] %= mo;
                }
                else {
                    dp[i+1][j+x][0]+=dp[i][j][0];
                    dp[i+1][j+x][0] %= mo;
                    dp[i+1][j+x][1]+=dp[i][j][1];
                    dp[i+1][j+x][1] %= mo;
                }
            }
        }
    }
    ll ret=0;
    FOR(i,101) ret+=dp[i][N][1];
    cout << ret % mo << endl;
}


int main(int argc,char** argv){
    string s;
    if(argc==1) ios::sync_with_stdio(false);
    for(int i=1;i<argc;i++) s+=argv[i],s+='\n';
    for(int i=s.size()-1;i>=0;i--) ungetc(s[i],stdin);
    solve();
    return 0;
}