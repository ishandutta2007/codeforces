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
int A[3][6];

void solve() {
	int i,j,k,l,r,x,y,z; string s;
	
	cin>>N;
	set<int> S;
	S.insert(0);
	FOR(y,N) FOR(x,6) {
		cin>>A[y][x];
		S.insert(A[y][x]);
	}
	
	FOR(y,6) FOR(x,6) {
		if(N==2) {
			S.insert(A[0][y]*10+A[1][x]);
			S.insert(A[1][y]*10+A[0][x]);
		}
		if(N==3) {
			S.insert(A[0][y]*10+A[1][x]);
			S.insert(A[1][y]*10+A[0][x]);
			S.insert(A[0][y]*10+A[2][x]);
			S.insert(A[2][y]*10+A[0][x]);
			S.insert(A[1][y]*10+A[2][x]);
			S.insert(A[2][y]*10+A[1][x]);
		}
	}
	FOR(y,6) FOR(x,6) FOR(z,6) if(N==3) {
		S.insert(A[0][x]*100+A[1][y]*10+A[2][z]);
		S.insert(A[0][x]*100+A[2][y]*10+A[1][z]);
		S.insert(A[1][x]*100+A[0][y]*10+A[2][z]);
		S.insert(A[1][x]*100+A[2][y]*10+A[0][z]);
		S.insert(A[2][x]*100+A[0][y]*10+A[1][z]);
		S.insert(A[2][x]*100+A[1][y]*10+A[0][z]);
	}
	
	FOR(i,1010) if(S.count(i)==0) return _P("%d\n",i-1);
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}