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

int N,K;
vector<int> E[5050];
const ll mo=998244353;
vector<ll> pat[5050];

void dfs(int cur,int pre) {
	vector<ll> A={1};
	FORR(e,E[cur]) if(e!=pre) {
		dfs(e,cur);
		pat[e].insert(pat[e].begin(),0);
		
		vector<ll> B(max(A.size(),pat[e].size()));
		int a,b;
		FOR(a,A.size()) FOR(b,pat[e].size()) {
			// connect
			if(a+b<=K) (B[max(a,b)]+=A[a]*pat[e][b])%=mo;
			// disconnect
			if(a<=K) (B[a]+=A[a]*pat[e][b])%=mo;
		}
		swap(A,B);
	}
	pat[cur]=A;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>K;
	FOR(i,N-1) {
		cin>>x>>y;
		E[x-1].push_back(y-1);
		E[y-1].push_back(x-1);
	}
	
	dfs(0,0);
	ll ret=0;
	FOR(i,pat[0].size()) if(i<=K) ret+=pat[0][i];
	cout<<ret%mo<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}