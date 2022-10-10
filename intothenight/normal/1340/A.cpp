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

void SOLVE(){
	int n;
	cin >> n;
	vector<int> pos(n);
	for(auto i = 0; i < n; ++ i){
		int x;
		cin >> x;
		pos[x - 1] = i;
	}
	vector<int> next(n);
	set<pair<int, int>> cnt; // Count, position
	vector<int> count(n, 1);
	iota(next.begin(), next.end(), 1);
	for(auto i = 0; i < n; ++ i){
		cnt.insert({1, i});
	}
	vector<int> prev(n + 1);
	iota(prev.begin(), prev.end(), -1);
	for(auto i = 0; i < n; ++ i){
		/*cout << "Testing i = " << i << "\n";
		cout << "count = ";
		for(auto x: count){
			cout << x << " ";
		}
		cout << "\n";
		cout << "cnt = ";
		for(auto [c, val]: cnt){
			cout << "(" << c << ", " << val << ") ";
		}
		cout << "\n";
		cout << "next = ";
		for(auto x: next){
			cout << x << " ";
		}
		cout << "\n\n";*/
		if(count[pos[i]] != cnt.rbegin()->first){
			cout << "No\n";
			return;
		}
		cnt.erase({count[pos[i]], pos[i]});
		if(next[pos[i]] != n){
			cnt.erase({count[next[pos[i]]], next[pos[i]]});
			cnt.insert({count[next[pos[i]]] += count[pos[i]], next[pos[i]]});
		}
		if(prev[pos[i]] != -1){
			next[prev[pos[i]]] = next[pos[i]];
			prev[next[pos[i]]] = prev[pos[i]];
		}
	}
	cout << "Yes\n";
}

int main(){
	cin.tie(0)->sync_with_stdio(0);
	int ttt;
	cin >> ttt;
	while(ttt --){
		SOLVE();
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