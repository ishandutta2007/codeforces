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
ll mo;
ll total[81][81];
ll bad[81][81];
ll P[81][81];

const int NUM_=2000003;
static ll fact[NUM_+1],factr[NUM_+1],inv[NUM_+1];

ll modpow(ll a, ll n = mo-2) {
	ll r=1;a%=mo;
	while(n) r=r*((n%2)?a:1)%mo,a=a*a%mo,n>>=1;
	return r;
}

ll comb(ll N_, ll C_) {
	if(C_<0 || C_>N_) return 0;
	return factr[C_]*fact[N_]%mo*factr[N_-C_]%mo;
}
ll perm(ll N_, ll C_) {
	if(C_<0 || C_>N_) return 0;
	ll p=1;
	for(int i=1;i<=C_;i++) {
		p=p*(N_+1-i)%mo;
	}
	return p;
}


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>K>>mo;
	inv[1]=fact[0]=factr[0]=1;
	for (int i=2;i<=NUM_;++i) inv[i] = inv[mo % i] * (mo - mo / i) % mo;
	for (int i=1;i<=NUM_;++i) fact[i]=fact[i-1]*i%mo, factr[i]=factr[i-1]*inv[i]%mo;
	
	total[0][0]=1;
	for(i=1;i<=N;i++) FOR(j,K+1) {
		total[i][j]=modpow(2,i*j);
		P[i][j]=perm(modpow(2,j)-1,i);
		FOR(y,j) {
			(total[i][j]-=comb(j,y)*total[i][y])%=mo;
			(P[i][j]-=P[i][y]*comb(j,y))%=mo;
		}
		total[i][j]=(total[i][j]+mo)%mo;
		P[i][j]=(P[i][j]+mo)%mo;

		FOR(x,i) FOR(y,j) {
			if(i==N&&(N%2==1)&&x==i-1) continue;
			ll f=comb(i,x)*comb(j,y)%mo*P[i-x][j-y]%mo*modpow(2,(i-x)*y)%mo;
			(bad[i][j]+=f*(total[x][y]-bad[x][y]+mo))%=mo;
		}
	}
	ll ret=0;
	FOR(j,K+1) (ret+=comb(K,j)*(total[N][j]-bad[N][j]+mo))%=mo;
	cout<<ret<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}