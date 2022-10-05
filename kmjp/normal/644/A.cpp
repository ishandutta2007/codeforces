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

int N,A,B;
int ret[101][101];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>A>>B;
	
	x=A*B;
	if(x<N) return _P("-1\n");
	
	i=0;
	FOR(y,A) {
		FOR(x,B) {
			i++;
			if(y%2) ret[y][B-1-x]=(i<=N)?i:0;
			else ret[y][x]=(i<=N)?i:0;
		}
	}

	FOR(y,A) FOR(x,B) _P("%d%s",ret[y][x],(x==B-1)?"\n":" ");
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}