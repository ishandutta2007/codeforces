#include <bits/stdc++.h>
using namespace std;
template<class T, class U> T &ctmax(T &x, const U &y){ return x = max<T>(x, y); }
template<class T, class U> T &ctmin(T &x, const U &y){ return x = min<T>(x, y); }

// Specialization of sparse_table
// Range min query by default. Set cmp = greater for max query
template<class T, class Compare = less<>>
struct range_minmax_query_solver{
	int n;
	vector<vector<T>> data;
	Compare cmp;
	T T_id;
	range_minmax_query_solver(){ }
	range_minmax_query_solver(const vector<T> &a, Compare cmp = less<>(), T T_id = numeric_limits<T>::max()): n((int)a.size()), cmp(cmp), T_id(T_id), data({a}){ // O(n log n)
		for(auto p = 1, i = 1; p << 1 <= n; p <<= 1, ++ i){
			data.emplace_back(n - (p << 1) + 1);
			for(auto j = 0; j < (int)data[i].size(); ++ j) data[i][j] = cmp(data[i - 1][j], data[i - 1][j + p]) ? data[i - 1][j] : data[i - 1][j + p];
		}
	}
	T query(int l, int r){ // O(1)
		if(l >= r) return T_id;
		int d = __lg(r - l);
		return cmp(data[d][l], data[d][r - (1 << d)]) ? data[d][l] : data[d][r - (1 << d)];
	}
};

int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	int n, qn;
	cin >> n >> qn;
	const int mx = 1e5 + 1;
	vector<vector<int>> pos(mx);
	for(auto i = 0; i < n; ++ i){
		int x;
		cin >> x;
		for(auto p = 2; p * p <= x; ++ p){
			if(x % p == 0){
				pos[p].push_back(i);
				while(x % p == 0){
					x /= p;
				}
			}
		}
		if(x > 1){
			pos[x].push_back(i);
		}
	}
	vector<int> reach(n + 1, n);
	for(auto p = 2; p < mx; ++ p){
		if((int)pos[p].size() >= 2){
			for(auto t = 0; t < (int)pos[p].size() - 1; ++ t){
				ctmin(reach[pos[p][t]], pos[p][t + 1]);
			}
		}
	}
	range_minmax_query_solver rmq(reach);
	const int mxbit = __lg(n);
	vector<vector<int>> jump(mxbit + 1, vector<int>(n + 1, n));
	for(auto i = 0; i < n; ++ i){
		jump[0][i] = rmq.query(i, n + 1);
	}
	for(auto bit = 1; bit <= mxbit; ++ bit){
		for(auto i = 0; i < n; ++ i){
			jump[bit][i] = jump[bit - 1][jump[bit - 1][i]];
		}
	}
	for(auto qi = 0; qi < qn; ++ qi){
		int l, r;
		cin >> l >> r, -- l;
		int res = 0;
		for(auto bit = mxbit; bit >= 0; -- bit){
			if(jump[bit][l] < r){
				res |= 1 << bit;
				l = jump[bit][l];
			}
		}
		cout << res + 1 << "\n";
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