#include <bits/stdc++.h>
using namespace std;
#if __cplusplus > 201703L
#include <ranges>
using namespace numbers;
#endif



int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	int n, m;
	cin >> n >> m;
	vector<long long> head(n);
	for(auto &x: head){
		cin >> x;
	}
	vector<long long> obj(m);
	for(auto &x: obj){
		cin >> x;
	}
	obj.insert(obj.end(), head.begin(), head.end());
	ranges::inplace_merge(obj, obj.begin() + m);
	obj.erase(unique(obj.begin(), obj.end()), obj.end());
	m = (int)obj.size();
	vector<int> pos(n);
	for(auto i = 0; i < n; ++ i){
		pos[i] = lower_bound(obj.begin(), obj.end(), head[i]) - obj.begin();
	}
	pos.push_back(m);
	auto bad = [&](long long th)->bool{
		static vector<int> dp(m);
		ranges::fill(dp, false);
		for(auto j = pos[0]; j < pos[1]; ++ j){
			dp[j] = obj[j] - obj[0] + min(obj[pos[0]] - obj[0], obj[j] - obj[pos[0]]) <= th;
		}
		for(auto i = 1; i < n; ++ i){
			static vector<long long> dist;
			dist.clear();
			for(auto j = pos[i] - 1; j >= pos[i - 1]; -- j){
				if(dp[j]){
					dist.push_back(obj[pos[i]] - obj[j + 1]);
				}
			}
			for(auto j = pos[i]; j < pos[i + 1]; ++ j){
				int t = lower_bound(dist.begin(), dist.end(), obj[j] - obj[pos[i]]) - dist.begin();
				dp[j] = t < (int)dist.size() && dist[t] + (obj[j] - obj[pos[i]]) * 2 <= th || t && dist.front() * 2 + (obj[j] - obj[pos[i]]) <= th;
			}
		}
		return !dp.back();
	};
	cout << *ranges::partition_point(ranges::iota_view(0LL, (long long)1e18), bad) << "\n";
	return 0;
}

/*

*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////