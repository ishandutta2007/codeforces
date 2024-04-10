#include <bits/stdc++.h>
using namespace std;

template<class T, class U>
struct lazy_segment_tree{
	int n, size, log;
	vector<T> data;
	vector<U> updates;
	function<T(T, T)> TT; // monoid operation (always adjacent)
	T T_id; // monoid identity
	function<U(U, U)> UU; // semigroup operation (superset, subset)
	function<U(int, int)> U_init; // semigroup default element for the interval [l, r)
	function<T(U, T)> UT; // action of U on T (superset, subset)
	lazy_segment_tree(int n,
		function<T(T, T)> TT, T T_id,
		function<U(U, U)> UU, function<U(int, int)> U_init,
		function<T(U, T)> UT
	): lazy_segment_tree(vector<T>(n, T_id), TT, T_id, UU, U_init, UT){ }
	lazy_segment_tree(int n, T init,
		function<T(T, T)> TT, T T_id,
		function<U(U, U)> UU, function<U(int, int)> U_init,
		function<T(U, T)> UT
	): lazy_segment_tree(vector<T>(n, init), TT, T_id, UU, U_init, UT){ }
	lazy_segment_tree(const vector<T> &a,
		function<T(T, T)> TT, T T_id,
		function<U(U, U)> UU, function<U(int, int)> U_init,
		function<T(U, T)> UT
	): n((int)a.size()), TT(TT), T_id(T_id), UU(UU), U_init(U_init), UT(UT){ // O(n)
		log = __lg(n + 1) + 1, size = 1 << log;
		data = vector<T>(size << 1, T_id), updates = vector<U>(size);
		copy(a.begin(), a.end(), data.begin() + size);
		for(auto i = 1; i < size; ++ i){
			int h = log - __lg(i);
			updates[i] = U_init((i << h) - size, (i + 1 << h) - size);
		}
		for(auto i = size - 1; i >= 1; -- i) refresh(i);
	}
	void refresh(int i){ data[i] = TT(data[i << 1], data[i << 1 | 1]); }
	void apply(int i, U f){
		data[i] = UT(f, data[i]);
		if(i < size) updates[i] = UU(f, updates[i]);
	}
	void push(int i){
		apply(i << 1, updates[i]), apply(i << 1 | 1, updates[i]);
		int h = log - __lg(i);
		updates[i] = U_init((i << h) - size, (i + 1 << h) - size);
	}
	T query(int p){ // O(log n)
		assert(0 <= p && p < n);
		p += size;
		for(auto i = log; i >= 1; -- i) push(p >> i);
		return data[p];
	}
	T query(int l, int r){ // O(log n)
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
	T query_all(){ return data[1]; } // O(1)
	void set(int p, T x){ // O(log n)
		assert(0 <= p && p < n);
		p += size;
		for(auto i = log; i >= 1; -- i) push(p >> i);
		data[p] = x;
		for(auto i = 1; i <= log; ++ i) refresh(p >> i);
	}
	void update(int p, U f){ // O(log n)
		assert(0 <= p && p < n);
		p += size;
		for(auto i = log; i >= 1; -- i) push(p >> i);
		data[p] = UT(f, data[p]);
		for(auto i = 1; i <= log; ++ i) refresh(p >> i);
	}
	void update(int l, int r, U f){ // O(log n)
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
	template<class G> int max_pref(int l, G g){ // O(log n)
		assert(0 <= l && l <= n), assert(g(T_id));
		if(l == n) return n;
		l += size;
		for(auto i = log; i >= 1; -- i) push(l >> i);
		T sm = T_id;
		do{
			while(~l & 1) l >>= 1;
			if(!g(TT(sm, data[l]))){
				while(l < size){
					push(l);
					l = l << 1;
					if(g(TT(sm, data[l]))) sm = TT(sm, data[l ++]);
				}
				return l - size;
			}
			sm = TT(sm, data[l]);
			++ l;
		}while((l & -l) != l);
		return n;
	} // f(sum[l, r)) is T, T, ..., T, F, F, ..., F, returns max r with T
	template<class G> int min_suff(int r, G g){ // O(log n)
		assert(0 <= r && r <= n), assert(g(T_id));
		if(r == 0) return 0;
		r += size;
		for(auto i = log; i >= 1; -- i) push(r - 1 >> i);
		T sm = T_id;
		do{
			-- r;
			while(r > 1 && r & 1) r >>= 1;
			if(!g(TT(data[r], sm))){
				while(r < size){
					push(r);
					r = r << 1 | 1;
					if(g(TT(data[r], sm))) sm = TT(data[r --], sm);
				}
				return r + 1 - size;
			}
			sm = TT(data[r], sm);
		}while((r & -r) != r);
		return 0;
	} // f(sum[l, r)) is F, F, ..., F, T, T, ..., T, returns min l with T
};
template<class T, class U> T &ctmax(T &x, const U &y){ return x = max<T>(x, y); }
template<class T, class U> T &ctmin(T &x, const U &y){ return x = min<T>(x, y); }

int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	auto __solve_tc = [&](int __tc_num){
		int n;
		cin >> n;
		vector<int> a(n), pos(n + 1, -1), prev(n, -1);
		for(auto i = 0; i < n; ++ i){
			cin >> a[i];
			prev[i] = pos[a[i]];
			pos[a[i]] = i;
		}
		fill(pos.begin(), pos.end(), n);
		vector<int> next(n + 1, n);
		for(auto i = n - 1; i >= 0; -- i){
			next[i] = pos[a[i]];
			pos[a[i]] = i;
		}
		int cur = count(a.begin(), a.end(), 0);
		vector<int> init(n + 1, cur);
		for(auto r = 1; r <= n; ++ r){
			if(a[r - 1] == 0){
				-- cur;
			}
			else if(!~prev[r - 1]){
				++ cur;
			}
			init[r] = cur;
		}
		lazy_segment_tree<int, int> ds(init, [&](int x, int y){ return min(x, y); }, numeric_limits<int>::max() / 2, plus<>(), [&](int, int){ return 0; }, plus<>());
		int res = count(a.begin(), a.end(), 0) / 2;
		for(auto l = 0; l < n; ++ l){
			ctmin(res, ds.query(l, n + 1));
			if(a[l] == 0){
				ds.update(0, n + 1, 1);
			}
			else{
				ds.update(0, next[l] + 1, -1);
			}
		}
		cout << res << "\n";
		return 0;
	};
	int __tc_cnt;
	cin >> __tc_cnt;
	for(auto __tc_num = 0; __tc_num < __tc_cnt; ++ __tc_num){
		__solve_tc(__tc_num);
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