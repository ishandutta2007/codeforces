#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define FORR(x,arr) for(auto& x:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

int N,M;
set<int> V[303030];
int vv[303030];
int pos[603030];
int vis[303030];


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	priority_queue<pair<int,int> > q;
	
	for(i=1;i<=N;i++) {
		cin>>x;
		FOR(j,x) {
			cin>>y;
			V[i].insert(y);
			pos[300000+y]=i;
		}
		q.push({-V[i].size(),i});
	}
	
	while(q.size()) {
		auto r=q.top();
		int cur=r.second;
		q.pop();
		
		if(vis[cur]) continue;
		vis[cur]=1;
		
		if(V[cur].empty()) return _P("NO\n");
		
		x=*V[cur].begin();
		vv[abs(x)]=x>0;
		
		if(pos[300000-x]>0) {
			V[pos[300000-x]].erase(-x);
			q.push({-V[pos[300000-x]].size(),pos[300000-x]});
		}
	}
	
	_P("YES\n");
	for(i=1;i<=M;i++) _P("%d",vv[i]);
	_P("\n");
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}