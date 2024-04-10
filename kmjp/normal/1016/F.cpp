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
vector<pair<int,int>> E[303030];
ll D[2][303030];
int ID[303030];
vector<int> cand;
int C[303030];
ll ma[303030];
ll R[303030];

int dfs(int cur,int pre,ll d,int id) {
	D[id][cur]=d;
	if(id==0&&D[0][cur]+D[1][cur]==D[1][1]) cand.push_back(cur);
	C[cur]=1;
	FORR(e,E[cur]) if(e.first!=pre) {
		C[cur]+=dfs(e.first,cur,d+e.second,id);
	}
	return C[cur];
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	scanf("%d%d",&N,&M);
	FOR(i,N-1) {
		scanf("%d%d%d",&x,&y,&r);
		E[x].push_back({y,r});
		E[y].push_back({x,r});
	}
	
	dfs(N,0,0,1);
	dfs(1,0,0,0);
	MINUS(ID);
	FOR(i,cand.size()) ID[cand[i]]=i;
	
	int lp=0;
	for(i=1;i<=N;i++) if(ID[i]>=0) {
		x=0;
		FORR(e,E[i]) if(ID[e.first]<0) x+=C[e.first], ma[i]=e.second;
		if(x>=2) lp=1;
	}
	
	
	ll rma=0;
	R[cand.size()]=R[cand.size()+1]=-1LL<<50;
	for(i=cand.size()-1;i>=0;i--) {
		R[i]=max(R[i+1], D[1][cand[i]]+ma[cand[i]]);
	}
	
	FOR(i,cand.size()-1) {
		if(ma[cand[i]] || ma[cand[i+1]]) {
			rma=max(rma,D[0][cand[i]]+ma[cand[i]]+R[i+1]);
		}
		else {
			rma=max(rma,D[0][cand[i]]+R[i+2]);
		}
	}
	
	FOR(i,M) {
		scanf("%d",&x);
		ll ret=D[0][N];
		if(lp==0) ret=min(ret,rma+x);
		_P("%I64d\n",ret);
	}
	
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}