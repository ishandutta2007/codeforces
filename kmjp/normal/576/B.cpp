#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define FORR(x,arr) for(auto& x:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

int N;
int P[101010];
int vis[101010];
vector<int> S;
vector<pair<int,int> > PP;
vector<vector<int> > M;
int path[101010];

int dfs(int cur,int pos) {
	if(vis[cur]) return pos;
	path[pos]=cur;
	vis[cur]=1;
	return dfs(P[cur],pos+1);
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) cin>>P[i+1];
	
	int odd=0;
	for(i=1;i<=N;i++) if(vis[i]==0) {
		x=dfs(i,0);
		if(x==1) S.push_back(path[0]);
		else if(x==2) PP.push_back({path[0],path[1]});
		else {
			vector<int> v;
			FOR(y,x) v.push_back(path[y]);
			M.push_back(v);
			odd += x%2;
		}
	}
	
	if(S.size()) {
		_P("YES\n");
		for(i=1;i<S.size();i++) _P("%d %d\n",S[0],S[i]);
		FORR(r,PP) {
			_P("%d %d\n",S[0],r.first);
			_P("%d %d\n",S[0],r.second);
		}
		FORR(r,M) FORR(v,r) _P("%d %d\n",S[0],v);
	}
	else if(PP.size() && odd==0) {
		_P("YES\n");
		_P("%d %d\n",PP[0].first,PP[0].second);
		for(i=1;i<PP.size();i++) {
			_P("%d %d\n",PP[0].first,PP[i].first);
			_P("%d %d\n",PP[0].second,PP[i].second);
		}
		FORR(r,M) {
			for(i=0;i<r.size();i+=2) {
				_P("%d %d\n",PP[0].first,r[i]);
				_P("%d %d\n",PP[0].second,r[i+1]);
			}
		}
	}
	else {
		_P("NO\n");
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}