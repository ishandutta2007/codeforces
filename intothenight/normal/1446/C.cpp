#include <bits/stdc++.h>
using namespace std;



int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	int n;
	cin >> n;
	vector<int> a(n);
	for(auto i = 0; i < n; ++ i){
		cin >> a[i];
	}
	sort(a.begin(), a.end());
	function<int(int, int, int)> solve = [&](int l, int r, int bit){
		if(r - l == 1){
			return 0;
		}
		int m = l;
		while(m < r && ~a[m] & 1 << bit){
			++ m;
		}
		if(m == l || m == r){
			return solve(l, r, bit - 1);
		}
		return min(solve(l, m, bit - 1) + r - m - 1, solve(m, r, bit - 1) + m - l - 1);
	};
	cout << solve(0, n, 30) << "\n";
	return 0;
}

/*

*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////