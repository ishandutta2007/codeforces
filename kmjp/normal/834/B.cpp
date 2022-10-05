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
string S;
int F[256],L[256];
int T[1010101];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>K>>S;
	FOR(i,N) {
		if(F[S[i]]==0) {
			F[S[i]]=1;
			T[i]++;
		}
		if(L[S[N-1-i]]==0) {
			L[S[N-1-i]]=1;
			T[N-i]--;
		}
	}
	FOR(i,N) {
		if(i) T[i]+=T[i-1];
		if(T[i]>K) return _P("YES\n");
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