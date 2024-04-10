#include "bits/stdc++.h"
using namespace std;
#include "ext/pb_ds/assoc_container.hpp"
#include "ext/pb_ds/tree_policy.hpp"
using namespace __gnu_pbds;
template<typename T> using Tree = tree<T, null_type, greater<T>, rb_tree_tag, tree_order_statistics_node_update>;



int main(){
	cin.tie(0)->sync_with_stdio(0);
	int n;
	cin >> n;
	long long tot = 0, top = 0;
	set<int> fire, light;
	Tree<int> both;
	for(auto i = 0; i < n; ++ i){
		int type, x;
		cin >> type >> x;
		tot += x;
		if(type == 0){
			if(x > 0){
				fire.insert(x), both.insert(x);
				if(both.order_of_key(x) < int(light.size())){
					top += x;
					if(int(both.size()) > int(light.size())){
						top -= *both.find_by_order(int(light.size()));
					}
				}
			}
			else{
				x = -x;
				if(both.order_of_key(x) < int(light.size())){
					top -= x;
					if(int(both.size()) > int(light.size())){
						top += *both.find_by_order(int(light.size()));
					}
				}
				fire.erase(x), both.erase(x);
			}
		}
		else{
			if(x > 0){
				light.insert(x), both.insert(x);
				if(both.order_of_key(x) < int(light.size())){
					top += x;
				}
				else{
					top += *both.find_by_order(int(light.size()) - 1);
				}
			}
			else{
				x = -x;
				if(both.order_of_key(x) < int(light.size())){
					top -= x;
				}
				else{
					top -= *both.find_by_order(int(light.size()) - 1);
				}
				light.erase(x), both.erase(x);
			}
		}
		if(fire.empty()){
			if(light.empty()){
				cout << "0\n";
			}
			else{
				cout << 2 * tot - *light.begin() << "\n";
			}
		}
		else{
			if(light.empty() || *light.begin() < *fire.rbegin()){
				cout << tot + top << "\n";
			}
			else{
				cout << tot + top - *light.begin() + *fire.rbegin() << "\n";
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