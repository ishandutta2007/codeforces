#include <bits/stdc++.h>
using namespace std;
#if __cplusplus > 201703L
#include <ranges>
using namespace numbers;
#endif



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
		multiset<long long> rem(a.begin(), a.end());
		priority_queue<long long, vector<long long>, greater<>> pq;
		pq.push(accumulate(a.begin(), a.end(), 0LL));
		while(!pq.empty()){
			auto w = pq.top();
			pq.pop();
			if(rem.contains(w)){
				rem.erase(rem.find(w));
				continue;
			}
			if(w < *rem.begin()){
				cout << "NO\n";
				return 0;
			}
			pq.push(w / 2);
			pq.push(w - w / 2);
		}
		cout << "YES\n";
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