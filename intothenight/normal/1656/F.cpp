#include <bits/stdc++.h>
using namespace std;
#if __cplusplus > 201703L
#include <ranges>
using namespace numbers;
#endif

// Assumes there exists p, q in [low, high) such that
// f(i) > f(i+1) if i<p,
// f(i) = f(i+1) if p<=i<q
// f(i) < f(i+1) if q<=i
// Returns a point in [p,q]
// O(log (high - low))
// Minimizes the # of function calls
template<class T, class Compare = less<>>
T discrete_golden_section_search(T low, T high, auto f, Compare cmp = less<>()){
	assert(low < high);
	if(high - low >= 10){
		double phi = (sqrt(5) - 1) / 2;
		T mid1 = high - (high - low) * phi, mid2 = low + (high - low) * phi;
		auto val1 = f(mid1), val2 = f(mid2);
		while(high - low >= 10){
			if(cmp(val1, val2)){
				high = mid2, mid2 = mid1, val2 = val1;
				mid1 = high - (high - low) * phi, val1 = f(mid1);
			}
			else{
				low = mid1, mid1 = mid2, val1 = val2;
				mid2 = low + (high - low) * phi, val2 = f(mid2);
			}
		}
	}
	T res = low;
	auto val = f(res);
	for(auto x = low + 1; x < high; ++ x) if(auto xval = f(x); cmp(xval, val)) res = x, val = xval;
	return res;
}

int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	auto __solve_tc = [&](auto __tc_num)->int{
		int n;
		cin >> n;
		vector<int> a(n);
		for(auto i = 0; i < n; ++ i){
			cin >> a[i];
		}
		ranges::sort(a);
		long long sum = accumulate(a.begin(), a.end(), 0LL);
		if(sum + 1LL * a[0] * (n - 2) > 0 || sum + 1LL * a[n - 1] * (n - 2) < 0){
			cout << "INF\n";
			return 0;
		}
		auto eval = [&](int t)->long long{
			long long res = 1LL * (a[0] + t) * (a[n - 1] + t) - 1LL * t * t * (n - 1);
			for(auto u = 1; u < n - 1; ++ u){
				res += min(1LL * (a[0] + t) * (a[u] + t), 1LL * (a[n - 1] + t) * (a[u] + t));
			}
			return res;
		};
		int t = discrete_golden_section_search<int, greater<>>(-2e6, 2e6, eval, greater<>());
		cout << eval(t) << "\n";
		return 0;
	};
	int __tc_cnt;
	cin >> __tc_cnt;
	for(auto __tc_num = 0; __tc_num < __tc_cnt; ++ __tc_num){
		__solve_tc(__tc_num);
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