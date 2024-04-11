#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

int N,M;
ll mo=1000000007;
ll dp[1010101];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	dp[0]=1;
	ll M1=1;
	ll M2=0;
	for(i=1;i<=N;i++) {
		dp[i]=(dp[i-1]+M1+M2*(M-1))%mo;
		(M1*=(M-1))%=mo;
		(M2*=(M-1))%=mo;
		(M1+=mo+dp[i]-dp[i-1])%=mo;
		(M2+=mo+dp[i]-dp[i-1])%=mo;
		(dp[i]*=M)%=mo;
	}
	cout<<dp[N]<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}