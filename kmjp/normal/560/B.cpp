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

int A[3],B[3];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	FOR(i,3) cin>>A[i]>>B[i];
	
	FOR(i,4) {
		if(A[1]<=A[0] && B[1]<=B[0]) {
			if(A[2]<=A[0]-A[1] && B[2]<=B[0]) return _P("YES\n");
			if(A[2]<=A[0] && B[2]<=B[0]-B[1]) return _P("YES\n");
		}
		swap(A[1],B[1]);
		if(i==1) swap(A[2],B[2]);
	}
	_P("NO\n");
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}