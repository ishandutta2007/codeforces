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
ll dp[61][61];
ll mo=1000000007;
ll rev[65];

ll modpow(ll a, ll n = mo-2) {
	ll r=1;a%=mo;
	while(n) r=r*((n%2)?a:1)%mo,a=a*a%mo,n>>=1;
	return r;
}

void hoge(int i) {
	if(dp[i][i]) return;
	
	int x,y,j;
	
	ll from[51],to[51];
	ZERO(from);
	from[i]=1;
	FOR(j,K) {
		ZERO(to);
		FOR(x,i+1) FOR(y,x+1) (to[y]+=from[x]*rev[x+1])%=mo;
		swap(from,to);
	}
	FOR(x,i+1) dp[i][x]=from[x];
	
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>K;
	
	for(i=1;i<=55;i++) rev[i]=modpow(i);
	
	ll ret=1;
	for(int a=2;1LL*a*a<=N;a++) if(N%a==0) {
		int num=0;
		while(N%a==0) num++, N/=a;
		
		ll tot=0;
		ll cur=1;
		hoge(num);
		for(i=0;i<=num;i++) {
			tot+=cur%mo*dp[num][i]%mo;
			cur*=a;
		}
		ret=ret*(tot%mo)%mo;
	}
	
	hoge(1);
	if(N>1) ret=ret*((1*dp[1][0]+N%mo*dp[1][1])%mo)%mo;
	
	cout<<ret<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}