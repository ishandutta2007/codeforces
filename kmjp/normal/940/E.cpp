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
	static V const def=1LL<<60;
	V comp(V l,V r){ return min(l,r);};
	
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

int N,C;
ll A[101010],S[101010];
SegTree_1<ll,1<<18> st_sum,st_v;
ll dp[101010];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>C;
	if(C==0) return _P("0\n");
	
	FOR(i,N) {
		cin>>A[i+1];
		S[i+1]=S[i]+A[i+1];
		st_v.update(i+1,A[i+1]);
	}
	
	for(i=1;i<=N;i++) {
		if(i<C) {
			dp[i]=S[i];
		}
		else {
			dp[i]=min(dp[i-C]+(S[i]-S[i-C])-st_v.getval(i-C+1,i+1),st_sum.getval(i-C+1,i)-(S[N]-S[i]));
		}
		st_sum.update(i,dp[i]+S[N]-S[i]);
	}
	
	cout<<dp[N]<<endl;
	
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}