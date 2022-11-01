#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cassert>

using namespace std;

#define FOR(i,k,n) for(int i=(k); i<(int)n; ++i)
#define REP(i,n) FOR(i,0,n)
#define FORIT(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)

template<class T> void debug(T begin, T end){ for(T i = begin; i != end; ++i) cout<<*i<<" "; cout<<endl; }

typedef long long ll;
const int INF = 100000000;
const double EPS = 1e-8;
const int MOD = 1000000007;
int dp[100010][30];

int main(){
	string s;
	int K;
	while(cin>>s>>K){
		int ans = 0;
		int n = s.size();
		REP(ps,K){
			string fob; cin>>fob;
			REP(i,100010)REP(j,30)dp[i][j] = INF;
			dp[0][0] = 0;
			REP(i,n)REP(j,30){
				int k = s[i] - 'a' + 1;
				dp[i+1][j] = min(dp[i+1][j],dp[i][j] + 1);
				if(!(s[i]==fob[0]&&'a'-1+j==fob[1]) && !(s[i]==fob[1]&&'a'-1+j==fob[0])){
					dp[i+1][k] = min(dp[i+1][k],dp[i][j]);
				}
			}
			int m = INF;
			REP(i,30) m = min(m, dp[n][i]);
			ans += m;
		}
		cout<<ans<<endl;
	}
	return 0;
}