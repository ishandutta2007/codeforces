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

int N;
ll A[202020],M;
vector<ll> D;


ll f(ll len, ll sp) {
	ll a=(len+sp)/(sp+1);
	ll b=len/(sp+1);
	return len%(sp+1)*a*a+(sp+1-len%(sp+1))*b*b;
}

pair<ll,ll> gh(ll c) {
	ll g=0,h=0;
	FORR(d,D) {
		ll cur=0;
		int i;
		for(i=29;i>=0;i--) if(cur+(1LL<<i)<d && f(d,cur+(1LL<<i)-1)-f(d,cur+(1LL<<i))>=c) cur+=1<<i;
		g+=cur;
		h+=f(d,cur);
	}
	return {g,h};
}


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	
	
	cin>>N;
	ll S=0;
	FOR(i,N) {
		cin>>A[i+1];
		D.push_back(A[i+1]-A[i]);
		S+=D.back()*D.back();
	}
	cin>>M;
	
	if(S<=M) {
		cout<<0<<endl;
		return;
	}
	
	ll cur=(1LL<<60)-1;
	for(i=59;i>=0;i--) {
		auto p=gh(cur-(1LL<<i));
		if(p.second>M) cur-=1LL<<i;
	}
	auto ret=gh(cur);
	ll dif=ret.second-M;
	
	
	ret.first += (dif+cur-2)/(cur-1);
	cout<<ret.first<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}