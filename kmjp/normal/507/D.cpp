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

ll N,K,M;

ll momo[1012];
ll momo2[1012];
ll dp[2][1010][105];
ll ret;


void solve() {
    int i,j,k,l,r,x,y; string s;
    
    cin>>N>>K>>M;
    
    momo[0]=momo2[0]=1;
    FOR(i,N+1) momo[i+1]=momo[i]*10%K;
    FOR(i,N+1) momo2[i+1]=momo2[i]*10%M;
    
    dp[0][0][0]=1;
    FOR(i,N) {
        FOR(k,2) FOR(j,10) {
            FOR(x,K) {
                y=(x+momo[i]*j)%K;
                if(y==0 && (k||j)) {
                    if(i==N-1) {
                        ret+=dp[k][i][x];
                    }
                    else {
                        ret+=9*momo2[N-i-2]*dp[k][i][x];
                    }
                    ret %= M;
                }
                else {
                    if(k || j) (dp[1][i+1][y]+=dp[k][i][x])%=M;
                    else (dp[0][i+1][y]+=dp[k][i][x])%=M;
                }
            }
        }
    }
    
    cout<<ret<<endl;;
}


int main(int argc,char** argv){
    string s;int i;
    if(argc==1) ios::sync_with_stdio(false);
    FOR(i,argc-1) s+=argv[i+1],s+='\n';
    FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
    solve(); return 0;
}