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


int N;
ll mo;

vector<ll> dp[505],S[505];



void solve() {
	int i,j,k,l,r,x,y; string s;

	cin>>N>>mo;
	
	FOR(i,55) {
		dp[i].resize(260000);
		S[i].resize(260000);
	}
	dp[0][130000]=1;
	for(i=1;i<260000;i++) S[0][i]=S[0][i-1]+dp[0][i];
	
	for(i=1;i<=N;i++) {
		int dif=i*(i-1)/2;
		for(j=130000-dif;j<=130000+dif;j++) {
			(dp[i][j-(i-1)]+=dp[i-1][j])%=mo;
			(dp[i][j+1]+=2*(mo-dp[i-1][j]))%=mo;
			(dp[i][j+(i-1)+2]+=dp[i-1][j])%=mo;
		}
		for(j=130000-dif-i;j<260000;j++) (dp[i][j]+=dp[i][j-1])%=mo;
		for(j=130000-dif-i;j<260000;j++) {
			(dp[i][j]+=dp[i][j-1])%=mo;
			(S[i][j]=S[i][j-1]+dp[i][j])%=mo;
		}
	}
	
	ll ret=0;
	for(i=2;i<=N;i++) {
		ll front=1;
		FOR(j,N-i) front=front*(N-j)%mo;
		
		for(int d=1;d<=i-1;d++) {
			int pat=i-d;
			ret+=front*pat%mo*(mo+S[i-1][259999]-S[i-1][130000+d])%mo;
		}
	}
	cout<<ret%mo<<endl;
	
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}