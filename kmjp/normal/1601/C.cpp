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

int T;
int N,M;
int A[1010101],B[1010101];

template<class V, int ME> class BIT {
public:
	V bit[1<<ME];
	V operator()(int e) {V s=0;e++;while(e) s+=bit[e-1],e-=e&-e; return s;}
	void add(int e,V v) { e++; while(e<=1<<ME) bit[e-1]+=v,e+=e&-e;}
};

static ll const def=1<<21;
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


BIT<int,20> bt;
template<class C> ll array_inv(vector<C> V) {
	
	int x=0,i;
	
	vector<pair<C,int>> W;
	FOR(i,V.size()) W.push_back({V[i],i});
	sort(ALL(W));
	reverse(ALL(W));
	ll ret=0;
	FOR(i,W.size()) {
		ret += bt(W[i].second-1);
		bt.add(W[i].second,1);
	}
	FOR(i,W.size()) bt.add(i,-1);
	return ret;
}

SegTree_3<int,1<<21> st;
vector<int> step[2020202];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N>>M;
		vector<int> Xs;
		FOR(i,N) {
			cin>>A[i];
			Xs.push_back(A[i]);
			st.update(i+1,N+1,1);
		}
		FOR(i,M) {
			cin>>B[i];
			Xs.push_back(B[i]);
		}
		sort(B,B+M);
		sort(ALL(Xs));
		Xs.erase(unique(ALL(Xs)),Xs.end());
		FOR(i,N) {
			A[i]=lower_bound(ALL(Xs),A[i])-Xs.begin();
			step[A[i]].push_back(i);
		}
		FOR(i,M) {
			B[i]=lower_bound(ALL(Xs),B[i])-Xs.begin();
			step[B[i]].push_back(N+1);
		}
		
		ll ret=array_inv(vector<ll>(A,A+N));
		FOR(i,Xs.size()) {
			FORR(x,step[i]) if(x<N) st.update(x+1,N+1,-1);
			FORR(x,step[i]) if(x>=N) ret+=st.getval(0,N+1);
			FORR(x,step[i]) if(x<N) st.update(0,x+1,1);
			step[i].clear();
		}
		
		cout<<ret<<endl;
		FOR(i,N) st.update(0,i+1,-1);
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}