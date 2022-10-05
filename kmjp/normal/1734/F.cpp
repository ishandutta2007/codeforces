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
ll N,M;

map<pair<ll,ll>,ll> memo;

ll hoge(ll N,ll M) {
	if(M<=0) return 0;
	if(memo.count({N,M})) return memo[{N,M}];
	
	if(M==1) {
		return __builtin_popcount(N)%2;
	}
	ll ret=0;
	if(N%2==0) {
		ret=hoge(N/2,M/2)+hoge(N/2,(M+1)/2);
	}
	else {
		ret=M-hoge(N/2+1,M/2)-hoge(N/2,(M+1)/2);
	}
	
	return memo[{N,M}]=ret;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N>>M;
		cout<<hoge(N,M)<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}