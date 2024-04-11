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

int N,A[101000];


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) cin>>A[i];
	
	if(A[N-1]==1) return _P("NO\n");
	
	if(N>=3) {
		if(A[N-2]==0 && A[N-3]==1) {
			for(i=N-3;i>=0;i--) if(A[i]==0) break;
			if(i<0) return _P("NO\n");
			_P("YES\n");
			
			FOR(j,i) _P("%d->",A[j]);
			_P("(0->(");
			for(i++;i<N-2;i++) _P("%d->",A[i]);
			_P("%d))->%d\n",0,A[N-1]);
			return;
		}
		_P("YES\n");
		
		FOR(i,N-3) _P("%d->",A[i]);
		if(A[N-2]==1) {
			_P("%d->%d->%d\n",A[N-3],A[N-2],A[N-1]);
		}
		else {
			_P("(%d->%d)->%d\n",A[N-3],A[N-2],A[N-1]);
		}
	}
	else if(N==1) {
		return _P("YES\n0\n");
	}
	else if(N==2) {
		if(A[0]==0) return _P("NO\n");
		return _P("YES\n1->0\n");
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}