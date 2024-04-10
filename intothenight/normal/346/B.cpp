#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace chrono;
using namespace __gnu_pbds;
mt19937 rng(high_resolution_clock::now().time_since_epoch().count());
mt19937_64 rngll(high_resolution_clock::now().time_since_epoch().count());
template<typename T> T ctmax(T &x, const T &y){ return x = max(x, y); }
template<typename T> T ctmin(T &x, const T &y){ return x = min(x, y); }
template<typename T> using Tree = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

template<typename Str>
vector<int> prefix_function(const Str &s){
	int n = int(s.size());
	vector<int> p(n);
	for(int i = 1; i < n; ++ i){
		int j = p[i - 1];
		while(j > 0 && s[i] != s[j]) j = p[j - 1];
		if(s[i] == s[j]) ++ j;
		p[i] = j;
	}
	return p;
}
template<typename Str, typename UO = function<char(int)>, int lim = 26>
pair<vector<int>, vector<vector<int>>> prefix_automaton(const Str &s, UO trans = [](int c){return c + 'A';}){
	vector<int> p = prefix_function(s);
	int n = int(s.size());
	vector<vector<int>> aut(n, vector<int>(lim));
	for(int i = 0; i < n; ++ i) for(int c = 0; c < lim; ++ c){
		if(i > 0 && trans(c) != s[i]) aut[i][c] = aut[p[i - 1]][c];
		else aut[i][c] = i + (trans(c) == s[i]);
	}
	return {p, aut};
}

int main(){
	cin.tie(0)->sync_with_stdio(0);
	string s, t, u;
	cin >> s >> t >> u;
	auto aut = prefix_automaton(u).second;
	int n = int(s.size()), m = int(t.size()), l = int(u.size());
	vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(m + 1, vector<int>(l, -1)));
	vector<vector<vector<array<int, 4>>>> prev(n + 1, vector<vector<array<int, 4>>>(m + 1, vector<array<int, 4>>(l, {-1, -1, -1, -1})));
	dp[0][0][0] = 0;
	auto update = [&](int i, int j, int k, int ni, int nj, int nk, int dif){
		if(dp[ni][nj][nk] < dp[i][j][k] + dif){
			dp[ni][nj][nk] = dp[i][j][k] + dif;
			prev[ni][nj][nk] = {i, j, k, dif};
		}
	};
	for(int i = 0; i <= n; ++ i){
		for(int j = 0; j <= m; ++ j){
			for(int k = 0; k < l; ++ k){
				if(i < n && j < m && s[i] == t[j]){
					if(s[i] == u[k]){
						if(k != l - 1){
							update(i, j, k, i + 1, j + 1, k + 1, 1);
						}
					}
					else{
						update(i, j, k, i + 1, j + 1, aut[k][s[i] - 'A'], 1);
					}
				}
				if(j < m) update(i, j, k, i, j + 1, k, 0);
				if(i < n) update(i, j, k, i + 1, j, k, 0);
			}
		}
	}
	int maxlen = *max_element(dp[n][m].begin(), dp[n][m].end());
	if(maxlen <= 0){
		cout << 0;
		return 0;
	}
	string res;
	for(int k = 0; k < l; ++ k){
		if(dp[n][m][k] == maxlen){
			array<int, 4> state{n, m, k, 0};
			while(prev[state[0]][state[1]][state[2]][0] != -1){
				auto pstate = prev[state[0]][state[1]][state[2]];
				if(pstate[3]){
					res.push_back(s[pstate[0]]);
				}
				state = pstate;
			}
			reverse(res.begin(), res.end());
			cout << res;
			return 0;
		}
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