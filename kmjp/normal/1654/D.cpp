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

int T,N;
int A[202020],B[202020],X[202020],Y[202020];
const ll mo=998244353;
vector<pair<int,int>> E[202020];
int L[202020],R[202020];
int id;
ll sum=0;

static ll const def=1<<20;
template<class V,int NV> class SegTree_3 {
public:
	vector<V> val, ma;
	SegTree_3(){
		int i;
		val.resize(NV*2,0); ma.resize(NV*2,0);
	};
	
	V getval(int x,int y,int l=0,int r=NV,int k=1) {
		if(r<=x || y<=l || y<=x) return def;
		if(x<=l && r<=y) return ma[k];
		return val[k]+min(getval(x,y,l,(l+r)/2,k*2),getval(x,y,(l+r)/2,r,k*2+1));
	}
	
	void update(int x,int y, V v,int l=0,int r=NV,int k=1) {
		if(l>=r||y<=x) return;
		if(x<=l && r<=y) {
			val[k]+=v;
			ma[k]+=v;
		}
		else if(l < y && x < r) {
			update(x,y,v,l,(l+r)/2,k*2);
			update(x,y,v,(l+r)/2,r,k*2+1);
			ma[k]=val[k]+min(ma[k*2],ma[k*2+1]);
		}
	}
};
SegTree_3<int,1<<20> st;

ll modpow(ll a, ll n = mo-2) {
	ll r=1;a%=mo;
	while(n) r=r*((n%2)?a:1)%mo,a=a*a%mo,n>>=1;
	return r;
}

const int prime_max = 1000000;
vector<int> prime;
int NP,divp[prime_max];

void cprime() {
	if(NP) return;
	for(int i=2;i<prime_max;i++) if(divp[i]==0) {
		//M[i]=NP;
		prime.push_back(i); NP++;
		for(ll j=1LL*i;j>=i&&j<prime_max;j+=i) if(divp[j]==0) divp[j]=i;
	}
}

void dfs(int cur,int pre,ll s) {
	L[cur]=id++;
	(sum+=s)%=mo;
	FORR2(e,i,E[cur]) if(e!=pre) {
		if(A[i]==cur) {
			dfs(e,cur,s*Y[i]%mo*modpow(X[i])%mo);
		}
		else {
			dfs(e,cur,s*X[i]%mo*modpow(Y[i])%mo);
		}
		
	}
	R[cur]=id;
}


vector<pair<int,pair<int,int>>> ev[202020];

void solve() {
	int i,j,k,l,r,x,y; string s;
	cprime();
	cin>>T;
	while(T--) {
		cin>>N;
		FOR(i,N+2) {
			E[i].clear();
			ev[i].clear();
		}
		
		FOR(i,N-1) {
			cin>>A[i]>>B[i]>>X[i]>>Y[i];
			A[i]--;
			B[i]--;
			int g=__gcd(X[i],Y[i]);
			X[i]/=g;
			Y[i]/=g;
			E[A[i]].push_back({B[i],i});
			E[B[i]].push_back({A[i],i});
		}
		id=sum=0;
		dfs(0,0,1);
		FOR(i,N-1) {
			x=X[i];
			while(x>1) {
				y=divp[x];
				if(L[A[i]]<L[B[i]]) {
					ev[y].push_back({-1,{L[B[i]],R[B[i]]}});
				}
				else {
					ev[y].push_back({1,{L[A[i]],R[A[i]]}});
				}
				x/=y;
			}
			x=Y[i];
			while(x>1) {
				y=divp[x];
				if(L[A[i]]>L[B[i]]) {
					ev[y].push_back({-1,{L[A[i]],R[A[i]]}});
				}
				else {
					ev[y].push_back({1,{L[B[i]],R[B[i]]}});
				}
				x/=y;
			}
		}
		FOR(i,N+1) if(ev[i].size()) {
			FORR2(e,r,ev[i]) {
				st.update(r.first,r.second,e);
			}
			x=st.getval(0,N);
			while(x>0) {
				x--;
				(sum*=modpow(i))%=mo;
			}
			while(x<0) {
				x++;
				(sum*=i)%=mo;
			}
			
			
			FORR2(e,r,ev[i]) {
				st.update(r.first,r.second,-e);
			}
		}
		
		cout<<sum<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}