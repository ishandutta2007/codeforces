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
int A[505050];
vector<int> P[505050];
int dp[505050];
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) {
		dp[i+1]=1<<20;
		cin>>A[i];
		A[i]--;
		P[A[i]].push_back(i);
	}
	int ret=N;
	FOR(i,N) {
		//not take
		dp[i+1]=min(dp[i+1],dp[i]+1);
		//take
		r=A[i];
		x=lower_bound(ALL(P[r]),i)-P[r].begin();
		if(x==0) {
			dp[P[r].back()+1]=min(dp[P[r].back()+1],dp[i]+(P[r].back()-i)-((int)P[r].size()-x-1));
		}
		else {
			ret=min(ret,dp[i]+(N-1-i)-((int)P[r].size()-x-1));
		}
		ret=min(ret,dp[i+1]+N-1-i);
	}
	cout<<ret<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}