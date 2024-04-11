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
set<int> E[202020];
set<int> liv;
vector<int> V;
int ret;

void dfs(int cur) {
	ret++;
	int nex=-1;
	liv.erase(cur);
	
	while(liv.size()) {
		auto it=liv.lower_bound(nex);
		if(it==liv.end()) break;
		nex=*it;
		if(E[cur].count(nex)==0) dfs(nex);
		nex++;
	}
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	FOR(i,N) liv.insert(i);
	FOR(i,M) {
		cin>>x>>y;
		x--;y--;
		E[x].insert(y);
		E[y].insert(x);
	}
	
	while(liv.size()) {
		ret=0;
		dfs(*liv.begin());
		V.push_back(ret);
	}
	sort(ALL(V));
	_P("%d\n",V.size());
	FOR(i,V.size()) _P("%d%c",V[i],(i+1==V.size())?'\n':' ');
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}