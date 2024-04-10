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
vector<int> E[301010];
vector<pair<int,int>> ev[303030];
ll add[303030];
ll tot=0;
ll ret[303030];

void dfs(int cur,int pre,int dep) {
	FORR(e,ev[cur]) {
		add[dep]+=e.second;
		if(dep+e.first<=303000) add[dep+e.first+1]-=e.second;
	}
	
	tot+=add[dep];
	ret[cur]=tot;
	FORR(e,E[cur]) if(e!=pre) dfs(e,cur,dep+1);
	
	tot-=add[dep];
	FORR(e,ev[cur]) {
		add[dep]-=e.second;
		if(dep+e.first<=303000) add[dep+e.first+1]+=e.second;
	}
}


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	scanf("%d",&N);
	FOR(i,N-1) {
		scanf("%d%d",&x,&y);
		E[x-1].push_back(y-1);
		E[y-1].push_back(x-1);
	}
	scanf("%d",&M);
	FOR(i,M) {
		scanf("%d%d%d",&x,&y,&r);
		ev[x-1].push_back({y,r});
	}
	
	dfs(0,-1,0);
	FOR(i,N) cout<<ret[i]<<" ";
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}