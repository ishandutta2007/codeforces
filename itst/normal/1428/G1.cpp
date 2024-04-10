#include<bits/stdc++.h>
using namespace std;

#define int long long
const int pw10[] = {1,10,100,1000,10000,100000}; int K , F[7] , Q , dp[7][2000000];

signed main(){
	cin >> K; for(int i = 1 ; i <= 6 ; ++i) cin >> F[i];
	memset(dp , -0x3f , sizeof(dp)); dp[0][0] = 0;
	for(int i = 1 ; i <= 6 ; ++i){
		for(int j = 0 ; j < 3 * pw10[i - 1] ; ++j){
			deque < pair < int , int > > q;
			for(int k = j , cnt = 0 ; k < 1e6 ; k += 3 * pw10[i - 1] , ++cnt){
				int val = dp[i - 1][k] - cnt * F[i]; while(q.size() && q.back().first <= val) q.pop_back();
				q.push_back(make_pair(val , cnt)); if(cnt - q.front().second > 3 * K) q.pop_front();
				dp[i][k] = max(dp[i][k] , cnt * F[i] + q.front().first); int pos = 0; while(cnt - q[pos].second > 3 * (K - 1)) ++pos;
				int v = cnt * F[i] + q[pos].first;
				for(int t = 0 ; t < 10 ; ++t) dp[i][k + t * pw10[i - 1]] = max(dp[i][k + t * pw10[i - 1]] , v);
			}
		}
	}
	for(cin >> Q ; Q ; --Q){int x; cin >> x; cout << max(0ll , dp[6][x]) << '\n';}
	return 0;
}