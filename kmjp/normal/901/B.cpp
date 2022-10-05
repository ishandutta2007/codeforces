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

int A[160][160];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	A[0][0]=1;
	A[1][1]=-1;
	for(i=2;i<=152;i++) {
		FOR(j,153) {
			if(j) A[i][j]=-A[i-1][j-1];
		}
		int pl=1,mi=1;
		FOR(j,153) {
			if(abs(A[i][j]+A[i-2][j])>=2) pl=0;
			if(abs(A[i][j]-A[i-2][j])>=2) mi=0;
		}
		assert(pl||mi);
		FOR(j,153) {
			if(pl) A[i][j]+=A[i-2][j];
			else A[i][j]-=A[i-2][j];
		}
	}
	
	FOR(i,152) {
		if(A[i][i]<0) {
			FOR(j,152) A[i][j]=-A[i][j];
		}
	}
	
	cin>>N;
	_P("%d\n",N);
	FOR(i,N+1) _P("%d%c",A[N][i],(i==N)?'\n':' ');
	N--;
	_P("%d\n",N);
	FOR(i,N+1) _P("%d%c",A[N][i],(i==N)?'\n':' ');
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}