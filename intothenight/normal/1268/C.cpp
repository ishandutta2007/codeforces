#include "bits/stdc++.h"
using namespace std;
#include "ext/pb_ds/assoc_container.hpp"
#include "ext/pb_ds/tree_policy.hpp"
using namespace __gnu_pbds;
template<typename T> using Tree = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;



int main(){
	cin.tie(0)->sync_with_stdio(0);
	int n;
	cin >> n;
	vector<array<int, 2>> a(n); // pos, val
	for(int i = 0; i < n; ++ i) cin >> a[i][1], a[i][0] = i;
	sort(a.begin(), a.end(), [&](auto &x, auto &y){ return x[1] < y[1]; });
	long long pos = 0, neg = 0, inv = 0;
	Tree<int> tr;
	tr.insert(a[0][0]);
	cout << "0 ";
	for(auto k = 2; k <= n; ++ k){
		auto [p, ignore] = a[k - 1];
		long long subt = 0;
		inv += int(tr.size()) - tr.order_of_key(p);
		auto it = tr.find_by_order(k / 2 - 1);
		if(k % 2 == 0){
			if(*it < p) neg += *it, pos += p;
			else neg += p, pos += *it;
			subt = 1LL * (k / 2 - 1) * (k / 2) / 2 + 1LL * (k / 2) * (k / 2 + 1) / 2;
		}
		else{
			if(*it > p) neg -= *it, neg += p;
			else if(*++ it < p) pos -= *it, pos += p;
			subt = 1LL * (k / 2) * (k / 2 + 1);
		}
		tr.insert(p);
		cout << pos + inv - neg - subt << " ";
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