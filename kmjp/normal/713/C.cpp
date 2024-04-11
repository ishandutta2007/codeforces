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
ll A[3030];
int cand[3030];
ll dp[3030][3030];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) {
		cin>>A[i];
		A[i]-=i;
		cand[i]=A[i];
	}
	sort(cand,cand+N);
	FOR(i,N) dp[0][i]=abs(A[0]-cand[i]);
	
	for(i=1;i<N;i++) FOR(x,N) {
		dp[i][x] = dp[i-1][x] + abs(cand[x]-A[i]);
		if(x) dp[i][x] = min(dp[i][x], dp[i][x-1] - abs(cand[x-1]-A[i]) + abs(cand[x]-A[i]));
	}
	cout<<*min_element(dp[N-1],dp[N-1]+N)<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}