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

int M;
ll mo=1000000007;
ll modpow(ll a, ll n = mo-2) {
	ll r=1;a%=mo;
	while(n) r=r*((n%2)?a:1)%mo,a=a*a%mo,n>>=1;
	return r;
}

ll dp[101010];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>M;
	for(i=2;i<=M;i++) {
		vector<int> C;
		for(j=1;j*j<=i;j++) if(i%j==0) {
			C.push_back(j);
			if(j*j!=i) C.push_back(i/j);
		}
		sort(ALL(C));
		vector<int> num(C.size());
		for(j=C.size()-1;j>=0;j--) {
			num[j]=M/C[j];
			for(x=j+1;x<C.size();x++) if(C[x]%C[j]==0) num[j]-=num[x];
		}
		dp[i]=M;
		FOR(j,C.size()-1) (dp[i]+=dp[C[j]]*num[j])%=mo;
		dp[i]=dp[i]*modpow(M-num.back())%mo;
	}
	ll ret=0;
	for(i=1;i<=M;i++) (ret+=dp[i])%=mo;
	ret=(1+ret*modpow(M))%mo;
	cout<<ret<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}