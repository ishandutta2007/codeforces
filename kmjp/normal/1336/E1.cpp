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

int N,M;
ll A[202020],ret[60];
const ll mo=998244353;

const int DI=12;
ll dp[1<<12][50];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	vector<ll> T;
	FOR(i,N) {
		ll v;
		cin>>v;
		FORR(t,T) v=min(v,t^v);
		if(v) T.push_back(v);
	}
	
	sort(ALL(T));
	reverse(ALL(T));
	FOR(i,T.size()) {
		for(j=60;j>=0;j--) if(T[i]&(1LL<<j)) break;
		for(k=i+1;k<T.size();k++) if(T[k]&(1LL<<j)) T[k]^=T[i];
	}
	vector<ll> A,B;
	FORR(t,T) {
		if(t>=1LL<<DI) A.push_back(t);
		else B.push_back(t);
	}
	
	for(int mask=0;mask<1<<A.size();mask++) {
		ll v=0;
		FOR(i,A.size()) if(mask&(1<<i)) v^=A[i];
		dp[v&((1<<DI)-1)][__builtin_popcount(v>>DI)]++;
	}
	for(int mask=0;mask<1<<B.size();mask++) {
		ll v=0;
		FOR(i,B.size()) if(mask&(1<<i)) v^=B[i];
		for(int m2=0;m2<1<<DI;m2++) {
			x=__builtin_popcount(m2^v);
			FOR(i,26) if(dp[m2][i]){
				ret[x+i]+=dp[m2][i];
			}
		}
	}
	
	ll m=1;
	FOR(i,N-T.size()) m=m*2%mo;
	
	FOR(i,M+1) {
		ret[i]=ret[i]*m%mo;
		cout<<ret[i]<<" ";
	}
	cout<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}