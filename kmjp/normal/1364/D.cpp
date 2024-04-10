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
vector<int> E[101010];
int D[101010];
vector<int> C[2];
vector<int> V;

set<pair<int,int>> S;

void dfs(int cur,int d) {
	if(D[cur]>=0) {
		if(d-D[cur]<=K) {
			int i;
			cout<<"2"<<endl;
			cout<<(d-D[cur])<<endl;
			FOR(i,d-D[cur]) cout<<V[V.size()-1-i]<<" ";
			cout<<endl;
			exit(0);
		}
		return;
	}
	
	D[cur]=d;
	V.push_back(cur);
	FORR(e,E[cur]) {
		if(S.count({e,cur})==0) {
			S.insert({cur,e});
			dfs(e,d+1);
		}
	}
	V.pop_back();
}

void dfs2(int cur,int d) {
	if(D[cur]>=0) {
		int i;
		cout<<"1"<<endl;
		FOR(i,(K+1)/2) cout<<V[V.size()-1-i*2]<<" ";
		cout<<endl;
		exit(0);
	}
	
	D[cur]=d;
	C[d%2].push_back(cur);
	V.push_back(cur);
	FORR(e,E[cur]) {
		if(S.count({e,cur})==0) {
			S.insert({cur,e});
			dfs2(e,d+1);
		}
	}
	V.pop_back();
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M>>K;
	FOR(i,M) {
		cin>>x>>y;
		E[x].push_back(y);
		E[y].push_back(x);
	}
	
	MINUS(D);
	dfs(1,0);
	S.clear();
	MINUS(D);
	dfs2(1,0);
	
	K=(K+1)/2;
	x=C[0].size()<C[1].size();
	
	cout<<1<<endl;
	FOR(i,K) cout<<C[x][i]<<" ";
	cout<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}