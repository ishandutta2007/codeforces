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

int same[5050][5050];
int mal[5050];
int N,A,B;
string S;

ll dp[5050];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>A>>B>>S;
	
	for(i=1;i<N;i++) {
		x=N-1-i;
		same[x][x+i]=S[x]==S[x+i];
		for(x=N-2-i;x>=0;x--) {
			if(S[x]==S[x+i]) same[x][x+i]=1+same[x+1][x+1+i];
		}
	}
	FOR(y,N) {
		FOR(x,y) mal[y]=max(mal[y],min(same[x][y],y-x));
	}
	
	FOR(x,5050) dp[x]=1LL<<60;
	dp[0]=0;
	FOR(i,N) {
		dp[i+1]=min(dp[i+1],dp[i]+A);
		for(j=1;j<=mal[i];j++) dp[i+j]=min(dp[i+j],dp[i]+B);
	}
	
	cout<<dp[N]<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}