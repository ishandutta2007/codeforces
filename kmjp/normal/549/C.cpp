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

int N,K,D;
int O,E;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>K;
	FOR(i,N) {
		cin>>x;
		if(x%2) O++;
		else E++;
	}
	D=N-K;
	
	if(D==0) {
		if(O%2) _P("Stannis\n");
		else _P("Daenerys\n");
	}
	else if(D%2==0) {
		if((E<=D/2 && K%2==1)) _P("Stannis\n");
		else _P("Daenerys\n");
	}
	else {
		if(O<=D/2 || (E<=D/2 && K%2==0)) _P("Daenerys\n");
		else _P("Stannis\n");
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}