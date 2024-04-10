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


ll N,F1,F2,F3,C;
ll mo=1000000007;

const int MAT=5;
ll G[MAT][MAT],G2[MAT][MAT];
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

ll modpow(ll a, ll n = mo-2) {
	ll r=1;
	while(n) r=r*((n%2)?a:1)%mo,a=a*a%mo,n>>=1;
	return r;
}

int modlog(int g,int a) {  // return g^x=a mod a
	map<int,int> M;
	ll cur=1;
	int sq=sqrt(mo);
	int i;
	FOR(i,sq) {
		M[cur]=i;
		cur=cur*g%mo;
	}
	
	ll step=cur;
	cur=1;
	ll num=0;
	while(1) {
		ll x=a*modpow(cur)%mo;
		if(M.count(x)) return num+M[x];
		cur=cur*step%mo;
		num+=sq;
	}
}


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>F1>>F2>>F3>>C;
	
	F1=modlog(5,F1);
	F2=modlog(5,F2);
	F3=modlog(5,F3);
	C=modlog(5,C);
	mo--;
	
	G[0][1]=G[1][2]=G[2][0]=G[2][1]=G[2][2]=G[2][3]=1;
	G[3][3]=G[4][4]=1;
	G[3][4]=2*C%mo;
	powmat(N-3,5,G,G2);
	ll p=(F1*G2[2][0]+F2*G2[2][1]+F3*G2[2][2]+2*C*G2[2][3]+G2[2][4])%mo;
	mo++;
	cout<<modpow(5,p)<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}