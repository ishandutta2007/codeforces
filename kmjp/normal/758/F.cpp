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

ll N,L,R;


ll modpow(ll a, ll n) {
	ll r=1;
	while(n) {
		r=min(1LL<<30,r*((n%2)?a:1));
		a=min(1LL<<30,a*a);
		n>>=1;
	}
	return r;
}


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>L>>R;
	if(N==1) {
		cout<<(R-L+1)<<endl;
	}
	else if(N==2) {
		cout<<(R-L+1)*(R-L)<<endl;
	}
	else if(N>=50) {
		cout<<0<<endl;
	}
	else {
		ll ret=0;
		ll bm=2;
		while(modpow(bm,N-1)<=R) bm++;
		
		for(ll a=1;a<=bm;a++) {
			ll ap=modpow(a,N-1);
			if(ap>R) break;
			for(ll b=a+1;b<=bm;b++) if(__gcd(a,b)==1) {
				ll bp=modpow(b,N-1);
				for(ll v=(L+ap-1)/ap*ap;v<=R;v+=ap) {
					if(v/ap*bp>R) break;
					ret++;
				}
			}
		}
		cout<<2*ret<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}