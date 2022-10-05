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

int N;
int A[30];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	int odd=0, oid=0, g=0;
	cin>>N;
	FOR(i,N) {
		cin>>A[i];
		g=__gcd(g,A[i]);
		if(A[i]%2==1) odd++, oid=i;
	}
	
	if(odd>1) {
		_P("0\n");
		FOR(i,N) FOR(j,A[i]) _P("%c",'a'+i);
	}
	else {
		_P("%d\n",g);
		FOR(i,N) A[i]/=g;
		if(odd) {
			FOR(x,g) {
				FOR(i,N) if(i!=oid) FOR(j,A[i]/2) _P("%c",'a'+i);
				FOR(j,A[oid]) _P("%c",'a'+oid);
				for(i=N-1;i>=0;i--) if(i!=oid) FOR(j,A[i]/2) _P("%c",'a'+i);
			}
		}
		else {
			FOR(x,g) {
				if(x%2==0) {
					FOR(i,N) FOR(j,A[i]) _P("%c",'a'+i);
				}
				else {
					for(i=N-1;i>=0;i--) FOR(j,A[i]) _P("%c",'a'+i);
				}
			}
		}
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