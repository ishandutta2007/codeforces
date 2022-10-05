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
int A[501010];
ll dp[505050][2];
const ll mo=998244353;

ll modpow(ll a, ll n = mo-2) {
	ll r=1;a%=mo;
	while(n) r=r*((n%2)?a:1)%mo,a=a*a%mo,n>>=1;
	return r;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	
	vector<pair<int,ll>> S[2];
	ll sum[2]={};
	dp[0][0]=1;
	
	FOR(i,N) {
		cin>>A[i];
		
		FOR(j,2) {
			ll ts=0;
			while(S[j].size()&&S[j].back().first>A[i]) {
				sum[j]+=mo-S[j].back().second;
				ts+=S[j].back().second*A[i]%mo*modpow(S[j].back().first)%mo;
				S[j].pop_back();
			}
			dp[i+1][j^1]=(ts+sum[j]+dp[i][j^1]*A[i])%mo;
			S[j].push_back({A[i],(ts+dp[i][j^1]*A[i])%mo});
			(sum[j]+=ts+dp[i][j^1]*A[i])%=mo;
		}
		swap(S[0],S[1]);
		swap(sum[0],sum[1]);
	}
	
	cout<<(dp[N][0]+mo-dp[N][1])%mo<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}