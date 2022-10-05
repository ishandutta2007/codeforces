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
int L;
int D[4];
int C[4];


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>S;
	L=S.size();
	FOR(i,L) {
		if(S[i]=='R') D[0]=i%4;
		if(S[i]=='B') D[1]=i%4;
		if(S[i]=='Y') D[2]=i%4;
		if(S[i]=='G') D[3]=i%4;
	}
	FOR(i,L) if(S[i]=='!') {
		if(i%4==D[0]) C[0]++;
		if(i%4==D[1]) C[1]++;
		if(i%4==D[2]) C[2]++;
		if(i%4==D[3]) C[3]++;
	}
	_P("%d %d %d %d\n",C[0],C[1],C[2],C[3]);
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}