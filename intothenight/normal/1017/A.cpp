#include <bits/stdc++.h>
using namespace std;



int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	int n;
	cin >> n;
	vector<array<int, 4>> a(n);
	for(auto i = 0; i < n; ++ i){
		for(auto j = 0; j < 4; ++ j){
			cin >> a[i][j];
		}
	}
	vector<int> order(n);
	iota(order.begin(), order.end(), 0);
	sort(order.begin(), order.end(), [&](int i, int j){
		if(accumulate(a[i].begin(), a[i].end(), 0) != accumulate(a[j].begin(), a[j].end(), 0)){
			return accumulate(a[i].begin(), a[i].end(), 0) > accumulate(a[j].begin(), a[j].end(), 0);
		}
		else{
			return i < j;
		}
	});
	int p = 0;
	while(order[p]){
		++ p;
	}
	cout << p + 1 << "\n";
	return 0;
}

/*

*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////