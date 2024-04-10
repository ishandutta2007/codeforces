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

int N,M;
int A[202020];
ll W[202020];
ll SW[2];
ll mo=998244353;

ll dp[3030][3030];

inline int mulmod(int a,int b,int mo=mo) {
	int d,r;
	if(a==0 || b==0) return 0;
	if(a==1 || b==1) return max(a,b);
	__asm__("mull %4;"
	        "divl %2"
		: "=d" (r), "=a" (d)
		: "r" (mo), "a" (a), "d" (b));
	return r;
}

int modpow(int a, int n = mo-2) {
	int r=1;
	while(n) r=mulmod(r,(n%2)?a:1,mo),a=mulmod(a,a,mo),n>>=1;
	return r;
}

ll comb(int P_,int Q_) {
	static const int N_=4020;
	static ll C_[N_][N_];
	
	if(C_[0][0]==0) {
		int i,j;
		FOR(i,N_) C_[i][0]=C_[i][i]=1;
		for(i=1;i<N_;i++) for(j=1;j<i;j++) C_[i][j]=(C_[i-1][j-1]+C_[i-1][j])%mo;
	}
	if(P_<0 || P_>N_ || Q_<0 || Q_>P_) return 0;
	return C_[P_][Q_];
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	FOR(i,N) cin>>A[i];
	
	FOR(i,N) {
		cin>>W[i];
		SW[A[i]]+=W[i];
	}
	
	dp[0][0]=1;
	FOR(x,M) FOR(y,M) if(x+y<M && dp[x][y]) {
		ll a=SW[1]+x;
		ll b=SW[0]-y;
		ll v=dp[x][y]*modpow(a+b)%mo;
		(dp[x+1][y]+=v*a)%=mo;
		(dp[x][y+1]+=v*b)%=mo;
	}
	
	ll S[2]={};
	ll Xs=1,As=1;
	int p,q;
	for(p=0;p<=M;p++) {
		ll sum=0,Ys=1,As2=As;
		for(q=0;p+q<=M;q++) {
			ll a=Ys*modpow(As2)%mo;
			(sum+=a*dp[p+q][M-(p+q)]%mo*comb(p+q,p))%=mo;
			Ys=mulmod(Ys,SW[1]-1+q);
			As2=mulmod(As2,SW[1]+p+q);
		}
		(Xs*=1+p)%=mo;
		(S[1]+=Xs*sum)%=mo;
		(As*=(SW[1]+p))%=mo;
	}
	Xs=As=1;
	ll Ys=1;
	for(q=0;q<=min(M,(int)SW[0]-1);q++) {
		ll a=Ys*modpow(As)%mo;
		(S[0]+=a*dp[M-q][q])%=mo;
		(Ys*=(SW[0]-1-q))%=mo;
		(As*=(SW[0]-q))%=mo;
	}
	
	FOR(i,N) cout<<S[A[i]]*W[i]%mo<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}