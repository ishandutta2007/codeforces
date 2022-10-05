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

template<class V,int NV> class SegTree {
public:
	vector<V> val;
	vector<V> ma;
	static V const def=0;
	SegTree(){
		val.resize(NV*2); ma.resize(NV*2);
	};
	
	V getval(int x,int y,int l=0,int r=NV,int k=1) {
		if(r<=x || y<=l) return 0;
		if(val[k]) return val[k];
		if(x<=l && r<=y) return ma[k];
		return getval(x,y,l,(l+r)/2,k*2)|getval(x,y,(l+r)/2,r,k*2+1);
	}
	
	void update(int x,int y, V v,int l=0,int r=NV,int k=1) {
		if(l>=r) return;
		if(x<=l && r<=y) {
			val[k]=ma[k]=v;
		}
		else if(l < y && x < r) {
			if(val[k]>0) {
				val[2*k]=val[2*k+1]=val[k];
				ma[2*k]=ma[2*k+1]=val[k];
				val[k]=0;
			}
			update(x,y,v,l,(l+r)/2,k*2);
			update(x,y,v,(l+r)/2,r,k*2+1);
			ma[k]=ma[k*2]|ma[k*2+1];
		}
	}
};

int N,Q;
vector<int> E[404040];
int C[404040];
int L[404040],R[404040],eid;
SegTree<ll,1<<20> st;

void EulerTour(int cur,int pre=-1) {
	if(pre==-1) ZERO(L),ZERO(R),eid=1;
	L[cur]=eid++;
	ITR(it,E[cur]) if(*it!=pre) EulerTour(*it,cur);
	R[cur]=eid;
}


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>Q;
	FOR(i,N) cin>>C[i];
	FOR(i,N-1) {
		cin>>x>>y;
		E[x-1].push_back(y-1);
		E[y-1].push_back(x-1);
	}
	EulerTour(0);
	FOR(i,N) st.update(L[i],L[i]+1,1LL<<C[i]);
	while(Q--) {
		cin>>i;
		if(i==1) {
			cin>>x>>y;
			st.update(L[x-1],R[x-1],1LL<<y);
		}
		else {
			cin>>x;
			ll v=st.getval(L[x-1],R[x-1]);
			cout<<__builtin_popcountll(v)<<endl;
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