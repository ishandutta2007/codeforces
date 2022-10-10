#include <bits/stdc++.h>
using namespace std;



int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	int n;
	cin >> n;
	vector<array<int, 2>> a(n);
	for(auto i = 0; i < n; ++ i){
		cin >> a[i][0];
	}
	for(auto i = 0; i < n; ++ i){
		cin >> a[i][1];
	}
	sort(a.begin(), a.end());
	int cur = 0;
	priority_queue<int> pq;
	long long pqsum = 0, res = 0;
	for(auto i = 0; i < n; ++ i){
		while(!pq.empty() && cur < a[i][0]){
			pqsum -= pq.top();
			pq.pop();
			res += pqsum;
			++ cur;
		}
		pq.push(a[i][1]);
		pqsum += a[i][1];
		cur = a[i][0];
	}
	while((int)pq.size() >= 2){
		pqsum -= pq.top();
		pq.pop();
		res += pqsum;
		++ cur;
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