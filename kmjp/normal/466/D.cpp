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

int N,H,A[2001];
ll mo=1000000007;
ll dp[2001][2001];

void solve() {
    int i,j,k,l,r,x,y; string s;
    
    cin>>N>>H;
    FOR(i,N) {
        cin>>A[i];
        if(A[i]>H) return _P("0\n");
        A[i]=H-A[i];
    }
    dp[0][0]=1;
    FOR(x,N) {
        
        dp[x+1][A[x]] += dp[x][A[x]];
        if(A[x]>=1) {
            dp[x+1][A[x]] +=  dp[x][A[x]-1];
            dp[x+1][A[x]-1] = A[x]*(dp[x][A[x]]+dp[x][A[x]-1])%mo;
        }
        dp[x+1][A[x]] %= mo;
    }
    cout << dp[N][0] << endl;
}


int main(int argc,char** argv){
    string s;int i;
    if(argc==1) ios::sync_with_stdio(false);
    FOR(i,argc-1) s+=argv[i+1],s+='\n';
    FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
    solve(); return 0;
}