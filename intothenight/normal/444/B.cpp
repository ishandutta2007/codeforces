#include <bits/stdc++.h>
using namespace std;
template<class T, class U> T &ctmax(T &x, const U &y){ return x = max<T>(x, y); }
template<class T, class U> T &ctmin(T &x, const U &y){ return x = min<T>(x, y); }



int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	int n, d, x;
	cin >> n >> d >> x;
	const int mod = 1e9 + 7;
	vector<int> a(n);
	iota(a.begin(), a.end(), 1);
	bitset<100000> b;
	for(auto i = 0; i < d; ++ i){
		b.set(i);
	}
	auto getnext = [&](){
		return x = (1LL * x * 37 + 10007) % mod;
	};
	for(auto i = 0; i < n; ++ i){
		swap(a[i], a[getnext() % (i + 1)]);
	}
	for(auto i = 0; i < n; ++ i){
		int j = getnext() % (i + 1);
		if(b[i] != b[j]){
			b.flip(i), b.flip(j);
		}
	}
	vector<int> pos(n + 1), ones;
	for(auto i = 0; i < n; ++ i){
		pos[a[i]] = i;
		if(b[i]){
			ones.push_back(i);
		}
	}
	vector<int> res(2 * n - 1, -1);
	const int tot = 30 * n / d + 1;
	for(auto x = max(1, n - tot); x <= n; ++ x){
		for(auto i: ones){
			res[pos[x] + i] = x;
		}
	}
	for(auto i = 0; i < n; ++ i){
		if(!~res[i]){
			res[i] = 0;
			for(auto j = b._Find_first(); j <= i; j = b._Find_next(j)){
				ctmax(res[i], a[i - j]);
			}
		}
		cout << res[i] << "\n";
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