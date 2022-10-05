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
int A[101010];
int A4,A2,A1;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>K;
	A4=N;
	A2=2*N;
	int tot=0;
	
	FOR(i,K) {
		cin>>A[i];
		x = min(A[i]/4,A4);
		A[i] -= 4*x;
		A4-=x;
	}
	A2+=A4;
	A1+=A4;
	FOR(i,K) {
		x = min(A[i]/2,A2);
		A[i] -= 2*x;
		A2-=x;
	}
	A1+=A2;
	FOR(i,K) {
		x = min(A[i],A1);
		A[i] -= x;
		A1-=x;
	}
	FOR(i,K) if(A[i]) return _P("NO\n");
	_P("YES\n");
	
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}