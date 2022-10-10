#include <bits/stdc++.h>
using namespace std;



int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	int n;
	cin >> n;
	vector<int> a(n);
	int g = 0;
	for(auto i = 0; i < n; ++ i){
		cin >> a[i];
		g = gcd(g, a[i]);
	}
	for(auto &x: a){
		x /= g;
	}
	int sum = accumulate(a.begin(), a.end(), 0);
	if(sum & 1){
		cout << "0\n";
		return 0;
	}
	bitset<100001> dp;
	dp.set(0);
	for(auto x: a){
		dp |= dp << x;
	}
	if(!dp[sum >> 1]){
		cout << "0\n";
		return 0;
	}
	for(auto i = 0; i < n; ++ i){
		if(a[i] & 1){
			cout << "1\n" << i + 1 << "\n";
			return 0;
		}
	}
	assert(false);
	return 0;
}

/*

*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////