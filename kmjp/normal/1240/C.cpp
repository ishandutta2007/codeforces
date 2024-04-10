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

int Q;
int N,K;
vector<pair<int,int>> E[505050];

pair<ll,ll> dfs(int cur,int pre) {
	int pc=0;
	vector<pair<ll,ll>> V;
	
	FORR(e,E[cur]) if(e.first!=pre) {
		auto p=dfs(e.first,cur);
		p.first=max(p.first,p.second);
		p.second=max(p.first,p.second+e.second);
		swap(p.first,p.second);
		p.first-=p.second;
		V.push_back(p);
	}
	
	sort(ALL(V));
	reverse(ALL(V));
	pair<ll,ll> ret={0,0};
	int i;
	FOR(i,V.size()) {
		auto& v=V[i];
		if(i<K) ret.first+=v.first+v.second;
		else ret.first+=v.second;
		if(i<K-1) ret.second+=v.first+v.second;
		else ret.second+=v.second;
	}
	return ret;
	
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	scanf("%d",&Q);
	while(Q--) {
		scanf("%d%d",&N,&K);
		FOR(i,N) E[i].clear();
		
		FOR(i,N-1) {
			scanf("%d%d%d",&x,&y,&r);
			x--;
			y--;
			E[x].push_back({y,r});
			E[y].push_back({x,r});
		}
		
		auto ret=dfs(0,-1);
		cout<<ret.first<<endl;
		
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}