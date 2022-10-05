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

int N,C;
int P[1010],T[1010];


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>C;
	FOR(i,N) cin>>P[i];
	FOR(i,N) cin>>T[i];
	int A=0,B=0;
	int ta=0,tb=0;
	FOR(i,N) {
		ta+=T[i];
		A+=max(0,P[i]-C*ta);
		j=N-1-i;
		tb+=T[j];
		B+=max(0,P[j]-C*tb);
	}
	if(A>B) _P("Limak\n");
	else if(A<B) _P("Radewoosh\n");
	else _P("Tie\n");
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}