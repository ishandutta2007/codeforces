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
vector<int> E[5050];
int S[5050],T[5050],C[5050];
int vis[5050];
int K;

void dfs(int cur) {
	vis[cur]=2;
	FORR(e,E[cur]) if(C[e]==0) {
		if(vis[T[e]]==2) {
			C[e]=1;
			K=1;
		}
		else if(vis[T[e]]==0) {
			dfs(T[e]);
		}
	}
	vis[cur]=1;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	FOR(i,M) {
		cin>>S[i]>>T[i];
		S[i]--;
		T[i]--;
		E[S[i]].push_back(i);
	}
	
	FOR(i,N) {
		ZERO(vis);
		dfs(i);
	}
	
	cout<<K+1<<endl;
	FOR(i,M) cout<<C[i]+1<<" ";
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}