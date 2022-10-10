#include "bits/stdc++.h"
using namespace std;



int main(){
	cin.tie(0)->sync_with_stdio(0);
	const int mx = 20;
	vector<int> cnt(mx);
	int n;
	cin >> n;
	for(auto i = 0; i < n; ++ i){
		int x;
		cin >> x;
		for(auto bit = 0; bit < mx; ++ bit){
			if(x & 1 << bit){
				++ cnt[bit];
			}
		}
	}
	long long res = 0;
	for(auto i = 1; i <= n; ++ i){
		int cur = 0;
		for(auto bit = 0; bit < mx; ++ bit){
			if(cnt[bit] >= i){
				cur += 1 << bit;
			}
		}
		res += 1LL * cur * cur;
	}
	cout << res << "\n";
	return 0;
}

/*

*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////