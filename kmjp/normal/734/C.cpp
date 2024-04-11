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

int N,M,K;
ll X,S;
ll A[202020],B[202020];
ll C[202020],D[202020];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M>>K;
	cin>>X>>S;
	A[0]=X;
	B[0]=0;
	FOR(i,M) cin>>A[i+1];
	FOR(i,M) cin>>B[i+1];
	M++;
	FOR(i,K) cin>>C[i];
	FOR(i,K) cin>>D[i];
	
	ll ret=N*X;
	FOR(i,M) {
		ll left=S-B[i];
		if(left<0) continue;
		
		x = (lower_bound(D,D+K,left+1)-D)-1;
		if(x<0) ret=min(ret,(N*A[i]));
		else ret=min(ret,(N-C[x])*A[i]);
	}
	
	cout<<ret<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}