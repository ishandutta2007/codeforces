#include <bits/stdc++.h>
using namespace std;
#if __cplusplus > 201703L
#include <ranges>
using namespace numbers;
#endif

template<class T, class F>
struct segment_tree_2d{
	int n, m;
	vector<vector<T>> data;
	F TT; // commutative monoid operation
	T T_id; // commutative monoid identity
	segment_tree_2d(int n, int m, F TT, T T_id): n(n), m(m), TT(TT), T_id(T_id), data(n << 1, vector<T>(m << 1, T_id)){ }
	segment_tree_2d(int n, int m, T x, F TT, T T_id): segment_tree_2d(vector<vector<T>>(n, vector<T>(m, x)), TT, T_id){ }
	segment_tree_2d(const vector<vector<T>> &a, F TT, T T_id): n((int)a.size()), m((int)a[0].size()), TT(TT), T_id(T_id), data(n << 1, vector<T>(m << 1, T_id)){
		for(auto i = 0; i < n; ++ i) for(auto j = 0; j < m; ++ j) data[i + n][j + m] = a[i][j];
		for(auto i = n - 1; i > 0; -- i) for(auto j = 0; j < m; ++ j) data[i][j + m] = TT(data[i << 1][j + m], data[i << 1 | 1][j + m]);
		for(auto i = 1; i < n << 1; ++ i) for(auto j = m - 1; j > 0; -- j) data[i][j] = TT(data[i][j << 1], data[i][j << 1 | 1]);
	} // O(nm)
	void set(int p, int q, T x){ // a[p][q] = x, O(log n log m)
		data[p += n][q += m] = x;
		for(auto j = q; j >>= 1; ) data[p][j] = TT(data[p][j << 1], data[p][j << 1 | 1]);
		for(auto i = p; i >>= 1; ){
			data[i][q] = TT(data[i << 1][q], data[i << 1 | 1][q]);
			for(auto j = q; j >>= 1; ) data[i][j] = TT(data[i][j << 1], data[i][j << 1 | 1]);
		}
	}
	T query(int p, int q){ // a[p][q], O(1)
		return data[p + n][q + m];
	}
	T query(int xl, int xr, int yl, int yr){ // sum of a[i][j] on [xl, xr) X [yl, yr), O(log n log m)
		if(xl >= xr || yl >= yr) return T_id;
		T res = T_id;
		xl += n, xr += n, yl += m, yr += m;
		for(auto il = xl, ir = xr; il < ir; il >>= 1, ir >>= 1){
			if(il & 1){
				for(auto jl = yl, jr = yr; jl < jr; jl >>= 1, jr >>= 1){
					if(jl & 1) res = TT(res, data[il][jl ++]);
					if(jr & 1) res = TT(res, data[il][-- jr]);
				}
				++ il;
			}
			if(ir & 1){
				-- ir;
				for(auto jl = yl, jr = yr; jl < jr; jl >>= 1, jr >>= 1){
					if(jl & 1) res = TT(res, data[ir][jl ++]);
					if(jr & 1) res = TT(res, data[ir][-- jr]);
				}
			}
		}
		return res;
	}
	template<class output_stream>
	friend output_stream &operator<<(output_stream &out, const segment_tree_2d<T, F> &seg){
		for(auto i = 0; i < seg.n; ++ i){
			out << "\n[";
			for(auto j = 0; j < seg.m; ++ j){
				out << seg.query(i, j);
				if(j != seg.m - 1) out << ", ";
			}
			out << "]\n";
		}
		return out;
	}
};

int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	int n, m;
	cin >> n >> m;
	#ifdef LOCAL
	const int mx = 4;
	#else
	const int mx = 1e5;
	#endif
	vector<vector<array<int, 2>>> pos(mx);
	for(auto i = 0; i < n; ++ i){
		for(auto j = 0; j < m; ++ j){
			int c;
			cin >> c, -- c;
			pos[c].push_back({i, j});
		}
	}
	long long res = 0;
	segment_tree_2d pref(n, m, plus<>(), 0LL);
	segment_tree_2d cnt(n, m, plus<>(), 0LL);
	for(auto c = 0; c < mx; ++ c){
		for(auto ref = 0; ref < 2; ++ ref){
			for(auto [x, y]: pos[c]){
				pref.set(x, y, x + y);
				cnt.set(x, y, 1);
			}
			for(auto [x, y]: pos[c]){
				res += 1LL * cnt.query(0, x + !ref,0,  y + !ref) * (x + y) - 1LL * pref.query(0, x + !ref, 0, y + !ref);
			}
			for(auto [x, y]: pos[c]){
				pref.set(x, y, 0);
				cnt.set(x, y, 0);
			}
			for(auto &[x, y]: pos[c]){
				x = n - 1 - x;
			}
		}
	}
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