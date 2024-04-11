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
int A[303030];
int S[303030];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>K;
	FOR(i,N) {
		cin>>A[i];
		S[i+1]=S[i]+(A[i]==0);
	}
	int ML=0,MR=-1;
	
	for(int L=0,R=-1;L<N;L++) {
		while(R+1<N && S[R+1+1]-S[L]<=K) R++;
		if(R-L>=MR-ML) MR=R,ML=L;
	}
	_P("%d\n",MR-ML+1);
	FOR(i,N) {
		if(ML<=i && i<=MR) _P("1 ");
		else _P("%d ",A[i]);
	}
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}