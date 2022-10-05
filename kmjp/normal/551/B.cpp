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

string A,B,C;
int num[3][256];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>A>>B>>C;
	FORR(r,A) num[0][r]++;
	FORR(r,B) num[1][r]++;
	FORR(r,C) num[2][r]++;
	
	int mab=0,mac=0;
	for(i=0;i*B.size()<=A.size();i++) {
		int ng=0;
		FOR(j,26) if(num[0][j+'a']<num[1][j+'a']*i) ng++;
		if(ng) continue;
		
		int mi=101010;
		FOR(j,26) if(num[2][j+'a']) mi=min(mi,(num[0][j+'a']-num[1][j+'a']*i)/num[2][j+'a']);
		if(i+mi >= mab+mac) mab=i,mac=mi;
	}
	FOR(i,mab) _P("%s",B.c_str());
	FOR(i,mac) _P("%s",C.c_str());
	FOR(j,26) {
		x=num[0][j+'a']-num[1][j+'a']*mab-num[2][j+'a']*mac;
		FOR(i,x) _P("%c",j+'a');
	}
	_P("\n");
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}