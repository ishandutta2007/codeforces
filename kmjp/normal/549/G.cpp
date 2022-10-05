#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define FORR(x,arr) for(auto& x:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

template<class V,int NV> class SegTree_3 {
public:
	vector<pair<V,int> > val;
	vector<pair<V,int> > ma;
	static V const def=-1LL<<50;
	SegTree_3(){
		int i;
		val.resize(NV*2); ma.resize(NV*2);
		FOR(i,NV) val[i+NV]=ma[i+NV]=make_pair(0,i);
		FOR(i,NV) val[i]=make_pair(0,0);
		for(i=NV-1;i>=1;i--) ma[i]=max(ma[2*i],ma[2*i+1]);
	};
	
	pair<V,int> getval(int x,int y,int l=0,int r=NV,int k=1) {
		if(r<=x || y<=l) return make_pair(def,0);
		if(x<=l && r<=y) return ma[k];
		auto a=max(getval(x,y,l,(l+r)/2,k*2),getval(x,y,(l+r)/2,r,k*2+1));
		a.first += val[k].first;
		return a;
	}
	
	void update(int x,int y, V v,int l=0,int r=NV,int k=1) {
		if(l>=r) return;
		if(x<=l && r<=y) {
			val[k].first+=v;
			ma[k].first+=v;
		}
		else if(l < y && x < r) {
			update(x,y,v,l,(l+r)/2,k*2);
			update(x,y,v,(l+r)/2,r,k*2+1);
			ma[k]=max(ma[k*2],ma[k*2+1]);
			ma[k].first += val[k].first;
		}
	}
};

int N,A[202000];

vector<ll> V;
SegTree_3<ll,1<<20> st;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) cin>>A[i], A[i]+=i;
	sort(A,A+N);
	FOR(i,N) A[i]-=i;
	FOR(i,N-1) if(A[i]>A[i+1]) return _P(":(\n");
	
	/*
	FOR(i,N) {
		cin>>A[i];
		st.update(i,i+1,A[i]-(N-1-i));
	}
	FOR(i,N) {
		auto r=st.getval(0,N);
		V.push_back(r.first);
		st.update(0,N,1);
		st.update(r.second,r.second+1,-1LL<<50);
	}
	reverse(ALL(V));
	FOR(i,N-1) if(V[i+1]<V[i]) return _P(":(\n");
	*/
	FOR(i,N) _P("%d ",A[i]);
	_P("\n");
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}