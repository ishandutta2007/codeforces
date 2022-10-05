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

double dp[2][1000];
int N,K;

void solve() {
    int i,j,k,l,r,x,y; string s;
    
    cin>>N>>K;
    dp[0][1]=1;
    double ret=0;
    FOR(i,N) {
        int cur=i%2,tar=cur^1;
        ZERO(dp[tar]);
        FOR(j,1000) if(dp[cur][j]>=1e-100) {
            ret+=dp[cur][j]*((j+2)/2.0-1/(j+1.0));
            dp[tar][j]+=dp[cur][j]*(1-1.0/(j+1)/K);
            dp[tar][j+1]+=dp[cur][j]*1.0/(j+1)/K;
        }
    }
    _P("%.12lf\n",ret);
}


int main(int argc,char** argv){
    string s;int i;
    if(argc==1) ios::sync_with_stdio(false);
    FOR(i,argc-1) s+=argv[i+1],s+='\n';
    FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
    solve(); return 0;
}