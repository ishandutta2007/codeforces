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
map<int,int> M;
ll mo=1000000007;
ll mo2=mo-1;
ll L[202020],R[202020];

ll modpow(ll a, ll n = mo-2) {
	ll r=1;
	while(n) r=r*((n%2)?a:1)%mo,a=a*a%mo,n>>=1;
	return r;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) {
		cin>>x;
		M[x]++;
	}
	vector<pair<int,int>> V;
	FORR(r,M) V.push_back(r);
	N=V.size();
	L[0]=R[N+1]=1;
	FOR(i,N) L[i+1]=L[i]*(V[i].second+1)%mo2;
	for(i=N;i>=1;i--) R[i]=R[i+1]*(V[i-1].second+1)%mo2;
	
	ll ret=1;
	FOR(i,N) {
		ll mul=1LL*V[i].second*(V[i].second+1)/2%mo2;
		(mul*=L[i]*R[i+2]%mo2)%=mo2;
		(ret*=modpow(V[i].first,mul))%=mo;
	}
	cout<<ret<<endl;
	
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}