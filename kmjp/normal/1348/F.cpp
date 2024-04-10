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

template<class V,int NV> class SegTree_1 {
public:
	vector<pair<V,int>> val;
	static V const def=1<<30;
	pair<V,int> comp(pair<V,int> l,pair<V,int> r){ return min(l,r);};
	
	SegTree_1(){val=vector<pair<V,int>>(NV*2,make_pair(1<<30,0));};
	pair<V,int> getval(int x,int y,int l=0,int r=NV,int k=1) { // x<=i<y
		if(r<=x || y<=l) return make_pair(1<<30,0);
		if(x<=l && r<=y) return val[k];
		return comp(getval(x,y,l,(l+r)/2,k*2),getval(x,y,(l+r)/2,r,k*2+1));
	}
	void update(int entry, pair<V,int> v) {
		entry += NV;
		val[entry]=v;
		while(entry>1) entry>>=1, val[entry]=comp(val[entry*2],val[entry*2+1]);
	}
};
SegTree_1<int,1<<20> st;
int N;
int L[202020],R[202020];
vector<int> add[202020];
vector<int> del[202020];
int A[202020],ret[202020];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) {
		cin>>L[i]>>R[i];
		L[i]--,R[i]--;
		add[L[i]].push_back(i);
	}
	
	set<pair<int,int>> Rs;
	FOR(i,N) {
		FORR(a,add[i]) Rs.insert({R[a],a});
		
		assert(Rs.size());
		
		A[i]=Rs.begin()->second;
		st.update(i,make_pair(L[A[i]],A[i]));
		Rs.erase(Rs.begin());
	}
	
	FOR(j,N) ret[A[j]]=j+1;
	FOR(i,N-1) {
		x=A[i];
		
		auto a=st.getval(i+1,R[x]+1);
		if(a.first<=i) {
			cout<<"NO"<<endl;
			FOR(j,N) cout<<ret[j]<<" ";
			cout<<endl;
			swap(ret[x],ret[a.second]);
			FOR(j,N) cout<<ret[j]<<" ";
			cout<<endl;
			return;
		}
		
	}
	
	cout<<"YES"<<endl;
	FOR(i,N) cout<<ret[i]<<" ";
	cout<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}