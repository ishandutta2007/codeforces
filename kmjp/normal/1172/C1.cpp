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

ll modpow(ll a, ll n = mo-2) {
	ll r=1;a%=mo;
	while(n) r=r*((n%2)?a:1)%mo,a=a*a%mo,n>>=1;
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
		(dp[x+1][y]+=dp[x][y]*a%mo*modpow(a+b))%=mo;
		(dp[x][y+1]+=dp[x][y]*b%mo*modpow(a+b))%=mo;
	}
	
	
	FOR(i,N) {
		int p,q;
		ll ret=0;
		ll Xs=1;
		if(A[i]==1) {
			for(p=0;p<=M;p++) {
				(Xs*=W[i]+p)%=mo;
				ll sum=0;
				for(q=0;p+q<=M;q++) {
					ll a=1,b=1;
					FOR(j,q) a=a*(SW[1]-W[i]+j)%mo;
					FOR(j,p+q) b=b*(SW[1]+j)%mo;
					a=a*modpow(b)%mo;
					a=a*comb(p+q,p)%mo;
					(sum+=a*dp[p+q][M-(p+q)])%=mo;
				}
				(ret+=Xs*sum)%=mo;
			}
		}
		else {
			for(p=0;p<=min(M,(int)SW[0]);p++) {
				(Xs*=W[i]-p)%=mo;
				ll sum=0;
				for(q=0;p+q<=min(M,(int)SW[0]);q++) {
					ll a=1,b=1;
					FOR(j,q) a=a*(SW[0]-W[i]-j)%mo;
					FOR(j,p+q) b=b*(SW[0]-j)%mo;
					a=a*modpow(b)%mo;
					a=a*comb(p+q,p)%mo;
					(sum+=a*dp[M-(p+q)][p+q])%=mo;
				}
				(ret+=Xs*sum)%=mo;
			}
		}
		
		cout<<ret<<endl;
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}