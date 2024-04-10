#include <bits/stdc++.h>
using namespace std;



template<class Q,
					Q (*merge)(Q, Q),
					Q (*identity)(),
					class L,
					L (*composite)(L, L),
					L (*identity_action)(int, int),
					Q (*act)(L, Q)>
struct lazy_segment_tree{
	lazy_segment_tree(): lazy_segment_tree(0){}
	lazy_segment_tree(int n): lazy_segment_tree(vector<Q>(n)){}
	lazy_segment_tree(const vector<Q> &v): n((int)v.size()){ // O(n)
		log = __lg(n + 1) + 1, size = 1 << log;
		val = vector<Q>(size << 1, identity()), lazy = vector<L>(size);
		copy(v.begin(), v.end(), val.begin() + size);
		for(int i = 1; i < size; ++ i){
			int h = log - __lg(i);
			lazy[i] = identity_action((i << h) - size, (i + 1 << h) - size);
		}
		for(int i = size - 1; i >= 1; -- i) refresh(i);
	}
	Q query(int p){ // O(log n)
		assert(0 <= p && p < n);
		p += size;
		for(int i = log; i >= 1; -- i) push(p >> i);
		return val[p];
	}
	Q query(int l, int r){ // O(log n)
		assert(0 <= l && l <= r && r <= n);
		if(l == r) return identity();
		l += size, r += size;
		for(int i = log; i >= 1; -- i) {
			if(l >> i << i != l) push(l >> i);
			if(r >> i << i != r) push(r - 1 >> i);
		}
		Q sml = identity(), smr = identity();
		for(; l < r; l >>= 1, r >>= 1){
			if(l & 1) sml = merge(sml, val[l ++]);
			if(r & 1) smr = merge(val[-- r], smr);
		}
		return merge(sml, smr);
	}
	Q query_all(){ return val[1]; } // O(1)
	void set(int p, Q x){ // O(log n)
		assert(0 <= p && p < n);
		p += size;
		for(int i = log; i >= 1; -- i) push(p >> i);
		val[p] = x;
		for(int i = 1; i <= log; ++ i) refresh(p >> i);
	}
	void update(int p, L f){ // O(log n)
		assert(0 <= p && p < n);
		p += size;
		for(int i = log; i >= 1; -- i) push(p >> i);
		val[p] = act(f, val[p]);
		for(int i = 1; i <= log; ++ i) refresh(p >> i);
	}
	void update(int l, int r, L f){ // O(log n)
		assert(0 <= l && l <= r && r <= n);
		if(l == r) return;
		l += size, r += size;
		for(int i = log; i >= 1; -- i){
			if(l >> i << i != l) push(l >> i);
			if(r >> i << i != r) push(r - 1 >> i);
		}
		int l2 = l, r2 = r;
		for(; l < r; l >>= 1, r >>= 1){
			if(l & 1) apply(l ++, f);
			if(r & 1) apply(-- r, f);
		}
		l = l2, r = r2;
		for(int i = 1; i <= log; ++ i){
			if(l >> i << i != l) refresh(l >> i);
			if(r >> i << i != r) refresh(r - 1 >> i);
		}
	}
	template<class G> int max_pref(int l, G g){ // O(log n)
		assert(0 <= l && l <= n), assert(g(identity()));
		if(l == n) return n;
		l += size;
		for(int i = log; i >= 1; -- i) push(l >> i);
		Q sm = identity();
		do{
			while(~l & 1) l >>= 1;
			if(!g(merge(sm, val[l]))){
				while(l < size){
					push(l);
					l = l << 1;
					if(g(merge(sm, val[l]))) sm = merge(sm, val[l ++]);
				}
				return l - size;
			}
			sm = merge(sm, val[l]);
			++ l;
		}while((l & -l) != l);
		return n;
	} // f(sum[l, r)) is T, T, ..., T, F, F, ..., F, returns max r with T
	template<class G> int min_suff(int r, G g){ // O(log n)
		assert(0 <= r && r <= n), assert(g(identity()));
		if(r == 0) return 0;
		r += size;
		for(int i = log; i >= 1; -- i) push(r - 1 >> i);
		Q sm = identity();
		do{
			-- r;
			while(r > 1 && r & 1) r >>= 1;
			if(!g(merge(val[r], sm))){
				while(r < size){
					push(r);
					r = r << 1 | 1;
					if(g(merge(val[r], sm))) sm = merge(val[r --], sm);
				}
				return r + 1 - size;
			}
			sm = merge(val[r], sm);
		}while((r & -r) != r);
		return 0;
	} // f(sum[l, r)) is F, F, ..., F, T, T, ..., T, returns min l with T
	int n, size, log;
	vector<Q> val;
	vector<L> lazy;
	void refresh(int i){ val[i] = merge(val[i << 1], val[i << 1 | 1]); }
	void apply(int i, L f){
		val[i] = act(f, val[i]);
		if(i < size) lazy[i] = composite(f, lazy[i]);
	}
	void push(int i){
		apply(i << 1, lazy[i]), apply(i << 1 | 1, lazy[i]);
		int h = log - __lg(i);
		lazy[i] = identity_action((i << h) - size, (i + 1 << h) - size);
	}
};
struct Q{
	long long sum;
	int len, min;
};
Q merge(Q x, Q y){ // merges adjacent intervals
	return {x.sum + y.sum, x.len + y.len, min(x.min, y.min)};
}
Q identity(){ // Monoid Identity
	return {0, 0, numeric_limits<int>::max()};
}
using L = int; // Semigroup (Lazy Type)
L composite(L f, L g){ // composites superset and subset 
	return ~f ? f : g;
}
L identity_action(int l, int r){
	return -1;
}
Q act(L f, Q x){ // semigroup action of L on Q, act superset onto subset
	if(~f) x.sum = 1LL * f * x.len, x.min = f;
	return x;
}
// lazy_segment_tree<Q, merge, identity, L, composite, identity_action, act> seg(a);

int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	int n, qn;
	cin >> n >> qn;
	vector<Q> init(n);
	for(auto i = 0; i < n; ++ i){
		cin >> init[i].sum;
		init[i].len = 1, init[i].min = init[i].sum;
	}
	lazy_segment_tree<Q, merge, identity, L, composite, identity_action, act> seg(init);
	for(auto qi = 0; qi < qn; ++ qi){
		int type;
		cin >> type;
		if(type == 1){
			int r, x;
			cin >> r >> x;
			if(seg.query_all().min < x){
				int l = seg.max_pref(0, [&](auto sum){ return sum.min >= x; });
				if(l < r){
					seg.update(l, r, x);
				}
			}
		}
		else{
			int l, x;
			cin >> l >> x, -- l;
			int res = 0;
			while(l < n && seg.query_all().min <= x){
				l = seg.max_pref(l, [&](auto sum){ return sum.min > x; });
				int r = seg.max_pref(l, [&](auto sum){ return sum.sum <= x; });
				x -= seg.query(l, r).sum;
				res += r - l;
				l = r;
			}
			cout << res << "\n";
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