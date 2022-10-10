#include <bits/stdc++.h>
using namespace std;



int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	int n, k;
	cin >> n >> k;
	vector<int> a(n);
	vector<long long> pref(n + 1);
	for(auto i = 0; i < n; ++ i){
		cin >> a[i];
		pref[i + 1] = pref[i] + a[i];
	}
	vector<long long> obj{1};
	if(k != 1){
		obj.push_back(k);
	}
	while(abs(k) > 1 && abs(obj.back() * k) <= 1'000'000'000'000'000'00){
		obj.push_back(obj.back() * k);
	}
	long long res = 0;
	map<long long, int> cnt;
	for(auto i = 0; i <= n; ++ i){
		for(auto x: obj){
			res += cnt[pref[i] - x];
		}
		++ cnt[pref[i]];
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