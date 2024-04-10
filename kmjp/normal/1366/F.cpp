#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

int N,M,Q;
vector<pair<int,int>> E[2020];
ll dp[2020][2020];
const ll mo=1000000007;


template<typename V> struct ConvexHull {
	deque<pair<V,V>> Q;
	V calc(pair<V,V> p, V x) {
		return p.first*x+p.second;
	}
	int dodo(pair<V,V> A,pair<V,V> B, pair<V,V> C) {
		return ((__int128)(B.second-C.second)*(B.first-A.first)<=(__int128)(A.second-B.second)*(C.first-B.first));
	}
	void add(V a, V b) { // add ax+b
		if(Q.size() && Q.back().first==a) {
			//a
			if(b<Q.back().second) return; //min
			Q.pop_back();
		}
		Q.push_back({a,b});
		int v;
		while((v=Q.size())>=3 && dodo(Q[v-3],Q[v-2],Q[v-1]))
			Q[v-2]=Q[v-1], Q.pop_back();
	}
	void add(vector<pair<V,V>> v) {
		sort(v.begin(),v.end());
		for(auto r=v.begin();r!=v.end();r++) add(r->first,r->second);
	}
	
	
	V query(V x) {
		int L=-1,R=Q.size()-1;
		while(R-L>1) {
			int M=(L+R)/2;
			(0^((calc(Q[M],x)<=calc(Q[M+1],x)))?L:R)=M;
		}
		return calc(Q[R],x);
	}
};
ConvexHull<ll> cht;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M>>Q;
	FOR(i,M) {
		cin>>x>>y>>r;
		E[x-1].push_back({y-1,r});
		E[y-1].push_back({x-1,r});
	}
	FOR(i,2020) FOR(j,2020) dp[i][j]=-1LL<<60;
	dp[0][0]=0;
	FOR(i,2010) {
		FOR(j,N) FORR(e,E[j]) dp[i+1][e.first]=max(dp[i+1][e.first],dp[i][j]+e.second);
	}
	
	ll ret=0;
	for(i=1;i<=min(Q,2010);i++) {
		ll ma=0;
		FOR(j,N) ma=max(ma,dp[i][j]);
		(ret+=ma)%=mo;
	}
	
	vector<pair<ll,ll>> cand;
	FOR(i,N) {
		int ma=0;
		FORR(e,E[i]) ma=max(ma,e.second);
		cand.push_back({ma,dp[2010][i]-2010*ma});
	}
	
	cht.add(cand);
	
	int cur=min(Q,2010);
	while(cur<Q) {
		ll dif=cht.query(cur+1)-cht.query(cur);
		for(i=29;i>=0;i--) {
			ll nc=cur+(1<<i);
			if(nc>Q) continue;
			if(cht.query(nc)-cht.query(cur)==(nc-cur)*dif) {
				ll now=cht.query(cur)%mo;
				(ret+=now*(nc-cur))%=mo;
				(ret+=(nc-cur)*(nc-cur+1)/2%mo*dif)%=mo;
				cur=nc;
			}
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