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
vector<int> E[202000];
ll mo=1000000007;

struct RemCumProd {
	vector<ll> le,ri,v;
	void init(vector<ll> V) { v=V; init(); }
	void add(ll d) { v.push_back(d); }
	void init() {
		le.clear(); ri.clear();
		le.push_back(1),ri.push_back(1);
		for(int i=0;i<v.size();i++) le.push_back(le.back()*v[i]%mo), ri.push_back(ri.back()*v[v.size()-1-i]%mo);
	}
	ll operator[](int x) { // if x<0 || x>=N, return all prod
		if(x<0 || x>=le.size()-1) return le.back();
		return le[x]*ri[le.size()-2-x]%mo;
	}
};

ll ppat[202000];
RemCumProd patp[202000];

void dfs(int cur) {
	FORR(r,E[cur]) {
		dfs(r);
		patp[cur].add(1+patp[r][-1]);
	}
	patp[cur].init();
}

void dfs2(int cur, ll p) {
	ppat[cur]=p;
	int i;
	FOR(i,E[cur].size()) dfs2(E[cur][i],1+p*patp[cur][i]%mo);
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	cin>>N;
	FOR(i,N-1) cin>>x, E[x-1].push_back(i+1);
	dfs(0);
	dfs2(0,1);
	
	FOR(i,N) _P("%I64d ",ppat[i]*patp[i][-1]%mo);
	_P("\n");
}



int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}