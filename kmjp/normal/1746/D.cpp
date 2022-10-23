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

int T,N,K;
int P[202020];
vector<int> E[202020];
int S[201010];

map<int,ll> memo[202020];

ll dfs(int cur,int K) {
	if(K==0) return 0;
	if(memo[cur].count(K)) return memo[cur][K];
	ll ret=0;
	int V=E[cur].size();
	if(V) {
		vector<ll> add;
		FORR(e,E[cur]) {
			ll a=dfs(e,K/V);
			ret+=a;
			if(K%V) {
				ll b=dfs(e,K/V+1);
				add.push_back(b-a);
			}
		}
		sort(ALL(add));
		reverse(ALL(add));
		int i;
		FOR(i,K%V) ret+=add[i];
	}
	
	return memo[cur][K]=ret+1LL*K*S[cur];
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	scanf("%d",&T);
	while(T--) {
		scanf("%d%d",&N,&K);
		FOR(i,N) {
			E[i].clear();
			memo[i].clear();
		}
		for(i=1;i<N;i++) {
			scanf("%d",&x);
			E[x-1].push_back(i);
		}
		FOR(i,N) scanf("%d",&S[i]);
		cout<<dfs(0,K)<<"\n";
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}