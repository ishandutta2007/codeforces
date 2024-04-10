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
	vector<int> pos(n);
	for(int i = 0; i < n; ++ i){
		int x;
		cin >> x;
	}
	for(int i = 0; i < n; ++ i){
		int x;
		cin >> x;
		if(x){
			-- x;
			pos[x] = i + 1;
		}
	}
	int i = 1;
	while(i < n && pos[i] == pos[i - 1] + 1){
		++ i;
	}
	-- i;
	if(pos[i] == n){
		bool ok = true;
		for(int j = i + 1; j < n; ++ j){
			if(pos[j] >= j - i){
				ok = false;
				break;
			}
		}
		if(ok){
			cout << pos[0] - 1;
			return 0;
		}
	}
	int cur = numeric_limits<int>::min();
	for(int i = 0; i < n; ++ i){
		ctmax(cur, pos[i] - i);
	}
	cout << cur + n;
	return 0;
}

/*

*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////