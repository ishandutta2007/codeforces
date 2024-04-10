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
int C[202020];
ll SC[202020];
ll ma;
void dfs(int cur,int pre) {
	C[cur]=1;
	FORR(e,E[cur]) if(e!=pre) {
		dfs(e,cur);
		C[cur]+=C[e];
		SC[cur]+=SC[e];
	}
	SC[cur]+=C[cur];
}

void dfs2(int cur,int pre,ll sc) {
	SC[cur]+=N-C[cur]+sc;
	ma=max(ma,SC[cur]);
	FORR(e,E[cur]) if(e!=pre) {
		dfs2(e,cur,SC[cur]-SC[e]-C[e]);
	}
	
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N-1) {
		cin>>x>>y;
		E[x-1].push_back(y-1);
		E[y-1].push_back(x-1);
	}
	
	dfs(0,0);
	dfs2(0,0,0);
	cout<<ma<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}