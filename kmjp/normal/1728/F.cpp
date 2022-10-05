#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define FORR2(x,y,arr) for(auto& [x,y]:arr)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
template<class T> bool chmax(T &a, const T &b) { if(a<b){a=b;return 1;}return 0;}
template<class T> bool chmin(T &a, const T &b) { if(a>b){a=b;return 1;}return 0;}
//-------------------------------------------------------

int N;
int A[1010];
vector<int> Vs;
vector<int> E[1<<20];
int vis[1<<20];
int op[1010];

int dfs(int cur) {
	if(vis[cur]) return 0;
	vis[cur]=1;
	FORR(e,E[cur]) if(op[e]==-1||dfs(op[e])) {
		op[e]=cur;
		return 1;
	}
	return 0;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) {
		cin>>A[i];
		FOR(j,N) Vs.push_back(A[i]*(j+1));
	}
	sort(ALL(Vs));
	Vs.erase(unique(ALL(Vs)),Vs.end());
	
	FOR(i,N) FOR(j,N) {
		x=lower_bound(ALL(Vs),A[i]*(j+1))-Vs.begin();
		E[x].push_back(i);
	}
	int NV=Vs.size();
	ll ret=0;
	MINUS(op);
	FOR(i,NV) if(dfs(i)) {
		ret+=Vs[i];
		ZERO(vis);
	}
	cout<<ret<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}