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

int N,M;
vector<int> E[1010];
int vis[1010], gr[1010];
int len[1010],d[1010];
vector<int> cand;


void dfs(int cur,int col,int g) {
	gr[cur]=g;
	if(vis[cur]!=-1) {
		if(vis[cur]!=col) {
			_P("-1\n");
			exit(0);
		}
	}
	else {
		vis[cur]=col;
		FORR(r,E[cur]) dfs(r,col^1,g);
	}
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	FOR(i,M) {
		cin>>x>>y;
		E[x-1].push_back(y-1);
		E[y-1].push_back(x-1);
	}
	MINUS(vis);
	FOR(i,N) if(vis[i]==-1) cand.push_back(i), dfs(i,0,i);
	FOR(i,N) {
		FOR(x,N) d[x]=1010;
		d[i]=0;
		
		queue<int> Q;
		Q.push(i);
		while(Q.size()) {
			x=Q.front();
			Q.pop();
			FORR(r,E[x]) if(d[r]>d[x]+1) d[r]=d[x]+1, len[gr[i]]=max(len[gr[i]],d[r]),Q.push(r);
		}
	}
	cout<<accumulate(len,len+N,0)<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}