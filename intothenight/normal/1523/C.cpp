#include <bits/stdc++.h>
using namespace std;



int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	auto __solve_tc = [&](int __tc_num){
		int n;
		cin >> n;
		int x;
		cin >> x;
		assert(x == 1);
		vector<vector<int>> a{{1}};
		cout << "1\n";
		vector<int> append{0}, inc{0};
		for(auto i = 1; i < n; ++ i){
			int x;
			cin >> x;
			if(x == 1){
				assert(!append.empty());
				int p = append.back(); append.pop_back();
				a.push_back(a[p]);
				a.back().push_back(x);
			}
			else{
				while(a[inc.back()].back() != x - 1){
					inc.pop_back();
				}
				assert(!inc.empty());
				int p = inc.back(); inc.pop_back();
				a.push_back(a[p]);
				++ a.back().back();
			}
			append.push_back(i);
			inc.push_back(i);
			for(auto i = 0; i < (int)a.back().size() - 1; ++ i){
				cout << a.back()[i] << ".";
			}
			cout << a.back().back() << "\n";
		}
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