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
queue<int> V[2];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,2) {
		cin>>x;
		FOR(j,x) cin>>y, V[i].push(y);
	}
	
	for(i=1;i<=5000;i++) {
		x=V[0].front();
		y=V[1].front();
		V[0].pop();
		V[1].pop();
		if(x<y) {
			V[1].push(x);
			V[1].push(y);
		}
		else {
			V[0].push(y);
			V[0].push(x);
		}
		if(V[0].size()==N) return _P("%d %d\n",i,1);
		if(V[1].size()==N) return _P("%d %d\n",i,2);
	}
	_P("%d\n",-1);
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}