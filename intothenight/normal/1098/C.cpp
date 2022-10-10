#include "bits/stdc++.h"
#include "ext/pb_ds/assoc_container.hpp"
#include "ext/pb_ds/tree_policy.hpp"
#include "ext/rope"
using namespace std;
using namespace chrono;
using namespace __gnu_pbds;
using namespace __gnu_cxx;
mt19937 rng(high_resolution_clock::now().time_since_epoch().count());
mt19937_64 rngll(high_resolution_clock::now().time_since_epoch().count());
#define lambdify(x) [&](auto &&...args){ return x(forward<decltype(args)>(args)...); }
template<typename T, typename U> T &ctmax(T &x, const U &y){ return x = max<T>(x, y); }
template<typename T, typename U> T &ctmin(T &x, const U &y){ return x = min<T>(x, y); }
template<typename T> using Tree = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

template<typename Pred>
long long custom_binary_search(long long low, long long high, Pred p, const bool &is_left = true){
	assert(low < high);
	while(high - low > 1){
		auto mid = low + (high - low >> 1);
		(p(mid) == is_left ? low : high) = mid;
	}
	return is_left ? low : high;
}

int main(){
	cin.tie(0)->sync_with_stdio(0);
	int n;
	long long s;
	cin >> n >> s;
	if(s < 2 * n - 1 || s > 1LL * n * (n + 1) / 2){
		cout << "No\n";
	}
	else{
		vector<vector<int>> h(n);
		vector<long long> lsz(n, 1);
		h[0].push_back(0);
		auto pred = [&](int branch){
			for(auto i = 0; i < n - 1; ++ i){
				lsz[i + 1] = min(lsz[i] * branch, 100000LL);
			}
			for(auto i = 1; i < n; ++ i){
				h[i].clear();
				h[i].push_back(i);
			}
			long long rem = 1LL * n * (n + 1) / 2 - s;
			int from = n - 1, to = 1;
			while(1){
				while(from >= 0 && h[from].empty()){
					-- from;
				}
				while(to < n && int(h[to].size()) == lsz[to]){
					++ to;
				}
				if(from <= to){
					return false;
				}
				int u = h[from].back(); h[from].pop_back();
				if(from - to >= rem){
					to = from - rem;
					h[to].push_back(u);
					return true;
				}
				else{
					h[to].push_back(u);
					rem -= from - to;
				}
			}
		};
		int branch = custom_binary_search(0, n - 1, pred, false);
		pred(branch);
		vector<int> p(n);
		for(auto i = 1; i < n; ++ i){
			int it = 0, cnt = 0;
			for(auto u: h[i]){
				p[u] = h[i - 1][it];
				++ cnt;
				if(cnt == branch){
					++ it;
					cnt = 0;
				}
			}
		}
		cout << "Yes\n";
		for(auto u = 1; u < n; ++ u){
			cout << p[u] + 1 << " ";
		}
		cout << "\n";
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