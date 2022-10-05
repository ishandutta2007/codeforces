#pragma GCC optimize("Ofast","unroll-loops","omit-frame-pointer","inline") //Optimization flags
#pragma GCC option("arch=native","tune=native","no-zero-upper") //Enable AVX
#pragma GCC target("avx2")  //Enable AVX

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
int A[21];
const int mo=31607;
int modpow(int a, int n = mo-2) {
	int r=1;a%=mo;
	while(n) r=r*((n%2)?a:1)%mo,a=a*a%mo,n>>=1;
	return r;
}

int C[1<<23];
int from[1<<23];

ll fal;

int md,ad;

void dfs(int cur,int v,int mask) {
	if(cur==N) {
		C[mask]=v;
	}
	else {
		dfs(cur+1,v*(1-A[cur]+mo)%mo,mask);
		dfs(cur+1,v*A[cur]%mo,mask|(1<<cur));
	}
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	int mask;
	cin>>N;
	
	ll p=1;
	FOR(i,(1<<(N+2))) from[i]=1;
	FOR(y,N) {
		FOR(x,N) {
			cin>>k;
			A[x]=k*modpow(10000)%mo;
		}
		ZERO(C);
		md=y;
		ad=N-1-y;
		dfs(0,1,0);
		fal+=p*C[(1<<(N))-1];
		p=p*(1-C[(1<<(N))-1]+mo)%mo;
		C[(1<<(N))-1]=0;
		
		
		FOR(i,N) {
			FOR(mask,1<<(N)) if(mask&(1<<i)) {
				(C[mask^(1<<i)]+=C[mask]);
				if(C[mask^(1<<i)]>=mo) C[mask^(1<<i)]-=mo;
			}
		}
		FOR(mask,1<<(N+2)) {
			int mask2=mask&((1<<N)-1);
			if(mask&(1<<N)) mask2|=1<<md;
			if(mask&(1<<(N+1))) mask2|=1<<ad;
			from[mask]=C[mask2]*from[mask]%mo;
		}
		fal%=mo;
	}

	FOR(i,N+2) {
		FOR(mask,1<<(N+2)) if(mask&(1<<i)) {
			from[mask^(1<<i)]-=from[mask];
			if(from[mask^(1<<i)]<0) from[mask^(1<<i)]+=mo;
		}
	}
	
	ll ret=fal%mo;
	FOR(mask,1<<(N+2)) if(mask) ret+=from[mask];
	cout<<ret%mo<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}