#include <bits/stdc++.h>
using namespace std;



int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	int n, qn;
	cin >> n >> qn;
	vector<int> a(n);
	vector<array<int, 2>> dif(n - 1);
	for(auto i = 0; i < n; ++ i){
		cin >> a[i];
	}
	for(auto i = 0; i < n - 1; ++ i){
		dif[i] = {abs(a[i + 1] - a[i]), i};
	}
	sort(dif.rbegin(), dif.rend());
	set<array<int, 2>> segs{{0, n - 1}};
	vector<array<int, 2>> range(n - 1, {-1, -1});
	for(auto [x, i]: dif){
		auto it = prev(segs.upper_bound({i, numeric_limits<int>::max()}));
		auto [l, r] = *it;
		segs.erase(it);
		range[i] = {l, r};
		if(l < i){
			segs.insert({l, i});
		}
		if(i + 1 < r){
			segs.insert({i + 1, r});
		}
	}
	for(auto qi = 0; qi < qn; ++ qi){
		int ql, qr;
		cin >> ql >> qr, -- ql, -- qr;
		long long res = 0;
		for(auto [x, i]: dif){
			auto [l, r] = range[i];
			if(ql <= i && i < qr){
				res += 1LL * x * (i - max(ql, l) + 1) * (min(qr, r) - i);
			}
		}
		cout << res << "\n";
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