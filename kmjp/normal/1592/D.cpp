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
int U[1010],V[1010];
set<pair<int,int>> E[1010];
set<int> alive;
set<int> cand;
int vis[1010];

int ask(set<int> S) {
	set<int> W;
	FORR(s,S) W.insert(U[s]),W.insert(V[s]);
	cout<<"? "<<W.size();
	FORR(s,W) cout<<" "<<s;
	cout<<endl;
	int ret;
	cin>>ret;
	return ret;
}

void dfs(int cur,int pre) {
	FORR2(e,i,E[cur]) if(alive.count(i)&&vis[i]==0&&cand.size()<alive.size()/2&&e!=pre) {
		vis[i]=1;
		cand.insert(i);
		dfs(e,cur);
	}
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N-1) {
		cin>>U[i]>>V[i];
		E[U[i]].insert({V[i],i});
		E[V[i]].insert({U[i],i});
	}
	
	
	FOR(i,N-1) alive.insert(i);
	int ma=ask(alive);
	while(alive.size()>1) {
		ZERO(vis);
		cand.clear();
		FORR(a,alive) if(cand.size()<alive.size()/2&&vis[a]==0) {
			int ok=2;
			FORR2(e,i,E[U[a]]) {
				if(alive.count(i)&&a!=i) ok--;
				break;
			}
			FORR2(e,i,E[V[a]]) {
				if(alive.count(i)&&a!=i) ok--;
				break;
			}
			if(ok==0) continue;
			
			cand.insert(a);
			vis[a]=1;
			dfs(U[a],V[a]);
			dfs(V[a],U[a]);
		}
		x=ask(cand);
		if(ma==x) {
			alive=cand;
		}
		else {
			FORR(c,cand) alive.erase(c);
		}
		
	}
	x=*alive.begin();
	cout<<"! "<<U[x]<<" "<<V[x]<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}