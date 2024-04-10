#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
mt19937_64 rngll(chrono::steady_clock::now().time_since_epoch().count());
template<typename T> T ctmax(T &x, const T &y){ return x = max(x, y); }
template<typename T> T ctmin(T &x, const T &y){ return x = min(x, y); }
template<typename T> using Tree = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;



int main(){
	cin.tie(0)->sync_with_stdio(0);
	int n;
	cin >> n;
	vector<string> a(n);
	copy_n(istream_iterator<string>(cin), n, a.begin());
	vector<vector<int>> dp(2 * n - 1);
	dp[2 * n - 2] = {0, 0};
	for(int i = 2 * n - 3; i >= 0; -- i){
		int cnt = n - abs(n - 1 - i);
		int ncnt = n - abs(n - 1 - (i + 1));
		int cx = min(i, n - 1), cy = max(0, i - (n - 1));
		int nx = min(i + 1, n - 1), ny = max(0, i + 1 - (n - 1));
		const int mx = 1 << cnt;
		dp[i].resize(mx);
		for(int mask = 1; mask < mx; ++ mask){
			static vector<int> adj(26);
			fill(adj.begin(), adj.end(), 0);
			for(int bit = 0; bit < cnt; ++ bit){
				if(mask & 1 << bit){
					int x = cx - bit, y = cy + bit;
					if(x < n - 1){
						adj[a[x + 1][y] - 'a'] |= 1 << y - ny;
					}
					if(y < n - 1){
						adj[a[x][y + 1] - 'a'] |= 1 << y + 1 - ny;
					}
				}
			}
			dp[i][mask] = cx + cy & 1 ? numeric_limits<int>::min() : numeric_limits<int>::max();
			for(int c = 0; c < 26; ++ c){
				if(adj[c]){
					if(cx + cy & 1){
						ctmax(dp[i][mask], dp[i + 1][adj[c]] + (c == 0) - (c == 1));
					}
					else{
						ctmin(dp[i][mask], dp[i + 1][adj[c]] + (c == 0) - (c == 1));
					}
				}
			}
		}
	}
	dp[0][1] += (a[0][0] == 'a') - (a[0][0] == 'b');
	if(dp[0][1] > 0){
		cout << "FIRST";
	}
	else if(dp[0][1] < 0){
		cout << "SECOND";
	}
	else{
		cout << "DRAW";
	}
	return 0;
}

/*

*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////