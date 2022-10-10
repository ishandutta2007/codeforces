#include "bits/stdc++.h"
#include "ext/pb_ds/assoc_container.hpp"
#include "ext/pb_ds/tree_policy.hpp"
#include "ext/rope"
using namespace std;
using namespace chrono;
using namespace __gnu_pbds;
using namespace __gnu_cxx;
mt19937 rng(high_resolution_clock::now().time_since_epoch().count());
mt19937_64 rngll(high_resolution_clock::now().time_since_epoch().count());
#define lambdify(x) [&](auto &&...args){ return x(forward<decltype(args)>(args)...); }
template<typename T, typename U> T &ctmax(T &x, const U &y){ return x = max<T>(x, y); }
template<typename T, typename U> T &ctmin(T &x, const U &y){ return x = min<T>(x, y); }
template<typename T> using Tree = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

array<vector<int>, 2> linearsieve(int n){
	vector<int> lpf(n + 1), prime;
	prime.reserve(n + 1);
	for(int i = 2; i <= n; ++ i){
		if(!lpf[i]) lpf[i] = i, prime.push_back(i);
		for(int j = 0; j < int(prime.size()) && prime[j] <= lpf[i] && i * prime[j] <= n; ++ j){
			lpf[i * prime[j]] = prime[j];
		}
	}
	return {lpf, prime};
}

int SOLVE(int obj, const auto &lpf, const auto &prime){
	int qcnt = 0;

	auto query = [&](long long x){
		++ qcnt;
		//cout << "query cnt = " << qcnt << endl;

		cout << "? " << x << endl;
		long long resp;
		cin >> resp;
		return resp;
	};

	/*auto query = [&](long long x){
		cout << "query cnt = " << ++ qcnt << endl;
		assert(qcnt < 22);
		cout << "? " << x << endl;
		long long resp;
		cout << "Response = " << (resp = gcd<long long>(obj, x)) << endl;
		return resp;
	};*/

	static const long long mx = 1e18;
	int res = 2;
	for(auto i = 0; qcnt < 22; ){
		long long t = 1;
		int j = i;
		while(!__builtin_mul_overflow_p(t, prime[j], 0LL) && t * prime[j] <= mx){
			t *= prime[j ++];
		}
		long long x = query(t);
		for(auto k = i; k < j; ++ k){
			if(gcd(x, prime[k]) != 1){
				if(qcnt == 22){
					res *= 2;
					continue;
				}
				long long t = 1;
				while(!__builtin_mul_overflow_p(t, prime[k], 0LL) && t * prime[k] <= mx){
					t *= prime[k];
				}
				long long y = query(t);
				int cnt = 0;
				while(y != 1){
					++ cnt;
					y /= prime[k];
				}
				//cout << "prime = " << prime[k] << ", exp = " << cnt << endl;
				res *= (cnt + 1);
			}
		}
		i = j;
	}
	
	cout << "! " << res << endl;
	/*cout << "Res = " << res << ", answer = ";
	int ans = 1;
	int tttt = obj;
	for(auto p = 2; p * p <= obj; ++ p){
		int e = 0;
		while(obj % p == 0){
			obj /= p;
			++ e;
		}
		ans *= (e + 1);
	}
	if(obj != 1){
		ans *= 2;
	}
	cout << ans << endl;
	if(abs(res - ans) > 7 && (2 * ans < res || ans > 2 * res)){
		cout << "Failed!!\n";
		cout << "Obj = " << tttt << endl;
		exit(0);
	}*/
	return 0;
}

int main(){
	cin.tie(0)->sync_with_stdio(0);
	auto [lpf, prime] = linearsieve(1000000);
	int ttt;
	cin >> ttt;
	while(ttt --){
		int obj = rng() % int(1000) + 1;
		SOLVE(obj, lpf, prime);
	}
	return 0;
}

/*
2 2 73
*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////