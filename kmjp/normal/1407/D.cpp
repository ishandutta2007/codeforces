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
int H[303030];

vector<int> T[303030];

template<class V,int NV> class SegTree_ma {
public:
	vector<V> val;
	static V const def=0;
	V comp(V l,V r){ return max(l,r);};
	
	SegTree_ma(){val=vector<V>(NV*2,def);};
	V getval(int x,int y,int l=0,int r=NV,int k=1) { // x<=i<y
		if(r<=x || y<=l) return def;
		if(x<=l && r<=y) return val[k];
		return comp(getval(x,y,l,(l+r)/2,k*2),getval(x,y,(l+r)/2,r,k*2+1));
	}
	void update(int entry, V v) {
		entry += NV;
		val[entry]=comp(v,val[entry]); //
		while(entry>1) entry>>=1, val[entry]=comp(val[entry*2],val[entry*2+1]);
	}
};
template<class V,int NV> class SegTree_mi {
public:
	vector<V> val;
	static V const def=1<<30;
	V comp(V l,V r){ return min(l,r);};
	
	SegTree_mi(){val=vector<V>(NV*2,def);};
	V getval(int x,int y,int l=0,int r=NV,int k=1) { // x<=i<y
		if(r<=x || y<=l) return def;
		if(x<=l && r<=y) return val[k];
		return comp(getval(x,y,l,(l+r)/2,k*2),getval(x,y,(l+r)/2,r,k*2+1));
	}
	void update(int entry, V v) {
		entry += NV;
		val[entry]=comp(v,val[entry]); //
		while(entry>1) entry>>=1, val[entry]=comp(val[entry*2],val[entry*2+1]);
	}
};
SegTree_ma<int,1<<19> sma;
SegTree_mi<int,1<<19> smi;
pair<int,int> P[303030],Q[303030];

int dp[303030];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	set<int> A[2];
	A[0].insert(-1);
	A[1].insert(-1);
	A[0].insert(N);
	A[1].insert(N);
	FOR(i,N) {
		dp[i]=303030;
		cin>>H[i];
		P[i]={H[i],i};
		Q[i]={-H[i],i};
		if(i<N-1) T[i].push_back(i+1);
		A[0].insert(i);
		A[1].insert(i);
		sma.update(i,H[i]);
		smi.update(i,H[i]);
	}
	sort(P,P+N);
	sort(Q,Q+N);
	
	FOR(i,N) {
		x=P[i].second;
		auto it=A[0].find(x);
		int L=*prev(it);
		int R=*next(it);
		A[0].erase(x);
		if(L>=0&&R<N&&L+2<=R&&min(H[L],H[R])>sma.getval(L+1,R)) T[L].push_back(R);
	}
	FOR(i,N) {
		x=Q[i].second;
		auto it=A[1].find(x);
		int L=*prev(it);
		int R=*next(it);
		A[1].erase(x);
		if(L>=0&&R<N&&L+2<=R&&max(H[L],H[R])<smi.getval(L+1,R)) T[L].push_back(R);
	}
	
	dp[0]=0;
	FOR(i,N) FORR(t,T[i]) dp[t]=min(dp[t],dp[i]+1);
	cout<<dp[N-1]<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}