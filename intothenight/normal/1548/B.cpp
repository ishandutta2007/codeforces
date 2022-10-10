#include <bits/stdc++.h>
using namespace std;
template<class T, class U> T &ctmax(T &x, const U &y){ return x = max<T>(x, y); }
template<class T, class U> T &ctmin(T &x, const U &y){ return x = min<T>(x, y); }

template<class T, class F>
struct sparse_table{
	int n;
	vector<vector<T>> data;
	F TT;
	T T_id;
	sparse_table(){ }
	// O(n log n)
	sparse_table(const vector<T> &a, F TT, T T_id): n((int)a.size()), TT(TT), T_id(T_id), data({a}){
		for(auto p = 1, i = 1; p << 1 <= n; p <<= 1, ++ i){
			data.emplace_back(n - (p << 1) + 1);
			for(auto j = 0; j < (int)data[i].size(); ++ j) data[i][j] = TT(data[i - 1][j], data[i - 1][j + p]);
		}
	}
	// O(1)
	T query(int l, int r) const{
		assert(0 <= l && l <= r && r <= n);
		if(l == r) return T_id;
		int d = __lg(r - l);
		return TT(data[d][l], data[d][r - (1 << d)]);
	}
};

int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	auto __solve_tc = [&](auto __tc_num)->int{
		int n;
		cin >> n, -- n;
		vector<long long> a(n);
		{
			vector<long long> b(n + 1);
			for(auto i = 0; i <= n; ++ i){
				cin >> b[i];
			}
			for(auto i = 0; i < n; ++ i){
				a[i] = abs(b[i + 1] - b[i]);
			}
		}
		sparse_table rgcdq(a, [&](auto x, auto y){ return gcd(x, y); }, 0LL);
		int res = 1;
		for(auto i = 0, j = 0; i < n; ++ i){
			while(j < n && rgcdq.query(i, j + 1) != 1){
				++ j;
			}
			ctmax(res, j - i + 1);
		}
		cout << res << "\n";
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
6 3 5
*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////