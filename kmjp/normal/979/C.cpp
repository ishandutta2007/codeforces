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

int N,X,Y;
vector<int> E[303030];
ll C[2][303030];

int dfs(int cur,int pre,int id) {
	C[id][cur]=1;
	FORR(e,E[cur]) if(e!=pre) C[id][cur]+=dfs(e,cur,id);
	return C[id][cur];
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	scanf("%d%d%d",&N,&X,&Y);
	X--;
	Y--;
	FOR(i,N-1) {
		scanf("%d%d",&x,&y);
		E[x-1].push_back(y-1);
		E[y-1].push_back(x-1);
	}
	dfs(X,X,0);
	dfs(Y,Y,1);
	ll ret=1LL*N*(N-1);
	ret-=C[0][Y]*C[1][X];
	cout<<ret<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}