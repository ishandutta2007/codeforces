#include <bits/stdc++.h>
using namespace std;



int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	int n, k, t;
	cin >> n >> k >> t;
	const int mx = 1 << 10;
	vector<int> cnt(mx);
	for(auto i = 0; i < n; ++ i){
		int x;
		cin >> x;
		++ cnt[x];
	}
	for(auto rep = 0; rep < k; ++ rep){
		vector<int> cnt_next(mx + 1);
		int par = 0;
		for(auto x = 0; x < mx; ++ x){
			cnt_next[x ^ t] += cnt[x] + !par >> 1;
			cnt_next[x] += cnt[x] + par >> 1;
			par ^= cnt[x] & 1;
		}
		swap(cnt, cnt_next);
	}
	for(auto x = mx - 1; x >= 0; -- x){
		if(cnt[x]){
			cout << x << " ";
			break;
		}
	}
	for(auto x = 0; x < mx; ++ x){
		if(cnt[x]){
			cout << x << "\n";
			break;
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