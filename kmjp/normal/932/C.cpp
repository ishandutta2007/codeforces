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
vector<int> V;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>A>>B;
	for(x=0;x*A<=N;x++) {
		y=N-(x*A);
		if(y%B) continue;
		
		y/=B;
		
		int nex=1;
		FOR(i,x) {
			int cur=nex;
			nex+=A;
			FOR(j,A) {
				if(j==0) V.push_back(nex-1);
				else V.push_back(cur+j-1);
			}
		}
		FOR(i,y) {
			int cur=nex;
			nex+=B;
			FOR(j,B) {
				if(j==0) V.push_back(nex-1);
				else V.push_back(cur+j-1);
			}
		}
		
		FOR(i,N) _P("%d%c",V[i],(i==N-1)?'\n':' ');
		return;
		
	}
	_P("-1\n");
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}