#include <bits/stdc++.h>
using namespace std;



int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	long long n, l, r;
	cin >> n >> l >> r, -- l;
	auto cnt = [&](long long n){
		return n ? (1LL << __lg(n) + 1) - 1 : 1;
	};
	int res = 0;
	function<void(long long, long long, long long)> solve = [&](long long n, long long l, long long r){
		if(n > 1){
			if(l < cnt(n >> 1)){
				solve(n >> 1, l, min(r, cnt(n >> 1)));
			}
			if(l <= cnt(n >> 1) && cnt(n >> 1) < r){
				res += n & 1;
			}
			if(cnt(n >> 1) + 1 < r){
				solve(n >> 1, max(0LL, l - cnt(n >> 1) - 1), r - cnt(n >> 1) - 1);
			}
		}
		else{
			res += n & 1;
		}
	};
	solve(n, l, r);
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