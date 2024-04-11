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
vector<int> E[202020];
vector<int> D[202020];

int dfs(int cur,int pre) {
	D[cur].push_back(0);
	FORR(e,E[cur]) if(e!=pre) {
		D[cur].push_back(dfs(e,cur));
	}
	sort(ALL(D[cur]));
	reverse(ALL(D[cur]));
	return D[cur][0]+1;
}

void dfs2(int cur,int pre,int par) {
	if(cur) D[cur].push_back(par);
	sort(ALL(D[cur]));
	reverse(ALL(D[cur]));
	FORR(e,E[cur]) if(e!=pre) {
		if(D[cur][0]==D[e][0]+1) dfs2(e,cur,D[cur][1]+1);
		else dfs2(e,cur,D[cur][0]+1);
	}
	D[cur].pop_back();
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N-1) {
		cin>>x>>y;
		E[x-1].push_back(y-1);
		E[y-1].push_back(x-1);
	}
	
	dfs(0,-1);
	dfs2(0,-1,0);
	
	int mi=201010;
	FOR(i,N) {
		set<int> S;
		FORR(e,D[i]) S.insert(e);
		if(S.size()>2) return _P("-1\n");
		if(S.size()==1) mi=min(mi,*S.begin());
	}
	while(mi%2==0) mi/=2;
	cout<<mi<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}