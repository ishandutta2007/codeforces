#include <bits/stdc++.h>
using namespace std;

template<class F>
struct y_combinator_result{
	F f;
	template<class T> explicit y_combinator_result(T &&f): f(forward<T>(f)){ }
	template<class ...Args> decltype(auto) operator()(Args &&...args){ return f(ref(*this), forward<Args>(args)...); }
};
template<class F>
decltype(auto) y_combinator(F &&f){
	return y_combinator_result<decay_t<F>>(forward<F>(f));
}

int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	int n;
	cin >> n;
	vector<vector<int>> adj(n);
	for(auto i = 0; i < n - 1; ++ i){
		int u, v;
		cin >> u >> v, -- u, -- v;
		adj[u].push_back(v), adj[v].push_back(u);
	}
	int qn;
	cin >> qn;
	vector<int> res(qn);
	vector<vector<array<int, 2>>> q(n);
	for(auto qi = 0; qi < qn; ++ qi){
		int u, k;
		cin >> u >> k, -- u;
		q[u].push_back({k, qi});
	}
	vector<vector<pair<array<int, 2>, double>>> dp(n);
	y_combinator([&](auto self, int u, int p)->void{
		dp[u] = {{{0, 0}, numeric_limits<double>::max()}};
		for(auto v: adj[u]){
			if(v == p) continue;
			self(v, u);
			static vector<array<int, 2>> temp;
			temp.clear();
			for(auto [line1, ignore]: dp[u]){
				temp.push_back({line1[0], line1[1] + 1});
				for(auto [line2, ignore]: dp[v]){
					temp.push_back({line1[0] + line2[0] + 1, line1[1] + line2[1]});
				}
			}
			sort(temp.rbegin(), temp.rend());
			auto &c = dp[u];
			c.clear();
			for(auto [m, ch]: temp){
				if(!c.empty() && c.back().first[0] == m){
					continue;
				}
				while((int)c.size() >= 2 && next(c.rbegin())->second >= 1.0 * (c.back().first[1] - ch) / (c.back().first[0] - m)){
					c.pop_back();
				}
				if(!c.empty()){
					c.back().second = 1.0 * (c.back().first[1] - ch) / (c.back().first[0] - m);
				}
				c.push_back({{m, ch}, numeric_limits<double>::max()});
			}
		}
		sort(q[u].begin(), q[u].end());
		for(auto [k, qi]: q[u]){
			auto &line = *partition_point(dp[u].begin(), dp[u].end(), [&](const auto &line){ return line.second <= k; });
			res[qi] = line.first[1] - line.first[0] * k;
		}
	})(0, -1);
	for(auto x: res){
		cout << x << "\n";
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