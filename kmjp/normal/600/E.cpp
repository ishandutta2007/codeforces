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

int N;
int C[101010];
vector<int> E[101010];

map<int,int> M[101010];
int mnum[101010];
ll S[101010];

void dfs(int cur,int pre) {
	int mar=-1;
	FORR(r,E[cur]) if(r!=pre) {
		dfs(r,cur);
		if(mar==-1 || M[r].size()>M[mar].size()) mar=r;
	}
	if(mar!=-1) swap(M[cur],M[mar]), mnum[cur]=mnum[mar], S[cur]=S[mar];
	FORR(r,E[cur]) if(r!=pre) {
		FORR(rr,M[r]) {
			int x = M[cur][rr.first] += rr.second;
			if(x > mnum[cur]) mnum[cur]=x, S[cur]=0;
			if(x == mnum[cur]) S[cur]+=rr.first;
		}
	}
	int x = M[cur][C[cur]] += 1;
	if(x > mnum[cur]) mnum[cur]=x, S[cur]=0;
	if(x == mnum[cur]) S[cur]+=C[cur];
	
	
	
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) cin>>C[i];
	FOR(i,N-1) {
		cin>>x>>y;
		E[x-1].push_back(y-1);
		E[y-1].push_back(x-1);
	}
	dfs(0,-1);
	FOR(i,N) cout<<S[i]<<" ";
	cout<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}