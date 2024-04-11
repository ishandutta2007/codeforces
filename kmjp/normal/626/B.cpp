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

int DP[202][202][202];

void solve() {
	int i,j,k,l,x,y; string s;
	
	cin>>L>>S;
	DP[count(ALL(S),'R')][count(ALL(S),'G')][count(ALL(S),'B')]=1;
	
	int r,g,b;
	for(i=200;i>=2;i--) {
		FOR(r,201) FOR(g,201) {
			b=i-r-g;
			if(b<0) continue;
			if(DP[r][g][b]) {
				if(r>=2) DP[r-1][g][b]=1;
				if(g>=2) DP[r][g-1][b]=1;
				if(b>=2) DP[r][g][b-1]=1;
				if(r&&g) DP[r-1][g-1][b+1]=1;
				if(g&&b) DP[r+1][g-1][b-1]=1;
				if(r&&b) DP[r-1][g+1][b-1]=1;
			}
		}
	}
	
	if(DP[0][0][1]) _P("B");
	if(DP[0][1][0]) _P("G");
	if(DP[1][0][0]) _P("R");
	_P("\n");
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}