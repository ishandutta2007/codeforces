#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define FORR(x,arr) for(auto& x:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

int N,M,B;
ll V;
int A[1010],Z;

ll dp[510][510];

void solve() {
    int i,j,k,l,r,x,y; string s;
    
    cin>>N>>M>>B>>V;
    FOR(i,N) cin>>A[i];
    
    int m,b;
    dp[M][B]=1;
    FOR(i,N) {
        for(m=M;m>=1;m--) {
            for(b=B;b>=A[i];b--) if(dp[m][b]) {
                dp[m-1][b-A[i]] += dp[m][b];
                if(dp[m-1][b-A[i]]>=V) dp[m-1][b-A[i]]-=V;
            }
        }
    }
    
    ll ret=0;
    FOR(b,B+1) ret+=dp[0][b];
    cout<<ret%V<<endl;
    
}


int main(int argc,char** argv){
    string s;int i;
    if(argc==1) ios::sync_with_stdio(false);
    FOR(i,argc-1) s+=argv[i+1],s+='\n';
    FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
    solve(); return 0;
}