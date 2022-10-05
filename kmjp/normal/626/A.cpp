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

int L;
string S;


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>L>>S;
	int ret=0;
	FOR(y,L) FOR(x,y+1) {
		int X=0,Y=0;
		for(i=x;i<=y;i++) {
			if(S[i]=='L') X--;
			if(S[i]=='R') X++;
			if(S[i]=='U') Y--;
			if(S[i]=='D') Y++;
		}
		if(X==0 && Y==0) ret++;
	}
	
	cout<<ret<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}