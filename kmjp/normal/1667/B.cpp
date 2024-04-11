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

int T,N;
ll A[505050],S[505050];

template<class V,int NV> class SegTree_1 {
public:
	vector<V> val;
	static V const def=-(1<<25);
	V comp(V l,V r){ return max(l,r);};
	
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
	void update2(int entry, V v) {
		entry += NV;
		val[entry]=v; //
		while(entry>1) entry>>=1, val[entry]=comp(val[entry*2],val[entry*2+1]);
	}
};
SegTree_1<int,1<<20> st;
int same[505050];
int dp[505050];
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N;
		vector<ll> cand;
		cand.push_back(0);
		S[0]=0;
		FOR(i,N) {
			cin>>A[i];
			S[i+1]=S[i]+A[i];
			cand.push_back(S[i+1]);
		}
		sort(ALL(cand));
		FOR(i,N+1) {
			st.update2(i,-1<<25);
			S[i]=lower_bound(ALL(cand),S[i])-cand.begin();
			same[i]=-1<<25;
		}
		st.update2(N+1,-1<<30);
		
		st.update(S[0],0);
		same[S[0]]=0;
		dp[0]=0;
		ll ret;
		for(i=1;i<=N;i++) {
			dp[i]=max(same[S[i]],st.getval(0,S[i])+i);
			if(A[i-1]==0) dp[i]=max(dp[i],dp[i-1]);
			if(A[i-1]<0) dp[i]=max(dp[i],dp[i-1]-1);
			if(A[i-1]>0) dp[i]=max(dp[i],dp[i-1]+1);
			if(i==N) {
				ret=dp[i];
			}
			else {
				same[S[i]]=max(same[S[i]],dp[i]);
				st.update(S[i],dp[i]-i);
			}
		}
		
		cout<<ret<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}