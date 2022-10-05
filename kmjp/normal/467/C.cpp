#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

int N,M,K;
ll P[5001],S[5005];
ll dp[5005][5005];

void solve() {
    int i,j,k,l,r,x,y; string s;
    cin>>N>>M>>K;
    FOR(i,N) cin>>P[i];
    FOR(i,N) S[i+1]=S[i]+P[i];
    
    FOR(x,5005) FOR(y,5005) dp[x][y]=-1LL<<50;
    dp[0][K]=0;
    FOR(i,N) FOR(j,K+1) {
        dp[i+1][j]=dp[i][j];
        if(i+1>=M) dp[i+1][j]=max(dp[i+1][j],dp[i+1-M][j+1]+S[i+1]-S[i+1-M]);
    }
    cout <<dp[N][0]<<endl;
    
}


int main(int argc,char** argv){
    string s;int i;
    if(argc==1) ios::sync_with_stdio(false);
    FOR(i,argc-1) s+=argv[i+1],s+='\n';
    FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
    solve(); return 0;
}