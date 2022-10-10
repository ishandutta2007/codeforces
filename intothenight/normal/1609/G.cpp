#include <bits/stdc++.h>
using namespace std;

template<class T, class U, class F1, class F2, class F3, class F4>
struct lazy_segment_tree{
	int n, size, log;
	vector<T> data;
	vector<U> updates;
	F1 TT; // monoid operation (always adjacent)
	T T_id; // monoid identity
	F2 UU; // semigroup operation (superset, subset)
	F3 U_init; // semigroup default element for the interval [l, r)
	F4 UT; // action of U on T (superset, subset)
	lazy_segment_tree(int n, F1 TT, T T_id, F2 UU, F3 U_init, F4 UT, U _type_deducer): lazy_segment_tree(vector<T>(n, T_id), TT, T_id, UU, U_init, UT, _type_deducer){ }
	lazy_segment_tree(int n, T init, F1 TT, T T_id, F2 UU, F3 U_init, F4 UT, U _type_deducer): lazy_segment_tree(vector<T>(n, init), TT, T_id, UU, U_init, UT, _type_deducer){ }
	lazy_segment_tree(const vector<T> &a, F1 TT, T T_id, F2 UU, F3 U_init, F4 UT, U): n((int)a.size()), TT(TT), T_id(T_id), UU(UU), U_init(U_init), UT(UT){ // O(n)
		log = __lg(max(n - 1, 1)) + 1, size = 1 << log;
		data = vector<T>(size << 1, T_id), updates = vector<U>(size);
		copy(a.begin(), a.end(), data.begin() + size);
		for(auto i = 1; i < size; ++ i){
			int h = log - __lg(i);
			updates[i] = U_init((i << h) - size, (i + 1 << h) - size);
		}
		for(auto i = size - 1; i >= 1; -- i) refresh(i);
	}
	void refresh(int i){
		data[i] = TT(data[i << 1], data[i << 1 | 1]);
	}
	void apply(int i, U f){
		data[i] = UT(f, data[i]);
		if(i < size) updates[i] = UU(f, updates[i]);
	}
	void push(int i){
		apply(i << 1, updates[i]), apply(i << 1 | 1, updates[i]);
		int h = log - __lg(i);
		updates[i] = U_init((i << h) - size, (i + 1 << h) - size);
	}
	// O(log n)
	T query(int p){
		assert(0 <= p && p < n);
		p += size;
		for(auto i = log; i >= 1; -- i) push(p >> i);
		return data[p];
	}
	// O(log n)
	T query(int l, int r){
		assert(0 <= l && l <= r && r <= n);
		if(l == r) return T_id;
		l += size, r += size;
		for(auto i = log; i >= 1; -- i) {
			if(l >> i << i != l) push(l >> i);
			if(r >> i << i != r) push(r - 1 >> i);
		}
		T res_left = T_id, res_right = T_id;
		for(; l < r; l >>= 1, r >>= 1){
			if(l & 1) res_left = TT(res_left, data[l ++]);
			if(r & 1) res_right = TT(data[-- r], res_right);
		}
		return TT(res_left, res_right);
	}
	// O(1)
	T query_all(){
		return data[1];
	}
	// O(log n)
	void set(int p, T x){
		assert(0 <= p && p < n);
		p += size;
		for(auto i = log; i >= 1; -- i) push(p >> i);
		data[p] = x;
		for(auto i = 1; i <= log; ++ i) refresh(p >> i);
	}
	// O(log n)
	void update(int p, U f){
		assert(0 <= p && p < n);
		p += size;
		for(auto i = log; i >= 1; -- i) push(p >> i);
		data[p] = UT(f, data[p]);
		for(auto i = 1; i <= log; ++ i) refresh(p >> i);
	}
	// O(log n)
	void update(int l, int r, U f){
		assert(0 <= l && l <= r && r <= n);
		if(l == r) return;
		l += size, r += size;
		for(auto i = log; i >= 1; -- i){
			if(l >> i << i != l) push(l >> i);
			if(r >> i << i != r) push(r - 1 >> i);
		}
		int l2 = l, r2 = r;
		for(; l < r; l >>= 1, r >>= 1){
			if(l & 1) apply(l ++, f);
			if(r & 1) apply(-- r, f);
		}
		l = l2, r = r2;
		for(auto i = 1; i <= log; ++ i){
			if(l >> i << i != l) refresh(l >> i);
			if(r >> i << i != r) refresh(r - 1 >> i);
		}
	}
	// pred(sum[l, r)) is T, T, ..., T, F, F, ..., F
	// Returns max r with T
	// O(log n)
	int max_pref(int l, auto pred){
		assert(0 <= l && l <= n);
		assert(pred(T_id));
		if(l == n) return n;
		l += size;
		for(auto i = log; i >= 1; -- i) push(l >> i);
		T sum = T_id;
		do{
			while(~l & 1) l >>= 1;
			if(!pred(TT(sum, data[l]))){
				while(l < size){
					push(l);
					l = l << 1;
					if(pred(TT(sum, data[l]))) sum = TT(sum, data[l ++]);
				}
				return l - size;
			}
			sum = TT(sum, data[l]);
			++ l;
		}while((l & -l) != l);
		return n;
	}
	// pred(sum[l, r)) is F, F, ..., F, T, T, ..., T
	// Returns min l with T
	// O(log n)
	int min_suff(int r, auto pred){
		assert(0 <= r && r <= n && pred(T_id));
		if(r == 0) return 0;
		r += size;
		for(auto i = log; i >= 1; -- i) push(r - 1 >> i);
		T sum = T_id;
		do{
			-- r;
			while(r > 1 && r & 1) r >>= 1;
			if(!pred(TT(data[r], sum))){
				while(r < size){
					push(r);
					r = r << 1 | 1;
					if(pred(TT(data[r], sum))) sum = TT(data[r --], sum);
				}
				return r - size + 1;
			}
			sum = TT(data[r], sum);
		}while((r & -r) != r);
		return 0;
	}
	template<class output_stream>
	friend output_stream &operator<<(output_stream &out, lazy_segment_tree<T, U, F1, F2, F3, F4> seg){
		out << "[";
		for(auto i = 0; i < seg.n; ++ i){
			out << seg.query(i);
			if(i != seg.n - 1) out << ", ";
		}
		return out << ']';
	}
};

struct T{
	int len = 0;
	long long coef = 0;
	long long d = 0;
	long long res = 0;
	long long dmax = numeric_limits<long long>::min() / 2;
	friend ostream &operator<<(ostream &out, const T &x){
		return out << "[len: " << x.len << ", coef: " << x.coef << ", d: " << x.d << ", res: " << x.res << ", dmax: " << x.dmax << "]";
	}
};

int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	int n, m, qn;
	cin >> n >> m >> qn;
	vector<long long> a(n), b(m), c(n - 1), d(m - 1);
	long long init = 0;
	for(auto i = 0; i < n; ++ i){
		cin >> a[i];
	}
	for(auto i = 0; i < n - 1; ++ i){
		c[i] = a[i + 1] - a[i];
	}
	for(auto j = 0; j < m; ++ j){
		cin >> b[j];
	}
	for(auto j = 0; j < m - 1; ++ j){
		d[j] = b[j + 1] - b[j];
	}
	int plen = n - 1 + m - 1;
	long long col_res = (a[0] + b[0]) * (plen + 1);
	vector<int> pos(n - 1);
	for(auto i = 0; i < n - 1; ++ i){
		pos[i] = lower_bound(d.begin(), d.end(), c[i]) - d.begin();
		col_res += (plen - pos[i] - i) * c[i];
	}
	auto TT = [&](T x, T y)->T{
		return {
			x.len + y.len,
			x.coef + y.coef,
			x.d + y.d,
			x.res + y.res,
			max(x.dmax, y.dmax)
		};
	};
	using U = array<long long, 2>;
	auto UU = [&](U x, U y)->U{
		return {x[0] + y[0], x[1] + y[1]};
	};
	auto U_init = [&](int, int)->U{
		return {0, 0};
	};
	auto UT = [&](U f, T x)->T{
		return {
			x.len,
			x.coef + f[0] * x.len,
			x.d + f[1] * x.len,
			x.res + f[1] * x.coef + f[0] * x.d + x.len * f[0] * f[1],
			x.dmax + f[1]
		};
	};
	vector<T> init_row(m - 1);
	for(auto j = 0; j < m - 1; ++ j){
		int pos = upper_bound(c.begin(), c.end(), d[j]) - c.begin();
		init_row[j].len = 1;
		init_row[j].coef = plen - pos - j;
		init_row[j].d = d[j];
		init_row[j].res = (plen - pos - j) * d[j];
		init_row[j].dmax = d[j];
	}
	lazy_segment_tree lseg(init_row, TT, T{}, UU, U_init, UT, U{});
	for(auto qi = 0; qi < qn; ++ qi){
		int type, len, delta;
		cin >> type >> len >> delta;
		if(type == 1){
			int l = max(n - 1 - len, 0);
			for(auto i = n - 2; i >= l; -- i){
				col_res -= (plen - pos[i] - i) * c[i];
				c[i] += delta;
				int npos = lseg.max_pref(pos[i], [&](const auto &x){
					return x.dmax < c[i];
				});
				col_res += (plen - npos - i) * c[i];
				lseg.update(pos[i], npos, {1, 0});
				pos[i] = npos;
			}
			if(len == n){
				col_res += delta * (plen + 1);
			}
		}
		else{
			int l = max(m - 1 - len, 0);
			lseg.update(l, m - 1, {0, delta});
			for(auto i = 0; i < n - 1; ++ i){
				col_res -= (plen - pos[i] - i) * c[i];
				int npos = lseg.max_pref(0, [&](const auto &x){
					return x.dmax < c[i];
				});
				col_res += (plen - npos - i) * c[i];
				lseg.update(npos, pos[i], {-1, 0});
				pos[i] = npos;
			}
			if(len == m){
				col_res += delta * (plen + 1);
			}
		}
		cout << col_res + lseg.query_all().res << "\n";
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