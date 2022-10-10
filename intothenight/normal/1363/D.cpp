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
template<typename T, typename U> T &ctmax(T &x, const U &y){ return x = max<T>(x, y); }
template<typename T, typename U> T &ctmin(T &x, const U &y){ return x = min<T>(x, y); }
template<typename T> using Tree = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;



int SOLVE(){
	int n, k;
	cin >> n >> k;
	vector<vector<int>> s(k);
	for(auto i = 0; i < k; ++ i){
		int sz;
		cin >> sz;
		for(auto j = 0; j < sz; ++ j){
			int ind;
			cin >> ind, -- ind;
			s[i].push_back(ind);
		}
	}
	auto query = [&](int low, int high, int forb = -1){
		int sz = 0;
		for(int i = low; i < high; ++ i) if(i != forb) sz += int(s[i].size());
		cout << "? " << sz << " ";
		for(int i = low; i < high; ++ i) if(i != forb) for(auto j: s[i]) cout << j + 1 << " ";
		cout << endl;
		int resp;
		cin >> resp;
		if(resp == -1) exit(0);
		return resp;
	};
	auto answer = [&](const vector<int> &a){
		assert(int(a.size()) == k);
		cout << "! ";
		for(auto x: a) cout << x << " ";
		cout << endl;
		string resp;
		cin >> resp;
		if(resp == "Incorrect") exit(0);
	};
	cout << "? " << n << " ";
	for(int i = 1; i <= n; ++ i) cout << i << " ";
	cout << endl;
	int mx;
	cin >> mx;
	int low = 0, high = k;
	while(high - low > 1){
		int mid = low + (high - low >> 1);
		int x = query(low, mid);
		(x == mx ? high : low) = mid;
	}
	vector<int> res(k);
	for(auto i = 0; i < k; ++ i){
		if(i != low){
			res[i] = mx;
		}
	}
	vector<int> in_low(n);
	for(auto i: s[low]){
		in_low[i] = true;
	}
	cout << "? " << n - int(s[low].size()) << "\n";
	for(auto i = 0; i < n; ++ i){
		if(!in_low[i]){
			cout << i + 1 << " ";
		}
	}
	cout << endl;
	cin >> res[low];
	answer(res);
	return 0;
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
n = 4, k = 1
A = [1, 2, 1, 1]
S: 2
*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////