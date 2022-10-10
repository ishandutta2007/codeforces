#include "bits/stdc++.h"
using namespace std;



int main(){
	cin.tie(0)->sync_with_stdio(0);
	int n;
	cin >> n;
	using point = array<long long, 2>;
	vector<point> a(n);
	for(auto i = 0; i < n; ++ i) for(auto j = 0; j < 2; ++ j) cin >> a[i][j];
	auto choose = [&](long long n, long long k){
		long long res = 1;
		for(int i = 1; i <= k; ++ i) res = res * (n - i + 1) / i;
		return res;
	};
	auto ori = [&](auto &p, auto &q, auto &r){
		return (q[0] - p[0]) * (r[1] - p[1]) - (q[1] - p[1]) * (r[0] - p[0]);
	};
	long long res = 5 * choose(n, 5);
	for(auto p: a){
		point t{p[0] + 1, p[1]};
		vector<point> upper, lower;
		for(auto q: a) if(q != p) (ori(p, t, q) >= 0 ? upper : lower).push_back(q);
		auto cmp = [&](auto &x, auto &y){return ori(x, y, p) > 0;};
		sort(upper.begin(), upper.end(), cmp), sort(lower.begin(), lower.end(), cmp);
		for(int tt = 0; tt < 2; ++ tt, swap(upper, lower)) for(int i = 0; i < int(upper.size()); ++ i){
			auto q = upper[i];
			int cnt = lower_bound(lower.begin(), lower.end(), t, [&](point x, point y){return ori(p, q, x) > 0;}) - lower.begin() + int(upper.size()) - i - 1;
			if(cnt >= 3) res -= choose(cnt, 3);
		}
	}
	cout << res;
	return 0;
}

/*

*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////