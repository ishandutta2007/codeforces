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

int N,K;
vector<int> E[202020];
int OK[202020];
int num[202020];
int cand=-1;
vector<int> V;

int dfs(int cur,int pre) {
	int ok=1;
	num[cur]=OK[cur];
	FORR(e,E[cur]) if(e!=pre) {
		int ret=dfs(e,cur);
		if(ret>K) ok=0;
		num[cur]+=ret;
	}
	if(2*K-num[cur]>K) ok=0;
	if(ok && cand==-1) cand=cur;
	return num[cur];
	
}

void dfs2(int cur,int pre) {
	if(OK[cur]) V.push_back(cur);
	FORR(e,E[cur]) if(e!=pre) dfs2(e,cur);

}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>K;
	FOR(i,N-1) {
		cin>>x>>y;
		E[x].push_back(y);
		E[y].push_back(x);
	}
	FOR(i,2*K) {
		cin>>x;
		OK[x]=1;
	}
	dfs(1,-1);
	ZERO(num);
	dfs2(cand,-1);
	_P("%d\n%d\n",1,cand);
	FOR(i,K) _P("%d %d %d\n",V[i],V[i+K],cand);
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}