#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define FORR2(x,y,arr) for(auto& [x,y]:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

int N,M;
int D[202020];
ll S[202020];
const ll mo=998244353;
int A,B;

ll modpow(ll a, ll n = mo-2) {
	ll r=1;a%=mo;
	while(n) r=r*((n%2)?a:1)%mo,a=a*a%mo,n>>=1;
	return r;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	FOR(i,N) cin>>D[i];
	sort(D,D+N);
	FOR(i,N) S[i+1]=S[i]+D[i];
	FOR(i,M) {
		cin>>A>>B;
		x=lower_bound(D,D+N,B)-D;
		int over=N-x;
		
		if(over<A) {
			cout<<0<<endl;
			continue;
		}
		ll ret=0;
		ll X=(S[N]-S[x])%mo;
		ret+=X*(over-A)%mo*modpow(over);
		if(x) {
			ll X=S[x]%mo;
			ret+=X*(over+1-A)%mo*modpow(over+1);
		}
		cout<<ret%mo<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}