#include <bits/stdc++.h>
using namespace std;
#if __cplusplus > 201703L
#include <ranges>
using namespace numbers;
#endif
template<class T> T &ctmin(T &x){ return x; }
template<class T, class Head, class ...Tail> T &ctmin(T &x, const Head &h, const Tail &... t){ return ctmin(x = min<T>(x, h), t...); }
template<class T> T &ctmax(T &x){ return x; }
template<class T, class Head, class ...Tail> T &ctmax(T &x, const Head &h, const Tail &... t){ return ctmax(x = max<T>(x, h), t...); }

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
	if(n == 1){
		cout << "0\n";
		return 0;
	}
	vector<vector<array<int, 2>>> adj(n);
	long long sum = 0;
	for(auto i = 0; i < n - 1; ++ i){
		int u, v, w;
		cin >> u >> v >> w, -- u, -- v;
		adj[u].push_back({v, w});
		adj[v].push_back({u, w});
		sum += 2LL * w;
		assert(w <= 1000000000);
	}
	vector<long long> up_path(n);
	vector<long long> up_diam(n);
	vector<long long> down_path(n);
	vector<long long> down_diam(n);
	long long res = numeric_limits<long long>::max();
	y_combinator([&](auto self, int u, int p)->void{
		for(auto [v, w]: adj[u]){
			if(v == p){
				continue;
			}
			self(v, u);
			ctmax(down_diam[u], down_diam[v]);
			ctmax(down_diam[u], down_path[u] + down_path[v] + w);
			ctmax(down_path[u], down_path[v] + w);
		}
	})(0, -1);
	y_combinator([&](auto self, int u, int p, long long P, long long D)->void{
		array<long long, 2> opt_diam{D};
		array<long long, 4> opt_path{P};
		for(auto [v, w]: adj[u]){
			if(v == p){
				continue;
			}
			auto x = down_diam[v];
			if(opt_diam[0] < x){
				opt_diam = {x, opt_diam[0]};
			}
			else if(opt_diam[1] < x){
				opt_diam = {opt_diam[0], x};
			}
			x = down_path[v] + w;
			if(opt_path[0] < x){
				opt_path = {x, opt_path[0], opt_path[1], opt_path[2]};
			}
			else if(opt_path[1] < x){
				opt_path = {opt_path[0], x, opt_path[1], opt_path[2]};
			}
			else if(opt_path[2] < x){
				opt_path = {opt_path[0], opt_path[1], x, opt_path[2]};
			}
			else if(opt_path[3] < x){
				opt_path = {opt_path[0], opt_path[1], opt_path[2], x};
			}
		}
		ctmin(res, sum - accumulate(opt_path.begin(), opt_path.end(), 0LL));
		for(auto [v, w]: adj[u]){
			if(v == p){
				continue;
			}
			auto x = down_diam[v];
			ctmax(up_diam[v], opt_diam[x == opt_diam[0]]);
			x = down_path[v] + w;
			up_path[v] = opt_path[x == opt_path[0]];
			if(x == opt_path[0]){
				ctmax(up_diam[v], opt_path[1] + opt_path[2]);
			}
			else if(x == opt_path[1]){
				ctmax(up_diam[v], opt_path[0] + opt_path[2]);
			}
			else{
				ctmax(up_diam[v], opt_path[0] + opt_path[1]);
			}
			ctmin(res, sum - 2LL * w - down_diam[v] - up_diam[v]);
			self(v, u, up_path[v] + w, up_diam[v]);
		}
	})(0, -1, 0, 0);
	y_combinator([&](auto self, int u, int p)->void{
		
	})(0, -1);
	cout << res << "\n";
	return 0;
}

/*

*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////