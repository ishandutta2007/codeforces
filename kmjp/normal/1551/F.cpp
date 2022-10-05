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
vector<int> E[101];
const ll mo=1000000007;
ll dp[102][102];
int num[102];

void dfs(int cur,int pre,int d) {
	num[d]++;
	FORR(e,E[cur]) if(e!=pre) dfs(e,cur,d+1);
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N>>K;
		FOR(i,N) {
			E[i].clear();
		}
		FOR(i,N-1) {
			cin>>x>>y;
			E[x-1].push_back(y-1);
			E[y-1].push_back(x-1);
		}
		
		if(K==2) {
			cout<<N*(N-1)/2<<endl;
			continue;
		}
		ll ret=0;
		FOR(i,N) {
			ZERO(dp);
			FOR(j,N) dp[j][0]=1;
			FORR(e,E[i]) {
				ZERO(num);
				dfs(e,i,1);
				
				FOR(j,N) {
					for(k=N;k>=0;k--) (dp[j][k+1]+=dp[j][k]*num[j])%=mo;
				}
				
			}
			FOR(j,N) ret+=dp[j][K];
		}
		cout<<ret%mo<<endl;
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}