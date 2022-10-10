#include <bits/stdc++.h>
using namespace std;



int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	auto end = [&](int t){
		t == 1 ? cout << "sjfnb\n" : cout << "cslnb\n";
		exit(0);
	};
	int n;
	cin >> n;
	vector<int> a(n);
	for(auto i = 0; i < n; ++ i){
		cin >> a[i];
	}
	sort(a.begin(), a.end());
	int cnt = 0;
	for(auto i = 1; i < n; ++ i){
		if(a[i - 1] == a[i]){
			++ cnt;
		}
	}
	if(cnt >= 2){
		end(2);
	}
	if(auto it = adjacent_find(a.begin(), a.end()); cnt == 1 && (it != a.begin() && *it == *prev(it) + 1 || !*it)){
		end(2);
	}
	end(2 - (accumulate(a.begin(), a.end(), 1LL * n * (n - 1) / 2) & 1));
	return 0;
}

/*

*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////