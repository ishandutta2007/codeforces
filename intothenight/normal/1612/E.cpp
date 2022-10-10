#include <bits/stdc++.h>
using namespace std;



int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	int n;
	cin >> n;
	vector<array<int, 2>> a(n);
	const int mx = 2e5;
	for(auto &[id, k]: a){
		cin >> id >> k, -- id;
	}
	array<int, 2> res{0, 1};
	for(auto x = 1; x <= 20; ++ x){
		vector<int> cnt(mx);
		for(auto [id, k]: a){
			cnt[id] += min(k, x);
		}
		vector<int> order(mx);
		iota(order.begin(), order.end(), 0);
		sort(order.begin(), order.end(), [&](int i, int j){ return cnt[i] > cnt[j]; });
		array<int, 2> cur{accumulate(order.begin(), order.begin() + x, 0, [&](int sum, int i){ return sum + cnt[i]; }), x};
		if(res[0] * cur[1] < res[1] * cur[0]){
			res = cur;
		}
	}
	{ // x >= 21
		vector<int> cnt(mx);
		for(auto [id, k]: a){
			cnt[id] += k;
		}
		vector<int> order(mx);
		iota(order.begin(), order.end(), 0);
		sort(order.begin(), order.end(), [&](int i, int j){ return cnt[i] > cnt[j]; });
		int sum = 0;
		for(auto x = 1; x <= 20; ++ x){
			sum += cnt[order[x - 1]];
		}
		for(auto x = 21; x <= mx; ++ x){
			sum += cnt[order[x - 1]];
			if(1LL * res[0] * x < 1LL * res[1] * sum){
				res = {sum, x};
			}
		}
	}
	int x = res[1];
	vector<int> cnt(mx);
	for(auto [id, k]: a){
		cnt[id] += min(k, x);
	}
	vector<int> order(mx);
	iota(order.begin(), order.end(), 0);
	sort(order.begin(), order.end(), [&](int i, int j){ return cnt[i] > cnt[j]; });
	cout << x << "\n";
	for(auto i = 0; i < x; ++ i){
		cout << order[i] + 1 << " ";
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