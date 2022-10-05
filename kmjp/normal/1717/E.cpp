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
const ll mo=1000000007;
ll dp[2020];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	ll ret=0;
	for(int c=1;c<=N-2;c++) {
		int ab=N-c;
		vector<int> g;
		for(i=1;i*i<=ab;i++) if(ab%i==0) {
			g.push_back(i);
			if(i*i<ab) g.push_back(ab/i);
		}
		sort(ALL(g));
		int G=g.size();
		FOR(i,G) dp[i]=0;
		for(i=G-1;i>=0;i--) {
			dp[i]=ab/g[i]-1;
			for(j=i+1;j<G;j++) if(g[j]%g[i]==0) dp[i]-=dp[j];
			int gc=g[i];
			(ret+=1LL*c/__gcd(c,gc)*gc%mo*dp[i])%=mo;
		}
		
	}
	cout<<ret<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}