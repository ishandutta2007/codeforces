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

int N,M,P;
vector<int> E[200000];
int man[202020];
vector<pair<int,int> > V;

int cd;
int st;
vector<pair<int,int>> D[202020];
int ma=0,cand=0;

int dfs(int cur,int pre) {
	FORR(r,E[cur]) if(r!=pre) D[cur].push_back({dfs(r,cur),r});
	D[cur].push_back({0,cur});
	return max_element(ALL(D[cur]))->first+1;
}

void dfs2(int cur,int pre,int par) {
	if(pre>=0) D[cur].push_back({par,pre});
	sort(ALL(D[cur]));
	reverse(ALL(D[cur]));
	int i;
	
	if(D[cur][0].first>ma || (D[cur][0].first==ma && cur<cand)) ma=D[cur][0].first,cand=cur;
	
	FORR(r,E[cur]) if(r!=pre) dfs2(r,cur,D[cur][(D[cur][0].second==r)].first+1);
	
	return;
}

int prune(int cur,int pre) {
	int num=0;
	vector<int> nn;
	FORR(r,E[cur]) if(r!=pre) {
		int n=prune(r,cur);
		num+=n;
		if(n) nn.push_back(r);
	}
	E[cur]=nn;
	
	if(man[cur]) st=cur;
	if((man[cur] || E[cur].size()) && pre>=0) E[cur].push_back(pre);
	
	return num+man[cur];
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	FOR(i,N-1) {
		cin>>x>>y;
		E[x].push_back(y);
		E[y].push_back(x);
	}
	FOR(i,M) {
		cin>>x;
		man[x]=1;
		st=x;
	}
	if(M==1) return _P("%d\n%d\n",st,0);
	
	prune(st,-1);
	int p=st;
	prune(st,-1);
	
	FOR(i,N) FORR(r,E[i+1]) P++;
	dfs(p,-1);
	dfs2(p,-1,0);
	
	_P("%d\n%d\n",cand,P-ma);
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}