#include <bits/stdc++.h>
using namespace std;



int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	int n, T;
	cin >> n >> T;
	vector<vector<int>> q(T + 1);
	for(auto i = 0; i < n; ++ i){
		int t, val;
		cin >> t >> val;
		q[t].push_back(val);
	}
	for(auto t = 1; t < T; ++ t){
		sort(q[t].rbegin(), q[t].rend());
		for(auto i = 1; i < (int)q[t].size(); i += 2){
			q[t + 1].push_back(q[t][i - 1] + q[t][i]);
		}
		if((int)q[t].size() % 2){
			q[t + 1].push_back(q[t].back());
		}
	}
	cout << *max_element(q[T].begin(), q[T].end()) << "\n";
	return 0;
}

/*

*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////