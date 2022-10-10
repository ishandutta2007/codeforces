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
	auto kill = [](){
		cout << -1;
		exit(0);
	};
	int n, k;
	cin >> n >> k;
	if(n > 1 && k == 1 || k > n){
		kill();
	}
	if(n == 1){
		cout << "a";
	}
	else if(k == 2){
		for(int i = 0; i < n; ++ i){
			if(i % 2){
				cout << "b";
			}
			else{
				cout << "a";
			}
		}
	}
	else{
		for(int i = 0; i < (n - (k - 2)); ++ i){
			if(i % 2){
				cout << "b";
			}
			else{
				cout << "a";
			}
		}
		for(int i = 0; i < k - 2; ++ i){
			cout << char('c' + i);
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