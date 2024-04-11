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
UF<500000> uf;

int N,M;
int A[404040],B[404040];

set<int> E[2][202020];
vector<pair<int,int>> R;
int S,T,DS,DT,ST;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	FOR(i,M) {
		cin>>A[i]>>B[i];
		A[i]--;
		B[i]--;
	}
	cin>>S>>T>>DS>>DT;
	S--,T--;
	if(S>T) swap(S,T),swap(DS,DT);
	FOR(i,M) {
		if(A[i]>B[i]) swap(A[i],B[i]);
		if(A[i]!=S && A[i]!=T && B[i]!=S && B[i]!=T && uf[A[i]]!=uf[B[i]]) {
			R.push_back({A[i],B[i]});
			uf(A[i],B[i]);
		}
	}
	
	FOR(i,M) {
		if(A[i]==S && B[i]==T) ST++;
		else if(A[i]==S) E[0][uf[B[i]]].insert(B[i]);
		else if(B[i]==S) E[0][uf[A[i]]].insert(A[i]);
		else if(A[i]==T) E[1][uf[B[i]]].insert(B[i]);
		else if(B[i]==T) E[1][uf[A[i]]].insert(A[i]);
	}
	
	
	FOR(i,N) {
		if(E[0][i].size() && E[1][i].size()) {
			DS--;
			DT--;
			uf(S,*E[0][i].begin());
			uf(T,*E[1][i].begin());
			R.push_back({S,*E[0][i].begin()});
			R.push_back({T,*E[1][i].begin()});
			E[0][i].clear();
			E[1][i].clear();
			break;
		}
	}
	
	if(uf[S]!=uf[T]) {
		if(ST==0) return _P("No\n");
		R.push_back({S,T});
		DS--;
		DT--;
		uf(S,T);
	}
	
	FOR(i,N) {
		if(E[0][i].size() && E[1][i].empty()) {
			DS--;
			uf(S,*E[0][i].begin());
			R.push_back({S,*E[0][i].begin()});
			E[0][i].clear();
		}
		if(E[1][i].size() && E[0][i].empty()) {
			DT--;
			uf(T,*E[1][i].begin());
			R.push_back({T,*E[1][i].begin()});
			E[1][i].clear();
		}
	}
	
	FOR(i,N) if(E[0][i].size() && E[1][i].size()) {
		if(DS>=DT) {
			DS--;
			uf(S,*E[0][i].begin());
			R.push_back({S,*E[0][i].begin()});
			E[0][i].clear();
		}
		else {
			DT--;
			uf(T,*E[1][i].begin());
			R.push_back({T,*E[1][i].begin()});
			E[1][i].clear();
		}
	}
	
	
	if(DS<0 || DT<0 || uf.count(S)!=N) return _P("No\n");
	_P("Yes\n");
	FORR(r,R) _P("%d %d\n",r.first+1,r.second+1);
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}