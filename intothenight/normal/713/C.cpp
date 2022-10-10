#include <bits/stdc++.h>
using namespace std;



int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	int n;
	cin >> n;
	vector<int> a(n);
	for(auto i = 0; i < n; ++ i){
		cin >> a[i];
		a[i] -= i;
	}
	priority_queue<int> pq;
	pq.push(a[0]);
	long long res = 0;
	for(auto i = 1; i < n; ++ i){
		if(pq.top() <= a[i]){
			pq.push(a[i]);
		}
		else{
			res += pq.top() - a[i];
			pq.push(a[i]), pq.push(a[i]), pq.pop();
		}
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