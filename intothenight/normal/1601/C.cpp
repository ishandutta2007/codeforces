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

template<class T>
struct fenwick_tree{
	int n;
	vector<T> data;
	fenwick_tree(){ }
	// O(n)
	fenwick_tree(int n): n(n), data(n){ }
	// O(n)
	fenwick_tree(int n, T init): fenwick_tree(vector<T>(n, init)){ }
	// O(n)
	fenwick_tree(const vector<T> &v): n((int)v.size()), data(v){
		for(auto i = 1; i <= n; ++ i) if(i + (i & -i) <= n) data[i + (i & -i) - 1] += data[i - 1];
	}
	fenwick_tree(const fenwick_tree &otr): n(otr.n), data(otr.data){
	}
	// O(log n)
	void update(int p, T x){
		assert(0 <= p && p < n);
		for(++ p; p <= n; p += p & -p) data[p - 1] += x;
	}
	// O(log n)
	T query(int r) const{
		T s{};
		for(; r > 0; r -= r & -r) s += data[r - 1];
		return s;
	}
	// O(log n)
	T query(int l, int r) const{
		assert(0 <= l && l <= r && r <= n);
		return query(r) - query(l);
	}
	// f(sum[0, r)) is T, T, ..., T, F, F, ..., F, returns min r with F (n + 1 if no such r)
	// O(log n)
	int max_pref(auto f) const{
		if(!f({})) return 0;
		int p = 0;
		T pref{};
		for(auto pw = 1 << __lg(n + 1); pw; pw >>= 1) if(p + pw <= n && f(pref + data[p + pw - 1])){
			pref += data[p + pw - 1];
			p += pw;
		}
		return p + 1;
	}
	int lower_bound(T x) const{
		if(x <= T{}) return 0;
		int p = 0;
		T pref{};
		for(auto pw = 1 << __lg(n + 1); pw; pw >>= 1) if(p + pw <= n && pref + data[p + pw - 1] < x){
			pref += data[p + pw - 1];
			p += pw;
		}
		return p + 1;
	}
	int upper_bound(T x) const{
		if(x < T{}) return 0;
		int p = 0;
		T pref{};
		for(auto pw = 1 << __lg(n + 1); pw; pw >>= 1) if(p + pw <= n && pref + data[p + pw - 1] <= x){
			pref += data[p + pw - 1];
			p += pw;
		}
		return p + 1;
	}
};

// O(n log n)
// Requires fenwick_tree
template<class T, class Compare = less<>>
long long count_inversions(const vector<T> &a, bool count_equal = false, Compare cmp = less<>()){
	int n = (int)a.size();
	vector<T> cmpr = a;
	sort(cmpr.begin(), cmpr.end(), cmp);
	fenwick_tree<int> rsumq(n);
	long long res = 0;
	for(auto x: a){
		int i = lower_bound(cmpr.begin(), cmpr.end(), x, cmp) - cmpr.begin();
		res += rsumq.query(i + !count_equal, n);
		rsumq.update(i, 1);
	}
	return res;
}

int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	auto __solve_tc = [&](auto __tc_num)->int{
		int n, m;
		cin >> n >> m, ++ m;
		vector<int> a(n), b(m);
		for(auto i = 0; i < n; ++ i){
			cin >> a[i];
		}
		vector<int> order(n);
		iota(order.begin(), order.end(), 0);
		sort(order.begin(), order.end(), [&](int i, int j){ return a[i] < a[j]; });
		b.back() = numeric_limits<int>::max();
		for(auto i = 0; i < m - 1; ++ i){
			cin >> b[i];
		}
		sort(b.begin(), b.end());
		segment_tree seg(n, array{0, 1}, [&](auto x, auto y){
			return array{min(x[0], x[1] + y[0]), x[1] + y[1]};
		}, array<int, 2>{});
		long long res = 0;
		int last = 0, l = 0, r = 0;
		for(auto x: b){
			while(r < n && a[order[r]] <= x){
				seg.set(order[r], {0, 0});
				++ r;
			}
			while(l < n && a[order[l]] < x){
				seg.set(order[l], {-1, -1});
				++ l;
			}
			res += l + seg.query_all()[0];
			last = x;
		}
		cout << res + count_inversions(a) << "\n";
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