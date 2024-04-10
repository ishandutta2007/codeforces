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
	string s;
	cin >> n >> s;
	vector<int> a, p;
	for(auto i = 0; i < n; ++ i){
		if(s[i] == '*'){
			a.push_back(i);
		}
		if(s[i] == 'P'){
			p.push_back(i);
		}
	}
	auto pred = [&](int t){
		int i = 0;
		for(auto x: p){
			if(abs(x - a[i]) > t){
				continue;
			}
			int j = i + 1;
			auto ok = [&](int j){
				if(a[j - 1] <= x){
					return abs(x - a[i]) <= t;
				}
				else if(a[i] <= x && x < a[j - 1]){
					int X = abs(x - a[i]), Y = abs(a[j - 1] - x);
					return max(X, Y) + 2 * min(X, Y) <= t;
				}
				else{
					return abs(a[j - 1] - x) <= t;
				}
			};
			while(j < int(a.size()) && ok(j + 1)){
				++ j;
			}
			i = j;
			if(i >= int(a.size())){
				break;
			}
		}
		return i >= int(a.size());
	};
	cout << custom_binary_search(-1, 2 * n, pred, false);
	return 0;
}

/*

*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////