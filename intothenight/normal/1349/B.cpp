#include "bits/stdc++.h"
#include "ext/pb_ds/assoc_container.hpp"
#include "ext/pb_ds/tree_policy.hpp"
#include "ext/rope"
using namespace std;
using namespace chrono;
using namespace __gnu_pbds;
using namespace __gnu_cxx;
mt19937 rng(high_resolution_clock::now().time_since_epoch().count());
mt19937_64 rngll(high_resolution_clock::now().time_since_epoch().count());
#define lambdify(x) [&](auto &&...args){ return x(forward<decltype(args)>(args)...); }
template<typename T> T ctmax(T &x, const T &y){ return x = max(x, y); }
template<typename T> T ctmin(T &x, const T &y){ return x = min(x, y); }
template<typename T> using Tree = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

void SOLVE(){
	int n, k;
	cin >> n >> k;
	vector<int> a(n);
	bool found = false;
	for(auto i = 0; i < n; ++ i){
		cin >> a[i];
		if(a[i] < k){
			a[i] = 0;
		}
		else if(a[i] == k){
			a[i] = 1;
			found = true;
		}
		else{
			a[i] = 2;
		}
	}
	if(!found){
		cout << "no\n";
		return;
	}
	for(auto i = 0; i + 3 <= n; ++ i){
		vector<int> cur(a.begin() + i, a.begin() + i + 3);
		sort(cur.begin(), cur.end());
		if(cur[1] >= 1){
			cout << "yes\n";
			return;
		}
	}
	for(auto i = 0; i + 2 <= n; ++ i){
		vector<int> cur(a.begin() + i, a.begin() + i + 2);
		sort(cur.begin(), cur.end());
		if(cur[0] >= 1){
			cout << "yes\n";
			return;
		}
	}
	vector<int> ded(n);
	for(auto i = 0; i < n - 1; ++ i){
		if(a[i] == (a[i + 1] ^ 2)){
			int l = i, r = i + 1;
			while(l >= 0 && r < n && !ded[l] && (a[l] == (a[r] ^ 2))){
				ded[l] = ded[r] = true;
				-- l, ++ r;
			}
			i = r - 1;
		}
	}
	vector<int> b;
	for(auto i = 0; i < n; ++ i){
		if(!ded[i]){
			b.push_back(a[i]);
		}
	}
	n = int(b.size());
	if(n == 1){
		cout << "yes\n";
	}
	else{
		for(auto i = 0; i < n - 1; ++ i){
			vector<int> cur(b.begin() + i, b.begin() + i + 2);
			sort(cur.begin(), cur.end());
			if(cur[0] >= 1){
				cout << "yes\n";
				return;
			}
		}
		for(auto i = 0; i < n - 2; ++ i){
			vector<int> cur(b.begin() + i, b.begin() + i + 3);
			sort(cur.begin(), cur.end());
			if(cur[1] >= 1){
				cout << "yes\n";
				return;
			}
		}
		cout << "no\n";
	}
}

int main(){
	cin.tie(0)->sync_with_stdio(0);
	int ttt;
	cin >> ttt;
	while(ttt --){
		SOLVE();
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