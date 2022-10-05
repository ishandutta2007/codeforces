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

int N,K;
double P[30];
double dp[1<<20];
double R[30];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>K;
	FOR(i,N) cin>>P[i];
	
	dp[0]=1;
	for(int mask=0;mask<1<<N;mask++) if(dp[mask]) {
		int ng=0;
		double el=1;
		FOR(i,N) if(mask&(1<<i)) el -= P[i];
		if(el<1e-9 || __builtin_popcount(mask)==K) {
			FOR(i,N) if(mask&(1<<i)) R[i]+=dp[mask];
		}
		else {
			FOR(i,N) if((mask&(1<<i))==0) dp[mask|(1<<i)] += dp[mask] * P[i]/el;
		}
		
	}
	
	FOR(i,N) _P("%.12lf%c",R[i],(i==N-1)?'\n':' ');
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}