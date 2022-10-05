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

int N,M,Q;
ll A[303030],B[303030];

template<class V,int NV> class SegTree_3 {
public:
	vector<V> val, ma;
	SegTree_3(){
		int i;
		val.resize(NV*2,0); ma.resize(NV*2,0);
	};
	
	V getval(int v,int l=0,int r=NV,int k=1) {
		if(v+ma[k]<=0) return -1;
		if(l+1==r) return l;
		
		if(v+val[k]+ma[2*k+1]>0) return getval(v+val[k],(l+r)/2,r,k*2+1);
		return getval(v+val[k],l,(l+r)/2,k*2);
	}
	
	void update(int x,int y, V v,int l=0,int r=NV,int k=1) {
		if(l>=r) return;
		if(x<=l && r<=y) {
			val[k]+=v;
			ma[k]+=v;
		}
		else if(l < y && x < r) {
			update(x,y,v,l,(l+r)/2,k*2);
			update(x,y,v,(l+r)/2,r,k*2+1);
			ma[k]=val[k]+max(ma[k*2],ma[k*2+1]);
		}
	}
};

SegTree_3<int,1<<20> st;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	FOR(i,N) {
		cin>>A[i];
		st.update(0,A[i]+1,1);
	}
	FOR(i,M) {
		cin>>B[i];
		st.update(0,B[i]+1,-1);
	}
	cin>>Q;
	int cur=0;
	while(Q--) {
		cin>>i>>x>>y;
		x--;
		if(i==1) {
			st.update(0,A[x]+1,-1);
			A[x]=y;
			st.update(0,A[x]+1,1);
		}
		else {
			st.update(0,B[x]+1,1);
			B[x]=y;
			st.update(0,B[x]+1,-1);
		}
		
		int cur=st.getval(0);
		if(cur<=0) cur=-1;
		
		cout<<cur<<endl;
	}
	
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}