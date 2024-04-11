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


int T;
ll A,B,C,D;

vector<ll> enumdiv(ll n) {
	vector<ll> S;
	for(ll i=1;i*i<=n;i++) if(n%i==0) {S.push_back(i); if(i*i!=n) S.push_back(n/i); }
	sort(S.begin(),S.end());
	return S;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>A>>B>>C>>D;
		
		if(C>=2*A&&D>=2*B) {
			cout<<2*A<<" "<<2*B<<endl;
			continue;
		}
		
		vector<ll> X=enumdiv(A);
		vector<ll> Y=enumdiv(B);
		int ok=0;
		FORR(x,X) FORR(y,Y) if(ok==0) {
			ll z=x*y;
			if(z>C) continue;
			z=C/z*z;
			if(z<=A) continue;
			ll g=__gcd(A*B,z);
			ll lef=A*B/g;
			ll ma=D/lef*lef;
			ll mi=B/lef*lef;
			if(ma==mi) continue;
			cout<<z<<" "<<ma<<endl;
			assert(z*ma>A*B&&z*ma%(A*B)==0);
			ok=1;
			
		}
		if(ok==0) cout<<"-1 -1"<<endl;
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}