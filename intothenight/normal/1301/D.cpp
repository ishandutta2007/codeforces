#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/rope>
using namespace std;
using namespace __gnu_pbds;
using namespace __gnu_cxx;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
mt19937_64 rngll(chrono::steady_clock::now().time_since_epoch().count());
template<typename T> T ctmax(T &x, const T &y){ return x = max(x, y); }
template<typename T> T ctmin(T &x, const T &y){ return x = min(x, y); }
template<typename T> using Tree = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
 
 
 
int main(){
	cin.tie(0)->sync_with_stdio(0);
	int n, m, k;
	cin >> n >> m >> k;
	if(k > 4 * n * m - 2 * n - 2 * m){
		cout << "NO";
		return 0;
	}
	-- m, -- n;
	cout << "YES\n";
	vector<pair<int, string>> res;
	auto answer = [&](){
		cout << res.size() << "\n";
		for(auto [x, s]: res){
			cout << x << " " << s << "\n";
		}
		exit(0);
	};
	for(int i = 0; i < n; ++ i){
		if(k <= 3 * m){
			if(k / 3) res.emplace_back(k / 3, "RDU");
			if(k % 3){
				res.emplace_back(1, string("RDU").substr(0, k % 3));
			}
			answer();
		}
		else{
			if(m) res.emplace_back(m, "RDU");
			k -= 3 * m;
		}
		if(k <= m){
			res.emplace_back(k, "L");
			answer();
		}
		else{
			if(m) res.emplace_back(m, "L");
			k -= m;
		}
		if(k == 1){
			res.emplace_back(1, "D");
			answer();
		}
		else{
			res.emplace_back(1, "D");
			-- k;
		}
	}
	if(k <= m){
		res.emplace_back(k, "R");
		answer();
	}
	else{
		if(m) res.emplace_back(m, "R");
		k -= m;
	}
	if(k <= m){
		res.emplace_back(k, "L");
		answer();
	}
	else{
		if(m) res.emplace_back(m, "L");
		k -= m;
	}
	res.emplace_back(k, "U");
	answer();
	return 0;
}
 
/*
 
*/
 
////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////