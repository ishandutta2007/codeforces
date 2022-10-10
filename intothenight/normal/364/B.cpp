#include <bits/stdc++.h>
using namespace std;



int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	int n, d;
	cin >> n >> d;
	bitset<600001> dp;
	dp.set(0);
	for(auto i = 0; i < n; ++ i){
		int x;
		cin >> x;
		dp |= dp << x;
	}
	int cnt = 0, res = 0;
	while(true){
		int next = res + d;
		while(!dp[next]){
			-- next;
		}
		if(res == next){
			break;
		}
		++ cnt;
		res = next;
	}
	cout << res << " " << cnt << "\n";
	return 0;
}

/*

*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////