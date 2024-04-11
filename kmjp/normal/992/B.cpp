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

ll L,R,X,Y;

vector<ll> enumdiv(ll n) {
	vector<ll> S;
	for(ll i=1;i*i<=n;i++) if(n%i==0) {S.push_back(i); if(i*i!=n) S.push_back(n/i); }
	sort(S.begin(),S.end());
	return S;
}


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>L>>R>>X>>Y;
	
	if(Y%X) {
		cout<<0<<endl;
		return;
	}
	
	ll ret=0;
	auto V=enumdiv(Y/X);
	
	FORR(v1,V) {
		ll a=v1*X;
		if(a<L || R<a) continue;
		FORR(v2,V) {
			ll b=v2*X;
			if(b<L || R<b) continue;
			if(__gcd(a,b)!=X) continue;
			if(a*(b/__gcd(a,b))!=Y) continue;
			ret++;
		}
	}
	
	cout<<ret<<endl;
	
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}