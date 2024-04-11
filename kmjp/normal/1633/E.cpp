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
int U[303],V[303];
ll W[303];
ll P,K,A,B,C;

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

vector<ll> cm,cp;

ll hoge(ll x) {
	UF<55> uf;
	vector<pair<ll,int>> E;
	int i;
	FOR(i,M) E.push_back({abs(W[i]*1000-x),i});
	sort(ALL(E));
	ll ret=0;
	FORR2(c,i,E) {
		if(uf[U[i]]!=uf[V[i]]) {
			ret+=c;
			uf(U[i],V[i]);
		}
	}
	return ret;
	
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	vector<ll> cand;
	FOR(i,M) {
		cin>>U[i]>>V[i]>>W[i];
		U[i]--;
		V[i]--;
		W[i]*=2;
		cand.push_back(W[i]);
	}
	FOR(x,M) FOR(y,x) cand.push_back((W[x]+W[y])/2);
	
	sort(ALL(cand));
	cand.erase(unique(ALL(cand)),cand.end());
	FORR(c,cand) {
		cm.push_back(hoge(c*1000-1));
		cp.push_back(hoge(c*1000+1));
	}
	cin>>P>>K>>A>>B>>C;
	ll tret=0;
	int R;
	FOR(i,K) {
		ll ret=0;
		if(i<P) {
			cin>>R;
		}
		else {
			R=(1LL*R*A+B)%C;
		}
		R*=2;
		x=lower_bound(ALL(cand),R)-cand.begin();
		if(x==cand.size()) {
			x--;
		}
		else if(x&&cand[x]-R>R-cand[x-1]) {
			x--;
		}
		
		
		
		if(R>=cand[x]) {
			y=cp[x]%1000;
			if(y<500) {
				ret=(cp[x]+500)/1000+(R-cand[x])*y;
			}
			else {
				ret=(cp[x]+500)/1000+(R-cand[x])*(y-1000);
			}
		}
		else {
			y=cm[x]%1000;
			if(y<500) {
				ret=(cm[x]+500)/1000-(cand[x]-R)*(-y);
			}
			else {
				ret=(cm[x]+500)/1000-(cand[x]-R)*(1000-y);
			}
		}
		ret/=2;
		tret^=ret;
		R/=2;
	}
	cout<<tret<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}