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


int N,M,K;
int U[202020],V[202020],W[202020];
vector<pair<int,int>> E[202020];
ll dp[101010];

template<typename V> struct ConvexHull {
	deque<pair<V,V>> Q;
	V calc(pair<V,V> p, V x) {
		return p.first*x+p.second;
	}
	int dodo(pair<V,V> A,pair<V,V> B, pair<V,V> C) { // max or min
		return ((__int128)(A.second-C.second)*(B.first-A.first)<=(__int128)(A.second-B.second)*(C.first-A.first));
	}
	void add(V a, V b) { // add ax+b
		Q.push_back({a,b});
		int v;
		while((v=Q.size())>=3 && dodo(Q[v-3],Q[v-2],Q[v-1]))
			Q[v-2]=Q[v-1], Q.pop_back();
	}
	V query(V x) {
		int L=-1,R=Q.size()-1;
		while(R-L>1) {
			int M=(L+R)/2;
			(((calc(Q[M],x)>=calc(Q[M+1],x)))?L:R)=M;
		}
		return calc(Q[R],x);
	}
};

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M>>K;
	FOR(i,M) {
		cin>>U[i]>>V[i]>>W[i];
		E[U[i]-1].push_back({V[i]-1,W[i]});
		E[V[i]-1].push_back({U[i]-1,W[i]});
	}
	FOR(i,N) dp[i]=1LL<<60;
	dp[0]=0;
	
	FOR(i,K+1) {
		
		if(i) {
			ConvexHull<ll> ch;
			FOR(j,N) ch.add(-2*j,dp[j]+1LL*j*j);
			FOR(j,N) dp[j]=ch.query(j)+1LL*j*j;
		}
		priority_queue<pair<ll,int>> Q;
		FOR(j,N) Q.push({-dp[j],j});
		while(Q.size()) {
			ll co=-Q.top().first;
			int cur=Q.top().second;
			Q.pop();
			if(dp[cur]!=co) continue;
			FORR2(e,c,E[cur]) if(dp[e]>co+c) {
				dp[e]=co+c;
				Q.push({-dp[e],e});
			}
		}
		
	}
	
	FOR(i,N) cout<<dp[i]<<" ";
	cout<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}