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

int N,K;
ll A[303030];
ll dp[5050][5050];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>K;
	FOR(i,N) cin>>A[i];
	sort(A,A+N);
	
	int step=N/K;
	int large=N%K,small=K-large;
	memset(dp,0x7f,sizeof(dp));
	dp[0][0]=0;
	FOR(x,large+1) FOR(y,small+1) {
		int pos=x*(step+1)+y*step;
		if(x<large) dp[x+1][y]=min(dp[x+1][y],dp[x][y]+A[pos+step]-A[pos]);
		if(y<small) dp[x][y+1]=min(dp[x][y+1],dp[x][y]+A[pos+step-1]-A[pos]);
	}
	cout<<dp[large][small]<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}