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

int A[4][4];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	FOR(y,4) FOR(x,4) cin>>A[y][x];
	
	if(A[0][0]&&A[3][3]) return _P("YES\n");
	if(A[0][1]&&A[2][3]) return _P("YES\n");
	if(A[0][2]&&A[1][3]) return _P("YES\n");
	if(A[1][0]&&A[0][3]) return _P("YES\n");
	if(A[1][1]&&A[3][3]) return _P("YES\n");
	if(A[1][2]&&A[2][3]) return _P("YES\n");
	if(A[2][0]&&A[1][3]) return _P("YES\n");
	if(A[2][1]&&A[0][3]) return _P("YES\n");
	if(A[2][2]&&A[3][3]) return _P("YES\n");
	if(A[3][0]&&A[2][3]) return _P("YES\n");
	if(A[3][1]&&A[1][3]) return _P("YES\n");
	if(A[3][2]&&A[0][3]) return _P("YES\n");
	FOR(y,4) {
		if(A[y][0]&&A[y][3]) return _P("YES\n");
		if(A[y][1]&&A[y][3]) return _P("YES\n");
		if(A[y][2]&&A[y][3]) return _P("YES\n");
	}
	_P("NO\n");
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}