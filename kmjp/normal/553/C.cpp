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
int col[101010];
vector<pair<int,int> > E[101010];
ll mo=1000000007;

void dfs(int cur,int co) {
	if(col[cur]!=-1) {
		if(col[cur]!=co) {
			cout<<0<<endl;
			exit(0);
		}
		return;
	}
	col[cur]=co;
	FORR(r,E[cur]) dfs(r.first,co^r.second);
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	FOR(i,M) {
		cin>>x>>y>>r;
		E[x-1].push_back({y-1,r^1});
		E[y-1].push_back({x-1,r^1});
	}
	MINUS(col);
	
	ll ret=mo/2+1;
	FOR(i,N) if(col[i]==-1) {
		ret=ret*2%mo;
		dfs(i,0);
	}
	cout<<ret<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}