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

int N;
vector<int> V[100500];
ll mo=1000000007;
ll dp[100500][2];

void solve() {
    int i,j,k,l,r,x,y; string s;
    
    cin>>N;
    FOR(i,N-1) cin>>x, V[x-1].push_back(i+1);
    
    for(i=N-1;i>=0;i--) {
        ll alleven=1,odd_even=1,odd_odd=0;
        
        dp[i][0]=0; //even
        dp[i][1]=1; //odd
        FOR(j,V[i].size()) {
            x=V[i][j];
            ll a=dp[i][0],b=dp[i][1];
            dp[i][0]=(a*(1+dp[x][0])+b*dp[x][1])%mo;
            dp[i][1]=(a*dp[x][1]+b*(1+dp[x][0]))%mo;
            alleven=(alleven*(1+dp[x][0]))%mo;
            
            a=odd_even,b=odd_odd;
            odd_even=(a+b*dp[x][1])%mo;
            odd_odd=(b+a*dp[x][1])%mo;
            
        }
        dp[i][0]=(dp[i][0]*2+(mo-odd_odd))%mo;
        dp[i][1]=(dp[i][1]*2+(mo-alleven))%mo;
    }
    
    cout << (dp[0][0]+dp[0][1])%mo << endl;
}


int main(int argc,char** argv){
    string s;int i;
    if(argc==1) ios::sync_with_stdio(false);
    FOR(i,argc-1) s+=argv[i+1],s+='\n';
    FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
    solve(); return 0;
}