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

int N,T;
double P;
double dp[2020][2020];

void solve() {
    int i,j,k,l,r,x,y; string s;
    cin>>N>>P>>T;
    
    dp[0][0]=1;
    FOR(i,T) {
        FOR(x,N) {
            dp[i+1][x+1]+=dp[i][x]*P;
            dp[i+1][x]+=dp[i][x]*(1-P);
        }
        dp[i+1][N]+=dp[i][N];
    }
    
    double ret=0;
    FOR(i,N+1) ret += dp[T][i]*i;
    _P("%.12lf\n",ret);
    
}


int main(int argc,char** argv){
    string s;int i;
    if(argc==1) ios::sync_with_stdio(false);
    FOR(i,argc-1) s+=argv[i+1],s+='\n';
    FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
    solve(); return 0;
}