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

ll mo=1000000007;
ll T,L,R;
ll dp[5050505];

const int prime_max = 5050505;
int NP,prime[500000],divp[prime_max];
map<int,int> M;

void cprime() {
	for(int i=2;i<prime_max;i++) if(divp[i]==0) {
		prime[NP++]=i;
		for(ll j=2*i;j>=i&&j<prime_max;j+=i) if(divp[j]==0) divp[j]=i;
	}
}


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cprime();
	
	cin>>T>>L>>R;
	
	for(i=1;i<=5000000;i++) {
		if(divp[i]==0) {
			dp[i]=1LL*i*(i-1)/2%mo;
		}
		else {
			x=divp[i];
			dp[i]=(1LL*dp[x]*(i/x)+dp[i/x])%mo;
		}
	}
	
	ll ret=0;
	ll t=1;
	for(i=L;i<=R;i++) {
		(ret += t*dp[i])%=mo;
		t=t*T%mo;
	}
	cout<<ret<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}