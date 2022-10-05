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

int L;
string S;

void solve() {
	int i,j,k,l,r,x,y,z; string s;
	
	cin>>S;
	
	FOR(x,S.size()) {
		if((S[x]-'0')%8==0) return _P("YES\n%c\n",S[x]);
	}
	FOR(y,S.size()) FOR(x,y) {
		i = (S[x]-'0')*10+(S[y]-'0');
		if(i%8==0) return _P("YES\n%d\n",i);
	}
	FOR(z,S.size()) FOR(y,z) FOR(x,y) {
		i = (S[x]-'0')*100+(S[y]-'0')*10+(S[z]-'0');
		if(i%8==0) return _P("YES\n%d\n",i);
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