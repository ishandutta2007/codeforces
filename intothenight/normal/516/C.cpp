#include <bits/stdc++.h>
using namespace std;

template<class Q, Q (*merge)(Q, Q), Q (*identity)()>
struct segment_tree_base{
	segment_tree_base(): segment_tree_base(0){}
	segment_tree_base(int n): segment_tree_base(vector<Q>(n)){}
	segment_tree_base(const vector<Q> &v): n((int)v.size()){ // O(n)
		log = __lg(n + 1) + 1, size = 1 << log;
		tree = vector<Q>(size << 1, identity());
		copy(v.begin(), v.end(), tree.begin() + size);
		for(int i = size - 1; i >= 1; -- i) refresh(i);
	}
	void set(int p, Q x){ // O(log n)
		assert(0 <= p && p < n);
		tree[p += size] = x;
		for(int i = 1; i <= log; ++ i) refresh(p >> i);
	}
	Q query(int p){ // O(1)
		assert(0 <= p && p < n);
		return tree[p + size];
	}
	Q query(int l, int r){ // O(log n)
		assert(0 <= l && l <= r && r <= n);
		Q sml = identity(), smr = identity();
		for(l += size, r += size; l < r; l >>= 1, r >>= 1){
			if(l & 1) sml = merge(sml, tree[l ++]);
			if(r & 1) smr = merge(tree[-- r], smr);
		}
		return merge(sml, smr);
	}
	Q query_all(){ return tree[1]; } // O(1)
	template<class F> int max_pref(int l, F f){ // O(log n)
		assert(0 <= l && l <= n);
		if(l == n) return n;
		l += size;
		Q sm = identity();
		do{
			while(~l & 1) l >>= 1;
			if(!f(merge(sm, tree[l]))){
				while(l < size){
					l = l << 1;
					if(f(merge(sm, tree[l]))) sm = merge(sm, tree[l ++]);
				}
				return l - size;
			}
			sm = merge(sm, tree[l ++]);
		}while((l & -l) != l);
		return n;
	} // f(sum[l, r)) is T, T, ..., T, F, F, ..., F, returns max r with T
	template<class F> int min_suff(int r, F f){ // O(log n)
		assert(0 <= r && r <= n);
		if(r == 0) return 0;
		r += size;
		Q sm = identity();
		do{
			-- r;
			while (r > 1 && r & 1) r >>= 1;
			if(!f(merge(tree[r], sm))){
				while(r < size){
					r = r << 1 | 1;
					if(f(merge(tree[r], sm))) sm = merge(tree[r --], sm);
				}
				return r + 1 - size;
			}
			sm = merge(tree[r], sm);
		}while((r & -r) != r);
		return 0;
	} // f(sum[l, r)) is F, F, ..., F, T, T, ..., T, returns min l with T
	int n, size, log;
	vector<Q> tree;
	void refresh(int i){ tree[i] = merge(tree[i << 1], tree[i << 1 | 1]); }
};
struct Q{
	long long ans = numeric_limits<long long>::min() / 3, pref = numeric_limits<long long>::min() / 3, suff = numeric_limits<long long>::min() / 3, len = 0, dist = 0;
};
Q merge(Q x, Q y){ // merges adjacent intervals
	return {max({x.ans, y.ans, x.suff + y.pref + x.dist}), max(x.pref, x.len + x.dist + y.pref), max(x.suff + x.dist + y.len, y.suff), x.len + y.len + x.dist, y.dist};
}
Q identity(){ // Monoid Identity
	return {};
}
using segment_tree = segment_tree_base<Q, merge, identity>;

int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	int n, qn;
	cin >> n >> qn;
	vector<Q> a(n);
	for(auto i = 0; i < n; ++ i){
		cin >> a[i].dist;
	}
	for(auto i = 0; i < n; ++ i){
		int h;
		cin >> h;
		a[i].pref = a[i].suff = 2 * h;
	}
	segment_tree seg(a);
	for(auto qi = 0; qi < qn; ++ qi){
		int l, r;
		cin >> l >> r, -- l, -- r;
		if(l <= r){
			cout << merge(seg.query(r + 1, n), seg.query(0, l)).ans << "\n";
		}
		else{
			cout << seg.query(r + 1, l).ans << "\n";
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