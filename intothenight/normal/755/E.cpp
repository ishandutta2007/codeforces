#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
mt19937_64 rngll(chrono::steady_clock::now().time_since_epoch().count());
template<typename T> T ctmax(T &x, const T &y){ return x = max(x, y); }
template<typename T> T ctmin(T &x, const T &y){ return x = min(x, y); }
template<typename T> using Tree = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;



int main(){
	cin.tie(0)->sync_with_stdio(0);
	int n, k;
	cin >> n >> k;
	auto kill = [](){
		cout << -1;
		exit(0);
	};
	if(n == 4){
		if(k == 3){
			cout << "3\n1 2\n2 3\n3 4";
		}
		else{
			kill();
		}
	}
	else if(n <= 3){
		kill();
	}
	else{
		if(k >= 4 || k == 1){
			kill();
		}
		else if(k == 2){
			cout << n - 1 << "\n";
			for(int i = 0; i < n - 1; ++ i){
				cout << i + 1 << " " << i + 2 << "\n";
			}
		}
		else{
			int g1 = n - 2 >> 1, g2 = n - 2 - g1;
			vector<int> a1, a2;
			for(int i = 2; i < 2 + g1; ++ i){
				a1.push_back(i);
			}
			for(int i = 2 + g1; i < 2 + g1 + g2; ++ i){
				a2.push_back(i);
			}
			cout << g1 + g2 + g1 * g2<< "\n";
			for(auto u: a1){
				cout << "1 " << u << "\n";
			}
			for(auto u: a2){
				cout << u << " " << g1 + g2 + 2 << "\n";
			}
			for(auto u: a1){
				for(auto v: a2){
					cout << u << " " << v << "\n";
				}
			}
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