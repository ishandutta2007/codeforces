#include <bits/stdc++.h>
using namespace std;
template<class T, class U> T &ctmax(T &x, const U &y){ return x = max<T>(x, y); }
template<class T, class U> T &ctmin(T &x, const U &y){ return x = min<T>(x, y); }



int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	int x2;
	cin >> x2;
	auto get_p = [&](int x){
		int res = -1;
		for(auto p = 2; p * p <= x; ++ p){
			while(x % p == 0){
				x /= p;
				res = p;
			}
		}
		if(x > 1){
			res = x;
		}
		return res;
	};
	int res = numeric_limits<int>::max();
	for(auto x = x2 - get_p(x2) + 1; x <= x2; ++ x){
		if(x >= 4){
			int p = get_p(x);
			if(x != p){
				ctmin(res, x - p + 1);
			}
		}
	}
	cout << res << "\n";
	return 0;
}

/*
14 <- 14, 13, 12, 11, 10, 9, 8
                            7
*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////