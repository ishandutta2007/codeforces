#include "bits/stdc++.h"
using namespace std;
template<typename T, typename U> T &ctmax(T &x, const U &y){ return x = max<T>(x, y); }
template<typename T, typename U> T &ctmin(T &x, const U &y){ return x = min<T>(x, y); }

// DEBUG BEGIN
template<typename L, typename R>
ostream &operator<<(ostream &out, pair<L, R> p){
	return out << "(" << p.first << ", " << p.second << ")";
}
template<typename Tuple, size_t ...Is>
void print_tuple(ostream &out, Tuple t, index_sequence<Is...>){
	((out << (Is ? ", " : "") << get<Is>(t)), ...);
}
template<typename ...Args>
ostream &operator<<(ostream &out, tuple<Args...> t){
	out << "(", print_tuple(out, t, index_sequence_for<Args...>{}); return out << ")";
}
template<typename ...Args, template<typename...> typename T>
ostream &operator<<(enable_if_t<!is_same_v<T<Args...>, string>, ostream> &out, T<Args...> arr){
	out << "{"; for(auto &x: arr) out << x << ", ";
	return out << (arr.size() ? "\b\b" : "") << "}";
}
template<typename T, size_t N>
ostream &operator<<(ostream &out, array<T, N> arr){
	out << "{"; for(auto &x: arr) out << x << ", ";
	return out << (arr.size() ? "\b\b" : "") << "}";
}
template<size_t S>
ostream &operator<<(ostream &out, bitset<S> b){
	for(int i = 0; i < S; ++ i) out << b[i];
	return out;
}
void debug_out(){ cerr << "\b\b " << endl; }
template<typename Head, typename... Tail>
void debug_out(Head H, Tail... T){ cerr << H << ", ", debug_out(T...); }
#ifdef LOCAL
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]: ", debug_out(__VA_ARGS__)
#else
#define debug(...) 42
#endif
// DEBUG END

int main(){
	cin.tie(0)->sync_with_stdio(0);
	int n, m, k;
	cin >> n >> m >> k;
	const int mx_day = 1e6 + 10;
	vector<vector<array<int, 2>>> depart(mx_day), arrive(mx_day);
	for(auto rep = 0; rep < m; ++ rep){
		int day, u, v, c;
		cin >> day >> u >> v >> c, -- u, -- v, -- day;
		if(!~v){
			depart[day].push_back({u, c});
		}
		else{
			arrive[day].push_back({v, c});
		}
	}
	static const int inf = numeric_limits<int>::max() / 2;
	vector<pair<int, long long>> depart_dp(mx_day + 1); // dp[i]: # of satisfied, min cost;
	for(auto d = 0; d < mx_day; ++ d){
		static vector<int> min_cost(n, inf);
		depart_dp[d + 1] = depart_dp[d];
		for(auto [u, c]: depart[d]){
			if(min_cost[u] > c){
				if(min_cost[u] == inf){
					++ depart_dp[d + 1].first;
				}
				else{
					depart_dp[d + 1].second -= min_cost[u];
				}
				min_cost[u] = c;
				depart_dp[d + 1].second += min_cost[u];
			}
		}
	}
	debug(depart_dp);
	long long res = numeric_limits<long long>::max();
	for(auto d = mx_day - 1; d >= k && depart_dp[d - k].first == n; -- d){
		static vector<int> min_cost(n, inf);
		static pair<int, long long> cur{};
		for(auto [u, c]: arrive[d]){
			if(min_cost[u] > c){
				if(min_cost[u] == inf){
					++ cur.first;
				}
				else{
					cur.second -= min_cost[u];
				}
				min_cost[u] = c;
				cur.second += min_cost[u];
			}
		}
		debug(d, cur);
		debug(min_cost);
		if(cur.first == n){
			ctmin(res, depart_dp[d - k].second + cur.second);
		}
	}
	res == numeric_limits<long long>::max() ? cout << "-1\n" : cout << res << "\n";
	return 0;
}

/*

*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////