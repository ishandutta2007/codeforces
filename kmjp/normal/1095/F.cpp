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
vector<vector<ll>> V;
ll A[202020];
set<pair<ll,int>> S;

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

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	FOR(i,N) {
		cin>>A[i];
		S.insert({A[i],i});
	}
	
	FOR(i,M) {
		ll a;
		cin>>x>>y>>a;
		V.push_back({a,x-1,y-1});
	}
	sort(ALL(V));
	reverse(ALL(V));
	
	ll ret=0;
	while(S.size()>1) {
		auto it=S.begin();
		ll t=it->first;
		it++;
		t+=it->first;
		
		while(V.size() && V.back()[0]<=t) {
			x=uf[V.back()[1]];
			y=uf[V.back()[2]];
			if(x==y) {
				V.pop_back();
				continue;
			}
			
			S.erase({A[x],x});
			S.erase({A[y],y});
			ret+=V.back()[0];
			A[x]=A[y]=min(A[x],A[y]);
			uf(x,y);
			x=uf[x];
			S.insert({A[x],x});
			V.pop_back();
			goto retry;
		}
		
		{
			auto a=*S.begin();
			S.erase(S.begin());
			auto b=*S.begin();
			S.erase(S.begin());
			x=uf[a.second];
			y=uf[b.second];
			
			S.erase({A[x],x});
			S.erase({A[y],y});
			ret+=A[x]+A[y];
			A[x]=A[y]=min(A[x],A[y]);
			uf(x,y);
			x=uf[x];
			S.insert({A[x],x});
		}
		
		retry:
		;
	}
	
	cout<<ret<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}