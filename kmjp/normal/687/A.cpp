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

int N,M;
int C[202020];
vector<int> E[202020];
vector<int> R[2];

void paint(int cur,int col) {
	if(C[cur]!=-1) {
		if(C[cur]==col) return;
		_P("-1\n");
		exit(0);
	}
	C[cur]=col;
	R[col].push_back(cur+1);
	FORR(r,E[cur]) paint(r,col^1);
	
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	MINUS(C);
	cin>>N>>M;
	FOR(i,M) {
		cin>>x>>y;
		E[x-1].push_back(y-1);
		E[y-1].push_back(x-1);
	}
	FOR(i,N) if(C[i]==-1) paint(i,0);
	
	FOR(i,2) {
		_P("%d\n",R[i].size());
		FOR(j,R[i].size()) _P("%d%s",R[i][j],(j==R[i].size()-1)?"\n":" ");
	}
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}