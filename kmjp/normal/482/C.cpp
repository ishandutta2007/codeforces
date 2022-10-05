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

int N,M;
string S[55];
ll same[1<<20];
double dp[1<<20];

void solve() {
    int i,j,k,l,r,x,y; string s;
    
    cin>>N;
    FOR(i,N) cin>>S[i];
    M=S[0].size();
    
    FOR(x,N) FOR(y,N) if(x!=y) {
        k=0;
        FOR(i,M) if(S[x][i]==S[y][i]) k|=1<<i;
        same[k] |= 1LL<<x;
    }
    
    for(int mask=(1<<M)-2;mask>=0;mask--) {
        FOR(y,M) if((mask & (1<<y))==0) {
            dp[mask]+=dp[mask|(1<<y)];
            same[mask] |= same[mask|(1<<y)];
        }
        dp[mask] = dp[mask]*1.0/(M-__builtin_popcount(mask)) + __builtin_popcountll(same[mask])*1.0/N;
    }
    _P("%.12lf\n",dp[0]);
}


int main(int argc,char** argv){
    string s;int i;
    if(argc==1) ios::sync_with_stdio(false);
    FOR(i,argc-1) s+=argv[i+1],s+='\n';
    FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
    solve(); return 0;
}