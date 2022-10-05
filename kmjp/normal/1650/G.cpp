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


int t,N,M;
vector<int> E[202020];
int D[202020];
ll dp[202020][2];
const ll mo=1000000007;
int S,T;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>t;
	while(t--) {
		cin>>N>>M;
		cin>>S>>T;
		S--,T--;
		FOR(i,N) {
			E[i].clear();
			D[i]=1<<30;
			dp[i][0]=dp[i][1]=0;
		}
		FOR(i,M) {
			cin>>x>>y;
			E[x-1].push_back(y-1);
			E[y-1].push_back(x-1);
		}
		D[S]=0;
		dp[S][0]=1;
		priority_queue<pair<int,int>> Q;
		Q.push({0,S});
		while(Q.size()) {
			int cur=Q.top().second%N;
			int id=Q.top().second/N;
			Q.pop();
			FORR(e,E[cur]) {
				if(D[e]>D[cur]+id+1) {
					D[e]=D[cur]+id+1;
					Q.push({-D[e],e});
					Q.push({-D[e]-1,e+N});
				}
				if(D[e]==D[cur]+id+1) (dp[e][0]+=dp[cur][id])%=mo;
				if(D[e]+1==D[cur]+id+1) (dp[e][1]+=dp[cur][id])%=mo;
			}
		}
		cout<<(dp[T][0]+dp[T][1])%mo<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}