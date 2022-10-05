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


ll N,X;

map<ll,int> memo;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>X;
	
	ll T=1;
	FOR(i,N-1) T*=10;
	
	memo[X]=0;
	queue<ll> Q;
	Q.push(X);
	while(Q.size()) {
		ll v=Q.front();
		s=to_string(v);
		Q.pop();
		
		int C[10]={};
		FORR(c,s) C[c-'0']++;
		
		for(x=2;x<=9;x++) if(C[x]) {
			if(v>=(T+x-1)/x) {
				cout<<memo[v]+1<<endl;
				return;
			}
			ll w=v*x;
			if(memo.count(w)==0) {
				memo[w]=memo[v]+1;
				Q.push(w);
			}
		}
		
		
	}
	
	
	
	cout<<-1<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}