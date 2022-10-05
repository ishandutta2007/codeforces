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

const ll mo=998244353;

int N,K;
int B[2020];
ll from[2020][2222];
ll to[2020][2222];
ll P[2020][2020];
int TL[2020],TR[2020];

const int NUM_=400001;
static ll fact[NUM_+1],factr[NUM_+1],inv[NUM_+1];

void solve() {
	int i,j,k,l,r,x,y; string s;

	inv[1]=fact[0]=factr[0]=1;
	for (int i=2;i<=NUM_;++i) inv[i] = inv[mo % i] * (mo - mo / i) % mo;
	for (int i=1;i<=NUM_;++i) fact[i]=fact[i-1]*i%mo, factr[i]=factr[i-1]*inv[i]%mo;
	
	for(i=0;i<=2000;i++) for(j=0;j<=i;j++) P[i][j]=fact[i]*factr[i-j]%mo;
	
	cin>>N>>K;
	FOR(i,N) {
		cin>>B[i];
		TL[i+1]=max(TL[i],B[i]-K);
		TR[i+1]=min(N+1,B[i]+K);
	}
	for(i=N-1;i>=0;i--) TR[i]=min(TR[i],TR[i+1]);
	FOR(i,N+1) if(TL[i]>TR[i]) {
		cout<<0<<endl;
		return;
	}
	
	from[0][0]=1;
	FOR(i,N) {
		int L=TL[i],R=TR[i+1];
		for(k=max(0,L-1);k<=R;k++) FOR(j,N+1) to[k][j]=0;
		
		for(j=L;j<=R;j++) FOR(k,N+1) if(from[j][k]) {
			// same val
			(to[j][k]+=(j+k)*from[j][k])%=mo;
			// add big
			(to[j][k+1]+=from[j][k])%=mo;
		}

		for(j=L;j<=R;j++) FOR(k,N+1) {
			(from[j][k]*=fact[k])%=mo;
			if(j>L) (from[j][k]+=from[j-1][k+1])%=mo;
			(to[j+1][k]+=from[j][k]*factr[k])%=mo;
		}
		

		for(k=L;k<=R;k++) FOR(j,N+1) from[k][j]=to[k][j];
		
	}
	
	
	ll ret=0;
	for(j=TL[N];j<=TR[N];j++) FOR(i,N+1) if(from[j][i]) {
		ret+=from[j][i]*P[N-j][i]%mo;
	}
	cout<<ret%mo<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}