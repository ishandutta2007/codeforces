#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace chrono;
using namespace __gnu_pbds;
mt19937 rng(high_resolution_clock::now().time_since_epoch().count());
mt19937_64 rngll(high_resolution_clock::now().time_since_epoch().count());
template<typename T> T ctmax(T &x, const T &y){ return x = max(x, y); }
template<typename T> T ctmin(T &x, const T &y){ return x = min(x, y); }
template<typename T> using Tree = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;



int main(){
	cin.tie(0)->sync_with_stdio(0);
	int n;
	cin >> n;
	vector<int> p(n);
	copy_n(istream_iterator<int>(cin), n, p.begin());
	for(auto &x: p){
		-- x;
	}
	vector<pair<int, int>> res;
	auto apply = [&](int i, int j){
		if(j < i){
			swap(i, j);
		}
		if(2 * abs(i - j) >= n){
			res.emplace_back(i, j);
		}
		else if(2 * i >= n && 2 * j >= n){
			res.emplace_back(0, i);
			res.emplace_back(0, j);
			res.emplace_back(0, i);
		}
		else if(2 * (n - 1 - i) >= n && 2 * (n - 1 - j) >= n){
			res.emplace_back(n - 1, i);
			res.emplace_back(n - 1, j);
			res.emplace_back(n - 1, i);
		}
		else{
			res.emplace_back(0, j);
			res.emplace_back(i, n - 1);
			res.emplace_back(0, n - 1);
			res.emplace_back(0, j);
			res.emplace_back(i, n - 1);
		}
	};
	vector<int> visited(n);
	for(int u = 0; u < n; ++ u){
		if(!visited[u]){
			vector<int> cycle;
			int v = u;
			do{
				visited[v] = true;
				cycle.push_back(v);
				v = p[v];
			}while(v != u);
			for(int i = int(cycle.size()) - 1; i > 0; -- i){
				apply(cycle[i - 1], cycle[i]);
			}
		}
	}
	cout << int(res.size()) << "\n";
	for(auto [u, v]: res){
		cout << u + 1 << " " << v + 1 << "\n";
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