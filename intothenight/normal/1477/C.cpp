#include <bits/stdc++.h>
using namespace std;
using namespace chrono;
mt19937 rng(high_resolution_clock::now().time_since_epoch().count());
mt19937_64 rngll(high_resolution_clock::now().time_since_epoch().count());



int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	int n;
	cin >> n;
	vector<array<int, 2>> a(n);
	for(auto i = 0; i < n; ++ i){
		cin >> a[i][0] >> a[i][1];
	}
	vector<int> order(n);
	iota(order.begin(), order.end(), 0);
	auto bad = [&](int i, int j, int k){
		int x = a[j][0] - a[i][0];
		int y = a[j][1] - a[i][1];
		int xx = a[j][0] - a[k][0];
		int yy = a[j][1] - a[k][1];
		return 1LL * x * xx + 1LL * y * yy <= 0;
	};
	while(true){
		bool changed = false;
		for(auto i = 1; i < n - 1; ++ i){
			if(bad(order[i - 1], order[i], order[i + 1])){
				swap(order[i], order[i + 1]);
				changed = true;
			}
		}
		if(!changed){
			break;
		}
	}
	for(auto i: order){
		cout << i + 1 << " ";
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