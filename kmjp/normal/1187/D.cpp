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

int Q,N;
int A[303030],B[303030];
int T[303030];

template<class V,int NV> class SegTree_1 {
public:
	vector<V> val;
	static V const def=0;
	V comp(V l,V r){ return max(l,r);};
	
	SegTree_1(){val=vector<V>(NV*2,def);};
	V getval(int x,int y,int l=0,int r=NV,int k=1) { // x<=i<y
		if(r<=x || y<=l) return def;
		if(x<=l && r<=y) return val[k];
		return comp(getval(x,y,l,(l+r)/2,k*2),getval(x,y,(l+r)/2,r,k*2+1));
	}
	void update(int entry, V v) {
		entry += NV;
		val[entry]=comp(v,val[entry]);
		while(entry>1) entry>>=1, val[entry]=comp(val[entry*2],val[entry*2+1]);
	}
	void set(int entry, V v) {
		entry += NV;
		val[entry]=v;
		while(entry>1) entry>>=1, val[entry]=comp(val[entry*2],val[entry*2+1]);
	}
};

SegTree_1<int,1<<20> st;

int ok() {
	map<int,deque<int>> M;
	int i,x;
	FOR(i,N) M[B[i]].push_back(i);
	FOR(i,N) {
		if(M[A[i]].empty()) return 0;
		T[i]=M[A[i]].front();
		M[A[i]].pop_front();
	}
	
	int ret=1;
	FOR(i,N) {
		x=st.getval(0,A[i]);
		if(x>T[i]) ret=0;
		st.update(A[i],T[i]);
	}
	
	FOR(i,N) st.set(A[i],0);
	
	reverse(A,A+N);
	reverse(T,T+N);
	FOR(i,N) T[i]=N-1-T[i];
	
	FOR(i,N) {
		x=st.getval(A[i]+1,1<<19);
		if(x>T[i]) ret=0;
		st.update(A[i],T[i]);
	}
	
	FOR(i,N) st.set(A[i],0);
	
	return ret;
}


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>Q;
	FOR(i,Q) {
		cin>>N;
		FOR(j,N) cin>>A[j];
		FOR(j,N) cin>>B[j];
		if(ok()) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}