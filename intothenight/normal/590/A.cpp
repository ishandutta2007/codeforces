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
	}
	vector<int> res(n, -1), depth(n);
	deque<int> dq;
	for(auto i = 0; i < n; ){
		int j = i;
		while(j < n && a[i] == a[j]){
			++ j;
		}
		if(j - i >= 2 || i == 0 || j == n){
			for(auto t = i; t < j; ++ t){
				res[t] = a[i];
				dq.push_back(t);
			}
		}
		i = j;
	}
	while(!dq.empty()){
		int i = dq.front(); dq.pop_front();
		if(i - 1 >= 0 && !~res[i - 1]){
			depth[i - 1] = depth[i] + 1;
			res[i - 1] = res[i];
			dq.push_back(i - 1);
		}
		if(i + 1 < n && !~res[i + 1]){
			depth[i + 1] = depth[i] + 1;
			res[i + 1] = res[i];
			dq.push_back(i + 1);
		}
	}
	cout << *max_element(depth.begin(), depth.end()) << "\n";
	for(auto x: res){
		cout << x << " " ;
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