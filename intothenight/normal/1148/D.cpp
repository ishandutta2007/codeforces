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
	typedef array<int, 3> T;
	int n;
	cin >> n;
	vector<T> a, b;
	for(int i = 0; i < n; ++ i){
		int x, y;
		cin >> x >> y;
		if(x < y){
			a.push_back({x, y, i});
		}
		else{
			b.push_back({x, y, i});
		}
	}
	if(int(a.size()) > int(b.size())){
		cout << int(a.size()) << "\n";
		sort(a.rbegin(), a.rend());
		for(auto [u, v, i]: a){
			cout << i + 1 << " ";
		}
	}
	else{
		cout << int(b.size()) << "\n";
		sort(b.begin(), b.end());
		for(auto [u, v, i]: b){
			cout << i + 1 << " ";
		}
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