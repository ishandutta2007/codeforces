#include <bits/stdc++.h>
using namespace std;



int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	int n;
	cin >> n;
	vector<int> v(n), t(n);
	vector<long long> preft(n + 1);
	for(auto i = 0; i < n; ++ i){
		cin >> v[i];
	}
	for(auto i = 0; i < n; ++ i){
		cin >> t[i];
		preft[i + 1] = preft[i] + t[i];
	}
	vector<int> s(n + 1);
	vector<long long> res(n);
	for(auto i = 0; i < n; ++ i){
		if(v[i]){
			int j = lower_bound(preft.begin(), preft.end(), preft[i] + v[i]) - preft.begin();
			++ s[i];
			if(j <= n){
				-- s[j - 1];
				res[j - 1] += preft[i] + v[i] - preft[j - 1];
			}
		}
	}
	for(auto i = 0; i < n; ++ i){
		res[i] += 1LL * t[i] * s[i];
		s[i + 1] += s[i];
	}
	for(auto x: res){
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