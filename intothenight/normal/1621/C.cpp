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
		int qcnt = 0;
		auto query = [&](int i)->int{
			++ qcnt;
			cout << "? " << i + 1 << endl;
			int x;
			cin >> x;
			if(!x) exit(0);
			return -- x;
		};
		vector<int> res(n, -1);
		for(auto i = 0; i < n; ++ i){
			if(!~res[i]){
				vector<int> orbit;
				int s = query(i), x = s;
				do{
					orbit.push_back(x);
					x = query(i);
				}while(x != s);
				for(auto j = 0; j < (int)orbit.size(); ++ j){
					res[orbit[j]] = orbit[(j + 1) % (int)orbit.size()];
				}
			}
		}
		cout << "! ";
		for(auto x: res){
			cout << x + 1 << " ";
		}
		cout << endl;
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