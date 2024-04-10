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
vector<int> E[505050];
queue<int> Q;
int L[505050],R[505050];
void dfs(int cur,int pre) {
	FORR(e,E[cur]) if(e!=pre) {
		L[e]=Q.front();
		Q.pop();
	}
	R[cur]=Q.front();
	Q.pop();
	reverse(ALL(E[cur]));
	FORR(e,E[cur]) if(e!=pre) dfs(e,cur);
	
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	scanf("%d",&N);
	FOR(i,N-1) {
		scanf("%d%d",&x,&y);
		E[x-1].push_back(y-1);
		E[y-1].push_back(x-1);
	}
	FOR(i,2*N) Q.push(i+1);
	
	L[0]=1;
	Q.pop();
	dfs(0,0);
	
	FOR(i,N) {
		_P("%d %d\n",L[i],R[i]);
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}