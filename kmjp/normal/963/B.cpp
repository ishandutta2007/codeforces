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
set<int> E[202020];
set<int> cand;
int C[202020];
vector<int> V;

int dfs(int cur,int pre) {
	C[cur]=1;
	FORR(e,E[cur]) if(e!=pre) C[cur]+=dfs(e,cur);
	return C[cur];
}

void dfs2(int cur,int pre) {
	if(C[cur]%2==1) {
		FORR(e,E[cur]) if(e!=pre) {
			if(C[e]%2==0) dfs2(e,cur);
		}
		V.push_back(cur);
		FORR(e,E[cur]) if(e!=pre) {
			if(C[e]%2==1) dfs2(e,cur);
		}
	}
	else {
		FORR(e,E[cur]) if(e!=pre) {
			if(C[e]%2==0) dfs2(e,cur);
		}
		V.push_back(cur);
		FORR(e,E[cur]) if(e!=pre) {
			if(C[e]%2==1) dfs2(e,cur);
		}
	}
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	if(N%2==0) return _P("NO\n");
	
	for(i=1;i<=N;i++) {
		cin>>x;
		if(x) {
			E[i].insert(x);
			E[x].insert(i);
		}
	}
	dfs(1,1);
	dfs2(1,1);
	
	cout<<"YES"<<endl;
	FORR(v,V) cout<<v<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}