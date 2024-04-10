#include <bits/stdc++.h>
using namespace std;



int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	int l, r;
	cin >> l >> r, r -= l - 1;
	int mxbit = __lg(r), n = 1;
	vector<array<int, 3>> res;
	auto insert = [&](int u, int v, int w){
		res.push_back({u, v, w});
	};
	for(auto i = 0; i <= mxbit; ++ i){
		int v = n ++;
		insert(0, v, 1);
		for(auto u = 1; u < v; ++ u){
			insert(u, v, 1 << u - 1);
		}
	}
	if(__builtin_popcount(r) != 1){
		int v = n ++;
		for(auto u = v - 1, high = r; u > 0; -- u){
			if(1 << u - 1 < high){
				insert(u, v, high - (1 << u - 1));
				high -= 1 << u - 1;
			}
		}
		insert(0, v, 1);
	}
	if(l >= 2){
		int v = n ++;
		insert(v - 1, v, l - 1);
	}
	cout << "YES\n" << n << " " << (int)res.size() << "\n";
	for(auto [u, v, w]: res){
		cout << u + 1 << " " << v + 1 << " " << w << "\n";
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