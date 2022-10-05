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
ll N;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	vector<ll> V;
	V.push_back(1);
	for(i=2;i<=14;i++) {
		V.push_back(V.back()*i);
	}
	
	cin>>T;
	while(T--) {
		cin>>N;
		int mi=1<<20;
		int mask;
		FOR(mask,1<<V.size()) {
			ll sum=0;
			FOR(i,V.size()) if(mask&(1<<i)) sum+=V[i];
			if(sum<=N&&(N-sum)%4==0) mi=min(mi,__builtin_popcount(mask)+__builtin_popcountll(N-sum));
		}
		if(mi==1<<20) mi=-1;
		cout<<mi<<endl;
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}