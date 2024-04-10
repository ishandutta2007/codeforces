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
int N,M;
int B[3030],W[3030];
vector<int> E[3030];

vector<pair<int,ll>> conv(vector<pair<int,ll>> A,vector<pair<int,ll>> B) {
	int a=A.size(),b=B.size();
	vector<pair<int,ll>> C(a+b,{-10000,0});
	int x,y;
	FOR(x,a) FOR(y,b) {
		C[x+y+1]=max(C[x+y+1],{A[x].first+B[y].first+(B[y].second>0),A[x].second});
		C[x+y]=max(C[x+y],{A[x].first+B[y].first,A[x].second+B[y].second});
	}
	return C;
	
}

vector<pair<int,ll>> dfs(int cur,int pre) {
	vector<pair<int,ll>> V;
	V.push_back({0,W[cur]-B[cur]});
	FORR(e,E[cur]) if(e!=pre) V=conv(V,dfs(e,cur));
	
	return V;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N>>M;
		FOR(i,N) cin>>B[i];
		FOR(i,N) cin>>W[i];
		FOR(i,N) E[i].clear();
		FOR(i,N-1) {
			cin>>x>>y;
			E[x-1].push_back(y-1);
			E[y-1].push_back(x-1);
		}
		auto v=dfs(0,0);
		
		cout<<v[M-1].first+(v[M-1].second>0)<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}