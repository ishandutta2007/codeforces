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

int N;

const int mo=998244353;
ll modpow(ll a, ll n = mo-2) {
	ll r=1;
	while(n) r=r*((n%2)?a:1)%mo,a=a*a%mo,n>>=1;
	return r;
}


ll F[1210101]; //single and double
ll F2[1210101]; //double
ll FS[1210101];
ll F2S[1210101];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	vector<ll> FF(1<<21);

	F[0]=F2[0]=FS[0]=F2S[0]=1;
	F[1]=2;
	F2[1]=1;
	FS[1]=3;
	F2S[1]=2;
	for(i=2;i<=N;i++) {
		F[i]=F[i-1]; // single
		F[i]+=F[i-1]; // same
		F[i]+=F[i-1]*(F[i-1]-1)/2; // dif
		F[i]+=F[i-1]*FS[i-2]; // dif
		F[i]%=mo;
		F2[i]=(F[i]+mo-F[i-1])%mo;
		(FS[i]=FS[i-1]+F[i])%=mo;
		(F2S[i]=F2S[i-1]+F2[i])%=mo;
		
	}
	
	ll ret=0;
	
	FOR(i,N) (ret+=F2[i]*F2S[N-1-i])%=mo;
	
	ll pat=0;
	pat=F2[N];
	// triple F[n]1*F[n]1*F[n]1
	pat+=F[N-1];
	// triple F[n]1*F[n]1*F[n]2
	(pat+=F[N-1]*(F[N-1]-1))%=mo;
	// triple F[n]1*F[n]2*F[n]3
	(pat+=F[N-1]*(F[N-1]-1)%mo*(F[N-1]-2)%mo*modpow(6))%=mo;
	// triple F[n]1*F[n]1*FS[n]1
	(pat+=F[N-1]*FS[N-2])%=mo;
	// triple F[n]1*F[n]2*FS[n]1
	(pat+=F[N-1]*(F[N-1]-1)%mo*FS[N-2]%mo*modpow(2))%=mo;
	// triple F[n]1*FS[n]1*FS[n]1
	(pat+=F[N-1]*FS[N-2])%=mo;
	// triple F[n]1*FS[n]1*FS[n]1
	(pat+=F[N-1]*FS[N-2]%mo*(FS[N-2]-1)%mo*modpow(2))%=mo;
	
	
	cout<<(ret+2*pat)%mo<<endl;
	
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}