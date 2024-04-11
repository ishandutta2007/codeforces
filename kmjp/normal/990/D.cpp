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

int N,A,B,C;
int E[1010][1010];
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>A>>B;
	if(A>1 && B>1) return _P("NO\n");
	
	if(A==1 && B==1) {
		if(N==2 || N==3) return _P("NO\n");
		FOR(i,N-1) E[i][i+1]=E[i+1][i]=1;
		
	}
	else {
		C=max(A,B);
		for(y=C-1;y<N-1;y++) E[y][y+1]=E[y+1][y]=1;
		if(A==1) {
			FOR(x,N) FOR(y,N) if(x!=y) E[x][y]^=1;
		}
	}
	_P("YES\n");
	FOR(y,N) {
		FOR(x,N) _P("%d",E[y][x]);
		_P("\n");
	}
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}