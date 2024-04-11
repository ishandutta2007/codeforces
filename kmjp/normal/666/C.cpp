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

ll modpow(ll a, ll n) {
	ll r=1;
	while(n) r=r*((n%2)?a:1)%mo,a=a*a%mo,n>>=1;
	return r;
}

ll combi(ll N_, ll C_) {
	const int NUM_=400001;
	static ll fact[NUM_+1],factr[NUM_+1],inv[NUM_+1];
	if (fact[0]==0) {
		inv[1]=fact[0]=factr[0]=1;
		for (int i=2;i<=NUM_;++i) inv[i] = inv[mo % i] * (mo - mo / i) % mo;
		for (int i=1;i<=NUM_;++i) fact[i]=fact[i-1]*i%mo, factr[i]=factr[i-1]*inv[i]%mo;
	}
	if(C_<0 || C_>N_) return 0;
	return factr[C_]*fact[N_]%mo*factr[N_-C_]%mo;
}
ll hcomb(int P_,int Q_) { return (P_==0&&Q_==0)?1:combi(P_+Q_-1,Q_);}

int M,L;
string S;
ll p[2][201010];
int r25_26;

vector<int> V[101010];

inline int mulmod(int a,int b,int mo) {
	int d,r;
	if(a==0 || b==0) return 0;
	if(a==1 || b==1) return max(a,b);
	__asm__("mull %4;"
	        "divl %2"
		: "=d" (r), "=a" (d)
		: "r" (mo), "a" (a), "d" (b));
	return r;
}

void create(int len) {
	if(V[len].size()) return;
	int i;
	int a=1;
	ll sum=0;
	FOR(i,101010) {
		sum += mulmod(hcomb(len,i),a,mo);
		if(sum>=mo) sum-=mo;
		V[len].push_back(sum);
		a=mulmod(a,r25_26,mo);
	}
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	p[0][0]=p[1][0]=1;
	FOR(i,200000) p[0][i+1]=p[0][i]*25%mo, p[1][i+1]=p[1][i]*26%mo;
	
	r25_26=25*modpow(26,mo-2)%mo;
	
	cin>>M>>S;
	L=S.size();
	create(L);
	while(M--) {
		cin>>i;
		if(i==1) cin>>S, L=S.size(), create(L);
		else {
			cin>>x;
			if(x<L) cout<<0<<endl;
			else cout<<V[L][x-L]*p[1][x-L]%mo<<endl;
		}
	}
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}