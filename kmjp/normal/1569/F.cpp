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

int N,M,K;
int E[12][12];

static const int N_=1020;
static ll P_[N_][N_];
int V[12];
ll ret;

map<vector<pair<int,int>>,int> memo;
int valid(vector<pair<int,int>> P) {
	sort(ALL(P));
	if(memo.count(P)) return memo[P];
	int ret=0;
	do {
		int i;
		int ok=1;
		if(E[P[0].first][P[0].second]==0) ok=0;
		for(i=1;i<P.size();i++) {
			int can=(E[P[i].first][P[i-1].first]&&E[P[i].second][P[i-1].second])|(E[P[i].first][P[i-1].second]&&E[P[i].second][P[i-1].first]);
			ok&=can;
		}
		if(ok) return memo[P]=1;
	} while(next_permutation(ALL(P)));
	return memo[P]=0;
}


int ok(int mask,vector<pair<int,int>>& P) {
	if(mask==0) return valid(P);
	int i,j;
	FOR(i,N) if(mask&(1<<i)) break;
	mask^=1<<i;
	FOR(j,N) if((mask&(1<<j))&&V[i]==V[j]) {
		P.push_back({i,j});
		int v=ok(mask^(1<<j),P);
		P.pop_back();
		if(v) return 1;
	}
	return 0;
	
}


void dfs(int cur,int ma,int mask) {
	int i;
	if(cur==N) {
		if(mask==0) {
			vector<pair<int,int>> P;
			if(ok((1<<N)-1,P)) ret+=P_[K][ma];
			
		}
		return;
	}
	
	for(i=0;i<min(ma+1,N/2);i++) {
		V[cur]=i;
		dfs(cur+1,max(ma,i+1),mask^(1<<i));
	}
}


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	FOR(i,15) {
		P_[i][0]=1;
		for(j=1;j<=i;j++) P_[i][j]=P_[i][j-1]*(i+1-j);
	}
	
	
	cin>>N>>M>>K;
	FOR(i,M) {
		cin>>x>>y;
		E[x-1][y-1]=E[y-1][x-1]=1;
	}
	dfs(0,0,0);
	cout<<ret<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}