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

int N,Q;
int C[202020];
vector<int> E[202020];
int O[202020];
int pos[202020];
int id;
void dfs(int cur) {
	O[id]=cur;
	pos[cur]=id++;
	C[cur]=1;
	FORR(e,E[cur]) {
		dfs(e);
		C[cur]+=C[e];
	}
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>Q;
	FOR(i,N-1) {
		cin>>x;
		E[x-1].push_back(i+1);
	}
	dfs(0);
	while(Q--) {
		cin>>x>>y;
		x--;
		if(C[x]<y) {
			cout<<-1<<endl;
		}
		else {
			cout<<O[pos[x]+y-1]+1<<endl;
		}
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}