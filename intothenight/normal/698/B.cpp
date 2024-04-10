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
	int n;
	cin >> n;
	vector<int> a(n);
	for(auto i = 0; i < n; ++ i){
		cin >> a[i], -- a[i];
	}
	vector<vector<int>> cycle;
	vector<int> visited(n, -1);
	for(auto u = 0; u < n; ++ u){
		if(!~visited[u]){
			int v = u;
			while(!~visited[v]){
				visited[v] = u;
				v = a[v];
			}
			if(visited[v] == u){
				int w = v;
				cycle.emplace_back();
				while(w != v || cycle.back().empty()){
					cycle.back().push_back(w);
					w = a[w];
				}
			}
		}
	}
	int t = -1;
	for(auto i = 0; i < int(cycle.size()); ++ i){
		if(int(cycle[i].size()) == 1){
			t = i;
			break;
		}
	}
	if(t == -1){
		cout << int(cycle.size()) << "\n";
		t = 0;
		a[cycle[t][0]] = cycle[t][0];
	}
	else{
		cout << int(cycle.size()) - 1 << "\n";
	}
	for(auto i = 0; i < int(cycle.size()); ++ i){
		if(i != t){
			a[cycle[i][0]] = cycle[t][0];
		}
	}
	for(auto u: a){
		cout << u + 1 << " ";
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