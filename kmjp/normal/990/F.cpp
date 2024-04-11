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
map<pair<int,int>,int> ID;
set<int> E[202020];
int F[202020];
int ret[202020];
int vis[202020];

void dfs(int cur) {
	vis[cur]=1;
	FORR(e,E[cur]) if(vis[e]==0) {
		dfs(e);
		F[cur]+=F[e];
		if(ID[{cur,e}]>0) ret[ID[{cur,e}]]=F[e];
		else ret[-ID[{cur,e}]]=-F[e];
		F[e]=0;
	}
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	ll sum=0;
	FOR(i,N) {
		cin>>F[i];
		sum+=F[i];
	}
	if(sum) return _P("Impossible\n");
	cin>>M;
	FOR(i,M) {
		cin>>x>>y;
		x--,y--;
		E[x].insert(y);
		E[y].insert(x);
		ID[{x,y}]=i+1;
		ID[{y,x}]=-(i+1);
	}
	dfs(0);
	
	
	cout<<"Possible"<<endl;
	FOR(i,M) cout<<ret[i+1]<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}