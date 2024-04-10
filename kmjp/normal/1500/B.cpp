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

int N,M;
ll K;
int A[505050],B[505050];

int P[1010101];
int Q[1010101];
pair<ll,ll> C[1010101];
ll ext_gcd(ll p,ll q,ll& x, ll& y) { // get px+qy=gcd(p,q)
	if(q==0) return x=1,y=0,p;
	ll g=ext_gcd(q,p%q,y,x);
	y-=p/q*x;
	return g;
}

pair<ll,ll> crt(ll a1,ll mo1,ll a2,ll mo2) { // return (x,y) y=lcm(a1,a2),x%mo1=a1,x%mo2=a2
	ll g,x,y,z;
	g=ext_gcd(mo1,mo2,x,y);
	a1=(a1%mo1+mo1)%mo1;a2=(a2%mo2+mo2)%mo2;
	if(a1%g != a2%g) return pair<ll,ll>(-1,0); // N/A
	__int128_t lcm=mo1*(mo2/g);
	if(lcm<mo1) return pair<ll,ll>(-2,0); // overflow
	
	__int128_t v=a1+((a2-a1)%lcm+lcm)*x%lcm*(mo1/g);
	return make_pair(((v%lcm)+lcm) % lcm,lcm);
}

ll fail(ll d) {
	int i;
	ll tot=0;
	FOR(i,1010000) if(P[i]>=0&&Q[i]>=0) {
		if(C[i].first==0&&C[i].second==0) {
			C[i]=crt(P[i],N,Q[i],M);
		}
		if(C[i].first<0) continue;
		auto& p=C[i];
		if(p.first<=d) {
			ll x=(d-p.first)/p.second;
			while(p.first+x*p.second>=d) x--;
			while(p.first+(x+1)*p.second<d) x++;
			tot+=x+1;
		}
	}
	return d-tot;
}


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	MINUS(P);
	MINUS(Q);
	cin>>N>>M>>K;
	FOR(i,N) {
		cin>>A[i];
		P[A[i]]=i;
	}
	FOR(i,M) {
		cin>>B[i];
		Q[B[i]]=i;
	}
	
	
	
	ll ret=1LL<<60;
	for(i=59;i>=0;i--) if(fail(ret-(1LL<<i))>=K) ret-=1LL<<i;
	cout<<ret<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}