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

int N,X;
int D[202020][2];
vector<int> E[202020];
int ma=0;

void dfs(int cur,int pre,int dep) {
	D[cur][0]=dep;
	FORR(e,E[cur]) if(e!=pre) dfs(e,cur,dep+2);
}

void dfs2(int cur,int pre,int dep) {
	D[cur][1]=dep;
	if(D[cur][0]<=dep+1) return;
	FORR(e,E[cur]) if(e!=pre) dfs2(e,cur,dep+2);
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>X;
	X--;
	FOR(i,N-1) {
		cin>>x>>y;
		E[x-1].push_back(y-1);
		E[y-1].push_back(x-1);
	}
	FOR(i,N) D[i][1]=10101010;
	dfs(0,-1,0);
	dfs2(X,-1,-1);
	
	int ma=0;
	FOR(i,N) if(D[i][0]>D[i][1]+1) ma=max(ma,D[i][0]);
	cout<<ma<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}