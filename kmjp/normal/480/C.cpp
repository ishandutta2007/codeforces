#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

ll N,A,B,K;
ll mo=1000000007;
ll dp[5020][5020];

void solve() {
    int i,j,k,l,r,x,y; string s;
    
    cin>>N>>A>>B>>K;
    if(B<A) {
        A=N+1-A;
        B=N+1-B;
    }
    
    for(x=A;x<B;x++) dp[0][x]=1;
    
    FOR(i,K) {
        for(x=1;x<B;x++) {
            int up=x+(B-x-1)/2;
            dp[i+1][x]=dp[i][up]-(dp[i][x]-dp[i][x-1]);
            dp[i+1][x]=(((dp[i+1][x]+dp[i+1][x-1])%mo)+mo)%mo;
        }
    }
    cout << dp[K][B-1] <<endl;
    
}


int main(int argc,char** argv){
    string s;int i;
    if(argc==1) ios::sync_with_stdio(false);
    FOR(i,argc-1) s+=argv[i+1],s+='\n';
    FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
    solve(); return 0;
}