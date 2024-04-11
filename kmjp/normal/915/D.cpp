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
vector<int> E[505];
int vis[505],vis2[505];
vector<int> V;
vector<int> cand;
int L,R;

void dfs(int cur) {
	if(vis2[cur]) return;
	vis[cur]++;
	if(vis[cur]>=2) {
		int i;
		for(i=V.size()-1;i>=0;i--) {
			cand.push_back(V[i]);
			if(V[i]==cur) break;
		}
		reverse(ALL(cand));
		cand.push_back(cur);
		return;
	}
	
	V.push_back(cur);
	FORR(r,E[cur]) {
		if(cand.empty()) dfs(r);
	}
	V.pop_back();
	vis2[cur]++;
}

int acyclic(int L,int R) {
	int in[505]={};
	int i;
	
	FOR(i,N) FORR(e,E[i]) if(L!=i || R!=e) in[e]++;
	queue<int> Q;
	FOR(i,N) if(in[i]==0) Q.push(i);
	int left=N;
	while(Q.size()) {
		int cur=Q.front();
		left--;
		Q.pop();
		
		FORR(e,E[cur]) {
			if(L==cur && R==e) continue;
			in[e]--;
			if(in[e]==0) Q.push(e);
		}
		
	}
	return left==0;
	
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	FOR(i,M) {
		cin>>x>>y;
		x--,y--;
		E[x].push_back(y);
	}
	FOR(i,N) if(vis2[i]==0 && cand.empty()) {
		ZERO(vis);
		V.clear();
		dfs(i);
	}
	
	if(cand.empty()) return _P("YES\n");
	FOR(i,cand.size()-1) if(acyclic(cand[i],cand[i+1])) return _P("YES\n");
	_P("NO\n");
	
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}