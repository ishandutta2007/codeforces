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

int N,M;
vector<int> E[505050];
string S;
int sumx[505050];

vector<int> Q[505050];
int V[505050],H[505050],ret[505050];

void dfs(int cur,int dep) {
	
	FORR(r,Q[cur]) ret[r] ^= sumx[H[r]];
	sumx[dep] ^= (1<<(S[cur]-'a'));
	FORR(r,E[cur]) dfs(r,dep+1);
	FORR(r,Q[cur]) ret[r] ^= sumx[H[r]];
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	FOR(i,N-1) cin>>x, E[x-1].push_back(i+1);
	cin>>S;
	
	FOR(i,M) {
		cin>>V[i]>>H[i];
		V[i]--;
		Q[V[i]].push_back(i);
	}
	
	dfs(0,1);
	
	FOR(i,M) {
		if(__builtin_popcount(ret[i])>1) _P("No\n");
		else _P("Yes\n");
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}