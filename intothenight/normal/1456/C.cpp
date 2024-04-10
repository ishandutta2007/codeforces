#include <bits/stdc++.h>
using namespace std;



int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	int n, k;
	cin >> n >> k;
	vector<int> a(n);
	for(auto i = 0; i < n; ++ i){
		cin >> a[i];
	}
	priority_queue<long long> pq;
	for(auto i = 0; i <= k; ++ i){
		pq.push(0);
	}
	sort(a.rbegin(), a.rend());
	long long res = 0;
	for(auto x: a){
		res += pq.top();
		long long y = x + pq.top();
		pq.pop();
		pq.push(y);
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