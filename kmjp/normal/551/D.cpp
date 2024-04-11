#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define FORR(x,arr) for(auto& x:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

ll N,K,L,mo;
ll dp[101010][2],sp0,sp1;

map<ll,ll> D;

const int MAT=2;
ll G[MAT][MAT],G2[MAT][MAT];
void powmat(ll p,int n,ll a[MAT][MAT],ll r[MAT][MAT]) {
	int i,x,y,z;
	ll a2[MAT][MAT];
	FOR(x,n) FOR(y,n) a2[x][y]=a[x][y];
	FOR(x,n) FOR(y,n) r[x][y]=0;
	FOR(i,n) r[i][i]=1;
	while(p) {
		ll h[MAT][MAT];
		if(p%2) {
			FOR(x,n) FOR(y,n) h[x][y]=0;
			FOR(x,n) FOR(z,n) FOR(y,n) h[x][y] += (r[x][z]*a2[z][y]) % mo;
			FOR(x,n) FOR(y,n) r[x][y]=h[x][y]%mo;
		}
		FOR(x,n) FOR(y,n) h[x][y]=0;
		FOR(x,n) FOR(z,n) FOR(y,n) h[x][y] += (a2[x][z]*a2[z][y]) % mo;
		FOR(x,n) FOR(y,n) a2[x][y]=h[x][y]%mo;
		p>>=1;
	}
}

ll modpow(ll a, ll n) {
	ll r=1;
	while(n) r=r*((n%2)?a:1)%mo,a=a*a%mo,n>>=1;
	return r;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>K>>L>>mo;
	if(L!=64 && K>=(1ULL<<L)) return _P("0\n");
	
	vector<ll> T;
	
	G[0][0]=G[0][1]=G[1][0]=1;
	powmat(N,2,G,G2);
	
	sp0=(G2[0][0]+G2[0][1])%mo;
	sp1=(mo+modpow(2,N)-sp0)%mo;
	
	ll pat=modpow(sp1,__builtin_popcountll(K))*modpow(sp0,L-__builtin_popcountll(K))%mo;
	cout<<pat<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}