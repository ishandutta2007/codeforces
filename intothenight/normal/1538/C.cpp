#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class T, class Compare = less<>> using ordered_set = tree<T, null_type, Compare, rb_tree_tag, tree_order_statistics_node_update>;
template<class T, class U, class Compare = less<>> using ordered_map = tree<T, U, Compare, rb_tree_tag, tree_order_statistics_node_update>;



int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	auto __solve_tc = [&](int __tc_num){
		int n, l, r;
		cin >> n >> l >> r, ++ r;
		ordered_set<array<int, 2>> os;
		long long res = 0;
		for(auto i = 0; i < n; ++ i){
			int x;
			cin >> x;
			res += os.order_of_key({r - x, 0}) - os.order_of_key({l - x, 0});
			os.insert({x, i});
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