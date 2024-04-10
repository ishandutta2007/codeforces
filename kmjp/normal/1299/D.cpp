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
vector<pair<int,int>> E[101010];

template<int um> class UF {
	public:
	vector<int> par,rank;
	UF() {rank=vector<int>(um,0); for(int i=0;i<um;i++) par.push_back(i);}
	int operator[](int x) {return (par[x]==x)?(x):(par[x] = operator[](par[x]));}
	int operator()(int x,int y) {
		if((x=operator[](x))==(y=operator[](y))) return x;
		if(rank[x]>rank[y]) return par[x]=y;
		rank[x]+=rank[x]==rank[y]; return par[y]=x;
	}
};
UF<500000> uf;

map<vector<int>,int> BM;
vector<int> B[505];
int mp[400][400];

vector<int> T[101010];
vector<int> V[101010];
int vis[101010];
ll mo=1000000007;

set<pair<int,int>> did;



int gf2_rank(vector<int>& V) { /* input */
	int i,j;
	int N=V.size();
	FOR(i,N) {
		int x=max_element(V.begin()+i,V.end())-V.begin();
		if(V[x]==0) break;
		swap(V[i],V[x]);
		int msb=1;
		while(msb<<1 <= V[i]) msb<<=1;
		FOR(j,N) if(j!=i) if(V[j]&msb) V[j]^=V[i];
	}
	return N-count(V.begin(),V.end(),0);
}

void dfs_vec(int cur,vector<int> V) {
	if(cur==-1) {
		int x=gf2_rank(V);
		if(x==V.size() && BM.count(V)==0) {
			int x=BM.size();
			B[x]=V;
			BM[V]=x;
		}
		return;
	}
	
	int i;
	dfs_vec(cur-1,V);
	FOR(i,1<<cur) {
		V.push_back((1<<cur)|i);
		dfs_vec(cur-1,V);
		V.pop_back();
	}
}

void dfs(int cur,int pre,int v,int id) {
	if(cur==0) return;
	if(did.count({pre,cur})) return;
	did.insert({cur,pre});
	if(vis[cur]!=-1) {
		V[id].push_back(v^vis[cur]);
		return;
	}
	vis[cur]=v;
	FORR(e,E[cur]) if(e.first!=pre) dfs(e.first,cur,v^e.second,id);
}


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	
	
	
	scanf("%d%d",&N,&M);
	FOR(i,M) {
		scanf("%d%d%d",&x,&y,&r);
		E[x-1].push_back({y-1,r});
		E[y-1].push_back({x-1,r});
		if(x>1 && y>1) uf(x-1,y-1);
	}
	
	FORR(e,E[0]) T[uf[e.first]].push_back(e.first);
	
	B[0]={-1};
	BM[B[0]]=0;
	dfs_vec(4,{});
	for(i=1;i<BM.size();i++) {
		for(j=1;j<=i;j++) {
			vector<int> A=B[i];
			FORR(v,B[j]) A.push_back(v);
			
			if(gf2_rank(A)==A.size()) {
				sort(ALL(A));
				reverse(ALL(A));
				assert(BM.count(A));
				mp[i][j]=mp[j][i]=BM[A];
			}
		}
	}
	ll from[400]={};
	from[BM[{}]]=1;
	MINUS(vis);
	
	for(j=1;j<N;j++) if(uf[j]==j) {
		dfs(j,j,0,j);
		
		if(gf2_rank(V[j])!=V[j].size()) {
			x=0;
		}
		else {
			assert(BM.count(V[j]));
			x=BM[V[j]];
		}
		
		ll to[400]={};
		FOR(i,BM.size()) to[i]=from[i];
		if(T[j].size()==1) {
			FOR(i,BM.size()) to[mp[i][x]]+=from[i];
		}
		else {
			assert(T[j].size()==2);
			int mask=0;
			FORR(e,E[T[j][0]]) if(e.first==0 || e.first==T[j][1]) mask^=e.second;
			FORR(e,E[T[j][1]]) if(e.first==0) mask^=e.second;
			if(mask==0) {
				y=0;
			}
			else {
				y=BM[{mask}];
			}
			FOR(i,BM.size()) {
				to[mp[i][x]]+=2*from[i];
				to[mp[i][mp[x][y]]]+=from[i];
			}
		}
		FOR(i,BM.size()) from[i]=to[i]%mo;
	}
	
	ll ret=0;
	FOR(i,BM.size()) if(i) ret+=from[i];
	cout<<ret%mo<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}