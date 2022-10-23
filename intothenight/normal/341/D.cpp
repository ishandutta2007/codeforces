#include <bits/stdc++.h>
using namespace std;
#if __cplusplus > 201703L
#include <ranges>
using namespace numbers;
#endif

template<class T>
struct range_add_range_sum_query_solver_2d{
	int n, m;
	vector<vector<T>> data0, data1, data2, data3;
	range_add_range_sum_query_solver_2d(){ }
	// O(n)
	range_add_range_sum_query_solver_2d(int n, int m): n(n), m(m), data0(n, vector<T>(m)), data1(n, vector<T>(m)), data2(n, vector<T>(m)), data3(n, vector<T>(m)){ }
	// O(n)
	range_add_range_sum_query_solver_2d(int n, int m, T init): range_add_range_sum_query_solver_2d(vector<vector<T>>(n, vector<T>(m, init))){ }
	// O(n)
	range_add_range_sum_query_solver_2d(const vector<vector<T>> &v): n((int)v.size()), m((int)v[0].size()), data0(n, vector<T>(m)), data1(n, vector<T>(m)), data2(n, vector<T>(m)), data3(v){
		for(auto i = 1; i <= n; ++ i) if(i + (i & -i) <= n) for(auto j = 0; j < m; ++ j) data3[i + (i & -i) - 1][j] += data3[i - 1][j];
		for(auto i = 0; i < n; ++ i) for(auto j = 1; j <= m; ++ j) if(j + (j & -j) <= m) data3[i][j + (j & -j) - 1] += data3[i][j - 1];
	}
	void update(int xl, int xr, int yl, int yr, T x){
		assert(0 <= xl && xl <= xr && xr <= n);
		assert(0 <= yl && yl <= yr && yr <= m);
		if(xl == xr || yl == yr) return;
		for(auto i = xl + 1; i <= n; i += i & -i) for(auto j = yl + 1; j <= m; j += j & -j){
			data0[i - 1][j - 1] += x;
			data1[i - 1][j - 1] -= xl * x;
			data2[i - 1][j - 1] -= yl * x;
			data3[i - 1][j - 1] += xl * (yl * x);
		}
		for(auto i = xl + 1; i <= n; i += i & -i) for(auto j = yr + 1; j <= m; j += j & -j){
			data0[i - 1][j - 1] -= x;
			data1[i - 1][j - 1] += xl * x;
			data2[i - 1][j - 1] += yr * x;
			data3[i - 1][j - 1] -= xl * (yr * x);
		}
		for(auto i = xr + 1; i <= n; i += i & -i) for(auto j = yl + 1; j <= m; j += j & -j){
			data0[i - 1][j - 1] -= x;
			data1[i - 1][j - 1] += xr * x;
			data2[i - 1][j - 1] += yl * x;
			data3[i - 1][j - 1] -= xr * (yl * x);
		}
		for(auto i = xr + 1; i <= n; i += i & -i) for(auto j = yr + 1; j <= m; j += j & -j){
			data0[i - 1][j - 1] += x;
			data1[i - 1][j - 1] -= xr * x;
			data2[i - 1][j - 1] -= yr * x;
			data3[i - 1][j - 1] += xr * (yr * x);
		}
	}
	T pref(int xr, int yr) const{
		assert(0 <= xr && xr <= n);
		assert(0 <= yr && yr <= m);
		T sum0 = {}, sum1 = {}, sum2 = {}, sum3 = {};
		for(auto x = xr; x > 0; x -= x & -x) for(auto y = yr; y > 0; y -= y & -y){
			sum0 += data0[x - 1][y - 1];
			sum1 += data1[x - 1][y - 1];
			sum2 += data2[x - 1][y - 1];
			sum3 += data3[x - 1][y - 1];
		}
		return xr * (yr * sum0) + yr * sum1 + xr * sum2 + sum3;
	}
	T query(int xl, int xr, int yl, int yr) const{
		assert(0 <= xl && xl <= xr && xr <= n);
		assert(0 <= yl && yl <= yr && yr <= m);
		if(xl == xr || yl == yr) return {};
		return pref(xl, yl) - pref(xl, yr) - pref(xr, yl) + pref(xr, yr);
	}
	template<class output_stream>
	friend output_stream &operator<<(output_stream &out, const range_add_range_sum_query_solver_2d<T> &solver){
		for(auto i = 0; i < solver.n; ++ i){
			out << "\n[";
			for(auto j = 0; j < solver.m; ++ j){
				out << solver.query(i, i + 1, j, j + 1);
				if(j != solver.m - 1) out << ", ";
			}
			out << "]\n";
		}
		return out;
	}
};

template<class T>
struct range_xor_query_xor_solver_2d{
	int n, m;
	vector<vector<T>> data0, data1, data2, data3;
	range_xor_query_xor_solver_2d(){ }
	// O(n)
	range_xor_query_xor_solver_2d(int n, int m): n(n), m(m), data0(n, vector<T>(m)), data1(n, vector<T>(m)), data2(n, vector<T>(m)), data3(n, vector<T>(m)){ }
	// O(n)
	range_xor_query_xor_solver_2d(int n, int m, T init): range_xor_query_xor_solver_2d(vector<vector<T>>(n, vector<T>(m, init))){ }
	// O(n)
	range_xor_query_xor_solver_2d(const vector<vector<T>> &v): n((int)v.size()), m((int)v[0].size()), data0(n, vector<T>(m)), data1(n, vector<T>(m)), data2(n, vector<T>(m)), data3(v){
		for(auto i = 1; i <= n; ++ i) if(i + (i & -i) <= n) for(auto j = 0; j < m; ++ j) data3[i + (i & -i) - 1][j] ^= data3[i - 1][j];
		for(auto i = 0; i < n; ++ i) for(auto j = 1; j <= m; ++ j) if(j + (j & -j) <= m) data3[i][j + (j & -j) - 1] ^= data3[i][j - 1];
	}
	void update(int xl, int xr, int yl, int yr, T x){
		assert(0 <= xl && xl <= xr && xr <= n);
		assert(0 <= yl && yl <= yr && yr <= m);
		if(xl == xr || yl == yr) return;
		for(auto i = xl + 1; i <= n; i += i & -i) for(auto j = yl + 1; j <= m; j += j & -j){
			data0[i - 1][j - 1] ^= x;
			data1[i - 1][j - 1] ^= (xl & 1) * x;
			data2[i - 1][j - 1] ^= (yl & 1) * x;
			data3[i - 1][j - 1] ^= (xl & yl & 1) * x;
		}
		for(auto i = xl + 1; i <= n; i += i & -i) for(auto j = yr + 1; j <= m; j += j & -j){
			data0[i - 1][j - 1] ^= x;
			data1[i - 1][j - 1] ^= (xl & 1) * x;
			data2[i - 1][j - 1] ^= (yr & 1) * x;
			data3[i - 1][j - 1] ^= (xl & yr & 1) * x;
		}
		for(auto i = xr + 1; i <= n; i += i & -i) for(auto j = yl + 1; j <= m; j += j & -j){
			data0[i - 1][j - 1] ^= x;
			data1[i - 1][j - 1] ^= (xr & 1) * x;
			data2[i - 1][j - 1] ^= (yl & 1) * x;
			data3[i - 1][j - 1] ^= (xr & yl & 1) * x;
		}
		for(auto i = xr + 1; i <= n; i += i & -i) for(auto j = yr + 1; j <= m; j += j & -j){
			data0[i - 1][j - 1] ^= x;
			data1[i - 1][j - 1] ^= (xr & 1) * x;
			data2[i - 1][j - 1] ^= (yr & 1) * x;
			data3[i - 1][j - 1] ^= (xr & yr & 1) * x;
		}
	}
	T pref(int xr, int yr) const{
		assert(0 <= xr && xr <= n);
		assert(0 <= yr && yr <= m);
		T sum0 = {}, sum1 = {}, sum2 = {}, sum3 = {};
		for(auto x = xr; x > 0; x -= x & -x) for(auto y = yr; y > 0; y -= y & -y){
			sum0 ^= data0[x - 1][y - 1];
			sum1 ^= data1[x - 1][y - 1];
			sum2 ^= data2[x - 1][y - 1];
			sum3 ^= data3[x - 1][y - 1];
		}
		return (xr & yr & 1) * sum0 ^ (yr & 1) * sum1 ^ (xr & 1) * sum2 ^ sum3;
	}
	T query(int xl, int xr, int yl, int yr) const{
		assert(0 <= xl && xl <= xr && xr <= n);
		assert(0 <= yl && yl <= yr && yr <= m);
		if(xl == xr || yl == yr) return {};
		return pref(xl, yl) ^ pref(xl, yr) ^ pref(xr, yl) ^ pref(xr, yr);
	}
	template<class output_stream>
	friend output_stream &operator<<(output_stream &out, const range_xor_query_xor_solver_2d<T> &solver){
		for(auto i = 0; i < solver.n; ++ i){
			out << "\n[";
			for(auto j = 0; j < solver.m; ++ j){
				out << solver.query(i, i + 1, j, j + 1);
				if(j != solver.m - 1) out << ", ";
			}
			out << "]\n";
		}
		return out;
	}
};

int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	int n, qn;
	cin >> n >> qn;
	range_xor_query_xor_solver_2d<long long> rxqx(n, n);
	for(auto qi = 0; qi < qn; ++ qi){
		int t, xl, yl, xr, yr;
		cin >> t >> xl >> yl >> xr >> yr;
		-- xl;
		-- yl;
		if(t == 1){
			cout << rxqx.query(xl, xr, yl, yr) << "\n";
		}
		else{
			long long x;
			cin >> x;
			rxqx.update(xl, xr, yl, yr, x);
		}
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