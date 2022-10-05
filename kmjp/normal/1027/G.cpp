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

ll M,X;
vector<ll> Ds;
vector<pair<ll,int>> Ps;

ll totient(ll v) {
	FORR(p,Ps) if(v%p.first==0) v=v/p.first*(p.first-1);
	return v;
}

ll multpow(ll a,ll b,ll m) {
	ll r=0;
	a%=m;
	while(b) {
		if(b&1) r+=a;
		a<<=1;
		b>>=1;
		if(a>=m) a-=m;
	}
	return r%m;
}
ll modpow(ll a,ll p,ll m) {
	ll r=1;
	while(p) {
		if(p&1) r=multpow(r,a,m);
		a=multpow(a,a,m);
		p/=2;
	}
	return r;
}

ll ord(ll x,ll d) {
	if(x==1) return 1;
	vector<pair<ll,int>> P;
	int i;
	ll t=totient(d);
	ll v=t;
	for(ll a=2;a*a<=v;a++) if(v%a==0) {
		P.push_back({a,0});
		while(v%a==0) P.back().second++, v/=a;
	}
	if(v>1) P.push_back({v,1});
	
	ll ret=t;
	FORR(p,P) {
		int i;
		ll dv=1,t2=t;
		FOR(i,p.second) {
			t2/=p.first;
			if(modpow(x,t2,d)!=1) break;
			ret/=p.first;
		}
	}
	return ret;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>M>>X;
	
	ll M2=M;
	for(ll d=1;d*d<=M;d++) {
		if(M%d==0) {
			if(d>1) Ds.push_back(d);
			if(d*d!=M) Ds.push_back(M/d);
		}
		if(d>1 && M2%d==0) {
			Ps.push_back({d,0});
			while(M2%d==0) M2/=d, Ps.back().second++;
		}
	}
	if(M2>1) Ps.push_back({M2,1});
	
	ll ret=1;
	FORR(d,Ds) {
		ll phi = totient(d);
		ll o = ord(X%d,d);
		ret += phi/o;
	}
	cout<<ret<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}