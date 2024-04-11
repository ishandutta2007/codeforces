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

ll X[3],Y[3];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	FOR(i,3) cin>>X[i]>>Y[i];
	if(X[0]==X[1]&&X[1]==X[2]) return _P("1\n");
	if(Y[0]==Y[1]&&Y[1]==Y[2]) return _P("1\n");
	FOR(i,3) FOR(j,3) FOR(k,3) if(i!=j&&j!=k&&i!=k) {
		if(X[i]==X[j] && (Y[k]<=min(Y[i],Y[j])||max(Y[i],Y[j])<=Y[k])) return _P("2\n");
		if(Y[i]==Y[j] && (X[k]<=min(X[i],X[j])||max(X[i],X[j])<=X[k])) return _P("2\n");
	}
	_P("3\n");
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}