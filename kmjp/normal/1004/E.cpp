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

int N,K;
vector<pair<int,int>> E[101010];
vector<ll> D[4],F[4];

pair<ll,ll> farthest(int cur,int pre,int d,vector<ll>& D,vector<ll>& F) {
	D[cur]=d;
	pair<ll,ll> r={d,cur};
	FORR(e,E[cur]) if(e.first!=pre) r=max(r, farthest(e.first,cur,d+e.second,D,F));
	F[cur]=max(D[cur],r.first);
	return r;
}

ll dfs(int cur,int pre,ll v,vector<ll>& D,vector<ll>& F) {
	ll num=0,path=0;
	if(pre==-1) {
		num++;
		FORR(e,E[cur]) {
			ll t=dfs(e.first,cur,v,D,F);
			if(t) num+=t,path++;
		}
		if(path>2) num=1<<20;
	}
	else {
		if(F[cur]-D[pre]>v) num++;
		FORR(e,E[cur]) if(e.first!=pre) {
			ll t=dfs(e.first,cur,v,D,F);
			if(t) num+=t,path++;
		}
		if(path>=2) num=1<<20;
	}
	return num;
	
}


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>K;
	FOR(i,N-1) {
		cin>>x>>y>>r;
		E[x-1].push_back({y-1,r});
		E[y-1].push_back({x-1,r});
	}
	
	FOR(i,4) D[i].resize(N), F[i].resize(N);
	auto v1=farthest(0,0,0,D[0],F[0]);
	auto v2=farthest(v1.second,v1.second,0,D[0],F[0]);
	farthest(v2.second,v2.second,0,D[1],F[1]);
	
	
	int id=0;
	ll mi=1LL<<60;
	FOR(i,N) if(max(D[0][i],D[1][i])<mi) mi=max(D[0][i],D[1][i]), id=i;
	farthest(id,0,0,D[2],F[2]);
	
	ll ret=(1LL<<40)-1;
	for(i=39;i>=0;i--) if(dfs(id,-1,ret-(1LL<<i),D[2],F[2])<=K) ret-=1LL<<i;
	cout<<ret<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}