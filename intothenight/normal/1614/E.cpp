#include <bits/stdc++.h>
using namespace std;
#if __cplusplus > 201703L
#include <ranges>
using namespace numbers;
#endif

template<class B, class T, class U, class F1, class F2, class F3, class F4, class F5>
struct dynamic_lazy_segment_tree{
	B n; // exclusive upper bound of coordinate
	vector<int> left, right;
	vector<T> data;
	vector<U> updates;
	F1 TT; // monoid operation (always adjacent)
	T T_id; // monoid identity
	F2 T_init;
	F3 UU; // semigroup operation (superset, subset)
	F4 U_init; // semigroup default element for the interval [l, r)
	F5 UT; // action of U on T (superset, subset)
	dynamic_lazy_segment_tree(B n, F1 TT, T T_id, F2 T_init, F3 UU, F4 U_init, F5 UT, U): n(n), TT(TT), T_id(T_id), T_init(T_init), UU(UU), U_init(U_init), UT(UT){
		new_state(-1, -1, T_init(0, n), U_init(0, n));
	}
	void extend(int u, B l, B r){
		if(!~left[u]){
			B m = l + (r - l >> 1);
			left[u] = new_state(-1, -1, T_init(l, m), U_init(l, m)); // Separate this on C++14 or below to avoid UB
			right[u] = new_state(-1, -1, T_init(m, r), U_init(m, r)); // Separate this on C++14 or below to avoid UB
		}
	}
	void push(int u, B l, B r){
		int m = l + (r - l >> 1), v = left[u], w = right[u];
		data[v] = UT(updates[u], data[v]);
		updates[v] = UU(updates[u], updates[v]);
		data[w] = UT(updates[u], data[w]);
		updates[w] = UU(updates[u], updates[w]);
		updates[u] = U_init(l, r);
	}
	void refresh(int u, B l, B r){
		data[u] = UT(updates[u], TT(data[left[u]], data[right[u]]));
	}
	int last_state(){
		return (int)data.size() - 1;
	}
	int new_state(int v, int w, T x, U y){
		left.push_back(v), right.push_back(w), data.push_back(x), updates.push_back(y);
		return last_state();
	}
	// O(log(n))
	void update(B ql, B qr, U x){
		assert(0 <= ql && ql <= qr && qr <= n);
		auto recurse = [&](auto recurse, int u, B l, B r)->void{
			if(qr <= l || r <= ql) return;
			if(ql <= l && r <= qr){
				data[u] = UT(x, data[u]), updates[u] = UU(x, updates[u]);
				return;
			}
			extend(u, l, r), push(u, l, r);
			B m = l + (r - l >> 1);
			recurse(recurse, left[u], l, m), recurse(recurse, right[u], m, r);
			refresh(u, l, r);
		};
		recurse(recurse, 0, 0, n);
	}
	// O(log(n))
	T query(B ql, B qr){
		assert(0 <= ql && ql <= qr && qr <= n);
		auto recurse = [&](auto recurse, int u, B l, B r)->T{
			if(qr <= l || r <= ql) return T_id;
			if(ql <= l && r <= qr) return data[u];
			extend(u, l, r), push(u, l, r);
			B m = l + (r - l >> 1);
			return TT(recurse(recurse, left[u], l, m), recurse(recurse, right[u], m, r));
		};
		return recurse(recurse, 0, 0, n);
	}
	// pred(sum[l, r)) is T, T, ..., T, F, F, ..., F
	// Returns max r with T
	// O(log(n))
	B max_pref(B ql, auto pred){
		assert(pred(T_id));
		if(ql == n) return ql;
		T pref = T_id;
		auto recurse = [&](auto self, int u, B l, B r)->B{
			if(r <= ql) return -1;
			if(ql <= l && pred(TT(pref, data[u]))){
				pref = TT(pref, data[u]);
				return -1;
			}
			if(r - l == 1) return l;
			extend(u, l, r), push(u, l, r);
			B m = l + (r - l >> 1), p = self(self, left[u], l, m);
			return ~p ? p : self(self, right[u], m, r);
		};
		B qr = recurse(recurse, 0, 0, n);
		if(!~qr) qr = n;
		return qr;
	}
	// pred(sum[l, r)) is F, F, ..., F, T, T, ..., T
	// Returns min l with T
	// O(log(n))
	B min_suff(B qr, auto pred){
		assert(pred(T_id));
		if(qr == 0) return qr;
		T suff = T_id;
		auto recurse = [&](auto self, int u, B l, B r)->B{
			if(qr <= l) return -1;
			if(r <= qr && pred(TT(data[u], suff))){
				suff = TT(data[u], suff);
				return -1;
			}
			if(r - l == 1) return r;
			extend(u, l, r), push(u, l, r);
			B m = l + (r - l >> 1), p = self(self, right[u], m, r);
			return ~p ? p : self(self, left[u], l, m);
		};
		B ql = recurse(recurse, 0, 0, n);
		if(!~ql) ql = 0;
		return ql;
	}
	template<class output_stream>
	friend output_stream &operator<<(output_stream &out, dynamic_lazy_segment_tree<B, T, U, F1, F2, F3, F4, F5> seg){
		out << "[";
		for(auto i = 0; i < seg.n; ++ i){
			out << seg.query(i, i + 1);
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
	#ifdef LOCAL
	const int mx = 100;
	#else
	const int mx = 1000000001;
	#endif
	using T = array<int, 2>; // min, max
	auto TT = [&](const T &x, const T &y)->T{
		return {min(x[0], y[0]), max(x[1], y[1])};
	};
	T T_id{numeric_limits<int>::max() / 2, numeric_limits<int>::min() / 2};
	auto T_init = [&](int l, int r)->T{
		return {l, r - 1};
	};
	auto U_init = [&](int, int)->int{
		return 0;
	};
	auto UT = [&](int f, const T &x)->T{
		return {x[0] + f, x[1] + f};
	};
	dynamic_lazy_segment_tree state(mx, TT, T_id, T_init, plus<>(), U_init, UT, 0);
	for(auto i = 0; i < n; ++ i){
		int t, qn;
		cin >> t >> qn;
		int r = state.min_suff(mx, [&](auto sum){ return sum[0] > t; });
		int l = state.min_suff(r, [&](auto sum){ return sum[0] >= t; });
		state.update(0, l, 1);
		state.update(r, mx, -1);
		for(auto qi = 0; qi < qn; ++ qi){
			static int last = 0;
			int x;
			cin >> x;
			x = (last + x) % 1000000001;
			cout << (last = state.query(x, x + 1)[0]) << "\n";
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