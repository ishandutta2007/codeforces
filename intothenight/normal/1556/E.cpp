#include <bits/stdc++.h>
using namespace std;

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
	// f(sum[l, r)) is T, T, ..., T, F, F, ..., F, returns min r with F (n + 1 if no such r)
	// O(log n)
	int max_pref(int l, auto f) const{
		assert(0 <= l && l <= n);
		if(!f(T_id)) return l;
		// if(l == n) return n + 1; // is this needed?
		l += size;
		T sm = T_id;
		do{
			while(~l & 1) l >>= 1;
			if(!f(TT(sm, data[l]))){
				while(l < size){
					l = l << 1;
					if(f(TT(sm, data[l]))) sm = TT(sm, data[l ++]);
				}
				return l - size + 1;
			}
			sm = TT(sm, data[l ++]);
		}while((l & -l) != l);
		return n + 1;
	}
	// f(sum[l, r)) is F, F, ..., F, T, T, ..., T, returns max l with F (-1 if no such l)
	// O(log n)
	int min_suff(int r, auto f) const{
		assert(0 <= r && r <= n);
		if(!f(T_id)) return r;
		// if(r == 0) return -1; // is this needed?
		r += size;
		T sm = T_id;
		do{
			-- r;
			while(r > 1 && r & 1) r >>= 1;
			if(!f(TT(data[r], sm))){
				while(r < size){
					r = r << 1 | 1;
					if(f(TT(data[r], sm))) sm = TT(data[r --], sm);
				}
				return r - size;
			}
			sm = TT(data[r], sm);
		}while((r & -r) != r);
		return -1;
	}
};

int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	int n, qn;
	cin >> n >> qn;
	vector<int> a(n);
	for(auto i = 0; i < n; ++ i){
		cin >> a[i];
	}
	for(auto i = 0; i < n; ++ i){
		int x;
		cin >> x;
		a[i] = x - a[i];
	}
	struct T{
		long long balance = 0;
		long long min_pref = 0;
		long long max_pref = 0;
		T(){}
		T(int x){
			balance = x;
			min_pref = min<long long>(min_pref, x);
			max_pref = max<long long>(max_pref, x);
		}
		T(long long a, long long b, long long c): balance(a), min_pref(b), max_pref(c){ }
	};
	auto TT = [&](T x, T y)->T{
		return {x.balance + y.balance, min(x.min_pref, x.balance + y.min_pref), max(x.max_pref, x.balance + y.max_pref)};
	};
	vector<T> init(n);
	for(auto i = 0; i < n; ++ i){
		init[i] = {a[i]};
	}
	segment_tree ds(init, TT, T{});
	for(auto qi = 0; qi < qn; ++ qi){
		int l, r;
		cin >> l >> r, -- l;
		auto res = ds.query(l, r);
		if(res.balance == 0 && res.min_pref == 0){
			cout << res.max_pref << "\n";
		}
		else{
			cout << "-1\n";
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