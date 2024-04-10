#include <bits/stdc++.h>
using namespace std;

template<typename Q>
struct segment_tree{
	segment_tree(): segment_tree(0){}
	segment_tree(int n): segment_tree(vector<Q>(n)){}
	segment_tree(const vector<Q> &v): n((int)v.size()){
		log = __lg(n + 1) + 1;
		size = 1 << log;
		val = vector<Q>(size << 1);
		for(int i = 0; i < n; ++ i) val[size + i] = v[i];
		for(int i = size - 1; i >= 1; -- i) update(i);
	}
	void update(int p, Q x){
		assert(0 <= p && p < n);
		p += size;
		val[p] = x;
		for(int i = 1; i <= log; ++ i) update(p >> i);
	}
	Q query(int p){
		assert(0 <= p && p < n);
		return val[p + size];
	}
	Q query(int l, int r){
		assert(0 <= l && l <= r && r <= n);
		Q sml{}, smr{};
		l += size, r += size;
		for(; l < r; l >>= 1, r >>= 1){
			if(l & 1) sml = sml + val[l ++];
			if(r & 1) smr = val[-- r] + smr;
		}
		return op(sml, smr);
	}
	Q query_all(){ return val[1]; }
	template<typename F> int partition_point_pref(int l, F f){
		assert(0 <= l && l <= n);
		if(l == n) return n;
		l += size;
		Q sm{};
		do{
			while(~l & 1) l >>= 1;
			if(!f(sm + val[l])){
				while(l < size){
					l = l << 1;
					if(f(sm + val[l])) sm = sm + val[l ++];
				}
				return l - size;
			}
			sm = sm + val[l ++];
		}while((l & -l) != l);
		return n;
	} // f(sum[l, r)) is T, T, ..., T, F, F, ..., F, returns max r with T
	template<typename F> int partition_point_suff(int r, F f){
		assert(0 <= r && r <= n);
		if(r == 0) return 0;
		r += size;
		Q sm{};
		do{
			-- r;
			while (r > 1 && r & 1) r >>= 1;
			if(!f(val[r] + sm)){
				while(r < size){
					r = r << 1 | 1;
					if(f(val[r] + sm)) sm = val[r --] + sm;
				}
				return r + 1 - size;
			}
			sm = val[r] + sm;
		}while((r & -r) != r);
		return 0;
	} // f(sum[l, r)) is F, F, ..., F, T, T, ..., T, returns min l with T
	int n, size, log;
	vector<Q> val;
	void update(int i){ val[i] = val[i << 1] + val[i << 1 | 1]; }
};

struct Q{ // Monoid (Query type) / Default value is the identity
	int val = 0;
	Q operator+(const Q &x) const{
		return {val + x.val};
	} // Monoid operator, always merges adjacent intervals
};

int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	int n, qq;
	cin >> n >> qq;
	vector<int> cnt(n);
	for(auto i = 0; i < n; ++ i){
		int x;
		cin >> x, -- x;
		++ cnt[x];
	}
	segment_tree seg(cnt);
	while(qq --){
		int k;
		cin >> k;
		if(k > 0){
			-- k;
			seg.update(k, seg.query(k) + 1);
		}
		else{
			k = -k - 1;
			int i = seg.partition_point_pref(0, [&](int s){ return s <= k; });
			seg.update(i, seg.query(i) - 1);
		}
	}
	cout << (seg.partition_point_pref(0, [&](int s){ return s <= 0; }) + 1) % (n + 1) << "\n";
	return 0;
}

/*

*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////