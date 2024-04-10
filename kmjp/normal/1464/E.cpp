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

int N,M;
vector<int> E[101010],RE[101010];
int in[101010];
int gr[101010];
int cgr[101010];
const ll mo=998244353;

const int MAT=512;
ll ma[MAT][MAT],V[MAT],R[MAT];
ll rev(ll a, ll n = mo-2) {
	ll r=1;
	while(n) r=r*((n%2)?a:1)%mo,a=a*a%mo,n>>=1;
	return r;
}

int Gauss(int n,ll mat_[MAT][MAT],ll v_[MAT],ll r[MAT]) {
	int i,j,k;
	ll mat[MAT][MAT],v[MAT];
	memmove(mat,mat_,sizeof(mat));
	memmove(v,v_,sizeof(v));
	
	FOR(i,n) {
		if(mat[i][i]==0) {
			for(j=i+1;j<n;j++) if(mat[j][i]) break;
			if(j>=n) return i;
			FOR(k,n) swap(mat[i][k],mat[j][k]);
			swap(v[i],v[j]);
		}
		(v[i]*=rev(mat[i][i]))%=mo;
		for(k=n-1;k>=i;k--) (mat[i][k]*=rev(mat[i][i]))%=mo;
		for(j=i+1;j<n;j++) {
			v[j]=((v[j]-v[i]*mat[j][i]%mo)+mo)%mo;
			for(k=n-1;k>=i;k--) mat[j][k]=((mat[j][k]-mat[i][k]*mat[j][i]%mo)+mo)%mo;
		}
	}
	
	for(i=n-1;i>=0;i--) {
		for(j=n-1;j>i;j--) v[i]=((v[i]-mat[i][j]*v[j]%mo)+mo)%mo;
		r[i]=v[i];
	}
	return n;
}


ll modpow(ll a, ll n = mo-2) {
	ll r=1;a%=mo;
	while(n) r=r*((n%2)?a:1)%mo,a=a*a%mo,n>>=1;
	return r;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	
	cin>>N>>M;
	FOR(i,M) {
		cin>>x>>y;
		x--,y--;
		E[x].push_back(y);
		RE[y].push_back(x);
		in[x]++;
	}
	queue<int> Q;
	FOR(i,N) if(in[i]==0) Q.push(i);
	int num=1;
	while(Q.size()) {
		x=Q.front();
		Q.pop();
		FORR(e,RE[x]) {
			in[e]--;
			if(in[e]==0) Q.push(e);
		}
		set<int> S;
		FORR(e,E[x]) S.insert(gr[e]);
		while(S.count(gr[x])) gr[x]++;
		if(gr[x]) num++;
		cgr[gr[x]]++;
		assert(gr[x]<=512);
	}
	V[0]=modpow(num);
	FOR(i,MAT) {
		ma[i][i]=1;
		for(j=1;j<MAT;j++) if(cgr[j]) ma[i^j][i]=mo-cgr[j]*modpow(num)%mo;
	}
	Gauss(MAT,ma,V,R);
	cout<<(mo-R[0]+1)%mo<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}