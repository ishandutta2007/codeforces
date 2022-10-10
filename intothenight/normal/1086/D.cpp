#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class T, class U, class Compare = less<>> using order_statistic_map = tree<T, U, Compare, rb_tree_tag, tree_order_statistics_node_update>;
template<class T, class Compare = less<>> using order_statistic_set = order_statistic_map<T, null_type, Compare>;



int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	int n, qn;
	string temp;
	vector<int> conv(300);
	conv['P'] = 1, conv['S'] = 2;
	cin >> n >> qn >> temp;
	vector<int> a(n);
	array<order_statistic_set<int>, 3> pos;
	for(auto i = 0; i < n; ++ i){
		a[i] = conv[temp[i]];
		pos[a[i]].insert(i);
	}
	auto solve = [&]()->int{
		int res = 0;
		for(auto x = 0; x <= 2; ++ x){
			int bad = (x + 1) % 3, good = 3 ^ x ^ bad;
			if(pos[good].empty()){
				if(pos[bad].empty()){
					res += (int)pos[x].size();
				}
			}
			else if(pos[bad].empty()){
				res += (int)pos[x].size();
			}
			else{
				res += pos[x].order_of_key(*pos[good].rbegin()) - pos[x].order_of_key(*pos[good].begin());
				res += pos[x].order_of_key(min(*pos[good].begin(), *pos[bad].begin()));
				res += (int)pos[x].size() - pos[x].order_of_key(max(*pos[good].rbegin(), *pos[bad].rbegin()));
			}
		}
		return res;
	};
	cout << solve() << "\n";
	for(auto qi = 0; qi < qn; ++ qi){
		int p;
		char temp;
		cin >> p >> temp, -- p;
		int x = conv[temp];
		pos[a[p]].erase(p);
		pos[a[p] = x].insert(p);
		cout << solve() << "\n";
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