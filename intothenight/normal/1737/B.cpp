#include <bits/stdc++.h>
using namespace std;
#if __cplusplus > 201703L
#include <ranges>
using namespace numbers;
#endif

// Find floor(n^1/k) for non-negative integers n, k
struct floored_root{
	vector<unsigned long long> pow[65];
	floored_root(){
		for(auto t = 2u; t < 1 << 16; ++ t){
			unsigned long long s = t * t;
			s = s * s;
			for(auto k = 4; ; ++ k){
				pow[k].push_back(s);
				if(__builtin_umulll_overflow(s, t, &s)) break;
			}
		}
	}
	unsigned long long sqrt(unsigned long long n) const{
		if(n == -1ull) return (unsigned int)-1;
		unsigned long long x = std::sqrt(n);
		return x * x > n ? x - 1 : x;
	}
	unsigned long long cbrt(unsigned long long n) const{
		unsigned long long x = 0, y = 0;
		for(auto s = 63; s >= 0; s -= 3){
			x <<= 1;
			y = 3 * x * (x + 1) + 1;
			if(y <= (n >> s)) n -= y << s, ++ x;
		}
		return x;
	}
	unsigned long long operator()(unsigned long long n, int k) const{
		assert(1 <= k && k <= 64);
		if(k == 1 || n == 0) return n;
		if(k == 2) return sqrt(n);
		if(k == 3) return cbrt(n);
		return upper_bound(pow[k].begin(), pow[k].end(), n) - pow[k].begin() + 1;
	}
};

int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	floored_root froot;
	auto __solve_tc = [&](auto __tc_num)->int{
		long long l, r;
		cin >> l >> r, ++ r;
		auto get = [&](long long r)->long long{
			long long s = froot.sqrt(r - 1);
			return s * 3 - (s * (s + 1) >= r) - (s * (s + 2) >= r);
		};
		cout << get(r) - get(l) << "\n";
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