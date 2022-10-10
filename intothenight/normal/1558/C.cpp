#include <bits/stdc++.h>
using namespace std;



int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	auto __solve_tc = [&](auto __tc_num)->int{
		int n;
		cin >> n;
		vector<int> a(n);
		for(auto i = 0; i < n; ++ i){
			cin >> a[i], -- a[i];
		}
		for(auto i = 0; i < n; ++ i){
			if((i & 1) != (a[i] & 1)){
				cout << "-1\n";
				return 0;
			}
		}
		vector<int> res;
		auto act = [&](int len)->void{
			res.push_back(len);
			reverse(a.begin(), a.begin() + len);
		};
		for(auto x = n - 1; x >= 1; x -= 2){
			int i = find(a.begin(), a.end(), x) - a.begin();
			act(i + 1);
			int j = find(a.begin(), a.end(), x - 1) - a.begin();
			act(j);
			act(j + 2);
			act(3);
			act(x + 1);
		}
		assert(is_sorted(a.begin(), a.end()));
		cout << (int)res.size() << "\n";
		for(auto len: res){
			cout << len << " ";
		}
		cout << "\n";
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