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

ll mo=1000000007;
ll rev(ll a) {
	ll r=1, n=mo-2;
	while(n) r=r*((n%2)?a:1)%mo,a=a*a%mo,n>>=1;
	return r;
}


template<int NV> class SegTree {
public:
	vector<ll> mul,sum;
	SegTree(){sum.resize(NV*2); mul=vector<ll>(NV*2,1);};
	ll update(int x,int y,int v,int l=0,int r=NV,int k=1) {
		if(l>=r) return 0;
		if(x<=l && r<=y) {
			(mul[k]*=v)%=mo;
			(sum[k]*=v)%=mo;
			return sum[k];
		}
		else if(l < y && x < r) {
			ll ret=0;
			ret += update(x,y,v,l,(l+r)/2,k*2);
			ret += update(x,y,v,(l+r)/2,r,k*2+1);
			sum[k]=(sum[k*2]+sum[k*2+1])*mul[k]%mo;
			return ret*mul[k]%mo;
		}
		else {
			return 0;
		}
	}
};
SegTree<1<<20> st;

int Q,N;
vector<int> E[202020];
int QtoV[202020];
int T[202020],P[202020],V[202020],U[202020];

int id=1;
int L[202020],R[202020];
int NC[202020];

void dfs(int cur) {
	L[cur]=id++;
	FORR(r,E[cur]) dfs(r);
	R[cur]=id;
}


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>V[1]>>Q;
	N=1;
	FOR(i,Q) {
		cin>>T[i];
		if(T[i]==1) {
			QtoV[i]=++N;
			cin>>P[N]>>V[N];
			E[P[N]].push_back(N);
		}
		else {
			cin>>U[i];
		}
	}
	dfs(1);
	r=L[1]+(1<<20);
	st.sum[r]=V[1]*st.mul[r]%mo;
	st.update(1,2,1);
	
	FOR(i,Q) {
		if(T[i]==1) {
			x = QtoV[i];
			y = P[x];
			ll mult=st.update(L[y],L[y]+1,1)*rev(V[y])%mo;
			NC[y]++;
			st.update(L[y],R[y],(NC[y]+1)*rev(NC[y])%mo);
			
			int r = L[x]+(1<<20);
			st.sum[r]=V[x]*st.mul[r]%mo;
			st.update(L[x],L[x]+1,1);
			
			
		}
		else {
			x = U[i];
			ll s=st.update(L[x],R[x],1);
			ll n1=st.update(L[x],L[x]+1,1)*rev(V[x])%mo;
			ll n2=NC[x]+1;
			cout<<(s*n2%mo*rev(n1)%mo)<<endl;
		}
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}