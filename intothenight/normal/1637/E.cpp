#include <bits/stdc++.h>
using namespace std;
#if __cplusplus > 201703L
#include <ranges>
using namespace numbers;
#endif
template<class T> T &ctmin(T &x){ return x; }
template<class T, class Head, class ...Tail> T &ctmin(T &x, const Head &h, const Tail &... t){ return ctmin(x = min<T>(x, h), t...); }
template<class T> T &ctmax(T &x){ return x; }
template<class T, class Head, class ...Tail> T &ctmax(T &x, const Head &h, const Tail &... t){ return ctmax(x = max<T>(x, h), t...); }



int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	auto __solve_tc = [&](auto __tc_num)->int{
		int n, m;
		cin >> n >> m;
		vector<int> a(n);
		map<int, int> cnt;
		vector<array<int, 2>> bad(m);
		for(auto i = 0; i < n; ++ i){
			cin >> a[i];
			++ cnt[a[i]];
		}
		for(auto &[x, y]: bad){
			cin >> x >> y;
		}
		ranges::sort(bad);
		vector<vector<int>> appear(n + 1);
		vector<int> f;
		for(auto [x, freq]: cnt){
			appear[freq].push_back(x);
			f.push_back(freq);
		}
		ranges::sort(f);
		f.erase(unique(f.begin(), f.end()), f.end());
		for(auto freq: f){
			ranges::sort(appear[freq] | ranges::views::reverse);
		}
		long long res = 0;
		for(auto i = 0; i < (int)f.size(); ++ i){
			for(auto j = i; j < (int)f.size(); ++ j){
				auto &left = appear[f[i]], &right = appear[f[j]];
				if(i == j && (int)left.size() == 1){
					continue;
				}
				priority_queue<array<int, 3>> pq;
				pq.push({left[0] + right[i == j], 0, i == j});
				set<array<int, 2>> used{{0, i == j}};
				while(!pq.empty()){
					auto [x, s, t] = pq.top();
					pq.pop();
					if(!ranges::binary_search(bad, array{left[s], right[t]}) && !ranges::binary_search(bad, array{right[t], left[s]})){
						ctmax(res, 1LL * x * (f[i] + f[j]));
						break;
					}
					for(auto d = 0; d < 2; ++ d){
						if((i < j || s + d < t + !d) && s + d < (int)left.size() && t + !d < (int)right.size() && !used.contains({s + d, t + !d})){
							used.insert({s + d, t + !d});
							pq.push({left[s + d] + right[t + !d], s + d, t + !d});
						}
					}
				}
			}
		}
		cout << res << "\n";
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