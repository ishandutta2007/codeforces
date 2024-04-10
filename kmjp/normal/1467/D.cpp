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

int N,K,Q;
ll A[5050];
ll dp[5050][5050];
ll num[5050];
const ll mo=1000000007;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>K>>Q;
	FOR(i,N) dp[0][i]=1;
	FOR(i,K) {
		FOR(j,N) {
			if(j) (dp[i+1][j-1]+=dp[i][j])%=mo;
			if(j+1<N) (dp[i+1][j+1]+=dp[i][j])%=mo;
		}
	}
	
	ll S=0;
	FOR(i,N) {
		for(j=0;j<=K;j++) (num[i]+=dp[j][i]*dp[K-j][i])%=mo;
		cin>>A[i];
		(S+=num[i]*A[i])%=mo;
	}
	
	while(Q--) {
		cin>>x>>y;
		x--;
		(S-=num[x]*A[x])%=mo;
		A[x]=y;
		(S+=mo+num[x]*A[x])%=mo;
		cout<<S<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}