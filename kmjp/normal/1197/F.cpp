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
int A[1010];
vector<pair<int,int>> ev[1010];
int X[3][3];

const int MAT=4*4*4;
struct Mat { ll v[MAT][MAT]; Mat(){ZERO(v);};};
ll mo=998244353;

Mat trans[3],go[31];


Mat mulmat(Mat& a,Mat& b,int n=MAT) {
	ll mo2=4*mo*mo;
	int x,y,z; Mat r;
	FOR(x,n) FOR(y,n) r.v[x][y]=0;
	FOR(x,n) FOR(z,n) FOR(y,n) {
		r.v[x][y] += a.v[x][z]*b.v[z][y];
		if(r.v[x][y]>mo2) r.v[x][y] -= mo2;
	}
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

struct Vec { ll v[MAT]; };
Vec mulmatvec(Mat& a,Vec& b,int n=MAT) {
	int x,y,z; Vec r;
	FOR(x,n) r.v[x]=0;
	FOR(x,n) FOR(y,n) (r.v[x] += a.v[x][y]*b.v[y]) %= mo;
	return r;
}

ll from[4],to[4];

vector<ll> hoge(int cur) {
	Vec v;
	ZERO(v.v);
	v.v[3*16+3*4+3]=1;
	sort(ALL(ev[cur]));
	
	int pre=0;
	int i;
	FORR(e,ev[cur]) {
		int dif=e.first-1-pre;
		for(i=0;i<=30 && dif;i++) if(dif&(1<<i)) {
			v=mulmatvec(go[i],v);
			dif-=1<<i;
		}
		v=mulmatvec(trans[e.second],v);
		pre=e.first;
	}
	int dif=A[cur]-pre;
	for(i=0;i<=30 && dif;i++) if(dif&(1<<i)) {
		v=mulmatvec(go[i],v);
		dif-=1<<i;
	}
	vector<ll> ret(4);
	FOR(i,64) (ret[i/16%4]+=v.v[i])%=mo;
	return ret;
	
}

int nex(int V,int c) {
	set<int> S;
	int i;
	if(X[c][0]) S.insert(V/16);
	if(X[c][1]) S.insert(V/4%4);
	if(X[c][2]) S.insert(V%4);
	int x=0;
	while(S.count(x)) x++;
	
	V=V/4+x*16;
	
	return V;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) cin>>A[i];
	cin>>r;
	FOR(i,r) {
		cin>>x>>y>>j;
		ev[x-1].push_back({y,j-1});
	}
	FOR(x,3) FOR(y,3) cin>>X[x][y];
	
	FOR(i,64) {
		FOR(j,3) {
			x=nex(i,j);
			trans[j].v[x][i]++;
			go[0].v[x][i]++;
		}
	}
	
	FOR(i,30) go[i+1]=mulmat(go[i],go[i]);
	
	from[0]=1;
	FOR(i,N) {
		auto a=hoge(i);
		ZERO(to);
		FOR(x,4) FOR(y,4) (to[x^y]+=from[x]*a[y])%=mo;
		swap(from,to);
	}
	cout<<from[0]<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}