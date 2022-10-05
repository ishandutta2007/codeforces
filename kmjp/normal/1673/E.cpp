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
int B[1<<20];

ll sum[25][3];
int dp[1<<20];
int lucas(ll N,ll K) { // C(N,K)
	if(K<0 || K>N) return 0;
	return ((~N)&K)==0;
}



void solve() {
	int i,j,k,l,r,x,y; string s;
	
	
	
	cin>>N>>K;
	FOR(i,25) {
		FOR(k,3) {
			FOR(j,1<<20) if(j+k>=K) {
				if(j<=N-1-i-k&&lucas(N-1-i-k,j)) sum[i][k]^=1;
			}
		}
	}
	
	FOR(i,N) cin>>B[i];
	ll ret=0;
	FOR(i,N) {
		ll a=B[i];
		if(sum[0][(i!=0)+(i<N-1)]) {
			dp[a]^=1;
		}
		for(j=1;i+j<N;j++) {
			if(B[i+j]>=20) break;
			a*=1<<B[i+j];
			if(a>=1<<20) break;
			if(sum[j][(i!=0)+(i+j<N-1)]) {
				dp[a]^=1;
			}
		}
		
	}
	s.resize(1<<20,'0');
	FOR(i,1<<20) if(dp[i]) s[i]='1';
	while(s.size()&&s.back()=='0') s.pop_back();
	reverse(ALL(s));
	
	if(s.empty()) {
		cout<<0<<endl;
	}
	else {
		cout<<s<<endl;
	}
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}