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
int cm[22];
int dp[1<<22];
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	FOR(i,N) cm[i]=1<<i;
	FOR(i,M) {
		cin>>x>>y;
		x--,y--;
		cm[x]|=1<<y;
		cm[y]|=1<<x;
	}
	if(M==N*(N-1)/2) return _P("0\n");
	
	int ret=(1<<N)-1;
	FOR(i,1<<N) dp[i]=-1;
	
	for(int mask=1;mask<1<<N;mask++) {
		if(__builtin_popcount(mask)==1) {
			FOR(i,N) if(mask&(1<<i)) {
				dp[mask]=cm[i];
			}
		}
		if(dp[mask]==-1) continue;
		int mo=0;
		FOR(i,N) if(mask&(1<<i)) mo|=cm[i];
		FOR(i,N) if(mo&(1<<i)) dp[mask|(1<<i)]=dp[mask] | cm[i];
		if(dp[mask]==(1<<N)-1 && __builtin_popcount(mask)<__builtin_popcount(ret)) ret=mask;
	}
	
	cout<<__builtin_popcount(ret)<<endl;
	FOR(i,N) if(ret&(1<<i)) cout<<(i+1)<<" ";
	cout<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}