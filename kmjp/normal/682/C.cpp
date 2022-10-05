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
int A[101010];
int P[101010], C[101010];
vector<pair<int,int>> E[101010];
int did[101010];
int ret;

void dfs(int cur,ll cd,int del) {
	did[cur]=1;
	if(cd>A[cur]) del++;
	if(del) ret++;
	FORR(r,E[cur]) if(did[r.first]==0) dfs(r.first, max((ll)r.second,cd+r.second), del);
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) cin>>A[i];
	for(i=1;i<N;i++) {
		cin>>P[i]>>C[i];
		P[i]--;
		E[i].push_back({P[i],C[i]});
		E[P[i]].push_back({i,C[i]});
	}
	dfs(0,0,0);
	
	cout<<ret<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}