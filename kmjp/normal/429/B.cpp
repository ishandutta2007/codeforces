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

int N,M;
int A[1001][1001];
ll dp[4][1001][1001];

void solve() {
    int f,i,j,k,l,x,y;
    
    cin>>N>>M;
    FOR(y,N) FOR(x,M) cin>>A[y][x];
    
    FOR(y,N) FOR(x,M) { // dr
        dp[0][y][x]=max((y>0)?dp[0][y-1][x]:0,(x>0)?dp[0][y][x-1]:0)+A[y][x];
    }
    for(y=N-1;y>=0;y--) for(x=M-1;x>=0;x--) { //ul
        dp[1][y][x]=max((y<N-1)?dp[1][y+1][x]:0,(x<M-1)?dp[1][y][x+1]:0)+A[y][x];
    }
    for(y=N-1;y>=0;y--) FOR(x,M) { //ur
        dp[2][y][x]=max((y<N-1)?dp[2][y+1][x]:0,(x>0)?dp[2][y][x-1]:0)+A[y][x];
    }
    FOR(y,N) for(x=M-1;x>=0;x--) { //dl
        dp[3][y][x]=max((y>0)?dp[3][y-1][x]:0,(x<M-1)?dp[3][y][x+1]:0)+A[y][x];
    }
    
    ll ma=0;
    for(y=1;y<N-1;y++) for(x=1;x<M-1;x++) {
        ma=max(ma,dp[0][y][x-1]+dp[1][y][x+1]+dp[2][y+1][x]+dp[3][y-1][x]);
        ma=max(ma,dp[0][y-1][x]+dp[1][y+1][x]+dp[2][y][x-1]+dp[3][y][x+1]);
    }
    cout << ma << endl;
    
}


int main(int argc,char** argv){
    string s;
    if(argc==1) ios::sync_with_stdio(false);
    for(int i=1;i<argc;i++) s+=argv[i],s+='\n';
    for(int i=s.size()-1;i>=0;i--) ungetc(s[i],stdin);
    solve();
    return 0;
}