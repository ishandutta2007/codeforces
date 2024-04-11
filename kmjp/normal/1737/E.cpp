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


int T,N;
const ll mo=1000000007;

ll p2[1010101],r2[1010101];
ll dp[1010101],sum[1010101];



void solve() {
	int i,j,k,l,r,x,y; string s;
	
	p2[0]=r2[0]=1;
	p2[1]=2;
	r2[1]=(mo+1)/2;
	for(i=2;i<=1000001;i++) {
		p2[i]=p2[i-1]*2%mo;
		r2[i]=r2[i-1]*r2[1]%mo;
	}
	
	cin>>T;
	while(T--) {
		cin>>N;
		
		if(N==1) {
			cout<<1<<endl;
			continue;
		}
		
		//
		for(i=2;i<=N;i++) {
			int win=(i+1)/2-1;
			if(i==N) dp[i]=r2[win];
			else dp[i]=r2[win+1];
			sum[i]=0;
		}
		sum[N+1]=0;
		for(i=N;i>=2;i--) { //
			(sum[i]+=sum[i+1])%=mo;
			dp[i]=dp[i]*(mo+1-sum[i])%mo;
			int win=(i+1)/2;
			
			(sum[i-win]+=dp[i])%=mo;
		}
		
		for(i=1;i<=N;i++) cout<<dp[i]<<"\n";
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}