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

ll N,L;
string S;

ll dp[1010];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>S;
	L=S.size();
	
	FOR(i,L+5) dp[i]=1LL<<60;
	
	dp[0]=0;
	FOR(i,L) if(dp[i]<1LL<<60) {
		ll a=0;
		for(x=i;x<L;x++) {
			a=a*10+S[x]-'0';
			if(a>=N) break;
			if(dp[i]*N/N == dp[i]) dp[x+1]=min(dp[x+1],dp[i]*N+a);
			if(S[i]=='0') break;
		}
	}
	cout<<dp[L]<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}