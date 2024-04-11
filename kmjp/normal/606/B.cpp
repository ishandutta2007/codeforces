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

int W,H,X,Y;
string S;

int used[501][501];
int ret[101010];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>H>>W>>Y>>X>>S;
	X--,Y--;
	int L=H*W;
	FOR(i,S.size()) {
		if(used[Y][X]==0) {
			ret[i]++;
			used[Y][X]=1;
			L--;
		}
		if(S[i]=='U' && Y>0) Y--;
		if(S[i]=='D' && Y<H-1) Y++;
		if(S[i]=='L' && X>0) X--;
		if(S[i]=='R' && X<W-1) X++;
	}
	ret[S.size()]=L;
	FOR(i,S.size()+1) _P("%d ",ret[i]);
	_P("\n");
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}