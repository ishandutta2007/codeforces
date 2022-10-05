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

int N,M;
int NG[202020];
vector<int> P[202020];
int ma[202020],to[202020];
int phi;

ll modpow(ll a, ll n, ll mo) {
	ll r=1;
	while(n) r=r*((n%2)?a:1)%mo,a=a*a%mo,n>>=1;
	return r;
}

ll hoge(ll a,ll b) {
	// b/a
	ll g=__gcd(a,b);
	a/=g;
	b/=g;
	ll ra=modpow(a,phi-1,M);
	return ra*b%M;
	
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	FOR(i,N) {
		cin>>x, NG[x]=1;
		if(x==0) NG[M]=1;
	}
	for(i=1;i<=M;i++) if(__gcd(i,M)==1) phi++;
	
	for(i=M;i>=1;i--) if(M%i==0) {
		for(j=i;j<=M;j+=i) {
			if(NG[j]==0) {
				P[i].push_back(j);
				NG[j]=1;
			}
		}
		ma[i]=P[i].size();
		for(j=2*i;j<=M;j+=i) {
			int sc=P[i].size()+ma[j];
			if(sc>=ma[i]) {
				ma[i]=sc;
				to[i]=j;
			}
		}
	}
	
	vector<int> R;
	ll cur=1;
	ll tot=1;
	while(cur<=M) {
		FORR(r,P[cur]) {
			R.push_back(hoge(tot,r));
			tot=r;
		}
		if(cur==M) break;
		cur=to[cur];
	}
	
	cout<<R.size()<<endl;
	FORR(r,R) cout<<r%M<<" ";
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}