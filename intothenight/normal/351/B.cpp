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
	cout << fixed << setprecision(15);
	int n;
	cin >> n;
	vector<int> p(n);
	copy_n(istream_iterator<int>(cin), n, p.begin());
	int inv = 0;
	for(int i = 0; i < n; ++ i){
		for(int j = i + 1; j < n; ++ j){
			if(p[i] > p[j]){
				++ inv;
			}
		}
	}
	if(inv % 2){
		cout << inv * 2 - 1;
	}
	else{
		cout << inv * 2;
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