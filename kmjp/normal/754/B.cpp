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

string S[4];

int check(int a1,int b1,int a2,int b2,int a3,int b3) {
	int nx=0;
	int nd=0;
	if(S[a1][b1]=='x') nx++;
	if(S[a2][b2]=='x') nx++;
	if(S[a3][b3]=='x') nx++;
	if(S[a1][b1]=='.') nd++;
	if(S[a2][b2]=='.') nd++;
	if(S[a3][b3]=='.') nd++;
	if(nx==2 && nd==1) {
		_P("YES\n");
		exit(0);
	}
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	FOR(y,4) cin>>S[y];
	FOR(y,4) {
		check(y,0,y,1,y,2);
		check(y,1,y,2,y,3);
		check(0,y,1,y,2,y);
		check(1,y,2,y,3,y);
	}
	check(0,0,1,1,2,2);
	check(1,0,2,1,3,2);
	check(0,1,1,2,2,3);
	check(1,1,2,2,3,3);
	check(3,0,2,1,1,2);
	check(2,0,1,1,0,2);
	check(3,1,2,2,1,3);
	check(2,1,1,2,0,3);
	_P("NO\n");
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}