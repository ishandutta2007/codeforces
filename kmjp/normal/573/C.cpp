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
vector<int> E[101010];
int have3[101010];

int dfs(int cur,int pre) {
	FORR(tar,E[cur]) if(tar!=pre) have3[cur]+=dfs(tar,cur);
	return have3[cur] += (E[cur].size()>=3);
}

void dfs2(int cur,int pre,int n3) {
	
	int ng=(n3>=2 || (n3==1 && pre!=-1 && (E[pre].size()==2 || E[pre].size()==4)));
	FORR(tar,E[cur]) if(tar!=pre) if(have3[tar]>=2 || (have3[tar]==1 && (E[tar].size()==2||E[tar].size()==4))) ng++;
	if(ng>=3) _P("No\n"), exit(0);
	FORR(tar,E[cur]) if(tar!=pre) dfs2(tar,cur,have3[cur]+n3-have3[tar]);
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
	_P("Yes\n");
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}