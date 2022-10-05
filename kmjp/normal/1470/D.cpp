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

int T,N,M;
vector<int> E[303030];
int vis[303030]; //0-notyet 1-color 2-uncolor

void dfs(int cur) {
	if(vis[cur]) return;
	vis[cur]=1;
	FORR(e,E[cur]) if(vis[e]==1) vis[cur]=2;
	FORR(e,E[cur]) if(vis[e]==0) dfs(e);
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	scanf("%d",&T);
	while(T--) {
		scanf("%d%d",&N,&M);
		FOR(i,N) {
			E[i].clear();
			vis[i]=0;
		}
		FOR(i,M) {
			scanf("%d%d",&x,&y);
			E[x-1].push_back(y-1);
			E[y-1].push_back(x-1);
		}
		dfs(0);
		vector<int> C;
		FOR(i,N) {
			if(vis[i]==0) break;
			if(vis[i]==1) C.push_back(i+1);
		}
		if(i<N) {
			cout<<"NO"<<endl;
		}
		else {
			cout<<"YES"<<endl;
			cout<<C.size()<<endl;
			FORR(v,C) cout<<v<<" ";
			cout<<endl;
		}
		
	}
		
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}