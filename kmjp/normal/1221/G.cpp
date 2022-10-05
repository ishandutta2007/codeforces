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
ll E[51];
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
UF<41> uf;
int vis[51];
ll num[1<<20];

ll F012() {
	return 1LL<<N;
}

ll F01() {
	int i;
	int mask;
	ll ret=0;
	FOR(mask,1<<(min(20,N))) {
		int ok=1;
		FOR(i,min(20,N)) if(mask&(1<<i)) {
			if(E[i]&mask) ok=0;
		}
		num[mask]=ok;
	}
	FOR(i,20) FOR(mask,1<<20) if(mask&(1<<i)) num[mask]+=num[mask^(1<<i)];
	FOR(mask,1<<20) {
		int ok=1;
		ll tmask=0;
		FOR(i,20) if(mask&(1<<i)) {
			if(i+20>=N) ok=0;
			tmask |= E[i+20];
			if(mask&(E[i+20]>>20)) ok=0;
		}
		if(ok) {
			tmask = ~tmask&((1<<20)-1);
			ret+=num[tmask];
		}
	}
	return ret;
}


ll F02(){
	int C=0;
	int i;
	FOR(i,N) if(uf[i]==i) C++;
	return 1LL<<C;
}
ll F0() {
	int C=0;
	int i;
	FOR(i,N) if(E[i]==0) C++;
	return 1LL<<C;
}

int dfs(int cur,int pre,int v) {
	if(vis[cur]!=-1) return vis[cur]==v;
	vis[cur]=v;
	int ret=1;
	int i;
	FOR(i,N) if(E[cur]&(1LL<<i)) ret &= dfs(i,cur,v^1);
	return ret;
}
ll F1() {
	ll ret=1;
	int i;
	MINUS(vis);
	FOR(i,N) if(uf[i]==i) {
		if(dfs(i,-1,0)==0) return 0;
		ret*=2;
	}
	return ret;
}
ll F() {
	if(M==0) return 1LL<<N;
	return 0;
}
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	FOR(i,M) {
		cin>>x>>y;
		x--,y--;
		uf(x,y);
		E[x] |= 1LL<<y;
		E[y] |= 1LL<<x;
	}
	
	ll ret=F012()-2*F01()-F02()+2*F0()+F1()-F();
	cout<<ret<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}