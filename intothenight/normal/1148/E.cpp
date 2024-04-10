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
	int n;
	cin >> n;
	vector<pair<int, int>> s(n);
	vector<int> t(n);
	for(int i = 0; i < n; ++ i){
		int x;
		cin >> x;
		s[i] = {x, i};
	}
	copy_n(istream_iterator<int>(cin), n, t.begin());
	auto kill = [](){
		cout << "NO";
		exit(0);
	};
	if(accumulate(s.begin(), s.end(), 0LL, [&](long long x, pair<int, int> y){ return x + y.first; }) != accumulate(t.begin(), t.end(), 0LL)){
		kill();
	}
	sort(s.begin(), s.end()), sort(t.begin(), t.end());
	vector<int> d(n);
	for(int i = 0; i < n; ++ i){
		d[i] = t[i] - s[i].first;
	}
	vector<array<int, 3>> res;
	for(int i = 0, j = 0; i < n; ){
		while(i < n && d[i] <= 0){
			++ i;
		}
		while(j < n && d[j] >= 0){
			++ j;
		}
		if(i > j){
			kill();
		}
		if(i < j){
			int x = min(d[i], -d[j]);
			d[i] -= x, d[j] += x;
			res.push_back({s[i].second, s[j].second, x});
		}
	}
	cout << "YES\n" << int(res.size()) << "\n";
	for(auto [i, j, x]: res){
		cout << i + 1 << " " << j + 1 << " " << x << "\n";
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