#include "bits/stdc++.h"
using namespace std;

struct dynamic_lazy_segment_tree{

	using B = int; // Base coordinate type
	using L = int; // Lazy type
	using Q = array<int, 2>; // Query type min_cancel, time
	L apply_lazy(const L &lazy, const L &x, array<B, 2> r, array<B, 2> rr){ // r is a subset of rr
		return lazy + x;
	} // update lazy node representing r with rr
	Q merge(const Q &lval, const Q &rval, B l, B m, B r){
		return min(lval, rval);
	} // merge two nodes representing the intervals [l, m) and [m, r)
	Q apply(const Q &val, const L &x, array<B, 2> r, array<B, 2> rr){ // r is a subset of r
		return {val[0] + x, val[1]};
	} // apply to node representing r lazy node representing rr
	pair<L, Q> id{0, {numeric_limits<int>::max() / 2, -1}};
	Q init(B l, B r){
		return {0, l};
	}

	dynamic_lazy_segment_tree *l = 0, *r = 0;
	B low, high;
	L lazy = id.first;
	Q val;
	dynamic_lazy_segment_tree(B low, B high): low(low), high(high), val(init(low, high)){ }
	template<typename IT>
	dynamic_lazy_segment_tree(IT begin, IT end, B low, B high): low(low), high(high){
		assert(end - begin == high - low);
		if(high - low > 1){
			IT inter = begin + (end - begin >> 1);
			B mid = low + (high - low >> 1);
			l = new dynamic_lazy_segment_tree(begin, inter, low, mid);
			r = new dynamic_lazy_segment_tree(inter, end, mid, high);
			val = merge(l->val, r->val, low, mid, high);
		}
		else val = *begin;
	}
	void push(){
		if(!l){
			B mid = low + (high - low >> 1);
			l = new dynamic_lazy_segment_tree(low, mid);
			r = new dynamic_lazy_segment_tree(mid, high);
		}
		if(lazy != id.first){
			l->update(low, high, lazy);
			r->update(low, high, lazy);
			lazy = id.first;
		}
	}
	void update(B ql, B qr, L x){
		if(qr <= low || high <= ql || x == id.first) return;
		if(ql <= low && high <= qr){
			lazy = apply_lazy(lazy, x, {low, high}, {ql, qr});
			val = apply(val, x, {low, high}, {ql, qr});
		}
		else{
			push();
			l->update(ql, qr, x);
			r->update(ql, qr, x);
			B mid = low + (high - low >> 1);
			val = merge(l->val, r->val, low, mid, high);
		}
	}
	Q query(B ql, B qr){
		if(qr <= low || high <= ql) return id.second;
		if(ql <= low && high <= qr) return val;
		push();
		B mid = clamp(low + (high - low >> 1), ql, qr);
		return merge(l->query(ql, qr), r->query(ql, qr), max(low, ql), mid, min(high, qr));
	}
};

int main(){
	cin.tie(0)->sync_with_stdio(0);
	int n, h, m, k;
	cin >> n >> h >> m >> k;
	dynamic_lazy_segment_tree tr(0, m >> 1);
	vector<array<int, 2>> a(n);
	for(auto i = 0; i < n; ++ i){
		int hi, mi;
		cin >> hi >> mi, a[i] = {hi, mi};
		mi %= m >> 1;
		if(mi + k > m >> 1){
			tr.update(mi + 1, m >> 1, 1);
			tr.update(0, (mi + k) - (m >> 1), 1);
		}
		else{
			tr.update(mi + 1, mi + k, 1);
		}
	}
	auto [cancel, t] = tr.query(0, m >> 1);
	cout << cancel << " " << t << "\n";
	for(auto i = 0; i < n; ++ i){
		int mi = a[i][1] % (m >> 1);
		if(mi + k > m >> 1){
			if(mi + 1 <= t || t < (mi + k) - (m >> 1)){
				cout << i + 1 << " ";
			}
		}
		else if(mi + 1 <= t && t < mi + k){
			cout << i + 1 << " ";
		}
	}
	cout << "\n";
	return 0;
}

/*

*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////