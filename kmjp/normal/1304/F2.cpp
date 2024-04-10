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

int H,W,K;
int A[51][20202];
ll S[51][20202];

ll dp[20202];

static ll const def=0;
template<class V,int NV> class SegTree_3 {
public:
	vector<V> val, ma;
	SegTree_3(){
		int i;
		val.resize(NV*2,0); ma.resize(NV*2,0);
		FOR(i,NV) val[i+NV]=ma[i+NV]=def;
		for(i=NV-1;i>=1;i--) ma[i]=max(ma[2*i],ma[2*i+1]);
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

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>H>>W>>K;
	FOR(y,H) {
		FOR(x,W) {
			cin>>A[y][x];
			S[y][x+1]=S[y][x]+A[y][x];
		}
	}
	for(x=0;x+K<=W;x++) dp[x]=S[0][x+K]-S[0][x]+S[1][x+K]-S[1][x];
	for(y=1;y<H;y++) {
		SegTree_3<ll,1<<16> st;
		for(x=0;x+K<=W;x++) st.update(x,x+1,dp[x]);
		FOR(x,K) st.update(x-K+1,x+1,-A[y][x]);
		for(x=0;x+K<=W;x++) {
			dp[x]=S[y][x+K]-S[y][x]+S[y+1][x+K]-S[y+1][x]+st.getval(0,W);
			st.update(x-K+1,x+1,A[y][x]);
			st.update(x+1,x+K+1,-A[y][x+K]);
		}
	}
	
	ll ret=0;
	FOR(x,W) ret=max(ret,dp[x]);
	cout<<ret<<endl;
	
		
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}