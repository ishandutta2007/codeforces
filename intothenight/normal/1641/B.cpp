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
		vector<array<int, 2>> op;
		vector<int> split;
		for(auto i = 0; i < (int)a.size(); ){
			int j = find(a.begin() + i + 1, a.end(), a[i]) - a.begin();
			if(j == (int)a.size()){
				cout << "-1\n";
				return 0;
			}
			split.push_back(j - i << 1);
			for(auto k = 1; k < j - i; ++ k){
				op.push_back({j + k, a[i + k]});
				a.insert(a.begin() + j + k, {a[i + k], a[i + k]});
			}
			i += j - i << 1;
		}
		cout << (int)op.size() << "\n";
		for(auto [p, c]: op){
			cout << p << " " << c << "\n";
		}
		cout << (int)split.size() << "\n";
		ranges::copy(split, ostream_iterator<int>(cout, " "));
		cout << "\n\n";
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