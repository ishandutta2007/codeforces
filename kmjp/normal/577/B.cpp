#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define FORR(x,arr) for(auto& x:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

int N,M;
int A[1010101];
int dp[2][1010];


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	dp[0][0]=1;
	FOR(i,N) {
		int cur=i%2,tar=cur^1;
		cin>>A[i];
		A[i]%=M;
		if(A[i]==0) return _P("YES\n");
		for(x=0;x<=M;x++) dp[tar][x]=dp[cur][x];
		for(x=0;x<M;x++) if(dp[cur][x]) {
			y=A[i]+x;
			if(y>M) y-=M;
			dp[tar][y]=1;
		}
	}
	if(dp[N%2][M]) cout<<"YES"<<endl;
	else cout<<"NO"<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}