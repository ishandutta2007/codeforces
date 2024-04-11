#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define FORR2(x,y,arr) for(auto& [x,y]:arr)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
template<class T> bool chmax(T &a, const T &b) { if(a<b){a=b;return 1;}return 0;}
template<class T> bool chmin(T &a, const T &b) { if(a>b){a=b;return 1;}return 0;}
//-------------------------------------------------------

template<class V,int NV> class SegTree_1 {
public:
	vector<V> val;
	static V const def=4LL<<60;
	V comp(V l,V r){ return min(l,r);};
	
	SegTree_1(){val=vector<V>(NV*2,def);};
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

int N,Q;
ll X[303030],W[303030];
SegTree_1<ll,1<<20> st;
vector<int> add[303030];
int L[303030],R[303030];
vector<int> qu[303030];
ll ret[303030];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	scanf("%d%d",&N,&Q);
	vector<pair<int,int>> V={{0,0}};
	for(i=1;i<=N;i++) {
		scanf("%d%d",&x,&y);
		X[i]=x+(1000000003);
		W[i]=y;
		while(V.back().first>y) V.pop_back();
		if(V.back().second!=0) add[V.back().second].push_back(i);
		V.push_back({W[i],i});
	}
	V={{0,N+1}};
	for(i=N;i>=1;i--) {
		while(V.back().first>W[i]) V.pop_back();
		if(V.back().second!=N+1) add[i].push_back(V.back().second);
		V.push_back({W[i],i});
	}
	FOR(i,Q) {
		scanf("%d%d",&L[i],&R[i]);
		R[i]++;
		qu[L[i]].push_back(i);
	}
	
	for(i=N;i>=1;i--) {
		FORR(e,add[i]) st.update(e,1LL*(X[e]-X[i])*(W[e]+W[i]));
		FORR(a,qu[i]) ret[a]=st.getval(i,R[a]);
	}
	FOR(i,Q) cout<<ret[i]<<endl;
		
		
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}