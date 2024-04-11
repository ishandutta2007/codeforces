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

ll N,Q;
ll L;
string S;
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>Q;
	while(1LL<<L<(N+1)) L++;
	L--;
	
	while(Q--) {
		ll C;
		cin>>C>>S;
		int CL=0;
		while((C & (1LL<<CL))==0) CL++;
		
		FORR(c,S) {
			if(c=='U') {
				if(CL!=L) {
					C^=1LL<<CL;
					CL++;
					C|=1LL<<CL;
				}
			}
			else if(c=='L') {
				if(CL) {
					C^=1LL<<CL;
					CL--;
					C^=1LL<<CL;
				}
			}
			else {
				if(CL) {
					CL--;
					C^=1LL<<CL;
				}
			}
		}
		cout<<C<<endl;
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}