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
vector<int> E[101010];
int vis[101010];
vector<pair<int,int>> T;

void dfs(int cur,int pre,int target) {
	T.push_back({cur,target});
	int num=E[cur].size()-1;
	int x=target;
	target--;
	
	
	FORR(e,E[cur]) if(e!=pre && num>target) {
		vis[e]=1;
		num--;
		dfs(e,cur,++x);
		T.push_back({cur,x});
	}
	
	T.push_back({cur,target-num});
	x=target-num;
	
	FORR(e,E[cur]) if(e!=pre && vis[e]==0) {
		dfs(e,cur,++x);
		T.push_back({cur,x});
	}
	
	assert(target==x);
	
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N-1) {
		cin>>x>>y;
		E[x].push_back(y);
		E[y].push_back(x);
	}
	
	T.push_back({1,0});
	FORR(e,E[1]) {
		dfs(e,1,T.back().second+1);
		T.push_back({1,T.back().second+1});
	}
	
	_P("%d\n",(int)T.size());
	FORR(e,T) _P("%d %d\n",e.first,e.second);
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}