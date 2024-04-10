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

int N;
int L[202020],R[202020];
ll P[202020];
ll mo=1000000007;

ll modpow(ll a, ll n = mo-2) {
	ll r=1;a%=mo;
	while(n) r=r*((n%2)?a:1)%mo,a=a*a%mo,n>>=1;
	return r;
}

ll hoge(int i) {
	if(i==0) return P[1];
	ll t=1-(1-P[i])-(1-P[i+1]);
	int LM=max({L[i-1],L[i],L[i+1]});
	int RM=min({R[i-1],R[i],R[i+1]});
	ll a=R[i]-L[i];
	ll b=R[i+1]-L[i+1];
	ll c=R[i-1]-L[i-1];
	ll d=max(0,RM-LM);
	return (t+d*modpow(a*b%mo*c%mo))%mo;
	
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) cin>>L[i];
	FOR(i,N) {
		cin>>R[i];
		R[i]++;
	}
	
	P[0]=1;
	ll PS=1;
	for(i=1;i<N;i++) {
		int LM=max(L[i],L[i-1]);
		int RM=min(R[i],R[i-1]);
		int a=R[i-1]-L[i-1];
		int b=R[i]-L[i];
		int c=max(0,RM-LM);
		ll same=c*modpow(1LL*a*b%mo)%mo;
		P[i]=(1+mo-same)%mo;
		(PS+=P[i])%=mo;
	}
	
	ll ret=PS;
	FOR(i,N) {
		ll tmp=PS-P[i];
		if(i) tmp-=P[i-1];
		if(i+1<N) tmp-=P[i+1];
		ret+=P[i]*tmp%mo;
		
		if(i) ret+=hoge(i-1);
		if(i+1<N) ret+=hoge(i);
		
	}
	
	cout<<(ret%mo+mo)%mo<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}