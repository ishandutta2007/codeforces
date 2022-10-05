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

int N,M,K,P;
ll mo;
static const int N_=1020;
static ll C_[N_][N_];
static ll fact[N_+1];

ll dp[101][101][101];


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M>>K>>mo;
	FOR(i,N_) C_[i][0]=C_[i][i]=1;
	for(i=1;i<N_;i++) for(j=1;j<i;j++) C_[i][j]=(C_[i-1][j-1]+C_[i-1][j])%mo;
	fact[0]=1;
	for (int i=1;i<=N_;++i) fact[i]=fact[i-1]*i%mo;
	
	FOR(i,M+1) dp[0][i][0]=1;
	for(i=1;i<=N;i++) dp[i][1][1]=fact[i];
	for(i=1;i<M;i++) {
		for(int lef=0;lef<N;lef++) for(int ml=0;ml<=lef;ml++) if(dp[lef][i][ml]) {
			for(int ri=0;lef+ri<N;ri++) for(int mr=0;mr<=ri;mr++) if(dp[ri][i][mr]) {
				(dp[lef+ri+1][i+1][ml+mr]+=C_[lef+ri][lef]*dp[lef][i][ml]%mo*dp[ri][i][mr])%=mo;
			}
		}
	}
	
	cout<<dp[N][M][K]<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}