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
	int n, th;
	string init;
	cin >> n >> th >> init;
	vector<string> res(n);
	for(auto u = 0; u < n; ++ u){
		res[u] = {init[u]};
	}
	vector<array<int, 2>> adj(n);
	for(auto &[u, v]: adj){
		cin >> u >> v, -- u, -- v;
	}
	vector<int> order;
	y_combinator([&](auto self, int u)->void{
		if(!~u){
			return;
		}
		self(adj[u][0]);
		order.push_back(u);
		self(adj[u][1]);
	})(0);
	vector<int> prefer(n);
	for(auto l = 0; l < n; ){
		int r = l;
		while(r < n && init[order[l]] == init[order[r]]){
			++ r;
		}
		if(r < n && init[order[l]] < init[order[r]]){
			for(auto u: order | ranges::views::take(r) | ranges::views::drop(l)){
				prefer[u] = true;
			}
		}
		l = r;
	}
	y_combinator([&](auto self, int u)->void{
		if(!~u){
			return;
		}
		vector<int> path;
		while(~u && (int)size(path) < th){
			path.push_back(u);
			u = adj[u][0];
		}
		while(!empty(path) && !prefer[path.back()]){
			path.pop_back();
		}
		th -= (int)size(path);
		for(auto u: path | ranges::views::reverse){
			res[u] += res[u];
			self(adj[u][1]);
		}
	})(0);
	for(auto u: order){
		cout << res[u];
	}
	cout << "\n";
	return 0;
}

/*

*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////