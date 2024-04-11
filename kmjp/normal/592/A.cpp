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

string S[8];
int mi[3]={10,10};

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	FOR(y,8) cin>>S[y];
	FOR(x,8) {
		FOR(y,8) {
			if(S[y][x]=='W') mi[0]=min(mi[0],y);
			if(S[y][x]=='B') break;
		}
		for(y=7;y>=0;y--) {
			if(S[y][x]=='B') mi[1]=min(mi[1],7-y);
			if(S[y][x]=='W') break;
		}
	}
	if(mi[0]<=mi[1]) _P("A\n");
	else _P("B\n");
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}