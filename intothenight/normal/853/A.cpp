#include "bits/stdc++.h"
using namespace std;



int main(){
	cin.tie(0)->sync_with_stdio(0);
	int n, k;
	cin >> n >> k;
	priority_queue<array<int, 2>> pq;
	for(auto i = 0; i < k; ++ i){
		int x;
		cin >> x;
		pq.push({x, i});
	}
	long long res = 0;
	vector<int> flights(n);
	for(auto i = k; i < n; ++ i){
		int x;
		cin >> x;
		pq.push({x, i});
		auto [c, ind] = pq.top(); pq.pop();
		res += 1LL * c * (i - ind);
		flights[ind] = i + 1;
	}
	for(auto i = n; i < n + k; ++ i){
		auto [c, ind] = pq.top(); pq.pop();
		res += 1LL * c * (i - ind);
		flights[ind] = i + 1;
	}
	cout << res << "\n";
	for(auto x: flights){
		cout << x << " ";
	}
	cout << "\n";
	return 0;
}

/*

*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////