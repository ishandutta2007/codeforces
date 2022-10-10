#include <bits/stdc++.h>
using namespace std;



int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	const int mod = 1e9 + 7;
	auto add = [&](int x, int y)->int{
		x += y;
		if(x >= mod){
			x -= mod;
		}
		return x;
	};
	auto sub = [&](int x, int y)->int{
		x -= y;
		if(x < 0){
			x += mod;
		}
		return x;
	};
	auto mul = [&](int x, int y)->int{
		return 1LL * x * y % mod;
	};
	auto pow = [&](int b, int e)->int{
		int res = 1;
		while(e){
			if(e & 1){
				res = mul(res, b);
			}
			b = mul(b, b);
			e >>= 1;
		}
		return res;
	};
	auto div = [&](int x, int y)->int{
		assert(y);
		return mul(x, pow(y, mod - 2));
	};
	auto print = [&](int x)->void{
		int d = 1;
		while(true){
			int n = mul(x, d);
			if(n <= 1000){
				cout << n << "/" << d << " ";
				return;
			}
			else if(n >= mod - 1000){
				cout << n - mod << "/" << d << " ";
				return;
			}
			++ d;
		}
	};
	int n, k;
	cin >> n >> k;
	vector<int> g(n, 1);
	for(auto x = 1; x < n; ++ x){
		g[x] = div(add(mul(mul(k - 1, x), g[x - 1]), n), n - x);
	}
	vector<int> f(n + 1);
	for(auto x = 1; x <= n; ++ x){
		f[x] = add(g[x - 1], f[x - 1]);
	}
	vector<int> fact(n + 1, 1), invfact(n + 1, 1);
	for(auto i = 1; i <= n; ++ i){
		fact[i] = mul(fact[i - 1], i);
	}
	invfact[n] = pow(fact[n], mod - 2);
	for(auto i = n - 1; i >= 0; -- i){
		invfact[i] = mul(invfact[i + 1], i + 1);
	}
	auto C = [&](int x, int y)->int{
		return mul(mul(fact[x], invfact[y]), invfact[x - y]);
	};
	map<int, int> cnt;
	for(auto i = 0; i < n; ++ i){
		int x;
		cin >> x;
		++ cnt[x];
	}
	int free = cnt[-1];
	vector<int> a;
	for(auto [c, x]: cnt){
		if(~c){
			a.push_back(x);
		}
	}
	sort(a.begin(), a.end());
	vector<int> pk(n + 1, 1);
	for(auto i = 1; i <= n; ++ i){
		pk[i] = mul(pk[i - 1], k - 1);
	}
	int res = 0, rem = k;
	for(auto l = 0; l < (int)a.size(); ){
		int r = l;
		while(r < (int)a.size() && a[l] == a[r]){
			++ r;
		}
		rem -= r - l;
		for(auto x = 0; x <= free; ++ x){
			res = add(res, mul(r - l, mul(mul(C(free, x), pk[free - x]), f[a[l] + x])));
		}
		l = r;
	}
	for(auto x = 0; x <= free; ++ x){
		res = add(res, mul(rem, mul(mul(C(free, x), pk[free - x]), f[x])));
	}
	cout << sub(f[n], div(res, pow(k, free))) << "\n";
	return 0;
}

/*

*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////