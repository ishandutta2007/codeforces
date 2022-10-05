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
vector<int> V;
const int mo=998244353;

inline int mulmod(int a,int b,int mo) {
	int d,r;
	if(a==0 || b==0) return 0;
	if(a==1 || b==1) return max(a,b);
	__asm__("mull %4;"
	        "divl %2"
		: "=d" (r), "=a" (d)
		: "r" (mo), "a" (a), "d" (b));
	return r;
}

ll modpow(ll a, ll n = mo-2) {
	ll r=1;
	while(n) {
		if(n&1) r=mulmod(r,a,mo);
		a=mulmod(a,a,mo);
		n>>=1;
	}
	return r;
}
vector<ll> fft(vector<ll> v, bool rev=false) {
	int n=v.size(),i,j,m;
	
	for(i=0,j=1;j<n-1;j++) {
		for(int k=n>>1;k>(i^=k);k>>=1);
		if(i>j) swap(v[i],v[j]);
	}
	for(int m=2; m<=n; m*=2) {
		ll wn=modpow(5,(mo-1)/m);
		if(rev) wn=modpow(wn);
		for(i=0;i<n;i+=m) {
			ll w=1;
			for(int j1=i,j2=i+m/2;j2<i+m;j1++,j2++) {
				int t1=v[j1],t2=mulmod(w,v[j2],mo);
				v[j1]=t1+t2;
				v[j2]=t1+mo-t2;
				while(v[j1]>=mo) v[j1]-=mo;
				while(v[j2]>=mo) v[j2]-=mo;
				w=mulmod(w,wn,mo);
			}
		}
	}
	if(rev) {
		ll rv = modpow(n);
		FOR(i,n) v[i]=mulmod(v[i],rv,mo);
	}
	return v;
}

vector<ll> MultPoly(vector<ll> P,vector<ll> Q,bool resize=false) {
	if(resize) {
		int maxind=0,pi=0,qi=0,i;
		int s=2;
		FOR(i,P.size()) if(norm(P[i])) pi=i;
		FOR(i,Q.size()) if(norm(Q[i])) qi=i;
		maxind=pi+qi+1;
		while(s*2<maxind) s*=2;
		P.resize(s*2);Q.resize(s*2);
	}
	P=fft(P), Q=fft(Q);
	for(int i=0;i<P.size();i++) P[i]=mulmod(P[i],Q[i],mo);
	return fft(P,true);
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	map<int,int> M;
	FOR(i,N) {
		cin>>x;
		M[x]++;
	}
	
	multiset<pair<int,vector<ll>>> S;
	FORR(m,M) {
		vector<ll> V(m.second+1,1);
		S.insert(make_pair((int)V.size(),V));
	}
	
	while(S.size()>1) {
		auto a=S.begin()->second;
		S.erase(S.begin());
		auto b=S.begin()->second;
		S.erase(S.begin());
		auto c=MultPoly(a,b,1);
		
		S.insert(make_pair((int)c.size(),c));
	}
	
	auto P=S.begin()->second;
	P.push_back(0);
	FOR(i,P.size()) if(P[i]==0) {
		j=i/2;
		cout<<P[i/2]<<endl;
		return;
	}
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}