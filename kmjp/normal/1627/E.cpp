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
int N,M,K;
int X[101010];
map<int,vector<int>> E[101010];
map<int,ll> dp[101010];
int A[101010],B[101010],C[101010],D[101010],H[101010];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	scanf("%d",&T);
	while(T--) {
		scanf("%d%d%d",&N,&M,&K);
		FOR(y,N) {
			scanf("%d",&X[y]);
			E[y].clear();
			dp[y].clear();
		}
		FOR(i,K) {
			scanf("%d%d%d%d%d",&A[i],&B[i],&C[i],&D[i],&H[i]);
			A[i]--;
			B[i]--;
			C[i]--;
			D[i]--;
			dp[A[i]][B[i]]=1LL<<60;
			dp[C[i]][D[i]]=1LL<<60;
			E[A[i]][B[i]].push_back(i);
		}
		dp[0][0]=0;
		dp[N-1][M-1]=1LL<<60;
		FOR(y,N) if(dp[y].size()) {
			vector<int> Xs;
			priority_queue<pair<ll,int>> Q;
			FORR2(a,b,dp[y]) {
				Xs.push_back(a);
				if(b!=1LL<<60) Q.push({-b,Xs.size()-1});
			}
			while(Q.size()) {
				ll co=-Q.top().first;
				int cur=Q.top().second;
				Q.pop();
				if(dp[y][Xs[cur]]!=co) continue;
				if(cur&&dp[y][Xs[cur-1]]>co+1LL*X[y]*(Xs[cur]-Xs[cur-1])) {
					dp[y][Xs[cur-1]]=co+1LL*X[y]*(Xs[cur]-Xs[cur-1]);
					Q.push({-dp[y][Xs[cur-1]],cur-1});
				}
				if(cur+1<Xs.size()&&dp[y][Xs[cur+1]]>co+1LL*X[y]*(Xs[cur+1]-Xs[cur])) {
					dp[y][Xs[cur+1]]=co+1LL*X[y]*(Xs[cur+1]-Xs[cur]);
					Q.push({-dp[y][Xs[cur+1]],cur+1});
				}
			}
			FORR(x,Xs) if(dp[y][x]!=1LL<<60) {
				FORR(e,E[y][x]) {
					dp[C[e]][D[e]]=min(dp[C[e]][D[e]],dp[y][x]-H[e]);
				}
				
			}
			
		}
		
		
		if(dp[N-1][M-1]==1LL<<60) {
			cout<<"NO ESCAPE"<<endl;
		}
		else {
			cout<<dp[N-1][M-1]<<endl;
		}
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}