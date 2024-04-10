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

int N,M;
string S,T,U;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M>>s>>T;
	FOR(i,N) if(s[i]=='*') {
		S=s.substr(0,i);
		U=s.substr(i+1);
		break;
	}
	if(i==N) {
		if(s==T) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
	else {
		if(S.size()+U.size()>T.size()) return _P("NO\n");
		if(S!=T.substr(0,S.size())) return _P("NO\n");
		if(U!=T.substr(M-U.size())) return _P("NO\n");
		_P("YES\n");
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}