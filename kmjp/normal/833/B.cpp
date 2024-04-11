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

int N,K;
int A[404040];
int pre[404040];
int P[404040];

static ll const def=0;
template<class V,int NV> class SegTree_3 {
public:
	vector<V> val, ma;
	void init(){
		int i;
		val.clear(); ma.clear();
		val.resize(NV*2,0); ma.resize(NV*2,0);
		FOR(i,2*NV) val[i]=ma[i]=0;
	};
	
	V getval(int x,int y,int l=0,int r=NV,int k=1) {
		if(r<=x || y<=l) return def;
		if(x<=l && r<=y) return ma[k];
		return val[k]+max(getval(x,y,l,(l+r)/2,k*2),getval(x,y,(l+r)/2,r,k*2+1));
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

SegTree_3<int,1<<17> st;
int dp[40404][52];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>K;
	FOR(i,N+1) pre[i]=-1;
	FOR(i,N) {
		cin>>A[i];
		P[i]=pre[A[i]];
		pre[A[i]]=i;
		
		if(i==0) {
			dp[i][0]=1;
		}
		else {
			dp[i][0]=dp[i-1][0];
			if(P[i]==-1) dp[i][0]++;
		}
	}
	
	for(i=1;i<K;i++) {
		st.init();
		FOR(x,N) st.update(x,x+1,dp[x][i-1]);
		
		FOR(x,N) {
			st.update(P[x],x,1);
			dp[x][i]=st.getval(0,x);
		}
	}
	
	cout<<dp[N-1][K-1]<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}