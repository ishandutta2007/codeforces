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

int N;
int C[101010];
string S[101010],T[101010];

ll dp[101010][2];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) cin>>C[i];
	FOR(i,N) {
		cin>>S[i];
		T[i]=S[i];
		reverse(ALL(T[i]));
	}
	
	memset(dp,0x3f,sizeof(dp));
	dp[0][0]=0;
	dp[0][1]=C[0];
	for(i=1;i<N;i++) {
		if(S[i-1]<=S[i]) dp[i][0]=min(dp[i][0],dp[i-1][0]);
		if(S[i-1]<=T[i]) dp[i][1]=min(dp[i][1],dp[i-1][0]+C[i]);
		if(T[i-1]<=S[i]) dp[i][0]=min(dp[i][0],dp[i-1][1]);
		if(T[i-1]<=T[i]) dp[i][1]=min(dp[i][1],dp[i-1][1]+C[i]);
	}
	
	ll mi=min(dp[N-1][0],dp[N-1][1]);
	if(mi>=0x3f3f3f3f3f3f3f3fLL) _P("-1\n");
	else cout<<mi<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}