#include <bits/stdc++.h>
using namespace std;
template<class T, class U> T &ctmax(T &x, const U &y){ return x = max<T>(x, y); }
template<class T, class U> T &ctmin(T &x, const U &y){ return x = min<T>(x, y); }


vector<pair<long long, int>> factorize(long long x){
	vector<pair<long long, int>> res;
	for(long long p = 2; p * p <= x; ++ p) if(x % p == 0){
		res.push_back({p, 0});
		while(x % p == 0) ++ res.back().second, x /= p;
	}
	if(x > 1) res.push_back({x, 1});
	return res;
}

long long pow(long long x, int e){
	long long res = 1;
	while(e --){
		res *= x;
	}
	return res;
}

int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	auto __solve_tc = [&](int __tc_num){
		long long p;
		int q;
		cin >> p >> q;
		if(p % q == 0){
			long long res = 1, pp = p;
			for(auto [pr, e]: factorize(q)){
				int pe = 0;
				while(pp % pr == 0){
					pp /= pr;
					++ pe;
				}
				ctmax(res, p / pow(pr, pe - e + 1));
			}
			cout << res << "\n";
		}
		else{
			cout << p << "\n";
		}
		return 0;
	};
	int __tc_cnt;
	cin >> __tc_cnt;
	for(auto __tc_num = 0; __tc_num < __tc_cnt; ++ __tc_num){
		__solve_tc(__tc_num);
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