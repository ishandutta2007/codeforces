#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace chrono;
using namespace __gnu_pbds;
mt19937 rng(high_resolution_clock::now().time_since_epoch().count());
mt19937_64 rngll(high_resolution_clock::now().time_since_epoch().count());
template<typename T> T ctmax(T &x, const T &y){ return x = max(x, y); }
template<typename T> T ctmin(T &x, const T &y){ return x = min(x, y); }
template<typename T> using Tree = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;



int main(){
	cin.tie(0)->sync_with_stdio(0);
	int n, k;
	cin >> n >> k;
	vector<int> a(n);
	copy_n(istream_iterator<int>(cin), n, a.begin());
	sort(a.begin(), a.end());
	vector<long long> SUM(n + 1);
	for(int i = 0; i < n; ++ i){
		SUM[i + 1] = SUM[i] + a[i];
	}
	auto sum = [&](int i, int j){
		return SUM[j] - SUM[i];
	};
	int ind = 0;
	long long res = numeric_limits<long long>::max();
	while(ind < n){
		auto it = equal_range(a.begin(), a.end(), a[ind]);
		int i = it.first - a.begin(), j = it.second - a.begin();
		int more = k - (j - i);
		if(more <= 0){
			cout << 0;
			return 0;
		}
		if(i >= more){
			long long cost = 1LL * (a[ind] - 1) * i - sum(0, i);
			ctmin(res, cost + more);
		}
		if(n - j >= more){
			long long cost = sum(j, n) - 1LL * (a[ind] + 1) * (n - j);
			ctmin(res, cost + more);
		}
		long long cost = 1LL * (a[ind] - 1) * i - sum(0, i) + sum(j, n) - 1LL * (a[ind] + 1) * (n - j);
		ctmin(res, cost + more);
		ind = j;
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