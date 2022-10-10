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
	template<class G> int partition_point_pref(int l, G g){ // O(log n)
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
	template<class G> int partition_point_suff(int r, G g){ // O(log n)
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
using Q = int; // Monoid (Query Type)
Q merge(Q x, Q y){ // merges adjacent intervals
	return max(x, y);
}
Q identity(){ // Monoid Identity
	return 0;
}
using L = int; // Semigroup (Lazy Type)
L composite(L f, L g){ // composites superset and subset 
	return f + g;
}
L identity_action(int l, int r){
	return 0;
}
Q act(L f, Q x){ // semigroup action of L on Q, act superset onto subset
	return f + x;
}
// lazy_segment_tree<Q, merge, identity, L, composite, identity_action, act> seg(a);

int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	int n;
	cin >> n;
	vector<int> pos(n);
	for(auto i = 0; i < n; ++ i){
		int x;
		cin >> x, -- x;
		pos[x] = i;
	}
	int cur = n - 1;
	lazy_segment_tree<Q, merge, identity, L, composite, identity_action, act> seg(n);
	seg.update(0, pos[cur] + 1, 1);
	for(auto rep = 0; rep < n; ++ rep){
		while(seg.query_all() <= 0){
			-- cur;
			seg.update(0, pos[cur] + 1, 1);
		}
		cout << cur + 1 << " ";
		int p;
		cin >> p, -- p;
		seg.update(0, p + 1, -1);
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