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
short P[5050][5050],ID[5050][5050];
vector<pair<int,int>> E[5050];
int V[5050],M;
int A[5050],B[5050],G[5050];

void dfs(int cur,int pre,int root,int d) {
	P[root][cur]=pre;
	FORR(e,E[cur]) {
		if(e.first!=pre) dfs(e.first,cur,root,d+1);
		else ID[root][cur]=e.second;
	}
}


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N-1) {
		cin>>x>>y;
		E[x-1].push_back({y-1,i});
		E[y-1].push_back({x-1,i});
	}
	FOR(i,N) {
		dfs(i,i,i,0);
		V[i]=1;
	}
	cin>>M;
	FOR(i,M) {
		cin>>A[i]>>B[i]>>G[i];
		A[i]--;
		B[i]--;
		x=B[i];
		while(x!=A[i]) {
			y=ID[A[i]][x];
			V[y]=max(V[y],G[i]);
			x=P[A[i]][x];
		}
	}
	FOR(i,M) {
		int mi=1000000;
		x=B[i];
		while(x!=A[i]) {
			y=ID[A[i]][x];
			mi=min(mi,V[y]);
			x=P[A[i]][x];
		}
		if(mi!=G[i]) return _P("-1\n");
	}
	FOR(i,N-1) cout<<V[i]<<" ";
	cout<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}