#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define FORR2(x,y,arr) for(auto& [x,y]:arr)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
template<class T> bool chmax(T &a, const T &b) { if(a<b){a=b;return 1;}return 0;}
template<class T> bool chmin(T &a, const T &b) { if(a>b){a=b;return 1;}return 0;}
//-------------------------------------------------------

int N;
int C[303030],SC[303030],TC,can[303030];
vector<pair<int,int>> E[303030];
vector<int> OE[303030],RE[303030];
int vis[303030];

int dfs(int cur, int pre) {
	SC[cur]=C[cur];
	FORR2(e,v,E[cur]) if(e!=pre) {
		int x=dfs(e,cur);
		if(x>=2) {
			v=1;
			RE[e].push_back(cur);
		}
		SC[cur]+=x;
	}
	FORR2(e,v,E[cur]) if(e==pre&&TC-SC[cur]>=2) {
		v=1;
		RE[e].push_back(cur);
	}
	return SC[cur];
}

void dfs2(int cur) {
	if(vis[cur]) return;
	can[cur]=vis[cur]=1;
	FORR(e,RE[cur]) dfs2(e);
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) {
		cin>>C[i];
		TC+=C[i];
		can[i]=C[i];
	}
	FOR(i,N-1) {
		cin>>x>>y;
		x--,y--;
		E[x].push_back({y,0});
		E[y].push_back({x,0});
		if(C[x]) can[y]=1;
		if(C[y]) can[x]=1;
	}
	dfs(0,0);
	FOR(i,N) if(can[i]) dfs2(i);
	
	FOR(i,N) cout<<can[i]<<" ";
	cout<<endl;
	
		
		
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}