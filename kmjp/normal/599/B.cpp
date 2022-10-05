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

int N,M;
int F[101010],R[101010],num[101010],ret[101010];
int B[101010];
int A[101010],is[101010];
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	FOR(i,N) {
		cin>>F[i];
		R[F[i]]=i+1;
		num[F[i]]++;
	}
	x=1;
	FOR(i,M) cin>>B[i];
	FOR(i,M) if(num[B[i]]==0) return _P("Impossible\n");
	FOR(i,M) {
		if(num[B[i]]>1) return _P("Ambiguity\n");
		ret[i]=R[B[i]];
	}
	_P("Possible\n");
	FOR(i,M) _P("%d%c",ret[i],(i==M-1)?'\n':' ');
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}