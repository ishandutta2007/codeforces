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
ll mo=1000000007;
const int NUM_=1200001;
static ll fact[NUM_+1],factr[NUM_+1],inv[NUM_+1];

ll combi(ll N_, ll C_) {
	if (fact[0]==0) {
		inv[1]=fact[0]=factr[0]=1;
		for (int i=2;i<=NUM_;++i) inv[i] = inv[mo % i] * (mo - mo / i) % mo;
		for (int i=1;i<=NUM_;++i) fact[i]=fact[i-1]*i%mo, factr[i]=factr[i-1]*inv[i]%mo;
	}
	if(C_<0 || C_>N_) return 0;
	return factr[C_]*fact[N_]%mo*factr[N_-C_]%mo;
}

/*
ll memo[1010101];

ll hoge(int n) {
	if(memo[n]>=0) return memo[n];
	ll ret=0;
	if(n<=K) {
		ret=fact[n-1];
	}
	else {
		for(int m=n-K;m<n;m++) {
			(ret+=hoge(m)*combi(n-2,m-1)%mo*fact[n-m-1])%=mo;
		}
	}
	return memo[n]=ret;
}
*/
ll F[1010100];
ll FS[1010100];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	combi(1,1);
	cin>>N>>K;
	
	ll ret=0;
	for(i=1;i<=N;i++) {
		if(i<=K) {
			F[i]=fact[i-1];
		}
		else {
			(F[i]=(FS[i]-FS[i-K]+mo)*fact[i-2])%=mo;
		}
		(FS[i+1]=FS[i]+F[i]*factr[i-1])%=mo;
		(ret+=F[i]*combi(N-1,i-1)%mo*fact[N-i])%=mo;
	}
	
	cout<<(fact[N]+mo-ret)%mo<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}