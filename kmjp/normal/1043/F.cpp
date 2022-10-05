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
int A[303030];

ll mo=1000000007;
ll comb(ll N_, ll C_) {
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

ll dp[8][303030];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	int G=0;
	FOR(i,N) {
		cin>>x;
		A[x]++;
	}
	for(i=1;i<=300000;i++) {
		for(j=2*i;j<=300000;j+=i) A[i]+=A[j];
	}
	
	for(i=1;i<=7;i++) {
		for(x=300000;x>=1;x--) {
			dp[i][x]=comb(A[x],i);
			for(j=2*x;j<=300000;j+=x) dp[i][x]-=dp[i][j];
			dp[i][x]=(dp[i][x]%mo+mo)%mo;
		}
		if(dp[i][1]) return _P("%d\n",i);
	}
	cout<<-1<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}