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
ll X,Y;
vector<int> E[202020];
int part;

int dfs(int cur,int pre) {
	int ret=0;
	FORR(r,E[cur]) if(r!=pre) ret+=dfs(r,cur);
	
	if(ret<=1) return 1;
	part += ret-1;
	return 0;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>X>>Y;
	FOR(i,N-1) {
		cin>>x>>y;
		E[x-1].push_back(y-1);
		E[y-1].push_back(x-1);
	}
	ll ret=0;
	if(X<=Y) {
		part+=dfs(0,-1);
		ret=(N-1)*X+(part-1)*(Y-X);
	}
	else {
		FOR(i,N) if(E[i].size()==N-1) break;
		if(i==N) ret=(N-1)*Y;
		else ret=(N-2)*Y+X;
		
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