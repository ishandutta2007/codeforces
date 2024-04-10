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
	int n, m;
	cin >> n >> m;
	vector<pair<int, int>> a(m);
	for(int i = 0; i < m; ++ i){
		cin >> a[i].first, a[i].second = i;
	}
	reverse(a.begin(), a.end());
	vector<long long> SUM(m + 1);
	for(int i = 0; i < m; ++ i){
		SUM[i + 1] = SUM[i] + a[i].first;
	}
	auto sum = [&](int i, int j){
		return SUM[j] - SUM[i];
	};
	vector<int> res(m);
	bool ok = true;
	int left = n;
	for(int i = n; i > n - m; -- i){
		auto [x, p] = a.back();
		if(i < x){
			ok = false;
			break;
		}
		else if(sum(0, int(a.size())) >= left && sum(0, int(a.size())) <= i){
			int cur = 0;
			for(auto [x, p]: a){
				res[p] = cur + 1;
				cur += x;
			}
			left = 0;
			break;
		}
		else{
			res[p] = i - x + 1;
			ctmin(left, i - x);
			a.pop_back();
		}
	}
	if(ok && !left){
		copy(res.begin(), res.end(), ostream_iterator<int>(cout, " "));
		cout << "\n";
	}
	else{
		cout << "-1\n";
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