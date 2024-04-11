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
vector<int> E[404040];
int V[404040];
int can[404040];
int ma[404040];

void dfs(int cur,int pre) {
	can[cur]=1;
	V[cur]=1;
	FORR(e,E[cur]) if(e!=pre) {
		dfs(e,cur);
		V[cur]+=V[e];
		if(ma[e]*2<=N) ma[cur]=max(ma[cur],ma[e]);
	}
	if(V[cur]*2<=N) ma[cur]=V[cur];
}
void dfs2(int cur,int pre,int pma) {
	vector<pair<int,int>> T;
	T.push_back({pma,pre});
	FORR(e,E[cur]) if(e!=pre) {
		if((V[e]-ma[e])*2>N) can[cur]=0;
		T.push_back({ma[e],e});
	}
	if((N-V[cur]-pma)*2>N) can[cur]=0;
	
	sort(ALL(T));
	reverse(ALL(T));
	FORR(e,E[cur]) if(e!=pre) {
		int nma=T[(T[0].second==e)].first;
		if((N-V[e])*2<=N) nma=max(nma,N-V[e]);
		dfs2(e,cur,nma);
	}
}


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N-1) {
		cin>>x>>y;
		E[x-1].push_back(y-1);
		E[y-1].push_back(x-1);
	}
	dfs(0,-1);
	dfs2(0,-1,0);
	FOR(i,N) _P("%d%c",can[i],(i==N-1)?'\n':' ');
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}