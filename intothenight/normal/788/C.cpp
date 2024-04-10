#include <bits/stdc++.h>
using namespace std;
template<class T, class U> T &ctmax(T &x, const U &y){ return x = max<T>(x, y); }
template<class T, class U> T &ctmin(T &x, const U &y){ return x = min<T>(x, y); }



int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	int n, k;
	cin >> n >> k;
	const int mx = 1e3;
	vector<int> present(mx + 1);
	for(auto i = 0; i < k; ++ i){
		int x;
		cin >> x;
		present[x] = true;
	}
	vector<int> a;
	for(auto x = 0; x <= mx; ++ x){
		if(present[x]){
			a.push_back(x);
		}
	}
	k = (int)a.size();
	if(a.back() < n || a.front() > n){
		cout << "-1\n";
		return 0;
	}
	const int mxsq = 1e6;
	using bs = bitset<mxsq + 1>;
	bs dp;
	dp.set(0);
	for(auto i = 1; i <= 1000; ++ i){
		bs dp_next;
		for(auto x: a){
			dp_next |= dp << x;
		}
		swap(dp, dp_next);
		if(dp[n * i]){
			cout << i << "\n";
			return 0;
		}
	}
	cout << "-1\n";
	return 0;
}

/*

*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////