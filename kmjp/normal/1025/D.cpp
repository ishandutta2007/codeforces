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
ll A[707];
int ok[707][707];

int LP[707][707];
int RP[707][707];


int dfsR(int L,int R);
int dfsL(int L,int R);

int dfsL(int L,int R) {
	if(LP[L][R]>=0) return LP[L][R];
	
	if(L+1==R) return LP[L][R]=1;
	
	int i;
	for(i=L+1;i<=R-1;i++) if(ok[L][i]) {
		if(dfsR(L,i)&&dfsL(i,R)) return LP[L][R]=1;
	}
	
	return LP[L][R]=0;
}
int dfsR(int L,int R) {
	if(RP[L][R]>=0) return RP[L][R];
	
	if(L+1==R) return RP[L][R]=1;
	
	int i;
	for(i=L+1;i<=R-1;i++) if(ok[i][R]) {
		if(dfsR(L,i)&&dfsL(i,R)) return RP[L][R]=1;
	}
	
	return RP[L][R]=0;
}


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) cin>>A[i+1];
	
	FOR(x,N) FOR(y,N) ok[x+1][y+1]=__gcd(A[x+1],A[y+1])>1;
	
	MINUS(LP);
	MINUS(RP);
	for(i=1;i<=N;i++) if(dfsR(0,i)&&dfsL(i,N+1)) return _P("Yes\n");
	_P("No\n");
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}