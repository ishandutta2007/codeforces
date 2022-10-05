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
		val[entry]=comp(v,val[entry]);
		while(entry>1) entry>>=1, val[entry]=comp(val[entry*2],val[entry*2+1]);
	}
};
SegTree_1<ll,1<<20> stL,stR;
int N,A;
ll D[303030],C[303030];
ll LC[303030],RC[303030];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>A;
	ll ret=0;
	FOR(i,N) {
		cin>>D[i+1]>>C[i+1];
		C[i+1]=A-C[i+1];
		ret=max(ret,C[i+1]);
		LC[i+1]=LC[i]+C[i+1];
	}
	set<int> NG;
	NG.insert(1);
	NG.insert(N+1);
	for(i=N;i>=1;i--) {
		RC[i]=RC[i+1]+C[i];
		stL.update(i,LC[i]);
		stR.update(i,RC[i]);
	}
	priority_queue<pair<ll,int>> PQ;
	for(i=2;i<=N;i++) PQ.push({(D[i]-D[i-1])*(D[i]-D[i-1]),i});
	
	while(PQ.size()) {
		auto p=PQ.top();
		PQ.pop();
		
		x=p.second;
		auto it=NG.lower_bound(p.second);
		int R=*it;
		it--;
		int L=*it;
		NG.insert(x);
		
		ret=max(ret,stL.getval(x,R)-LC[x-1]+stR.getval(L,x)-RC[x]-p.first);
	}
	cout<<ret<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}