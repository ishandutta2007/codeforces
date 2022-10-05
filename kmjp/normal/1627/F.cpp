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

int T;
int N,K;
int V[1010][1010];
int H[1010][1010];
int dp[1010][1010];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N>>K;
		FOR(y,K+2) FOR(x,K+2) {
			H[y][x]=V[y][x]=0;
			dp[y][x]=1<<25;
		}
		FOR(i,N) {
			int y1,x1,y2,x2;
			cin>>y1>>x1>>y2>>x2;
			if(y1==y2) V[y1][min(x1,x2)]++;
			else H[min(y1,y2)][x1]++;
			y1=K+1-y1;
			y2=K+1-y2;
			x1=K+1-x1;
			x2=K+1-x2;
			if(y1==y2) V[y1][min(x1,x2)]++;
			else H[min(y1,y2)][x1]++;
		}
		
		dp[K/2+1][K/2+1]=0;
		priority_queue<pair<int,int>> Q;
		Q.push({0,(K/2+1)*1000+(K/2+1)});
		while(Q.size()) {
			int co=-Q.top().first;
			int ty=Q.top().second/1000;
			int tx=Q.top().second%1000;
			Q.pop();
			if(dp[ty][tx]!=co) continue;
			
			if(ty>1&&dp[ty-1][tx]>co+V[ty-1][tx-1]) {
				dp[ty-1][tx]=co+V[ty-1][tx-1];
				Q.push({-dp[ty-1][tx],(ty-1)*1000+tx});
			}
			if(ty+1<=K+1&&dp[ty+1][tx]>co+V[ty][tx-1]) {
				dp[ty+1][tx]=co+V[ty][tx-1];
				Q.push({-dp[ty+1][tx],(ty+1)*1000+tx});
			}
			if(tx>1&&dp[ty][tx-1]>co+H[ty-1][tx-1]) {
				dp[ty][tx-1]=co+H[ty-1][tx-1];
				Q.push({-dp[ty][tx-1],(ty)*1000+tx-1});
			}
			if(tx+1<=K+1&&dp[ty][tx+1]>co+H[ty-1][tx]) {
				dp[ty][tx+1]=co+H[ty-1][tx];
				Q.push({-dp[ty][tx+1],(ty)*1000+tx+1});
			}
			
			
		}
		
		cout<<N-dp[1][1]<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}