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

string S[10];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	FOR(i,10) cin>>S[i];
	FOR(y,10) {
		FOR(x,6) {
			int A=0,B=0;
			FOR(i,5) {
				if(S[y][x+i]=='X') A++;
				if(S[y][x+i]=='O') B++;
			}
			if(A==4 && B==0) return _P("YES\n");
		}
	}
	FOR(x,10) {
		FOR(y,6) {
			int A=0,B=0;
			FOR(i,5) {
				if(S[y+i][x]=='X') A++;
				if(S[y+i][x]=='O') B++;
			}
			if(A==4 && B==0) return _P("YES\n");
		}
	}
	FOR(x,6) {
		FOR(y,6) {
			int A=0,B=0;
			FOR(i,5) {
				if(S[y+i][x+i]=='X') A++;
				if(S[y+i][x+i]=='O') B++;
			}
			if(A==4 && B==0) return _P("YES\n");
		}
	}
	for(x=4;x<10;x++) {
		FOR(y,6) {
			int A=0,B=0;
			FOR(i,5) {
				if(S[y+i][x-i]=='X') A++;
				if(S[y+i][x-i]=='O') B++;
			}
			if(A==4 && B==0) return _P("YES\n");
		}
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