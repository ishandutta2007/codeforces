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

template<class V,int NV> class SegTree_count {
public:
	vector<V> val[NV*2];
	V comp(V l,V r){ return max(l,r);};
	SegTree_count(){ for(int i=NV;i<NV*2;i++) val[i].push_back(1<<30);}
	
	int getval(int x,int y,V v,int l=0,int r=NV,int k=1) {
		if(r<=x || y<=l) return 0;
		if(x<=l && r<=y) return lower_bound(ALL(val[k]),v+1)-val[k].begin();
		return getval(x,y,v,l,(l+r)/2,k*2)+getval(x,y,v,(l+r)/2,r,k*2+1);
	}
	void build() {
		for(int e=NV-1;e>=1;e--) {
			val[e].clear();
			merge(ALL(val[e*2]),ALL(val[e*2+1]),back_inserter(val[e]));
		}
	}
	void update(int entry, V v) {
		val[NV+entry][0]=v;
	}
};


int N,K;
int A[101010];
SegTree_count<int,1<<20> st;

vector<int> V[101010];
int pre[101010];
int Q;
int L,R;


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>K;
	FOR(i,N) {
		cin>>A[i];
		if(V[A[i]].size()>=K) pre[i]=V[A[i]][V[A[i]].size()-K];
		V[A[i]].push_back(i+1);
		st.update(i+1,pre[i]);
	}
	st.build();
	
	cin>>Q;
	int ret=0;
	while(Q--) {
		cin>>L>>R;
		L=(L+ret)%N;
		R=(R+ret)%N;
		if(L>R) swap(L,R);
		ret=st.getval(L+1,R+2,L);
		cout<<ret<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}