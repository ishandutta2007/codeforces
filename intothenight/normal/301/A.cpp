#include <bits/stdc++.h>
using namespace std;
#if __cplusplus > 201703L
#include <ranges>
using namespace numbers;
#endif



int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	int n;
	cin >> n;
	vector<int> a(2 * n - 1);
	for(auto &x: a){
		cin >> x;
	}
	int sum = 0;
	for(auto x: a){
		sum += abs(x);
	}
	if(n & 1){
		cout << sum << "\n";
	}
	else{
		int cnt = 0;
		for(auto &x: a){
			if(x < 0){
				++ cnt;
			}
			x = abs(x);
		}
		if(cnt & 1){
			cout << sum - 2 * ranges::min(a) << "\n";
		}
		else{
			cout << sum << "\n";
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