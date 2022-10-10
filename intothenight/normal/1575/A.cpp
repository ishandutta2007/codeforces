#include <bits/stdc++.h>
using namespace std;



int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	int n, m;
	cin >> n >> m;
	vector<string> a(n);
	for(auto i = 0; i < n; ++ i){
		cin >> a[i];
	}
	vector<int> order(n);
	iota(order.begin(), order.end(), 0);
	stable_sort(order.begin(), order.end(), [&](int i, int j){
		int p = 0;
		while(a[i][p] == a[j][p]){
			++ p;
		}
		return ~p & 1 ? a[i][p] < a[j][p] : a[i][p] > a[j][p];
	});
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