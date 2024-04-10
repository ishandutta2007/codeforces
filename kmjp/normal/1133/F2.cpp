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

int N,M,D;
vector<int> E[202020];
int used[202020];

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
UF<202020> uf;
vector<pair<int,int>> R;


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M>>D;
	FOR(i,M) {
		cin>>x>>y;
		E[x].push_back(y);
		E[y].push_back(x);
	}
	
	int ma=0;
	
	for(i=2;i<=N;i++) {
		FORR(e,E[i]) if(uf[e]!=uf[i] && e!=1 && i!=1) {
			uf(e,i);
		}
	}
	
	int num=0;
	for(i=2;i<=N;i++) if(uf[i]==i) num++;
	if(D<num || D>E[1].size()) return _P("NO\n");
	
	FORR(e,E[1]) if(uf[e]!=uf[1]) {
		uf(e,1);
		used[e]=1;
		D--;
	}
	
	
	FORR(e,E[1]) if(D&&used[e]==0) {
		used[e]=1;
		D--;
	}
	
	uf.reinit();
	FORR(e,E[1]) if(used[e]==1) {
		uf(e,1);
		R.push_back({1,e});
	}
	
	for(i=2;i<=N;i++) FORR(e,E[i]) if(e!=1 && uf[i]!=uf[e]) {
		uf(e,i);
		R.push_back({i,e});
	}
	
	
	
	
	cout<<"YES"<<endl;
	FORR(r,R) cout<<r.first<<" "<<r.second<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}