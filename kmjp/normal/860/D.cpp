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
vector<int> E[202020];
map<pair<int,int>,int> EE;
int vis[202020];
int vise[202020];
vector<vector<int>> R;

int dfs(int cur,int pre) {
	int m=-1;
	if(vis[cur]) return cur;
	vis[cur]=1;
	FORR(e,E[cur]) if(e!=pre) {
		if(vise[EE[{cur,e}]]) continue;
		vise[EE[{cur,e}]]=1;
		int tar=dfs(e,cur);
		if(tar!=-1) {
			if(m==-1) {
				m=tar;
			}
			else {
				R.push_back({m,cur,tar});
				m=-1;
			}
		}
	}
	
	if(m==-1) {
		return cur;
	}
	else {
		if(pre!=-1) R.push_back({m,cur,pre});
		return -1;
	}
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	FOR(i,M) {
		cin>>x>>y;
		E[x].push_back(y);
		E[y].push_back(x);
		EE[{x,y}]=EE[{y,x}]=i;
	}
	FOR(i,N) if(vis[i+1]==0) dfs(i+1,-1);
	
	_P("%d\n",R.size());
	FORR(r,R) _P("%d %d %d\n",r[0],r[1],r[2]);
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}