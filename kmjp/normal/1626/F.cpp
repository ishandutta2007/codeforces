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
ll A,X,Y,M;
const ll mo=998244353;
ll pat[720720][19];
ll addsum[720720][19];
ll sum[720720][19];

ll modpow(ll a, ll n = mo-2) {
	ll r=1;a%=mo;
	while(n) r=r*((n%2)?a:1)%mo,a=a*a%mo,n>>=1;
	return r;
}

int K;
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	int g=1;
	for(i=1;i<=16;i++) {
		g=g/__gcd(i,g)*i;
	}

	cin>>N>>A>>X>>Y>>K>>M;
	
	FOR(i,g) pat[i][K+1]=1;
	for(j=K;j>=1;j--) {
		FOR(i,g) {
			// not select
			pat[i][j]=pat[i][j+1]*(N-1)%mo;
			sum[i][j]=sum[i][j+1]*(N-1)%mo;
			addsum[i][j]=addsum[i][j+1]*(N-1)%mo;
			// select
			k=i-i%j;
			(pat[i][j]+=pat[k][j+1])%=mo;
			(sum[i][j]+=(sum[k][j+1]+pat[k][j+1]))%=mo;
			(addsum[i][j]+=(addsum[k][j+1]+i*pat[k][j+1]))%=mo;
		}
	}
	
	ll ret=0;
	FOR(i,N) {
		x=A%g;
		(ret+=A/g*g*sum[x][1]+addsum[x][1])%=mo;
		A=(A*X+Y)%M;
	}
	cout<<ret<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}