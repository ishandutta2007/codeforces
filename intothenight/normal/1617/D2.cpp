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
		auto query = [&](int i, int j, int k)->int{
			cout << "? " << i + 1 << " " << j + 1 << " " << k + 1 << endl;
			int type;
			cin >> type;
			if(!~type) exit(0);
			return type;
		};
		int n;
		cin >> n;
		array<vector<array<int, 3>>, 2> group;
		for(auto i = 0; i < n; i += 3){
			group[query(i, i + 1, i + 2)].push_back({i, i + 1, i + 2});
		}
		array<vector<int>, 2> classes;
		{
			array<int, 3> last = group[0].back();
			group[0].pop_back();
			array<int, 3> state{};
			for(auto t = 0; t < 2; ++ t){
				for(auto i = 0; i < 3; ++ i){
					state[t] |= query(last[t], last[(t + 1) % 3], group[1].back()[i]);
				}
			}
			state[2] = state[0] ^ state[1];
			if(state[0] + state[1] + state[2] == 0){
				classes[0].insert(end(classes[0]), {last[0], last[1], last[2]});
			}
			else{
				int t = 0;
				while(state[t]){
					++ t;
				}
				classes[0].insert(end(classes[0]), {last[t], last[(t + 1) % 3]});
				classes[1].push_back(last[(t + 2) % 3]);
			}
		}
		for(auto p = 1; p >= 0; -- p){
			while(!group[p].empty()){
				array<int, 3> last = group[p].back();
				group[p].pop_back();
				array<int, 3> state{};
				for(auto t = 0; t < 2; ++ t){
					state[t] = query(last[t], last[(t + 1) % 3], classes[!p].back());
				}
				if(state[0] != p && state[1] == p || state[0] == p && state[1] != p){
					state[2] = !p;
				}
				else{
					state[2] = p;
				}
				if(state[0] == p && state[1] == p && state[2] == p){
					classes[p].insert(end(classes[p]), {last[0], last[1], last[2]});
				}
				else{
					int t = 0;
					while(state[t] != p){
						++ t;
					}
					classes[p].insert(end(classes[p]), {last[t], last[(t + 1) % 3]});
					classes[!p].push_back(last[(t + 2) % 3]);
				}
			}
		}
		cout << "! " << (int)size(classes[0]) << " ";
		ranges::copy(classes[0] | ranges::views::transform([&](int i){ return i + 1; }), ostream_iterator<int>(cout, " "));
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