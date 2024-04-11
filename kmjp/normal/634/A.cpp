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
int A[202020];
int B[202020];
vector<int> R[2];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	
	FOR(i,N) {
		cin>>A[i];
		if(A[i]==1) j=i;
	}
	for(i=j;i<N;i++) if(A[i]) R[0].push_back(A[i]);
	FOR(i,j) if(A[i]) R[0].push_back(A[i]);
	
	FOR(i,N) {
		cin>>B[i];
		if(B[i]==1) j=i;
	}
	for(i=j;i<N;i++) if(B[i]) R[1].push_back(B[i]);
	FOR(i,j) if(B[i]) R[1].push_back(B[i]);
	
	
	
	if(R[0]==R[1]) _P("YES\n");
	else _P("NO\n");
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}