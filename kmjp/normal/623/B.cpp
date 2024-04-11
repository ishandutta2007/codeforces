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
ll A,B;
int V[1010101];
ll ret;
ll dp[1010101][3];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>A>>B;
	FOR(i,N) cin>>V[i];
	ret=A*(N-1);
	
	vector<int> aa={V[0],V[0]-1,V[0]+1,V[N-1],V[N-1]+1,V[N-1]-1};
	set<int> S;
	FORR(r,aa) {
		y=r;
		for(x=2;x*x<=y;x++) while(y%x==0) S.insert(x),y/=x;
		if(y>1) S.insert(y);
	}
	
	FORR(r,S) {
		dp[0][1]=dp[0][2]=1LL<<60;
		FOR(x,N) {
			j=V[x]%r;
			if(j==0) {
				dp[x+1][0]=dp[x][0];
				dp[x+1][2]=min(dp[x][2],dp[x][1]);
			}
			else if(j==1 || j==r-1) {
				dp[x+1][0]=dp[x][0]+B;
				dp[x+1][2]=min(dp[x][2],dp[x][1])+B;
			}
			else {
				dp[x+1][0]=dp[x+1][2]=1LL<<60;
			}
			dp[x+1][1]=min(dp[x][0],dp[x][1])+A;
		}
		
		FOR(x,3) ret=min(ret,dp[N][x]);
	}
	cout<<ret<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}