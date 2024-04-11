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

int N,K,D;
int P[303030];
int dist[303030];
vector<pair<int,int>> E[303030];
int used[303030];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>K>>D;
	MINUS(dist);
	queue<int> Q;
	FOR(i,K) {
		cin>>x;
		dist[x]=D;
		Q.push(x);
	}
	FOR(i,N-1) {
		cin>>x>>y;
		E[x].push_back({y,i});
		E[y].push_back({x,i});
	}
	int unused=N-1;
	while(Q.size()) {
		int c = Q.front();
		Q.pop();
		if(dist[c]==0) continue;
		FORR(e,E[c]) if(dist[e.first]<0) {
			dist[e.first] = dist[c]-1;
			Q.push(e.first);
			used[e.second]=1;
			unused--;
		}
	}
	_P("%d\n",unused);
	FOR(i,N-1) if(used[i]==0) _P("%d ",i+1);
	_P("\n");
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}