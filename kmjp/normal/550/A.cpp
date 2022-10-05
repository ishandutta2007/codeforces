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

string S;
set<int> A,B;
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>S;
	FOR(i,S.size()-1) {
		if(S[i]=='A' && S[i+1]=='B') A.insert(i);
		if(S[i]=='B' && S[i+1]=='A') B.insert(i);
	}
	
	FORR(r,A) {
		FORR(r2,B) {
			if(abs(r-r2)==1) continue;
			return _P("YES\n");
		}
	}
	_P("NO\n");
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}