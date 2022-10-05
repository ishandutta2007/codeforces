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

int dp[2][11][31];

void solve() {
    int i,j,k,l,r,x,y; string s,t;
    
    cin>>s>>t;
    dp[0][0][15]=dp[1][0][15]=1;
    FOR(i,s.size()) {
        for(x=1;x<=29;x++) {
            if(s[i]=='+') dp[0][i+1][x+1]+=dp[0][i][x]*2;
            if(s[i]=='-') dp[0][i+1][x-1]+=dp[0][i][x]*2;
            if(s[i]=='?') dp[0][i+1][x+1]+=dp[0][i][x], dp[0][i+1][x-1]+=dp[0][i][x];
            if(t[i]=='+') dp[1][i+1][x+1]+=dp[1][i][x]*2;
            if(t[i]=='-') dp[1][i+1][x-1]+=dp[1][i][x]*2;
            if(t[i]=='?') dp[1][i+1][x+1]+=dp[1][i][x], dp[1][i+1][x-1]+=dp[1][i][x];
        }
    }
    int tot=0;
    for(x=1;x<=29;x++) tot+=dp[0][s.size()][x]*dp[1][s.size()][x];
    _P("%.9lf\n",tot*1.0/(1<<(2*s.size())));
    
}


int main(int argc,char** argv){
    string s;int i;
    if(argc==1) ios::sync_with_stdio(false);
    FOR(i,argc-1) s+=argv[i+1],s+='\n';
    FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
    solve(); return 0;
}