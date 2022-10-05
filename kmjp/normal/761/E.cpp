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
vector<int> E[31];
ll X[101],Y[101];
ll dx[4]={1,-1,0,0};
ll dy[4]={0,0,1,-1};

void dfs(int cur,int pre,int NG,ll dis) {
	int ok=15;
	if(NG>=0) ok ^= 1<<NG;
	FORR(e,E[cur]) if(e!=pre) {
		int dir;
		FOR(dir,4) if(ok & (1<<dir)) {
			ok ^= (1<<dir);
			X[e]=X[cur]+dis*dx[dir];
			Y[e]=Y[cur]+dis*dy[dir];
			dfs(e,cur,dir^1,dis/2);
			break;
		}
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
	FOR(i,N) if(E[i].size()>4) return _P("NO\n");
	dfs(0,-1,-1,1LL<<40);
	cout<<"YES"<<endl;
	FOR(i,N) cout<<X[i]<<" "<<Y[i]<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}