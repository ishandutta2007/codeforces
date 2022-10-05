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

template<class V,int NV> class SegTree_Pair {
public:
	vector<pair<V,int> > val;
	static V const def=0;
	pair<V,int> comp(pair<V,int> l,pair<V,int> r){ return max(l,r);}
	SegTree_Pair(){
		val.resize(NV*2);
		int i;
		FOR(i,NV) val[i+NV]=make_pair(def,i);
		for(i=NV-1;i>=1;i--) val[i]=comp(val[2*i],val[2*i+1]);
	};
	pair<V,int> getval(int x,int y,int l=0,int r=NV,int k=1) {
		if(r<=x || y<=l) return make_pair(def,NV);
		if(x<=l && r<=y) return val[k];
		return comp(getval(x,y,l,(l+r)/2,k*2),getval(x,y,(l+r)/2,r,k*2+1));
	}
	void update(int entry, V v) {
		entry += NV;
		val[entry]=make_pair(v,entry-NV);
		while(entry>1) entry>>=1, val[entry]=comp(val[entry*2],val[entry*2+1]);
	}
};
SegTree_Pair<int,1<<20> st;

int N,K;
int A[303030];
ll S[303030];
vector<int> P[1010000];

ll dodo(int L,int R) {
	if(R-L<=0) return 0;
	auto ma=st.getval(L,R+1);
	ll ret=0;
	
	int i;
	if(ma.second-L<R-ma.second) {
		for(i=L;i<=ma.second;i++) {
			int v=(S[i-1]+ma.first)%K;
			ret += lower_bound(ALL(P[v]),R+1)-lower_bound(ALL(P[v]),ma.second+(i==ma.second));
		}
	}
	else {
		for(i=ma.second;i<=R;i++) {
			int v=(S[i]-ma.first)%K;
			ret += lower_bound(ALL(P[v]),ma.second-(i==ma.second))-lower_bound(ALL(P[v]),L-1);
		}
	}
	return ret+dodo(L,ma.second-1)+dodo(ma.second+1,R);
	
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>K;
	P[0].push_back(0);
	FOR(i,N) {
		cin>>A[i+1];
		S[i+1]=S[i]+A[i+1];
		P[S[i+1]%K].push_back(i+1);
		st.update(i+1,A[i+1]);
	}
	cout<<dodo(1,N)<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}