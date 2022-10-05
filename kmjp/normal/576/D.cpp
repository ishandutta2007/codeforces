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


int N,M;
int A[200],B[200],D[200];
map<int,vector<int>> MM;
set<int> S;

struct mat { ll v[150][3]={};};
struct vec { ll v[3]={};};

void print(mat a,int n) {
	int x,y;
	FOR(x,n) {
		_P("%d: ",x);
		FOR(y,n) _P("%d",(a.v[x][y/64]&(1LL<<(y%64)))!=0);
		_P("\n");
	}
}
void print(vec a,int n) {
	int i;
	FOR(i,n) _P("%d",(a.v[i/64]&(1LL<<(i%64)))!=0);
	_P("\n");
}

mat mult(mat a,mat b,int n) {
	mat c,d; int x,y,z;
	FOR(x,n) FOR(y,n) if(b.v[y][x/64] & (1LL<<(x%64))) c.v[x][y/64] |= 1LL<<(y%64); // rot
	FOR(x,n) FOR(y,n) {
		ll v=0;
		FOR(z,(n+63)/64) v |= a.v[x][z] & c.v[y][z];
		v=(v!=0);
		d.v[x][y/64] |= v<<(y%64);
	}
	return d;
}
mat init(int n) {
	mat r; int x;
	FOR(x,n) r.v[x][x/64] |= 1LL<<(x%64);
	return r;
}
mat powm(mat a,int p,int n) {
	mat r=init(n);
	while(p) {
		if(p%2) r=mult(r,a,n);
		a=mult(a,a,n);
		p/=2;
	}
	return r;
}
vec mult(mat a,vec b,int n) {
	vec c;
	int x,y;
	FOR(x,n) if(b.v[x/64] & (1LL<<(x%64))) FOR(y,(n+63)/64) c.v[y] |= a.v[x][y];
	return c;
}

bool reachable(mat a,vec b) {
	int x,y;
	
	FOR(x,150) {
		vec c=mult(a,b,N);
		b.v[0] |= c.v[0];
		b.v[1] |= c.v[1];
		b.v[2] |= c.v[2];
	}
	int n=N-1;
	return (b.v[n/64] & (1LL<<(n%64)))!=0;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	FOR(i,M) {
		cin>>A[i]>>B[i]>>D[i];
		A[i]--;B[i]--;
		MM[D[i]].push_back(i);
		S.insert(D[i]);
	}
	
	int cur=0;
	vec v;
	mat m;
	v.v[0]=1;
	FORR(r,MM) {
		
		v = mult(powm(m,r.first-cur,N),v,N);
		cur=r.first;
		FORR(r2,r.second) m.v[A[r2]][B[r2]/64] |= 1LL<<(B[r2]%64);
		
		if(reachable(m,v)) break;
	}
	
	if(!reachable(m,v)) return _P("Impossible\n");
	
	int n=N-1;
	while((v.v[n/64] & (1LL<<(n%64)))==0) {
		v = mult(m,v,N);
		cur++;
		if(S.count(cur)) FORR(r2,MM[cur]) m.v[A[r2]][B[r2]/64] |= 1LL<<(B[r2]%64);
	}
	cout<<cur<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}