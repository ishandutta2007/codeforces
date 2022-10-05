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

int N,L;
int A[1<<18];
int X;
ll dp[19][1<<18];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	while(1<<L < N) L++;
	FOR(i,N) {
		cin>>A[i];
		if(A[i]==-1) X=i;
	}
	FOR(i,X+1) A[i]=0;
	
	FOR(j,L+1) FOR(i,N) dp[j][i]=1LL<<60;
	dp[0][N-1]=A[N-1];
	int num=1;
	for(i=1;i<=L;i++) {
		num+=1<<(L-i);
		ll mi=1LL<<60;
		for(j=N-1;j>=N-num;j--) {
			dp[i][j]=mi+A[j];
			mi=min(mi,dp[i-1][j]);
		}
	}
	cout<<dp[L][0]<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}