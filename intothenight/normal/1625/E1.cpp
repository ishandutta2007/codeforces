#include <bits/stdc++.h>
using namespace std;
#if __cplusplus > 201703L
#include <ranges>
using namespace numbers;
#endif

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
	int n, qn;
	string s;
	cin >> n >> qn >> s;
	vector<int> match(n, -1);
	{
		vector<int> stack;
		for(auto i = 0; i < n; ++ i){
			if(s[i] == '('){
				stack.push_back(i);
			}
			else if(!stack.empty()){
				match[stack.back()] = i;
				match[i] = stack.back();
				stack.pop_back();
			}
		}
	}
	vector<int> repr(n, -1);
	vector<array<int, 3>> edge;
	vector<int> edge_order;
	vector<int> pv;
	vector<vector<int>> adj;
	int root = y_combinator([&](auto self, int l, int r)->int{
		int u = (int)adj.size();
		adj.emplace_back();
		pv.push_back(-1);
		for(auto i = l; i < r; ++ i){
			if(~match[i]){
				int v = self(i + 1, match[i]);
				int id = (int)edge.size();
				edge.push_back({v, i, match[i]});
				edge_order.push_back((int)adj[u].size());
				pv[v] = u;
				adj[u].push_back(id);
				repr[i] = repr[match[i]] = id;
				i = match[i];
			}
		}
		return u;
	})(0, n);
	vector<vector<long long>> dp((int)adj.size());
	y_combinator([&](auto self, int u)->void{
		dp[u].resize((int)adj[u].size() + 1);
		for(auto t = 0; t < (int)adj[u].size(); ++ t){
			int id = adj[u][t];
			int v = edge[id][0];
			self(v);
			int degv = (int)adj[v].size();
			dp[u][t + 1] = dp[u][t] + dp[v].back() + 1LL * degv * (degv + 1) / 2;
		}
	})(root);
	for(auto qi = 0; qi < qn; ++ qi){
		int t, l, r;
		cin >> t >> l >> r, -- l, -- r;
		int id_l = repr[l], id_r = repr[r];
		int u = pv[edge[id_l][0]];
		assert(u == pv[edge[id_r][0]]);
		int cnt = edge_order[id_r] + 1 - edge_order[id_l];
		cout << dp[u][edge_order[id_r] + 1] - dp[u][edge_order[id_l]] + 1LL * cnt * (cnt + 1) / 2 << "\n";
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