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
vector<int> S[303030];
vector<int> E[303030];
int color[303030];

void dfs(int cur,int pre) {
	set<int> C;
	FORR(s,S[cur]) if(color[s]) C.insert(color[s]);
	
	int x=1;
	FORR(s,S[cur]) if(color[s]==0) {
		while(C.count(x)) x++;
		color[s]=x;
		C.insert(x);
	}
	FORR(e,E[cur]) if(e!=pre) dfs(e,cur);
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	set<pair<int,int>> Q;
	int ma=0;
	FOR(i,N) {
		cin>>x;
		FOR(j,x) {
			cin>>y;
			S[i].push_back(y-1);
		}
		if(x>S[ma].size()) ma=i;
	}
	FOR(i,N-1) {
		cin>>x>>y;
		E[x-1].push_back(y-1);
		E[y-1].push_back(x-1);
	}
	
	dfs(ma,-1);
	
	FOR(i,M) if(color[i]==0) color[i]=1;
	_P("%d\n",*max_element(color,color+M));
	FOR(i,M) _P("%d%c",color[i],(i==M-1)?'\n':' ');
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}