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

int N;
int X[4],Y[4];

void solve() {
	int i,j,k,l,r,x,y; string s;
	int L=1010,R=-1010,T=1010,B=-1010;
	
	cin>>N;
	FOR(i,N) {
		cin>>X[i]>>Y[i];
		L=min(L,X[i]);
		R=max(R,X[i]);
		T=min(T,Y[i]);
		B=max(B,Y[i]);
	}
	
	if((R-L)*(B-T)==0) return _P("-1\n");
	_P("%d\n",(R-L)*(B-T));
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}