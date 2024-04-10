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

int N,K;
const ll mo=1000000007;

ll dp[404][404];
ll fact[404];
ll ret[404];

ll modpow(ll a, ll n=mo-2) {
	ll r=1;
	while(n) r=r*((n%2)?a:1)%mo,a=a*a%mo,n>>=1;
	return r;
}

ll comb(int P_,int Q_) {
	if(P_<0 || Q_<0 || Q_>P_) return 0;
	ll p=1,q=1;
	Q_=min(Q_,P_-Q_);
	for(int i=1;i<=Q_;i++) p=p*P_%mo, q=q*i%mo,P_--;
	
	return p*modpow(q,mo-2)%mo;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	fact[0]=1;
	for(i=1;i<=400;i++) fact[i]=fact[i-1]*i%mo;
	
	
	
	cin>>N>>K;
	dp[0][0]=1;
	for(int step=0;step<=K;step++) for(int num=0;num<=2*K;num++) if(dp[step][num]) {
		(ret[step]+=dp[step][num]*modpow(fact[num-step]))%=mo;
		for(x=2;num+x<=N&&step+(x-1)<=K;x++) {
			(dp[step+x-1][num+x]+=comb(N-num,x)*dp[step][num]%mo*fact[x-1])%=mo;
		}
	}
	
	for(i=1;i<=K;i++) {
		ll sum=0;
		for(j=i;j>=0;j-=2) sum+=ret[j];
		cout<<sum%mo<<" ";
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}