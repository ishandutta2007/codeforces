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

int N,M;
vector<int> E[101010];
int D[101010];
vector<int> cand[101010];
int R;
vector<int> V;

void dfs(int cur, int pre, int d) {
	if(D[cur]>=0) {
		if(d-D[cur]>=R) {
			cout<<2<<endl;
			cout<<d-D[cur]<<endl;
			int i;
			FOR(i,d-D[cur]) cout<<(V[V.size()-1-i])<<" ";
			cout<<endl;
			exit(0);
		}
		return;
	}
	D[cur]=d;
	cand[d%(R-1)].push_back(cur+1);
	V.push_back(cur+1);
	FORR(e,E[cur]) if(e!=pre) dfs(e,cur,d+1);
	V.pop_back();
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	R=ceil(sqrt(N));
	
	FOR(i,M) {
		cin>>x>>y;
		E[x-1].push_back(y-1);
		E[y-1].push_back(x-1);
	}
	
	MINUS(D);
	dfs(0,0,0);
	
	FOR(i,R-1) if(cand[i].size()>=R) {
		cout<<1<<endl;
		FOR(j,R) cout<<cand[i][j]<<" ";
		cout<<endl;
		break;
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}