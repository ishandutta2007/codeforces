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
ll A[202020];
vector<int> E[202020];
ll ma=-1LL<<60;
ll dp[202020];
ll sum[202020];

void dfs(int cur,int pre) {
	sum[cur]=A[cur];
	vector<ll> V;
	FORR(e,E[cur]) if(e!=pre) {
		dfs(e,cur);
		sum[cur]+=sum[e];
		V.push_back(dp[e]);
	}
	sort(ALL(V));
	reverse(ALL(V));
	if(V.size()>=2) ma=max(ma,V[0]+V[1]);
	if(V.size()) dp[cur]=max(V[0],sum[cur]);
	else dp[cur]=sum[cur];
	
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) cin>>A[i];
	FOR(i,N-1) {
		cin>>x>>y;
		E[x-1].push_back(y-1);
		E[y-1].push_back(x-1);
	}
	
	dfs(0,-1);
	
	if(ma==-1LL<<60) cout<<"Impossible"<<endl;
	else cout<<ma<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}