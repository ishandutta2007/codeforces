#include <bits/stdc++.h>
using namespace std;
#if __cplusplus > 201703L
#include <ranges>
using namespace numbers;
#endif
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class T, class U, class Compare = less<>> using order_statistic_map = tree<T, U, Compare, rb_tree_tag, tree_order_statistics_node_update>;
template<class T, class Compare = less<>> using order_statistic_set = order_statistic_map<T, null_type, Compare>;


int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	int n, qn;
	cin >> n >> qn;
	order_statistic_set<int> r, c;
	vector<int> rcnt(n), ccnt(n);
	for(auto qi = 0; qi < qn; ++ qi){
		int type, x, y;
		cin >> type >> x >> y, -- x, -- y;
		if(type == 1){
			++ rcnt[x];
			if(rcnt[x] == 1){
				r.insert(x);
			}
			++ ccnt[y];
			if(ccnt[y] == 1){
				c.insert(y);
			}
		}
		else if(type == 2){
			-- rcnt[x];
			if(rcnt[x] == 0){
				r.erase(x);
			}
			-- ccnt[y];
			if(ccnt[y] == 0){
				c.erase(y);
			}
		}
		else{
			int xr, yr;
			cin >> xr >> yr;
			auto a = r.order_of_key(x);
			auto b = r.order_of_key(xr);
			if(b - a == xr - x){
				cout << "Yes\n";
				continue;
			}
			a = c.order_of_key(y);
			b = c.order_of_key(yr);
			if(b - a == yr - y){
				cout << "Yes\n";
			}
			else{
				cout << "No\n";
			}
		}
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