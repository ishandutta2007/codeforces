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
ll H[202020];
vector<int> E[202020];

pair<ll,ll> dfs(int cur,int pre) {
	
	ll sum=0;
	if(cur!=pre) {
		ll ma=0;
		
		FORR(e,E[cur]) if(e!=pre) {
			auto p=dfs(e,cur);
			sum+=p.first;
			ma=max(ma,p.second);
		}
		
		if(H[cur]>ma) {
			sum+=H[cur]-ma;
			ma=H[cur];
		}
		return {sum,ma};
	}
	else {
		vector<ll> C={0,0};
		FORR(e,E[cur]) if(e!=pre) {
			auto p=dfs(e,cur);
			sum+=p.first;
			C.push_back(p.second);
		}
		sort(ALL(C));
		reverse(ALL(C));
		sum+=H[cur]-C[0];
		sum+=H[cur]-C[1];
		return {sum,H[cur]};
		
		
	}
	
	
}


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	ll ma=0;
	j=0;
	FOR(i,N) {
		cin>>H[i];
		ma=max(ma,H[i]);
		if(H[i]==ma) j=i;
	}
	FOR(i,N-1) {
		cin>>x>>y;
		E[x-1].push_back(y-1);
		E[y-1].push_back(x-1);
	}
	
	auto p=dfs(j,j);
	cout<<p.first<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}