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
template<typename T> T ctmax(T &x, const T &y){ return x = max(x, y); }
template<typename T> T ctmin(T &x, const T &y){ return x = min(x, y); }
template<typename T> using Tree = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;



int main(){
	cin.tie(0)->sync_with_stdio(0);
	int m, k, n, s;
	cin >> m >> k >> n >> s;
	int rlimit = m - k * n;
	const int mx = 5e5;
	vector<int> a(m), req(mx), cur(mx);
	for(auto i = 0; i < m; ++ i){
		cin >> a[i], -- a[i];
	}
	for(auto i = 0; i < s; ++ i){
		int x;
		cin >> x, -- x;
		++ req[x];
	}
	int rem = accumulate(req.begin(), req.end(), 0, [&](int x, int y){ return x + (y > 0); });
	auto ins = [&](int i){
		++ cur[a[i]];
		if(cur[a[i]] == req[a[i]]){
			-- rem;
		}
	};
	auto del = [&](int i){
		if(cur[a[i]] == req[a[i]]){
			++ rem;
		}
		-- cur[a[i]];
	};
	for(auto l = 0, r = 0; l < m; del(l ++)){
		while(r < m && rem){
			ins(r ++);
		}
		if(!rem && l % k + max(r - l - k, 0) <= rlimit){
			vector<int> res;
			for(auto i = 0; i < l % k; ++ i){
				res.push_back(i);
			}
			vector<int> otr;
			fill(cur.begin(), cur.end(), 0);
			for(auto i = l; i < r; ++ i){
				if(cur[a[i]] < req[a[i]]){
					++ cur[a[i]];
				}
				else{
					otr.push_back(i);
				}
			}
			for(auto i = 0; i < max(r - l - k, 0); ++ i){
				res.push_back(otr[i]);
			}
			cout << int(res.size()) << "\n";
			for(auto i: res){
				cout << i + 1 << " ";
			}
			cout << "\n";
			return 0;
		}
	}
	cout << -1;
	return 0;
}

/*

*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////