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

int N,K;
ll mo=1000000007;
ll B[2020200];

const int prime_max = 2100000;
vector<int> P[2020202];
int po[2020202];

ll modpow(ll a, ll n = mo-2) {
	ll r=1;
	while(n) r=r*((n%2)?a:1)%mo,a=a*a%mo,n>>=1;
	return r;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>K;
	
	for(i=1;i<=2020000;i++) {
		po[i]=modpow(i,N);
		if(i>1 && P[i].empty()) {
			for(j=i;j<2020000;j+=i) P[j].push_back(i);
		}
	}
	
	
	ll ret=0;
	int tot=0;
	for(i=1;i<=K;i++) {
		B[i]=(B[i-1]+po[i]-po[i-1]+mo)%mo;
		
		for(int mask=1;mask<1<<P[i].size();mask++) {
			int v=1;
			int s=1;
			FOR(j,P[i].size()) if(mask&(1<<j)) s=-s,v*=P[i][j];
			B[i]+=s*(po[i/v]-po[i/v-1]);
		}
		
		B[i]=(B[i]%mo+mo)%mo;
		ret += B[i]^i;
	}
	cout<<ret%mo<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}