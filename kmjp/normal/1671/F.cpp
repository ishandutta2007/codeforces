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


int T;
int N;
int K,X;
const ll mo=998244353;

ll dp[1<<12][14][14][14];
ll sum[25][23][23];

ll dp2[12][24][12][12];


ll modpow(ll a, ll n=mo-2) {
	ll r=1;
	while(n) r=r*((n%2)?a:1)%mo,a=a*a%mo,n>>=1;
	return r;
}

ll comb(ll P_,ll Q_) {
	if(P_<0 || Q_<0 || Q_>P_) return 0;
	ll p=1,q=1;
	Q_=min(Q_,P_-Q_);
	for(int i=1;i<=Q_;i++) p=p*P_%mo, q=q*i%mo,P_--;
	
	return p*modpow(q,mo-2)%mo;
}


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	for(i=1;i<=11;i++) dp[1<<i][i][0][0]=1;
	
	int mask,pre;
	FOR(mask,1<<12) {
		r=__builtin_popcount(mask);
		
		
		FOR(pre,12) FOR(k,12) FOR(x,12) {
			ll a=dp[mask][pre][k][x];
			
			if(mask==(1<<r)-1 && a) {
				if(pre==r-1) continue;
				(sum[r][k][x]+=a)%=mo;
				continue;
			}
			
			int add=0;
			for(y=11;y>=0;y--) {
				if(mask&(1<<y)) {
					add++;
				}
				else {
					if(k+add<=11) {
						(dp[mask|(1<<y)][y][k+add][x+(y<pre)]+=a)%=mo;
					}
					
				}
			}
		}
	}
	
	dp2[0][0][0][0]=1;
	FOR(i,12) FOR(l,23) {
		FOR(k,11) FOR(x,11) {
			int l2,k2,x2;
			for(l2=1;l+l2<=22;l2++) for(k2=1;k+k2<=11;k2++) for(x2=1;x+x2<=11;x2++) {
				(dp2[i+1][l+l2][k+k2][x+x2]+=dp2[i][l][k][x]*sum[l2][k2][x2])%=mo;
			}
		}
		
	}
	
	
	cin>>T;
	while(T--) {
		cin>>N>>K>>X;
		ll ret=0;
		for(i=1;i<=11;i++) for(l=1;l<=min(22,N);l++) if(dp2[i][l][K][X]) {
			if(N-l+i>=i) (ret+=comb(N-l+i,i)*dp2[i][l][K][X])%=mo;
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