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


void solve() {
    int i,j,k,l,r,x,y; string s;
    
    int N,dp[5010];
    ll A[5010];
    
    cin>>N;
    int ret=N;
    FOR(x,N) {
        cin>>A[x];
        dp[x]=x;
        ll X=A[x];
        for(y=x-1;y>=0;y--) {
            if(X%2==0 && (A[y]%X)==X/2) dp[x]=min(dp[x],dp[y]+x-y-1);
            if(X%2==1 && (A[y]%X)==0) dp[x]=min(dp[x],dp[y]+x-y-1);
            if(X%2==0) X>>=1;
        }
        ret=min(ret,dp[x]+(N-(x+1)));
    }
    cout << ret << endl;
}


int main(int argc,char** argv){
    string s;int i;
    if(argc==1) ios::sync_with_stdio(false);
    FOR(i,argc-1) s+=argv[i+1],s+='\n';
    FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
    solve(); return 0;
}