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

int T,N;
vector<pair<int,pair<int,int>>> E[202020];
int D[202020];
ll A[202020];
ll B[202020];
int P[20][202020];

void dfs(int cur,int pre) {
	FORR(e,E[cur]) if(e.first==pre) {
		P[0][cur]=e.first;
		D[cur]=D[e.first]+1;
		A[cur]=A[e.first]+e.second.first;
		B[cur]=B[e.first]+e.second.second;
	}
	FORR(e,E[cur]) if(e.first!=pre) {
		dfs(e.first,cur);
	}
	
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N;
		FOR(i,N) E[i].clear();
		FOR(i,N-1) {
			cin>>x>>y>>r;
			E[i+1].push_back({x-1,{y,r}});
			E[x-1].push_back({i+1,{y,r}});
		}
		dfs(0,0);
		FOR(i,19) FOR(x,N) P[i+1][x]=P[i][P[i][x]];
		
		for(i=1;i<N;i++) {
			x=i;
			
			if(B[x]<=A[x]) {
				cout<<D[x]<<" ";
			}
			else {
				for(j=18;j>=0;j--) if(D[x]>=1<<j) {
					y=P[j][x];
					if(B[y]>A[i]) x=y;
				}
				cout<<D[x]-1<<" ";
			}
		}
		cout<<endl;
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}