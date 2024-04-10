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

int N,M,K;
vector<pair<int,int>> E[202020];
int from[202020][11];

int ng2[11][11];
int ng[11][11][11];
int C[11];
int ret;
void dfs(int cur) {
	if(cur==K+1) {
		int i;
		//for(i=1;i<=K;i++) cout<<C[i];
		//cout<<endl;
		ret++;
		return;
	}
	int i,x;
	for(i=1;i<=cur;i++) {
		if(ng2[cur][i]) continue;
		for(x=1;x<cur;x++) {
			if(ng[cur][i][x]&(1<<C[x])) break;
		}
		if(x<cur) continue;
		C[cur]=i;
		dfs(cur+1);
		
	}
	
	
}


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M>>K;
	FOR(i,M) {
		cin>>x>>y>>r;
		E[x-1].push_back({r,y-1});
	}
	FOR(i,N) {
		sort(ALL(E[i]));
		if(E[i].empty()) return _P("0\n");
		FOR(j,E[i].size()) {
			if(from[E[i][j].second][E[i].size()]&(1<<j)) ng2[E[i].size()][j+1]=1;
			from[E[i][j].second][E[i].size()] |= 1<<j;
		}
	}
	
	FOR(i,N) {
		FOR(x,10) if(from[i][x]) {
			//cout<<"!"<<i<<x<<" "<<from[i][x]<<endl;
			FOR(y,10) if(x!=y) {
				FOR(j,x) if(from[i][x]&(1<<j)) ng[x][j+1][y] |= from[i][y]<<1;
			}
		}
	}
	
	/*
	for(x=1;x<=K;x++) {
		for(y=1;y<=x;y++) {
			for(r=1;r<x;r++) cout<<x<<y<<r<<" "<<ng[x][y][r]<<endl;
		}
	}
	*/
	dfs(1);
	cout<<ret<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}