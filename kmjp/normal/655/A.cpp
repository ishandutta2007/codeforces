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

string S;
string T;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>S;
	cin>>s;
	S+=s[1];
	S+=s[0];
	FOR(i,4) if(S[i]=='X') {
		S=S.substr(0,i)+S.substr(i+1);
		break;
	}
	
	cin>>T;
	cin>>s;
	T+=s[1];
	T+=s[0];
	FOR(i,4) if(T[i]=='X') {
		T=T.substr(0,i)+T.substr(i+1);
		break;
	}
	
	S=S+S;
	T=T+T;
	x=y=0;
	FOR(i,5) if(S[i]=='A' && S[i+1]=='B') x=1;
	FOR(i,5) if(T[i]=='A' && T[i+1]=='B') y=1;
	
	if(x==y) _P("YES\n");
	else _P("NO\n");
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}