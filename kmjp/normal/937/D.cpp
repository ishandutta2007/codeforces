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

int N,M,S;
vector<int> E[202020];
int from[202020][2];
int loop;
int vis[202020];

void dfs(int cur) {
	if(vis[cur]==-1) {
		cout<<"Draw"<<endl;
		exit(0);
	}
	if(vis[cur]) return;
	vis[cur]=-1;
	FORR(e,E[cur]) dfs(e);
	vis[cur]=1;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	for(i=1;i<=N;i++) {
		cin>>x;
		FOR(j,x) cin>>y, E[i].push_back(y);
		sort(ALL(E[i]));
	}
	cin>>S;
	
	from[S][0]=S;
	queue<pair<int,int>> Q;
	Q.push({S,0});
	while(Q.size()) {
		int cur=Q.front().first;
		int id=Q.front().second^1;
		Q.pop();
		FORR(e,E[cur]) if(from[e][id]==0) {
			from[e][id]=cur;
			Q.push({e,id});
		}
	}
	
	for(i=1;i<=N;i++) if(from[i][1] && E[i].empty()) {
		vector<int> R;
		x=i,y=1;
		while(x!=S||y!=0) {
			R.push_back(x);
			x=from[x][y];
			y^=1;
		}
		R.push_back(S);
		reverse(ALL(R));
		cout<<"Win"<<endl;
		FORR(r,R) cout<<r<<" ";
		cout<<endl;
		return;
	}
	
	dfs(S);
	cout<<"Lose"<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}