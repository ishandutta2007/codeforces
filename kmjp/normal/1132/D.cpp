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
ll A[202020],B[202020];
int cand[202020];

int hoge(ll v) {
	ll num=0;
	int i;
	FOR(i,N) {
		ll x=A[i]-K*B[i];
		if(x<0) {
			if(v==0) return 0;
			x=-x;
			num+=(x+(v-1))/v;
		}
	}
	if(num>K) return 0;
	ZERO(cand);
	FOR(i,N) {
		ll cur=A[i];
		while(cur-B[i]*K<0) {
			ll ng=cur/B[i]+1;
			cand[ng]++;
			cur+=v;
		}
	}
	
	ll sum=0;
	for(i=1;i<=K;i++) {
		sum+=cand[i];
		if(sum>i) return 0;
	}
	return 1;
	
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>K;
	K--;
	FOR(i,N) cin>>A[i];
	FOR(i,N) cin>>B[i];
	
	ll ret=(1LL<<43)-1;
	if(hoge(ret)==0) return _P("-1\n");
	for(i=42;i>=0;i--) if(hoge(ret-(1LL<<i))) ret-=1LL<<i;
	cout<<ret<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}