#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define FORR2(x,y,arr) for(auto& [x,y]:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

int N;
int A[2020][2020];
const ll mo=998244353;
int cand[1515*1515];

template<int um> class UF {
	public:
	vector<int> par,rank,cnt;
	UF() {par=rank=vector<int>(um,0); cnt=vector<int>(um,1); for(int i=0;i<um;i++) par[i]=i;}
	void reinit() {int i; FOR(i,um) rank[i]=0,cnt[i]=1,par[i]=i;}
	int operator[](int x) {return (par[x]==x)?(x):(par[x] = operator[](par[x]));}
	int count(int x) { return cnt[operator[](x)];}
	int operator()(int x,int y) {
		if((x=operator[](x))==(y=operator[](y))) return x;
		cnt[y]=cnt[x]=cnt[x]+cnt[y];
		if(rank[x]>rank[y]) return par[x]=y;
		rank[x]+=rank[x]==rank[y]; return par[y]=x;
	}
};

UF<3200> uf;
int V[3000];
int E[3000];
int P[3030];
vector<int> C[3030];
int ok[3030];

ll dp[3030][1600];


void dfs(int cur) {
	if(ok[cur]) dp[cur][1]=1;
	if(C[cur].size()) {
		int a=C[cur][0];
		int b=C[cur][1];
		int x,y;
		dfs(a);
		dfs(b);
		for(x=1;x<=V[a];x++) for(y=1;y<=V[b];y++) {
			(dp[cur][x+y]+=dp[a][x]*dp[b][y])%=mo;
		}
	}
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	int ma=0;
	FOR(y,N) FOR(x,N) {
		cin>>A[y][x];
		ma=max(ma,A[y][x]);
		if(A[y][x]) cand[A[y][x]-1]=y*2000+x;
	}
	FOR(i,N) V[i]=1,P[i]=i,ok[i]=1;
	int nex=N;
	FOR(i,ma) {
		x=cand[i]%2000;
		y=cand[i]/2000;
		x=uf[x];
		y=uf[y];
		if(x==y) {
			r=P[x];
			E[r]++;
			if(E[r]==V[r]*(V[r]-1)/2) {
				ok[r]=1;
			}
		}
		else {
			C[nex].push_back(P[x]);
			C[nex].push_back(P[y]);
			uf(x,y);
			V[nex]=V[P[x]]+V[P[y]];
			E[nex]=E[P[x]]+E[P[y]]+1;
			if(E[nex]==V[nex]*(V[nex]-1)/2) {
				ok[nex]=1;
			}
			P[x]=P[y]=nex;
			nex++;
		}
	}
	dfs(nex-1);
	
	for(i=1;i<=N;i++) cout<<dp[nex-1][i]<<" ";
	cout<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}