#include <bits/stdc++.h>
using namespace std;
#if __cplusplus > 201703L
#include <ranges>
using namespace numbers;
#endif
template<class T> T &ctmin(T &x){ return x; }
template<class T, class Head, class ...Tail> T &ctmin(T &x, const Head &h, const Tail &... t){ return ctmin(x = min<T>(x, h), t...); }
template<class T> T &ctmax(T &x){ return x; }
template<class T, class Head, class ...Tail> T &ctmax(T &x, const Head &h, const Tail &... t){ return ctmax(x = max<T>(x, h), t...); }

template<class T, class F>
struct segment_tree{
	int n, size, log;
	vector<T> data;
	F TT; // monoid operation (always adjacent)
	T T_id; // monoid identity
	// O(n)
	segment_tree(int n, F TT, T T_id): segment_tree(vector<T>(n, T_id), TT, T_id){}
	// O(n)
	segment_tree(int n, T init, F TT, T T_id): segment_tree(vector<T>(n, init), TT, T_id){}
	// O(n)
	segment_tree(const vector<T> &a, F TT, T T_id): n((int)a.size()), TT(TT), T_id(T_id){ // O(n)
		log = __lg(max(n - 1, 1)) + 1, size = 1 << log;
		data = vector<T>(size << 1, T_id);
		copy(a.begin(), a.end(), data.begin() + size);
		for(auto i = size - 1; i >= 1; -- i) refresh(i);
	}
	// O(1)
	void refresh(int i){
		data[i] = TT(data[i << 1], data[i << 1 | 1]);
	}
	// O(log n)
	void set(int p, T x){
		assert(0 <= p && p < n);
		data[p += size] = x;
		for(auto i = 1; i <= log; ++ i) refresh(p >> i);
	}
	// O(log n)
	void update(int p, T x){
		assert(0 <= p && p < n);
		p += size;
		data[p] = TT(data[p], x);
		for(auto i = 1; i <= log; ++ i) refresh(p >> i);
	}
	// O(1)
	T query(int p) const{
		assert(0 <= p && p < n);
		return data[p + size];
	}
	// O(log n)
	T query(int l, int r) const{
		assert(0 <= l && l <= r && r <= n);
		T res_left = T_id, res_right = T_id;
		for(l += size, r += size; l < r; l >>= 1, r >>= 1){
			if(l & 1) res_left = TT(res_left, data[l ++]);
			if(r & 1) res_right = TT(data[-- r], res_right);
		}
		return TT(res_left, res_right);
	}
	// O(1)
	T query_all() const{
		return data[1];
	}
	// pred(sum[l, r)) is T, T, ..., T, F, F, ..., F
	// Returns max r with T
	// O(log n)
	int max_pref(int l, auto pred) const{
		assert(0 <= l && l <= n && pred(T_id));
		if(l == n) return n;
		l += size;
		T sm = T_id;
		do{
			while(~l & 1) l >>= 1;
			if(!pred(TT(sm, data[l]))){
				while(l < size){
					l = l << 1;
					if(pred(TT(sm, data[l]))) sm = TT(sm, data[l ++]);
				}
				return l - size;
			}
			sm = TT(sm, data[l ++]);
		}while((l & -l) != l);
		return n;
	}
	// pred(sum[l, r)) is F, F, ..., F, T, T, ..., T
	// Returns min l with T
	// O(log n)
	int min_suff(int r, auto pred) const{
		assert(0 <= r && r <= n && pred(T_id));
		if(r == 0) return 0;
		r += size;
		T sm = T_id;
		do{
			-- r;
			while(r > 1 && r & 1) r >>= 1;
			if(!pred(TT(data[r], sm))){
				while(r < size){
					r = r << 1 | 1;
					if(pred(TT(data[r], sm))) sm = TT(data[r --], sm);
				}
				return r + 1 - size;
			}
			sm = TT(data[r], sm);
		}while((r & -r) != r);
		return 0;
	}
	template<class output_stream>
	friend output_stream &operator<<(output_stream &out, const segment_tree<T, F> &seg){
		out << "[";
		for(auto i = 0; i < seg.n; ++ i){
			out << seg.query(i);
			if(i != seg.n - 1) out << ", ";
		}
		return out << ']';
	}
};

int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	int n;
	cin >> n;
	vector<array<array<array<int, 2>, 2>, 2>> a(n, {{{-1, -1}, {-1, -1}}});
	for(auto i = 0; i < n - 1; ++ i){
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2, -- x1, -- y1, -- x2, -- y2;
		// out
		a[i][1][0] = {x1, y1};
		a[i][1][1] = {x2, y2};
		// in
		a[i + 1][0][0] = {x1 + 1, y1};
		a[i + 1][0][1] = {x2, y2 + 1};
	}
	auto dist = [&](auto x, auto y){
		return abs(x[0] - y[0]) + abs(x[1] - y[1]);
	};
	const long long inf = numeric_limits<long long>::max() / 4;
	using T = array<array<long long, 2>, 2>;
	auto TT = [&](T x, T y)->T{
		T res{{{inf, inf}, {inf, inf}}};
		for(auto i = 0; i < 2; ++ i){
			for(auto j = 0; j < 2; ++ j){
				for(auto k = 0; k < 2; ++ k){
					ctmin(res[i][k], x[i][j] + y[j][k] + 1);
				}
			}
		}
		return res;
	};
	T T_id = {{{-1, inf}, {inf, -1}}};
	vector<T> init(n - 1, T_id);
	for(auto i = 1; i < n - 1; ++ i){
		for(auto l = 0; l < 2; ++ l){
			for(auto r = 0; r < 2; ++ r){
				init[i][l][r] = dist(a[i][0][l], a[i][1][r]);
			}
		}
	}
	segment_tree seg(init, TT, T_id);
	int qn;
	cin >> qn;
	for(auto qi = 0; qi < qn; ++ qi){
		array<int, 2> q1, q2;
		for(auto i = 0; i < 2; ++ i){
			cin >> q1[i], -- q1[i];
		}
		for(auto i = 0; i < 2; ++ i){
			cin >> q2[i], -- q2[i];
		}
		int l1 = max(q1[0], q1[1]);
		int l2 = max(q2[0], q2[1]);
		if(l1 > l2){
			swap(q1, q2);
			swap(l1, l2);
		}
		if(l1 == l2){
			cout << dist(q1, q2) << "\n";
			continue;
		}
		auto q = seg.query(l1 + 1, l2);
		long long res = inf;
		for(auto i = 0; i < 2; ++ i){
			for(auto j = 0; j < 2; ++ j){
				ctmin(res, q[i][j] + 2 + dist(q1, a[l1][1][i]) + dist(q2, a[l2][0][j]));
			}
		}
		cout << res << "\n";
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