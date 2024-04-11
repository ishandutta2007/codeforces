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
vector<int> E[101010];
int id[101010];
int depth[101010][4];
int hoge[101010][3];
int dia[101010];
vector<int> D[101010];
vector<ll> S[101010];
int ma;
map<pair<int,int>, double> memo;

void dfs(int cur,int pre,int d,int cid,int forest) {
	id[cur]=forest;
	depth[cur][cid]=d;
	if(d>depth[ma][cid]) ma=cur;
	FORR(e,E[cur]) if(e!=pre) dfs(e,cur,d+1,cid,forest);
}

double ask(int a,int b) {
	if(memo.count({a,b})) return memo[{a,b}];
	
	int md=max(D[a].back(),D[b].back());
	
	ll tot=0;
	FORR(r,D[a]) {
		int mi=md-(r+1);
		int x=lower_bound(ALL(D[b]),mi)-D[b].begin();
		tot += 1LL*x*md + (D[b].size()-x)*1LL*(r+1)+S[b].back()-S[b][x];
	}
	
	
	return memo[{a,b}]=tot*1.0/D[a].size()/D[b].size();
	
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M>>Q;
	FOR(i,M) {
		cin>>x>>y;
		E[x-1].push_back(y-1);
		E[y-1].push_back(x-1);
	}
	
	x=0;
	FOR(i,N) if(id[i]==0) {
		++x;
		ma=i;
		dfs(i,-1,0,0,x);
		hoge[x][0]=ma;
		dfs(ma,-1,0,1,x);
		hoge[x][1]=ma;
		dfs(ma,-1,0,2,x);
		dia[x]=depth[hoge[x][0]][2];
	}
	
	FOR(i,N) D[id[i]].push_back(max(depth[i][1],depth[i][2]));
	FOR(i,N+1) if(D[i].size()) {
		sort(ALL(D[i]));
		S[i].push_back(0);
		FORR(r,D[i]) S[i].push_back(S[i].back()+r);
	}
	
	
	while(Q--) {
		cin>>x>>y;
		x=id[x-1];
		y=id[y-1];
		
		if(x==y) {
			_P("-1\n");
			continue;
		}
		
		if(D[x].size()>D[y].size()) swap(x,y);
		_P("%.12lf\n",ask(x,y));
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}