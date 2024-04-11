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

int N;
int A[101010],B[101010],H[101010];
vector<int> V;
vector<pair<int,int>> E[202020];

template<class V,int NV> class SegTree_1 {
public:
	vector<V> val;
	static V const def=-1LL<<40;
	V comp(V l,V r){ return max(l,r);};
	
	SegTree_1(){val=vector<V>(NV*2,def);};
	V getval(int x,int y,int l=0,int r=NV,int k=1) { // x<=i<y
		if(r<=x || y<=l) return def;
		if(x<=l && r<=y) return val[k];
		return comp(getval(x,y,l,(l+r)/2,k*2),getval(x,y,(l+r)/2,r,k*2+1));
	}
	void update(int entry, V v) {
		entry += NV;
		val[entry]=v;
		while(entry>1) entry>>=1, val[entry]=comp(val[entry*2],val[entry*2+1]);
	}
};

SegTree_1<ll,1<<20> st;
ll TH[202020];


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	V.push_back(0);
	FOR(i,N) {
		cin>>A[i]>>B[i]>>H[i];
		V.push_back(A[i]);
		V.push_back(B[i]);
	}
	FOR(i,2*N+2) TH[i]=-1LL<<40;
	TH[0]=0;
	st.update(0,0);
	sort(ALL(V));
	V.erase(unique(ALL(V)),V.end());
	FOR(i,N) {
		A[i]=lower_bound(ALL(V),A[i])-V.begin();
		B[i]=lower_bound(ALL(V),B[i])-V.begin();
		E[B[i]].push_back({A[i],i});
	}
	ll ma=0;
	for(i=200010;i>=0;i--) {
		sort(ALL(E[i]));
		reverse(ALL(E[i]));
		FORR(e,E[i]) {
			x=e.second;
			ll v=max(0LL,st.getval(0,B[x]))+H[x];
			if(v>TH[A[x]]) {
				ma=max(ma,v);
				TH[A[x]]=v;
				st.update(A[x],v);
			}
		}
	}
	cout<<ma<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}