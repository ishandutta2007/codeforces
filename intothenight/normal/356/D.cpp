#include <bits/stdc++.h>
using namespace std;



int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	int n, tot;
	cin >> n >> tot;
	vector<int> a(n);
	for(auto i = 0; i < n; ++ i){
		cin >> a[i];
	}
	int mxi = max_element(a.begin(), a.end()) - a.begin();
	if(tot < a[mxi]){
		cout << "-1\n";
		return 0;
	}
	tot -= a[mxi];
	const int mx = 7e4 + 1;
	vector<vector<int>> new_weight(n);
	bitset<mx> dp;
	dp.set(0);
	for(auto i = 0; i < n; ++ i){
		bitset<mx> dp_next = dp;
		if(i != mxi){
			dp_next |= dp << a[i];
			auto dif = dp ^ dp_next;
			for(auto x = dif._Find_first(); x < mx; x = dif._Find_next(x)){
				new_weight[i].push_back(x);
			}
		}
		swap(dp, dp_next);
	}
	if(!dp[tot]){
		cout << "-1\n";
		return 0;
	}
	vector<int> used(n);
	used[mxi] = true;
	for(auto x = tot, i = n - 1; i >= 0; -- i){
		if(binary_search(new_weight[i].begin(), new_weight[i].end(), x)){
			x -= a[i];
			used[i] = true;
		}
	}
	vector<int> rem;
	for(auto i = 0; i < n; ++ i){
		if(!used[i]){
			rem.push_back(i);
		}
	}
	sort(rem.begin(), rem.end(), [&](int i, int j){ return a[i] < a[j]; });
	vector<pair<int, vector<int>>> res(n);
	for(auto i = 0; i < n; ++ i){
		res[i].first = a[i];
	}
	if(!rem.empty()){
		res[mxi].first -= a[rem.back()];
		res[mxi].second.push_back(rem.back());
		for(auto t = (int)rem.size() - 2; t >= 0; -- t){
			res[rem[t + 1]].first -= res[rem[t]].first;
			res[rem[t + 1]].second.push_back(rem[t]);
		}
	}
	for(auto i = 0; i < n; ++ i){
		cout << res[i].first << " " << (int)res[i].second.size() << " ";
		for(auto j: res[i].second){
			cout << j + 1 << " ";
		}
		cout << "\n";
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