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

ll X,Y;
vector<ll> V;

vector<ll> enumdiv(ll n) {
	vector<ll> S;
	for(ll i=1;i*i<=n;i++) if(n%i==0) {S.push_back(i); if(i*i!=n) S.push_back(n/i); }
	sort(S.begin(),S.end());
	return S;
}

ll hoge(ll X,ll Y) {
	if(Y==0) return 0;
	if(Y%X==0) return Y/X;
	ll g=__gcd(X,Y);
	X/=g;
	Y/=g;
	
	ll mi=1LL<<60;
	FORR(v,V) if(X%v==0 && v>1) mi=min(mi,Y-Y/v*v);
	return mi+hoge(X,Y-mi);
}


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>X>>Y;
	V=enumdiv(X);
	cout<<hoge(X,Y)<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}