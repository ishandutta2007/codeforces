#include "bits/stdc++.h"
using namespace std;



int main(){
	cin.tie(0)->sync_with_stdio(0);
	int n;
	cin >> n;
	vector<array<long long, 3>> a(n);
	for(auto i = 0; i < n; ++ i){
		for(auto j = 0; j < 3; ++ j){
			cin >> a[i][j];
		}
	}
	vector<int> res;
	for(auto i = 0; i < n; ++ i){
		if(a[i][2] >= 0){
			res.push_back(i);
			long long s = 0, delta = a[i][0];
			for(auto j = i + 1; j < n; ++ j){
				if(a[j][2] >= 0){
					a[j][2] -= s + max(delta, 0LL);
					-- delta;
					if(a[j][2] < 0){
						s += a[j][1];
					}
				}
			}
		}
	}
	cout << int(res.size()) << "\n";
	for(auto i: res){
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