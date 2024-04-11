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
string S;
const ll mo=998244353;
string T[(1<<18)+1];
ll dp[1<<19];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>S;
	
	for(i=1<<(N-1);i<1<<N;i++) {
		T[i]=S.substr(i-1,1);
		dp[i]=1;
	}
	for(i=(1<<(N-1))-1;i>=1;i--) {
		if(T[2*i]==T[2*i+1]) {
			T[i]=S.substr(i-1,1)+T[2*i]+T[2*i+1];
			dp[i]=dp[2*i]*dp[2*i+1]%mo;
		}
		else if(T[2*i]<T[2*i+1]) {
			T[i]=S.substr(i-1,1)+T[2*i]+T[2*i+1];
			dp[i]=2*dp[2*i]*dp[2*i+1]%mo;
		}
		else {
			T[i]=S.substr(i-1,1)+T[2*i+1]+T[2*i];
			dp[i]=2*dp[2*i]*dp[2*i+1]%mo;
		}
		
	}
	cout<<dp[1]<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}