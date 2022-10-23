#include <bits/stdc++.h>
using namespace std;
#if __cplusplus > 201703L
#include <ranges>
using namespace numbers;
#endif

// Returns the indices
// O(n log n)
template<class T, class Compare = less<>>
vector<int> longest_monotone_subsequence(const vector<T> &a, Compare cmp = less<>()){
	// less: longest increasing subsequence
	// less_equal: longest non-decreasing subsequence
	// greater: longest decreasing subsequence
	// greater_equal: longest non-increasing subsequence
	if(a.empty()) return {};
	int n = (int)a.size();
	vector<int> prev(n), active;
	for(auto i = 0; i < n; ++ i){
		auto it = partition_point(active.begin(), active.end(), [&](int j){ return cmp(a[j], a[i]); });
		if(it == active.end()) active.emplace_back(), it = std::prev(active.end());
		*it = i;
		prev[i] = it == active.begin() ? -1 : *std::prev(it);
	}
	int len = (int)active.size(), cur = active.back();
	vector<int> res(len);
	while(len --) res[len] = cur, cur = prev[cur];
	return res;
}

int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	int n;
	cin >> n;
	vector<int> a(n);
	copy_n(istream_iterator<int>(cin), n, a.begin());
	cout << longest_monotone_subsequence(a).size() << "\n";
	return 0;
}

/*

*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////