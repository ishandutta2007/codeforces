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

int P,X,Y;

int ok(int P,int S) {
	int i;
	S=S/50%475;
	FOR(i,25) {
		S=(S*96+42)%475;
		if(P==26+S) return 1;
	}
	return 0;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>P>>X>>Y;
	
	for(x=X;x>=Y;x-=50) {
		if(ok(P,x)) return _P("0\n");
	}
	for(i=1;i<=1000;i++) {
		if(ok(P,X+100*i)) return _P("%d\n",i);
		if(ok(P,X+100*i-50)) return _P("%d\n",i);
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}