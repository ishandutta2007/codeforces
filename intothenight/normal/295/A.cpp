#include <bits/stdc++.h>
using namespace std;
#if __cplusplus > 201703L
#include <ranges>
using namespace numbers;
#endif



int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	int n, m, k;
	cin >> n >> m >> k;
	vector<int> a(n);
	for(auto i = 0; i < n; ++ i){
		cin >> a[i];
	}
	vector<array<int, 3>> q(m);
	for(auto &[l, r, d]: q){
		cin >> l >> r >> d, -- l;
	}
	vector<int> cnt(m + 1);
	for(auto i = 0; i < k; ++ i){
		int l, r;
		cin >> l >> r, -- l;
		++ cnt[l], -- cnt[r];
	}
	vector<long long> pref(n + 1);
	for(auto i = 0; i < m; ++ i){
		cnt[i + 1] += cnt[i];
		auto [l, r, d] = q[i];
		pref[l] += 1LL * cnt[i] * d;
		pref[r] -= 1LL * cnt[i] * d;
	}
	for(auto i = 0; i < n; ++ i){
		pref[i + 1] += pref[i];
		cout << a[i] + pref[i] << " ";
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