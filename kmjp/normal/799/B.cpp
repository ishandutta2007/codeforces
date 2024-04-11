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
int P[202020];

int M;
set<int> X[4];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) cin>>P[i];
	FOR(i,N) cin>>x, X[x].insert(P[i]);
	FOR(i,N) cin>>x, X[x].insert(P[i]);
	
	cin>>M;
	FOR(i,M) {
		cin>>x;
		
		if(X[x].empty()) {
			y = -1;
		}
		else {
			y = *X[x].begin();
			X[1].erase(y);
			X[2].erase(y);
			X[3].erase(y);
		}
		
		_P("%d%c",y,(i==M-1)?'\n':' ');
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}