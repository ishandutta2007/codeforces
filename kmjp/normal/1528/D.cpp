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

int N,M;
ll C[606][606];
ll dp[606][606];



void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	FOR(x,N) FOR(y,N) C[x][y]=1LL<<60;
	FOR(i,M) {
		cin>>x>>y>>k;
		C[x][y]=k;
	}
	FOR(x,N) FOR(y,N) dp[x][y]=1LL<<60;
	priority_queue<pair<ll,int>> Q;
	FOR(x,N) dp[x][x]=0, Q.push({0,x*1000+x});
	while(Q.size()) {
		ll co=-Q.top().first;
		int start=Q.top().second/1000;
		int cur=Q.top().second%1000;
		Q.pop();
		if(dp[start][cur]!=co) continue;
		ll to[606]={};
		FOR(i,N) to[(i+co)%N]=C[cur][i];
		FOR(i,2*N) {
			to[(i+1)%N]=min(to[(i+1)%N],to[i%N]+1);
		}
		FOR(x,N) if(dp[start][x]>co+to[x]) {
			dp[start][x]=co+to[x];
			Q.push({-dp[start][x],start*1000+x});
		}
	}
	
	FOR(y,N) {
		FOR(x,N) cout<<dp[y][x]<<" ";
		cout<<endl;
	}
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}