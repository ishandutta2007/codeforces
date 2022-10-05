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

int N,Q;
const ll mo=1000000007;

ll comb(ll N_, ll C_) {
	const int NUM_=4400001;
	static ll fact[NUM_+1],factr[NUM_+1],inv[NUM_+1];
	if (fact[0]==0) {
		inv[1]=fact[0]=factr[0]=1;
		for (int i=2;i<=NUM_;++i) inv[i] = inv[mo % i] * (mo - mo / i) % mo;
		for (int i=1;i<=NUM_;++i) fact[i]=fact[i-1]*i%mo, factr[i]=factr[i-1]*inv[i]%mo;
	}
	if(C_<0 || C_>N_) return 0;
	return factr[C_]*fact[N_]%mo*factr[N_-C_]%mo;
}

ll A[3030303];
ll B[3030303];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	scanf("%d%d",&N,&Q);
	assert(N<=1000000);
	FOR(i,3*N) {
		ll x=comb(3*N,i+1);
		(A[i]+=x)%=mo;
		(A[i+1]+=3*x)%=mo;
		(A[i+2]+=3*x)%=mo;
		(A[i+3]+=x)%=mo;
	}
	
	for(i=3*N+5;i>=2;i--) {
		B[i-2]=A[i];
		(A[i-1]+=(mo-A[i])*3)%=mo;
		(A[i-2]+=(mo-A[i])*3)%=mo;
	}
	assert(A[0]==0);
	assert(A[1]==0);
	
	FOR(i,Q) {
		scanf("%d",&x);
		_P("%d\n",(int)B[x]);
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}