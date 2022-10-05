#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define FORR2(x,y,arr) for(auto& [x,y]:arr)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
template<class T> bool chmax(T &a, const T &b) { if(a<b){a=b;return 1;}return 0;}
template<class T> bool chmin(T &a, const T &b) { if(a>b){a=b;return 1;}return 0;}
//-------------------------------------------------------

int N,M,X;
ll A[303030];

set<pair<int,int>> E[303030];
int R[303030];
int U[303030],V[303030];

template<int um> class UF {
	public:
	vector<int> par,rank,cnt;
	UF() {par=rank=vector<int>(um,0); cnt=vector<int>(um,1); for(int i=0;i<um;i++) par[i]=i;}
	void reinit(int num=um) {int i; FOR(i,num) rank[i]=0,cnt[i]=1,par[i]=i;}
	int operator[](int x) {return (par[x]==x)?(x):(par[x] = operator[](par[x]));}
	int count(int x) { return cnt[operator[](x)];}
	int operator()(int x,int y) {
		if((x=operator[](x))==(y=operator[](y))) return x;
		cnt[y]=cnt[x]=cnt[x]+cnt[y];
		if(rank[x]>rank[y]) return par[x]=y;
		rank[x]+=rank[x]==rank[y]; return par[y]=x;
	}
};
UF<303030> uf;
vector<int> ret;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M>>X;
	ll sum=0;
	FOR(i,N) {
		cin>>A[i];
		sum+=A[i];
	}
	if(sum<1LL*(N-1)*X) {
		cout<<"NO"<<endl;
		return;
	}
	
	FOR(i,M) {
		cin>>U[i]>>V[i];
		U[i]--;
		V[i]--;
		if(uf[U[i]]!=uf[V[i]]) {
			uf(U[i],V[i]);
			E[U[i]].insert({V[i],i+1});
			E[V[i]].insert({U[i],i+1});
		}
	}
	
	
	uf.reinit();
	set<pair<ll,int>> S;
	FOR(i,N) S.insert({-A[i],i});

	cout<<"YES"<<endl;
	while(S.size()>1) {
		int cur=uf[S.begin()->second];
		S.erase(S.begin());
		
		int tar=0;
		while(E[cur].size()) {
			tar=uf[E[cur].begin()->first];
			if(cur!=tar) break;
			E[cur].erase(E[cur].begin());
		}
		cout<<E[cur].begin()->second<<endl;
		E[cur].erase(E[cur].begin());
		x=uf(cur,tar);
		y=cur+tar-x;
		S.erase({-A[tar],tar});
		A[cur]=A[tar]=A[cur]+A[tar]-X;
		S.insert({-A[x],x});
		if(E[x].size()<E[y].size()) swap(E[x],E[y]);
		FORR(v,E[y]) E[x].insert(v);
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}