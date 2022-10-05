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

ll N,K;
map<pair<ll,ll>,ll> memo;

ll hoge(ll S,ll m) {
	if(S==0) return 0;
	if(memo.count({S,m})) return memo[{S,m}];
	
	ll ret=0;
	ll sm=(S-1)/2;
	ll la=S-1-sm;
	if(sm<m) return 0;
	ret = 1+hoge(sm,m)+hoge(la,m);
	return memo[{S,m}]=ret;
}

ll pos(ll L,ll R,ll low,ll K) {
	ll M=(L+R)/2;
	if(K==1) return M;
	K--;
	
	ll ns=hoge(M-L,low);
	ll nl=hoge(R-M,low+1);
	if(ns+nl>=K) {
		return pos(L,M-1,low,K-nl);
	}
	else {
		return pos(M+1,R,low,K-ns);
	}
	
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>K;
	if(K==1) {
		cout<<1<<endl;
	}
	else if(K==2) {
		cout<<N<<endl;
	}
	else {
		K-=2;
		ll L=0,R=N+1;
		while(L+1<R) {
			ll M=(L+R)/2;
			if(hoge(N-2,M)>=K) L=M;
			else R=M;
		}
		cout<<pos(2,N-1,L,K)<<endl;
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}