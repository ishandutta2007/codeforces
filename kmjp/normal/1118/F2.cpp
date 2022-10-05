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
int C[303030];
vector<int> col[303030];
vector<int> E[303030];

int P[21][300005],D[300005];

void dfs(int cur) {
	ITR(it,E[cur]) if(*it!=P[0][cur]) D[*it]=D[cur]+1, P[0][*it]=cur, dfs(*it);
}

int lca(int a,int b) {
	int ret=0,i,aa=a,bb=b;
	if(D[aa]>D[bb]) swap(aa,bb);
	for(i=19;i>=0;i--) if(D[bb]-D[aa]>=1<<i) bb=P[i][bb];
	for(i=19;i>=0;i--) if(P[i][aa]!=P[i][bb]) aa=P[i][aa], bb=P[i][bb];
	return (aa==bb)?aa:P[0][aa];               // vertex
}

ll mo=998244353;
ll dp[303030][2];
int vis[303030];

void dfs2(int cur,int pre) {
	vis[cur]=1;
	if(C[cur]) {
		dp[cur][0]=1;
		dp[cur][1]=0;
		return;
	}
	dp[cur][0]=0;
	dp[cur][1]=1;
	FORR(e,E[cur]) if(e!=pre) {
		dfs2(e,cur);
		ll p[2]={dp[cur][0],dp[cur][1]};
		dp[cur][0]=(p[0]*dp[e][1]+p[0]*dp[e][0]+p[1]*dp[e][0])%mo;
		dp[cur][1]=(p[1]*dp[e][0]+p[1]*dp[e][1])%mo;
	}
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	int R[2];
	
	cin>>N>>K;
	FOR(i,N) {
		cin>>C[i];
		col[C[i]].push_back(i);
	}
	FOR(i,N-1) {
		cin>>x>>y;
		E[x-1].push_back(y-1);
		E[y-1].push_back(x-1);
	}
	
	dfs(0);
	FOR(i,19) FOR(x,N) P[i+1][x]=P[i][P[i][x]];
	for(i=1;i<=K;i++) if(col[i].size()>1) {
		int lc=col[i][0];
		FORR(v,col[i]) lc=lca(lc,v);
		FORR(v,col[i]) {
			x=v;
			while(x!=lc) {
				x=P[0][x];
				if(C[x]==i) break;
				if(C[x]==0) C[x]=i;
				if(C[x]!=i) return _P("0\n");
			}
		}
	}
	
	ll ret=1;
	FOR(i,N) if(C[i]==0 && vis[i]==0) {
		dfs2(i,-1);
		ret=ret*dp[i][0]%mo;
	}
	cout<<ret<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}