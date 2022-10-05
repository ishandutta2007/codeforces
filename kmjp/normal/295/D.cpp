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

int N,M;
ll mo=1000000007;

ll dp[2002][2002],dp2[2002][2002],dp3[2002][2002],dp4[2002][2002];

void solve() {
    int i,j,k,l,r,x,y,w; string s;
    
    cin>>N>>M;
    
    for(x=2;x<=2000;x++) dp[x][0]=dp2[x][0]=dp3[x][0]=dp4[x][0]=1;
    for(y=1;y<=2000;y++) {
        ll tot=0;
        for(x=2;x<=2000;x++) {
            tot+=dp[x][y-1];
            dp[x][y]=(dp[x-1][y]+tot)%mo; // same row
            dp2[x][y]=(dp[x][y]+mo-dp[x][y-1])%mo; // first shrink
            dp3[x][y]=(dp3[x][y-1]+dp2[x][y])%mo; // sum1
            dp4[x][y]=(dp4[x][y-1]+dp3[x][y])%mo; // sum2
        }
    }
    
    ll ret=0;
    for(w=2;w<=M;w++) {
        ll tmp=0;
        FOR(y,N) tmp+=dp3[w][y]*dp4[w][N-1-y]%mo;
        ret+=tmp*(M+1-w)%mo;
    }
    cout << ret%mo << endl;
}


int main(int argc,char** argv){
    string s;int i;
    if(argc==1) ios::sync_with_stdio(false);
    FOR(i,argc-1) s+=argv[i+1],s+='\n';
    FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
    solve(); return 0;
}