#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define FORR(x,arr) for(auto& x:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

int W,H,Q;

ll mo=1000000007;
const int MAT=20;
struct Vec { ll v[MAT]; };
struct Mat { ll v[MAT][MAT]; };
Mat mulmat(Mat& a,Mat& b,int n=MAT) {
	int x,y,z; Mat r;
	FOR(x,n) FOR(y,n) r.v[x][y]=0;
	FOR(x,n) FOR(z,n) FOR(y,n) r.v[x][y] += (a.v[x][z]*b.v[z][y]) % mo;
	FOR(x,n) FOR(y,n) r.v[x][y]%=mo;
	return r;
}

Mat powmat(ll p,Mat a,int n=MAT) {
	int i,x,y; Mat r;
	FOR(x,n) FOR(y,n) r.v[x][y]=0;
	FOR(i,n) r.v[i][i]=1;
	while(p) {
		if(p%2) r=mulmat(r,a,n);
		a=mulmat(a,a,n);
		p>>=1;
	}
	return r;
}

Vec mulmatvec(Mat& a,Vec& b,int n=MAT) {
	int x,y,z; Vec r;
	FOR(x,n) r.v[x]=0;
	FOR(x,n) FOR(y,n) (r.v[x] += a.v[x][y]*b.v[y]) %= mo;
	return r;
}
Mat G;
Vec V;

int is[20][20];
int id(int y,int x) { return y*W+x;}
void setup() {
	int y,x;
	ZERO(G.v);
	FOR(y,H) FOR(x,W) if(is[y][x]==0) {
		G.v[id(y,x)][id(y,x)]=1;
		if(y) G.v[id(y,x)][id(y-1,x)]=1;
		if(x) G.v[id(y,x)][id(y,x-1)]=1;
		if(y<H-1) G.v[id(y,x)][id(y+1,x)]=1;
		if(x<W-1) G.v[id(y,x)][id(y,x+1)]=1;
	}
	
}


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>H>>W>>Q;
	setup();
	V.v[0]=1;
	
	ll cur=1;
	while(Q--) {
		ll t;
		cin>>i>>y>>x>>t;
		y--; x--;
		auto GG=powmat(t-cur,G,H*W);
		V=mulmatvec(GG,V,H*W);
		if(i==1) {
			cout<<V.v[id(y,x)]<<endl;
		}
		else if(i==2 || i==3) {
			is[y][x]^=1;
			V.v[id(y,x)]=0;
			setup();
			
		}
		cur=t;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}