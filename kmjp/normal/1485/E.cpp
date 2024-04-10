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
int N;
vector<int> E[202020],C[202020];
int A[202020];

int L[202020],R[202020],D[202020],mad;
int id;
vector<int> V[202020];
ll dp[202020];

void dfs(int cur,int pre,int d) {
	D[cur]=d;
	mad=max(mad,d);
	V[d].push_back(cur);
	FORR(e,E[cur]) if(e!=pre) {
		dfs(e,cur,d+1);
		C[cur].push_back(e);
	}
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N;
		FOR(i,N) E[i].clear(),V[i].clear(),C[i].clear(),dp[i]=-1LL<<60;
		FOR(i,N-1) {
			cin>>x;
			E[i+1].push_back(x-1);
			E[x-1].push_back(i+1);
		}
		FOR(i,N-1) cin>>A[i+1];
		
		mad=0;
		dfs(0,0,0);
		dp[0]=0;
		ll ret=-1LL<<60;
		for(int d=0;d<mad;d++) {
			//
			int mi=1<<30,ma=0;
			FORR(v,V[d+1]) mi=min(mi,A[v]),ma=max(ma,A[v]);
			set<ll> SP,SM;
			FORR(v,V[d]) {
				FORR(c,C[v]) {
					SP.insert(dp[v]+A[c]);
					SM.insert(-dp[v]+A[c]);
				}
			}
			FORR(v,V[d]) {
				FORR(c,C[v]) {
					dp[c]=max({dp[c],*SP.rbegin()-A[c],A[c]-*SM.begin()});
					dp[c]=max({dp[c],dp[v]+A[c]-mi,dp[v]+ma-A[c]});
					ret=max(ret,dp[c]);
				}
			}
		}
		cout<<ret<<endl;
		
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}