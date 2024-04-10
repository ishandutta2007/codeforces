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
	vector<int> a(n);
	copy_n(istream_iterator<int>(cin), n, a.begin());
	vector<__int128_t> pref(n + 1);
	for(auto i = 0; i < n; ++ i){
		pref[i + 1] = pref[i] + a[i];
	}
	vector<pair<__int128_t, int>> t(n);
	t[0] = {pref[n], 1};
	vector<array<int, 2>> stack{{0, 1}};
	for(auto i = 1; i < n; ++ i){
		auto [l, r] = stack.front();
		if((pref[r] - pref[l]) * (i + 1 - (r - l)) >= (pref[n] - pref[r]) * (r - l)){
			t[i] = {pref[r] - pref[l], r - l};
		}
		else{
			t[i] = {pref[n] - pref[l], i + 1 - l};
		}
		l = i, r = i + 1;
		while(!stack.empty() && (pref[stack.back()[1]] - pref[stack.back()[0]]) * (r - l) <= (pref[r] - pref[l]) * (stack.back()[1] - stack.back()[0])){
			l = stack.back()[0];
			stack.pop_back();
		}
		stack.push_back({l, r});
	}
	int qn;
	cin >> qn;
	for(auto qi = 0; qi < qn; ++ qi){
		int th;
		cin >> th;
		if(1LL * th * t[n - 1].second < t[n - 1].first){
			cout << "-1\n";
		}
		else{
			cout << *ranges::partition_point(ranges::iota_view(1, n), [&](int x){ return 1LL * th * t[x - 1].second < t[x - 1].first; }) << "\n";
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