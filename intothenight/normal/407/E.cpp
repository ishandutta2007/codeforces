#include <bits/stdc++.h>
using namespace std;
#if __cplusplus > 201703L
#include <ranges>
using namespace numbers;
#endif

template<class T, class U, class F1, class F2, class F3, class F4>
struct lazy_segment_tree{
	int n, size, log;
	vector<T> data;
	vector<U> updates;
	F1 TT; // monoid operation (always adjacent)
	T T_id; // monoid identity
	F2 UU; // semigroup operation (superset, subset)
	F3 U_init; // semigroup default element for the interval [l, r)
	F4 UT; // action of U on T (superset, subset)
	lazy_segment_tree(int n, F1 TT, T T_id, F2 UU, F3 U_init, F4 UT, U _type_deducer): lazy_segment_tree(vector<T>(n, T_id), TT, T_id, UU, U_init, UT, _type_deducer){ }
	lazy_segment_tree(int n, T init, F1 TT, T T_id, F2 UU, F3 U_init, F4 UT, U _type_deducer): lazy_segment_tree(vector<T>(n, init), TT, T_id, UU, U_init, UT, _type_deducer){ }
	lazy_segment_tree(const vector<T> &a, F1 TT, T T_id, F2 UU, F3 U_init, F4 UT, U): n((int)a.size()), TT(TT), T_id(T_id), UU(UU), U_init(U_init), UT(UT){ // O(n)
		log = __lg(max(n - 1, 1)) + 1, size = 1 << log;
		data = vector<T>(size << 1, T_id), updates = vector<U>(size);
		copy(a.begin(), a.end(), data.begin() + size);
		for(auto i = 1; i < size; ++ i){
			int h = log - __lg(i);
			updates[i] = U_init((i << h) - size, (i + 1 << h) - size);
		}
		for(auto i = size - 1; i >= 1; -- i) refresh(i);
	}
	void refresh(int i){
		data[i] = TT(data[i << 1], data[i << 1 | 1]);
	}
	void apply(int i, U f){
		data[i] = UT(f, data[i]);
		if(i < size) updates[i] = UU(f, updates[i]);
	}
	void push(int i){
		apply(i << 1, updates[i]), apply(i << 1 | 1, updates[i]);
		int h = log - __lg(i);
		updates[i] = U_init((i << h) - size, (i + 1 << h) - size);
	}
	// O(log n)
	T query(int p){
		assert(0 <= p && p < n);
		p += size;
		for(auto i = log; i >= 1; -- i) push(p >> i);
		return data[p];
	}
	// O(log n)
	T query(int l, int r){
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
	// O(1)
	T query_all(){
		return data[1];
	}
	// O(log n)
	void set(int p, T x){
		assert(0 <= p && p < n);
		p += size;
		for(auto i = log; i >= 1; -- i) push(p >> i);
		data[p] = x;
		for(auto i = 1; i <= log; ++ i) refresh(p >> i);
	}
	// O(log n)
	void update(int p, U f){
		assert(0 <= p && p < n);
		p += size;
		for(auto i = log; i >= 1; -- i) push(p >> i);
		data[p] = UT(f, data[p]);
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
	// pred(sum[l, r)) is T, T, ..., T, F, F, ..., F
	// Returns max r with T
	// O(log n)
	int max_pref(int l, auto pred){
		assert(0 <= l && l <= n);
		assert(pred(T_id));
		if(l == n) return n;
		l += size;
		for(auto i = log; i >= 1; -- i) push(l >> i);
		T sum = T_id;
		do{
			while(~l & 1) l >>= 1;
			if(!pred(TT(sum, data[l]))){
				while(l < size){
					push(l);
					l = l << 1;
					if(pred(TT(sum, data[l]))) sum = TT(sum, data[l ++]);
				}
				return l - size;
			}
			sum = TT(sum, data[l]);
			++ l;
		}while((l & -l) != l);
		return n;
	}
	// pred(sum[l, r)) is F, F, ..., F, T, T, ..., T
	// Returns min l with T
	// O(log n)
	int min_suff(int r, auto pred){
		assert(0 <= r && r <= n && pred(T_id));
		if(r == 0) return 0;
		r += size;
		for(auto i = log; i >= 1; -- i) push(r - 1 >> i);
		T sum = T_id;
		do{
			-- r;
			while(r > 1 && r & 1) r >>= 1;
			if(!pred(TT(data[r], sum))){
				while(r < size){
					push(r);
					r = r << 1 | 1;
					if(pred(TT(data[r], sum))) sum = TT(data[r --], sum);
				}
				return r + 1 - size;
			}
			sum = TT(data[r], sum);
		}while((r & -r) != r);
		return 0;
	}
	template<class output_stream>
	friend output_stream &operator<<(output_stream &out, lazy_segment_tree<T, U, F1, F2, F3, F4> seg){
		out << "[";
		for(auto i = 0; i < seg.n; ++ i){
			out << seg.query(i);
			if(i != seg.n - 1) out << ", ";
		}
		return out << ']';
	}
};

int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	int n, k, d;
	cin >> n >> k >> d;
	vector<int> a(n);
	for(auto i = 0; i < n; ++ i){
		cin >> a[i];
	}
	if(d == 0){
		array<int, 2> res{};
		for(auto l = 0; l < n; ){
			int r = l;
			while(r < n && a[l] == a[r]){
				++ r;
			}
			if(res[1] - res[0] < r - l){
				res = {l, r};
			}
			l = r;
		}
		cout << res[0] + 1 << " " << res[1] << "\n";
		return 0;
	}
	array<int, 2> res{};
	auto solve = [&](const vector<int> &a, int init_l)->void{
		int n = (int)a.size();
		lazy_segment_tree lseg(n, 0, [&](int x, int y){ return min(x, y); }, numeric_limits<int>::max() / 2, plus<>(), [&](int, int){ return 0; }, plus<>(), 0);
		set<int> has;
		deque<int> min_stack, max_stack;
		for(auto l = n - 1, r = n; l >= 0; -- l){
			while(has.contains(a[l])){
				-- r;
				has.erase(a[r]);
				if(min_stack.front() == r){
					min_stack.pop_front();
				}
				if(max_stack.front() == r){
					max_stack.pop_front();
				}
			}
			has.insert(a[l]);
			while(!min_stack.empty() && a[min_stack.back()] >= a[l]){
				lseg.update(min_stack.back(), (int)min_stack.size() == 1 ? r : *next(min_stack.rbegin()), a[min_stack.back()] - a[l]);
				min_stack.pop_back();
			}
			min_stack.push_back(l);
			while(!max_stack.empty() && a[max_stack.back()] <= a[l]){
				lseg.update(max_stack.back(), (int)max_stack.size() == 1 ? r : *next(max_stack.rbegin()) , a[l] - a[max_stack.back()]);
				max_stack.pop_back();
			}
			max_stack.push_back(l);
			lseg.update(l + 1, r, -1);
			int p = lseg.min_suff(r, [&](auto sum){ return sum > k; }) - 1;
			if(res[1] - res[0] < p + 1 - l || res[1] - res[0] == p + 1 - l && init_l + l < res[0]){
				res = {init_l + l, init_l + p + 1};
			}
		}
	};
	auto div = [&](int x)->int{
		x %= d;
		if(x < 0){
			x += d;
		}
		return x;
	};
	for(auto l = 0; l < n; ){
		int r = l;
		vector<int> b;
		while(r < n && div(a[l]) == div(a[r])){
			b.push_back((a[r] - div(a[r])) / d);
			++ r;
		}
		solve(b, l);
		l = r;
	}
	cout << res[0] + 1 << " " << res[1] << "\n";
	return 0;
}

/*

*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////