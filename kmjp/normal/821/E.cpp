#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

int N;
ll K;
ll A[101],B[101],C[101];
ll V[16],V2[16];

const int MAT=16;
ll G[MAT][MAT],G2[MAT][MAT];
ll mo=1000000007;
void powmat(ll p,int n,ll a[MAT][MAT],ll r[MAT][MAT]) {
	int i,x,y,z;
	ll a2[MAT][MAT];
	FOR(x,n) FOR(y,n) a2[x][y]=a[x][y];
	FOR(x,n) FOR(y,n) r[x][y]=(x==y);
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


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>K;
	V[0]=1;
	FOR(i,N) {
		cin>>A[i]>>B[i]>>C[i];
		for(y=C[i]+1;y<16;y++) V[y]=0;
		B[i]=min(K,B[i]);
		
		ZERO(G);
		FOR(x,16) {
			if(x-1>=0 && x-1<=C[i]) G[x-1][x]=1;
			if(x<=C[i]) G[x][x]=1;
			if(x+1<=C[i]) G[x+1][x]=1;
		}
		powmat(B[i]-A[i],16,G,G2);
		ZERO(V2);
		FOR(x,16) FOR(y,16) (V2[y]+=G2[y][x]*V[x])%=mo;
		swap(V,V2);
	}
	cout<<V[0]<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}