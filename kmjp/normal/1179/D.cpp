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

ll N;
vector<int> E[505050];
ll C[505050];
ll dp[505050];
ll mi=1LL<<60;

template<typename V> struct ConvexHull {
	deque<pair<V,V>> Q;
	V calc(pair<V,V> p, V x) {
		return p.first*x+p.second;
	}
	int dodo(pair<V,V> A,pair<V,V> B, pair<V,V> C) { // max or min
		return ((A.second-C.second)*(B.first-A.first)<=(A.second-B.second)*(C.first-A.first));
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


int dfs(int cur,int pre) {
	C[cur]=1;
	FORR(e,E[cur]) if(e!=pre) C[cur]+=dfs(e,cur);
	return C[cur];
}

void dfs2(int cur,int pre) {
	vector<pair<ll,ll>> cand;
	dp[cur]=C[cur]*(C[cur]-1)/2;
	FORR(e,E[cur]) if(e!=pre) {
		dfs2(e,cur);
		dp[cur]=min(dp[cur],dp[e]+(C[cur]-C[e])*(C[cur]-C[e]-1)/2);
		cand.push_back({C[e],dp[e]});
		// select one
		mi=min(mi,dp[e]+(N-C[e])*(N-C[e]-1)/2);
	}
	// select two
	ConvexHull<ll> ch;
	sort(ALL(cand));
	reverse(ALL(cand));
	int x,y;
	FOR(x,cand.size()) {
		if(x) {
			ll v=ch.query(cand[x].first)+(N*(N-1)+2*cand[x].second-2*N*cand[x].first+cand[x].first*(cand[x].first+1));
			//cout<<ch.query(2*cand[x].first)<<" "<<v<<endl;
			mi=min(mi,v/2);
		}
		ch.add(2*cand[x].first,2*cand[x].second-2*N*cand[x].first+cand[x].first*(cand[x].first+1));
	}
	/*
	FOR(y,cand.size()) FOR(x,y) {
		ll v=cand[x].second+cand[y].second+(N-cand[x].first-cand[y].first)*(N-cand[x].first-cand[y].first-1)/2;
		cout<<"!"<<v<<endl;
		mi=min(mi,v);
	}
	*/
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N-1) {
		cin>>x>>y;
		E[x-1].push_back(y-1);
		E[y-1].push_back(x-1);
	}
	dfs(0,0);
	dfs2(0,0);
	//cout<<mi<<endl;
	cout<<(1LL*N*(N-1)-mi)<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}