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

int M;
ll num[1505050];
const ll mo=1000000007;
ll dp[1010101];
ll fact[1010101];
ll modpow(ll a, ll n = mo-2) {
	ll r=1;a%=mo;
	while(n) r=r*((n%2)?a:1)%mo,a=a*a%mo,n>>=1;
	return r;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	
	fact[0]=1;
	FOR(i,1010000) fact[i+1]=fact[i]*(i+1)%mo;
	
	cin>>M;
	ll tlen=0;
	FOR(i,M) {
		cin>>x;
		tlen+=x;
		num[x]++;
	}
	ll dif=0;
	ll pat=1;
	for(i=1000000;i>=1;i--) {
		num[i]+=num[i+2];
		(pat*=fact[num[i]])%=mo;
		if(i>1) {
			(pat*=fact[num[i]])%=mo;
			tlen-=2*num[i];
			(dif+=(num[i]+tlen)%mo*(i-1)%mo*num[i])%=mo;
			
		}
		
	}
	
	cout<<dif<<" "<<pat<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}