#include <bits/stdc++.h>
using namespace std;



int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	int n, m;
	cin >> n >> m;
	vector<int> a(m + 1);
	for(auto i = 0; i < n; ++ i){
		int l, r;
		cin >> l >> r, -- l;
		++ a[l], -- a[r];
	}
	for(auto i = 1; i <= m; ++ i){
		a[i] += a[i - 1];
	}
	vector<int> lis(m + 1), active;
	for(auto i = 0; i < m; ++ i){
		auto it = upper_bound(active.begin(), active.end(), a[i]);
		if(it == active.end()){
			active.push_back(a[i]);
		}
		else{
			*it = a[i];
		}
		lis[i + 1] = (int)active.size();
	}
	active.clear();
	int res = *max_element(lis.begin(), lis.end());
	for(auto i = m - 1; i >= 0; -- i){
		auto it = upper_bound(active.begin(), active.end(), a[i]);
		if(it == active.end()){
			active.push_back(a[i]);
		}
		else{
			*it = a[i];
		}
		res = max(res, (int)active.size() + lis[i]);
	}
	cout << res << "\n";
	return 0;
}

/*

*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////