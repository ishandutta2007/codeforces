#include <bits/stdc++.h>
using namespace std;

// Queries return a pair where the second number is the last occuring position.
template<class T, class U>
struct lazy_segment_tree_range_add_range_min_index{
	int n, size, log;
	T inf = numeric_limits<T>::max() / 2;
	vector<pair<T, int>> data;
	vector<U> updates;
	lazy_segment_tree_range_add_range_min_index(int n): lazy_segment_tree_range_add_range_min_index(vector<T>(n, numeric_limits<T>::max() / 2)){  }
	lazy_segment_tree_range_add_range_min_index(int n, T init): lazy_segment_tree_range_add_range_min_index(vector<T>(n, init)){  }
	lazy_segment_tree_range_add_range_min_index(const vector<T> &a): n((int)a.size()){ // O(n)
		log = __lg(max(n - 1, 1)) + 1, size = 1 << log;
		data = vector<pair<T, int>>(size << 1, {inf, numeric_limits<int>::max()}), updates = vector<U>(size);
		for(auto i = 0; i < n; ++ i) data[i + size] = pair<T, int>{a[i], -i};
		for(auto i = size - 1; i >= 1; -- i) refresh(i);
	}
	void refresh(int i){
		data[i] = min(data[i << 1], data[i << 1 | 1]);
	}
	void apply(int i, U f){
		data[i].first += f;
		if(i < size) updates[i] += f;
	}
	void push(int i){
		apply(i << 1, updates[i]), apply(i << 1 | 1, updates[i]);
		updates[i] = 0;
	}
	// O(log n)
	pair<T, int> query(int p){
		assert(0 <= p && p < n);
		p += size;
		for(auto i = log; i >= 1; -- i) push(p >> i);
		return {data[p].first, -data[p].second};
	}
	// O(log n)
	pair<T, int> query(int l, int r){
		assert(0 <= l && l <= r && r <= n);
		if(l == r) return {inf, -1};
		l += size, r += size;
		for(auto i = log; i >= 1; -- i) {
			if(l >> i << i != l) push(l >> i);
			if(r >> i << i != r) push(r - 1 >> i);
		}
		pair<T, int> res{inf, -1};
		for(; l < r; l >>= 1, r >>= 1){
			if(l & 1) res = min(res, data[l ++]);
			if(r & 1) res = min(data[-- r], res);
		}
		return {res.first, -res.second};
	}
	// O(1)
	pair<T, int> query_all(){
		return {data[1].first, -data[1].second};
	}
	// O(log n)
	void set(int p, T x){
		assert(0 <= p && p < n);
		p += size;
		for(auto i = log; i >= 1; -- i) push(p >> i);
		data[p].first = x;
		for(auto i = 1; i <= log; ++ i) refresh(p >> i);
	}
	// O(log n)
	void update(int p, U f){
		assert(0 <= p && p < n);
		p += size;
		for(auto i = log; i >= 1; -- i) push(p >> i);
		data[p].first += f;
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
	// f(sum[l, r)) is T, T, ..., T, F, F, ..., F, returns min r with F (n + 1 if no such r)
	// O(log n)
	int max_pref(int l, auto g){
		assert(0 <= l && l <= n);
		if(!g(pair<T, int>{inf, -1})) return l;
		// if(l == n) return n + 1; // is this needed?
		l += size;
		for(auto i = log; i >= 1; -- i) push(l >> i);
		pair<T, int> sm{inf, -1};
		do{
			while(~l & 1) l >>= 1;
			if(!g(min(sm, data[l]))){
				while(l < size){
					push(l);
					l = l << 1;
					if(g(min(sm, data[l]))) sm = min(sm, data[l ++]);
				}
				return l - size + 1;
			}
			sm = min(sm, data[l]);
			++ l;
		}while((l & -l) != l);
		return n + 1;
	}
	// f(sum[l, r)) is F, F, ..., F, T, T, ..., T, returns max l with F (-1 if no such l)
	// O(log n)
	int min_suff(int r, auto g){
		assert(0 <= r && r <= n);
		if(!g(pair<T, int>{inf, -1})) return r;
		// if(r == 0) return -1; // is this needed?
		r += size;
		for(auto i = log; i >= 1; -- i) push(r - 1 >> i);
		pair<T, int> sm{inf, -1};
		do{
			-- r;
			while(r > 1 && r & 1) r >>= 1;
			if(!g(min(data[r], sm))){
				while(r < size){
					push(r);
					r = r << 1 | 1;
					if(g(min(data[r], sm))) sm = min(data[r --], sm);
				}
				return r - size;
			}
			sm = min(data[r], sm);
		}while((r & -r) != r);
		return -1;
	}
};

template<class T, class U> T &ctmax(T &x, const U &y){ return x = max<T>(x, y); }
template<class T, class U> T &ctmin(T &x, const U &y){ return x = min<T>(x, y); }

int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	int n, m;
	cin >> n >> m;
	vector<array<int, 3>> a(n);
	for(auto &[w, l, r]: a){
		cin >> l >> r >> w, -- l, -- r;
	}
	sort(a.begin(), a.end());
	lazy_segment_tree_range_add_range_min_index<int, int> ds(m - 1, 0);
	assert(ds.inf == numeric_limits<int>::max() / 2);
	int res = numeric_limits<int>::max();
	for(auto i = 0, j = 0; i < n; ++ i){
		while(j < n && !ds.query_all().first){
			ds.update(a[j][1], a[j][2], 1);
			++ j;
		}
		if(!ds.query_all().first){
			break;
		}
		ctmin(res, a[j - 1][0] - a[i][0]);
		ds.update(a[i][1], a[i][2], -1);
	}
	cout << res << "\n";
	return 0;
}

/*

*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////