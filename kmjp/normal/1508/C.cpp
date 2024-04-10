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

int N,M;
set<pair<int,int>> E[202020];
set<int> S[202020];
int U[202020],V[202020],C[202020];

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
UF<202020> uf;


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	int T=0;
	ll lef=1LL*N*(N-1)/2-M;
	vector<pair<int,ll>> cand,cand2;
	FOR(i,M) {
		cin>>U[i]>>V[i]>>C[i];
		U[i]--;
		V[i]--;
		T^=C[i];
		S[U[i]].insert(V[i]);
		S[V[i]].insert(U[i]);
		ll a=1LL*U[i]*1000000+V[i];
		cand.push_back({C[i],a});
	}
	
	ll ret=0;
	if(lef>=N) {
		set<int> L;
		FOR(i,N) L.insert(i);
		while(L.size()) {
			x=*L.begin();
			L.erase(x);
			queue<int> Q;
			Q.push(x);
			while(Q.size()) {
				int cur=Q.front();
				Q.pop();
				vector<int> D;
				FORR(a,L) {
					if(S[cur].count(a)==0) {
						D.push_back(a);
						Q.push(a);
						uf(cur,a);
					}
				}
				FORR(a,D) L.erase(a);
			}
		}
		FOR(i,M) {
			ll a=1LL*U[i]*1000000+V[i];
			cand.push_back({C[i],a});
		}
		
		sort(ALL(cand));
		FORR2(c,a,cand) {
			x=a/1000000;
			y=a%1000000;
			if(uf[x]!=uf[y]) uf(x,y), ret+=c, cand2.push_back({c,a});
		}
	}
	else {
		sort(ALL(cand));
		FORR2(c,a,cand) {
			x=a/1000000;
			y=a%1000000;
			if(uf[x]!=uf[y]) uf(x,y), cand2.push_back({c,a});
		}
		ret=1LL<<60;
		vector<pair<int,int>> cand3;
		FOR(x,N) FOR(y,N) if(x<y&&S[x].count(y)==0) {
			cand3.push_back({x,y});
		}
		FORR(v,cand3) {
			UF<1000> uf;
			cand=cand2;
			FORR(w,cand3) {
				ll a=1LL*w.first*1000000+w.second;
				if(v==w) cand.push_back({T,a});
				else cand.push_back({0,a});
			}
			ll sum=0;
			sort(ALL(cand));
			FORR2(c,a,cand) {
				x=a/1000000;
				y=a%1000000;
				if(uf[x]!=uf[y]) uf(x,y), sum+=c;
			}
			ret=min(ret,sum);
		}
	}
	cout<<ret<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}