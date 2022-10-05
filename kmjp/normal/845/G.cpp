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
vector<pair<int,int>> E[101010];
int D[101010];
vector<int> C;

template<class C> vector<C> gf2_rank(vector<C> V) { /* input */
	int i,j;
	int N=V.size();
	FOR(i,N) {
		sort(V.begin()+i,V.end(),greater<C>());
		if(V[i]==0) break;
		C msb=1;
		while(msb<<1 <= V[i]) msb<<=1;
		for(j=i+1;j<N;j++) if(V[j]&msb) V[j]^=V[i];
	}
	return V;
}

void dfs(int cur,int c) {
	if(D[cur]!=-1) {
		if(D[cur]!=c) C.push_back(D[cur]^c);
	}
	else {
		D[cur]=c;
		FORR(e,E[cur]) dfs(e.first,c^e.second);
	}
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	FOR(i,M) {
		cin>>x>>y>>r;
		E[x-1].push_back({y-1,r});
		E[y-1].push_back({x-1,r});
	}
	MINUS(D);
	dfs(0,0);
	
	int ret=D[N-1];
	C=gf2_rank(C);
	FORR(c,C) ret=min(ret,ret^c);
	cout<<ret<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}