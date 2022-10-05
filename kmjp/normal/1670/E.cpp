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


int T,P,N;
vector<pair<int,int>> E[202020];
int V[202020];
int C[202020];
int p=1;

void dfs(int cur,int pre,int id) {
	FORR2(e,i,E[cur]) if(e!=pre) {
		if(id==0) {
			V[e]=p;
			C[i]=N+p;
		}
		else {
			V[e]=N+p;
			C[i]=p;
		}
		p++;
		dfs(e,cur,id^1);
	}
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>P;
		N=1<<P;
		FOR(i,N) E[i].clear();
		FOR(i,N-1) {
			cin>>x>>y;
			E[x-1].push_back({y-1,i});
			E[y-1].push_back({x-1,i});
		}
		
		V[0]=N;
		p=1;
		dfs(0,0,0);
		cout<<1<<endl;
		FOR(i,N) cout<<V[i]<<" ";
		cout<<endl;
		FOR(i,N-1) cout<<C[i]<<" ";
		cout<<endl;
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}