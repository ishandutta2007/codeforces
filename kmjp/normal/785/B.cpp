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
int L[2][202020],R[2][202020];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) cin>>L[0][i]>>R[0][i];
	cin>>M;
	int mal=0,mir=1<<30;
	FOR(i,M) {
		cin>>L[1][i]>>R[1][i];
		mal=max(mal,L[1][i]);
		mir=min(mir,R[1][i]);
	}
	
	int ret=0;
	FOR(i,N) {
		if(mir<=L[0][i]) ret=max(ret,L[0][i]-mir);
		if(R[0][i]<=mal) ret=max(ret,mal-R[0][i]);
	}
	mal=0,mir=1<<30;
	FOR(i,N) {
		mal=max(mal,L[0][i]);
		mir=min(mir,R[0][i]);
	}
	FOR(i,M) {
		if(mir<=L[1][i]) ret=max(ret,L[1][i]-mir);
		if(R[1][i]<=mal) ret=max(ret,mal-R[1][i]);
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