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

int T;
int N;
vector<pair<int,int>> E[201010];
int C[202020];
ll ret[2];

int dfs(int cur,int pre) {
	C[cur]=1;
	int pd=0;
	FORR(e,E[cur]) {
		if(e.first!=pre) {
			C[cur]+=dfs(e.first,cur);
		}
		else {
			pd=e.second;
		}
	}
	
	if(C[cur]%2) ret[0]+=pd;
	ret[1]+=1LL*min(C[cur],2*N-C[cur])*pd;
	return C[cur];
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N;
		FOR(i,2*N) E[i].clear(), C[i]=0;
		FOR(i,2*N-1) {
			cin>>x>>y>>r;
			E[x-1].push_back({y-1,r});
			E[y-1].push_back({x-1,r});
		}
		
		ret[0]=ret[1]=0;
		dfs(0,0);
		cout<<ret[0]<<" "<<ret[1]<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}