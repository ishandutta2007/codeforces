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

int N,Q;
int A[3][505050];
ll S[3][505050];

template<class V,int NV> class SegTree_1 {
public:
	vector<V> val;
	static V const def=-(1LL<<60);
	V comp(V l,V r){ return max(l,r);};
	
	SegTree_1(){val=vector<V>(NV*2,def);};
	V getval(int x,int y,int l=0,int r=NV,int k=1) { // x<=i<y
		if(r<=x || y<=l) return def;
		if(x<=l && r<=y) return val[k];
		return comp(getval(x,y,l,(l+r)/2,k*2),getval(x,y,(l+r)/2,r,k*2+1));
	}
	void update(int entry, V v) {
		entry += NV;
		val[entry]=comp(v,val[entry]); //
		while(entry>1) entry>>=1, val[entry]=comp(val[entry*2],val[entry*2+1]);
	}
};

template<class V,int NV> class SegTree_2 {
public:
	vector<V> A,B,C;
	static V const def=-(1LL<<60);
	V comp(V l,V r){ return max(l,r);};
	
	SegTree_2(){A=B=C=vector<V>(NV*2,def);};
	
	pair<pair<ll,ll>,ll> getval(int x,int y,int l=0,int r=NV,int k=1) { // x<=i<y
		if(r<=x || y<=l) return {{def,def},def};
		if(x<=l && r<=y) return {{A[k],B[k]},C[k]};
		auto a=getval(x,y,l,(l+r)/2,k*2);
		auto b=getval(x,y,(l+r)/2,r,k*2+1);
		ll s=max(a.first.first,b.first.first);
		ll t=max(a.first.second,b.first.second);
		ll u=max({a.second,b.second,a.first.first+b.first.second});
		return {{s,t},u};
	}
	void update(int entry, ll a,ll b) {
		entry += NV;
		A[entry]=a;
		B[entry]=b;
		C[entry]=a+b;
		while(entry>1) {
			entry>>=1;
			A[entry]=max(A[entry*2],A[entry*2+1]);
			B[entry]=max(B[entry*2],B[entry*2+1]);
			C[entry]=max({C[entry*2],C[entry*2+1],A[entry*2]+B[entry*2+1]});
		}
	}
};
SegTree_1<ll,1<<19> Sst;
SegTree_2<ll,1<<19> Fst;
ll ret=-1LL<<60;

vector<int> Rev[505050];
int L[505050],R[505050],K[505050];


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	scanf("%d%d",&N,&Q);
	FOR(y,3) {
		FOR(x,N) {
			scanf("%d",&A[y][x]);
			S[y][x+1]=S[y][x]+A[y][x];
		}
	}
	FOR(i,N) {
		Sst.update(i+1,S[0][i+1]-S[1][i]);
	}
	FOR(i,Q) {
		scanf("%d%d%d",&L[i],&R[i],&K[i]);
		Rev[R[i]].push_back(i);
	}
	for(i=1;i<=N;i++) {
		FORR(r,Rev[i]) {
			ll v=Sst.getval(L[r],R[r]+1)-K[r];
			Sst.update(i+1,v);
		}
	}
	for(i=1;i<=N;i++) {
		ll a=Sst.getval(i,i+1);
		ll b=S[1][i]+S[2][N]-S[2][i-1];
		Fst.update(i,a,b);
	}
	
	FOR(i,Q) {
		auto a=Fst.getval(L[i],R[i]+1);
		ret=max(ret,a.second-K[i]);
	}
	
	cout<<ret<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}