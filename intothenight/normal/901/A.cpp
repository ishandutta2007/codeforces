#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/rope>
using namespace std;
using namespace __gnu_pbds;
using namespace __gnu_cxx;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
mt19937_64 rngll(chrono::steady_clock::now().time_since_epoch().count());
template<typename T> using Tree = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;



int main(){
	cin.tie(0)->sync_with_stdio(0);
	int n;
	cin >> n, ++ n;
	vector<int> a(n);
	for(auto &x: a){
		cin >> x;
	}
	bool ok = true;
	for(int i = 1; i < n; ++ i){
		if(a[i] > 1 && a[i - 1] > 1){
			ok = false;
			break;
		}
	}
	if(ok){
		cout << "perfect";
		return 0;
	}
	cout << "ambiguous\n";
	vector<int> b{0}, c{0};
	int l = 0, r = 1;
	for(int i = 1; i < n; ++ i){
		if(r - l == 1){
			for(int j = 0; j < a[i]; ++ j){
				b.push_back(l + 1);
				c.push_back(l + 1);
			}
		}
		else{
			b.push_back(l + 1);
			c.push_back(l + 1);
			for(int j = 1; j < a[i]; ++ j){
				b.push_back(l + 1);
				c.push_back(l + 2);
			}
		}
		l = r, r += a[i];
	}
	for(auto x: b){
		cout << x << " ";
	}
	cout << "\n";
	for(auto x: c){
		cout << x << " ";
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