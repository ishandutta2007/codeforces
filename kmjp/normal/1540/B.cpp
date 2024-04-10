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
const ll mo=1000000007;
int C[202][202];

ll modpow(ll a, ll n = mo-2) {
	ll r=1;a%=mo;
	while(n) r=r*((n%2)?a:1)%mo,a=a*a%mo,n>>=1;
	return r;
}

ll memo[202][202];
ll win(int a,int b) {
	if(a==0) return 1;
	if(b==0) return 0;
	if(memo[a][b]>=0) return memo[a][b];
	
	return memo[a][b]=(win(a-1,b)+win(a,b-1))*modpow(2)%mo;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	MINUS(memo);
	cin>>N;
	FOR(x,N) FOR(y,N) C[x][y]=(x==y)?0:2020;
	FOR(i,N-1) {
		cin>>x>>y;
		C[x-1][y-1]=C[y-1][x-1]=1;
	}
	FOR(k,N) FOR(x,N) FOR(y,N) C[x][y]=min(C[x][y],C[x][k]+C[k][y]);
	ll ret=0;
	
	FOR(y,N) FOR(x,y) {
		int c=C[x][y];
		FOR(i,N) {
			int a=C[i][y];
			int b=C[i][x];
			int d=((a+b)-c)/2;
			
			a-=d;
			b-=d;
			ret+=win(a,b);
		}
	}
	ret=ret%mo*modpow(N)%mo;
	
	cout<<ret<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}