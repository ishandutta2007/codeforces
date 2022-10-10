#include <bits/stdc++.h>
using namespace std;
template<class T, class U> T &ctmax(T &x, const U &y){ return x = max<T>(x, y); }
template<class T, class U> T &ctmin(T &x, const U &y){ return x = min<T>(x, y); }

template<class F>
struct y_combinator_result{
	F f;
	template<class T> explicit y_combinator_result(T &&f): f(forward<T>(f)){ }
	template<class ...Args> decltype(auto) operator()(Args &&...args){ return f(ref(*this), forward<Args>(args)...); }
};
template<class F>
decltype(auto) y_combinator(F &&f){
	return y_combinator_result<decay_t<F>>(forward<F>(f));
}

int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	int n, m;
	cin >> n >> m;
	vector<int> a(n);
	for(auto i = 0; i < n; ++ i){
		cin >> a[i];
	}
	cout << y_combinator([&](auto self, int l, int r)->vector<long long>{
		vector<long long> dp{0, 0};
		int root = min_element(a.begin() + l, a.begin() + r) - a.begin(), szl = 1;
		auto update = [&](const vector<long long> &dpv, int w)->void{
			int szr = (int)dpv.size() - 1;
			vector<long long> dp_next(szl + szr + 1, numeric_limits<long long>::min());
			for(auto x = 0; x <= szl; ++ x){
				for(auto y = 0; y <= szr; ++ y){
					ctmax(dp_next[x + y], dp[x] + dpv[y] + 1LL * w * (m - y) * y);
				}
			}
			swap(dp, dp_next);
			szl += szr;
		};
		if(l < root){
			update(self(l, root), a[min_element(a.begin() + l, a.begin() + root) - a.begin()] - a[root]);
		}
		if(root + 1 < r){
			update(self(root + 1, r), a[min_element(a.begin() + root + 1, a.begin() + r) - a.begin()] - a[root]);
		}
		return move(dp);
	})(0, n)[m] << "\n";
	return 0;
}

/*

*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////