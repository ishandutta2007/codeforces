#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define FORR(x,arr) for(auto& x:arr)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

ll N,M,T,P;
vector<ll> E,BF;
ll B[22];

ll mo=1000000007;
vector<ll> DWTxor(vector<ll> v) {
	int n=v.size(),i,j,m,b;
	for(b=1;b<n;b*=2) {
		for(i=0;i<n;i+=2*b) FOR(j,b) {
			ll x=v[i+j],y=v[i+j+b];
			v[i+j]=x+y-((x+y>=mo)?mo:0);
			v[i+j+b]=x-y+((x-y<0)?mo:0);
		}
	}
	return v;
}

ll multmod(ll a,ll b,ll mo=mo) { // mo<10^15
	ll ret=0;
	if(a<b) swap(a,b);
	for(;b;b>>=11,a=(a<<11)%mo) ret += a * (b&2047);
	return ret%=mo;
}
ll powmod(ll a,ll n,ll mo=mo) {
	ll ret=1,a2=a;
	static map<ll,ll> M;
	if(M.count(a2)) return M[a2];
	a=(a%mo+mo)%mo;
	for(;n;n/=2,a=multmod(a,a,mo)) if(n&1) ret = multmod(ret,a,mo);
	return M[a2]=ret;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>M>>T>>P;
	N=1<<M;
	mo=P<<M;
	FOR(i,N) cin>>x, E.push_back(x%mo);
	FOR(i,M+1) cin>>B[i];
	FOR(i,N) BF.push_back(B[__builtin_popcount(i)]);
	
	auto ed=DWTxor(E);
	auto bd=DWTxor(BF);
	FOR(i,N) ed[i]=multmod(ed[i],powmod(bd[i],T));
	auto ed2=DWTxor(ed);
	FORR(r,ed2) _P("%d\n",(int)(r>>M));
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}