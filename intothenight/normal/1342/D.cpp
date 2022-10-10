#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/rope>
using namespace std;
using namespace chrono;
using namespace __gnu_pbds;
using namespace __gnu_cxx;
mt19937 rng(high_resolution_clock::now().time_since_epoch().count());
mt19937_64 rngll(high_resolution_clock::now().time_since_epoch().count());
template<typename T> T ctmax(T &x, const T &y){ return x = max(x, y); }
template<typename T> T ctmin(T &x, const T &y){ return x = min(x, y); }
template<typename T> using Tree = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;



int main(){
	cin.tie(0)->sync_with_stdio(0);
	int n, k;
	cin >> n >> k;
	vector<int> cnt(k);
	for(auto i = 0; i < n; ++ i){
		int x;
		cin >> x;
		++ cnt[x - 1];
	}
	vector<int> c(k);
	for(auto i = 0; i < k; ++ i){
		cin >> c[i];
	}
	vector<vector<int>> res;
	int prev = 0;
	for(auto i = k - 1; i >= 0; -- i){
		int p = i != k - 1 && c[i] == c[i + 1] ? prev : 0;
		for(auto REP = 0; REP < cnt[i]; ++ REP){
			if(p == int(res.size())){
				res.emplace_back();
			}
			while(int(res[p].size()) == c[i]){
				++ p;
				if(p == int(res.size())){
					res.emplace_back();
				}
			}
			res[p].push_back(i);
		}
		prev = p;
	}
	cout << int(res.size()) << "\n";
	for(auto &t: res){
		cout << int(t.size()) << " ";
		for(auto x: t){
			cout << x + 1 << " ";
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