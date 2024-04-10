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
	int n, k;
	cin >> n >> k;
	vector<int> a(k);
	copy_n(istream_iterator<int>(cin), k, a.begin());
	for(auto &x: a){
		-- x;
	}
	vector<int> firstpos(n, k); // cnt[i]: # of distinct values in [i, n)
	for(int i = 0; i < k; ++ i){
		if(firstpos[a[i]] == k){
			firstpos[a[i]] = i;
		}
	}
	vector<vector<int>> query(k + 1);
	for(int x = 0; x < n; ++ x){
		if(x) query[firstpos[x]].push_back(x - 1);
		query[firstpos[x]].push_back(x);
		if(x != n - 1) query[firstpos[x]].push_back(x + 1);
	}
	set<int> q;
	int res = 0;
	for(int i = k; i >= 0; -- i){
		if(i < k){
			q.insert(a[i]);
		}
		for(auto u: query[i]){
			if(!q.count(u)){
				++ res;
			}
		}
	}
	cout << res;
	return 0;
}

/*

*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////