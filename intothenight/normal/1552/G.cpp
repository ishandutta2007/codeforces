#include <bits/stdc++.h>
using namespace std;



int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	int n, k;
	cin >> n >> k;
	if(n == 1){
		cout << "ACCEPTED\n";
		return 0;
	}
	vector<int> ind;
	vector<long long> dp{0};
	for(auto rep = k; rep; -- rep){
		int m;
		cin >> m;
		vector<int> cur_ind(m);
		long long cur_mask = 0;
		for(auto &i: cur_ind){
			cin >> i, -- i;
			cur_mask |= 1LL << i;
		}
		vector<int> new_ind, common_ind;
		set_difference(cur_ind.begin(), cur_ind.end(), ind.begin(), ind.end(), back_inserter(new_ind));
		set_difference(cur_ind.begin(), cur_ind.end(), new_ind.begin(), new_ind.end(), back_inserter(common_ind));
		vector<long long> dp_next;
		for(auto mask: dp){
			int cnt = 0;
			for(auto i: common_ind){
				cnt += mask >> i & 1;
			}
			for(auto x = cnt; x <= cnt + (int)new_ind.size(); ++ x){
				long long nmask = mask & ~cur_mask;
				for(auto t = m - x; t < m; ++ t){
					nmask |= 1LL << cur_ind[t];
				}
				dp_next.push_back(nmask);
			}
		}
		swap(dp, dp_next);
		sort(dp.begin(), dp.end());
		dp.erase(unique(dp.begin(), dp.end()), dp.end());
		int sz = (int)ind.size();
		ind.insert(ind.end(), new_ind.begin(), new_ind.end());
		inplace_merge(ind.begin(), ind.begin() + sz, ind.end());
	}
	if((int)ind.size() != n){
		cout << "REJECTED\n";
		return 0;
	}
	for(auto mask: dp){
		for(auto i = 0; i < n - 1; ++ i){
			if((mask >> i & 1) > (mask >> i + 1 & 1)){
				cout << "REJECTED\n";
				return 0;
			}
		}
	}
	cout << "ACCEPTED\n";
	return 0;
}

/*

*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////