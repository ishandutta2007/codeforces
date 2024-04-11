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

ll N;
ll L,R,Z;

ll dp[100][1050][2];
const ll mo=1000000007;

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

ll hoge(ll v) {
	ZERO(dp);
	dp[0][0][0]=1;
	
	int i,x,y;
	FOR(i,61) {
		FOR(x,1010) {
			FOR(y,N+1) {
				if(y%2==((Z>>i)%2)) {
					ll a=comb(N,y);
					if((x+y)%2==0&&(v>>i)%2) {
						(dp[i+1][(x+y)/2][0]+=a*dp[i][x][0])%=mo;
						(dp[i+1][(x+y)/2][0]+=a*dp[i][x][1])%=mo;
					}
					else if((x+y)%2&&(v>>i)%2==0) {
						(dp[i+1][(x+y)/2][1]+=a*dp[i][x][0])%=mo;
						(dp[i+1][(x+y)/2][1]+=a*dp[i][x][1])%=mo;
					}
					else {
						(dp[i+1][(x+y)/2][0]+=a*dp[i][x][0])%=mo;
						(dp[i+1][(x+y)/2][1]+=a*dp[i][x][1])%=mo;
					}
				}
			}
		}
	}
	
	return dp[61][0][0];
	
	
}


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>L>>R>>Z;
	cout<<(hoge(R)+mo-hoge(L-1))%mo<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}