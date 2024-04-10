#include <bits/stdc++.h>
using namespace std;



int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	int a;
	string s;
	cin >> a >> s;
	int n = (int)s.size();
	const int mx = 4000 * 10;
	vector<int> cnt(mx + 1);
	for(auto i = 0; i < n; ++ i){
		long long sum = 0;
		for(auto j = i + 1; j <= n; ++ j){
			sum += s[j - 1] - '0';
			++ cnt[sum];
		}
	}
	if(a == 0){
		long long tot = accumulate(cnt.begin(), cnt.end(), 0LL);
		cout << tot * tot - (tot - cnt[0]) * (tot - cnt[0]) << "\n";
	}
	else{
		long long res = 0;
		for(auto x = 1; x <= mx; ++ x){
			if(a % x == 0 && a / x <= mx){
				res += 1LL * cnt[x] * cnt[a / x];
			}
		}
		cout << res << "\n";
	}
	return 0;
}

/*

*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////