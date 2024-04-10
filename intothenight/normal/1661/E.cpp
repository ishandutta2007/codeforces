#include <bits/stdc++.h>
using namespace std;
#if __cplusplus > 201703L
#include <ranges>
using namespace numbers;
#endif

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
	// O(log n)
	void update(int p, T x){
		assert(0 <= p && p < n);
		p += size;
		data[p] = TT(data[p], x);
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
	// pred(sum[l, r)) is T, T, ..., T, F, F, ..., F
	// Returns max r with T
	// O(log n)
	int max_pref(int l, auto pred) const{
		assert(0 <= l && l <= n && pred(T_id));
		if(l == n) return n;
		l += size;
		T sm = T_id;
		do{
			while(~l & 1) l >>= 1;
			if(!pred(TT(sm, data[l]))){
				while(l < size){
					l = l << 1;
					if(pred(TT(sm, data[l]))) sm = TT(sm, data[l ++]);
				}
				return l - size;
			}
			sm = TT(sm, data[l ++]);
		}while((l & -l) != l);
		return n;
	}
	// pred(sum[l, r)) is F, F, ..., F, T, T, ..., T
	// Returns min l with T
	// O(log n)
	int min_suff(int r, auto pred) const{
		assert(0 <= r && r <= n && pred(T_id));
		if(r == 0) return 0;
		r += size;
		T sm = T_id;
		do{
			-- r;
			while(r > 1 && r & 1) r >>= 1;
			if(!pred(TT(data[r], sm))){
				while(r < size){
					r = r << 1 | 1;
					if(pred(TT(data[r], sm))) sm = TT(data[r --], sm);
				}
				return r + 1 - size;
			}
			sm = TT(data[r], sm);
		}while((r & -r) != r);
		return 0;
	}
	template<class output_stream>
	friend output_stream &operator<<(output_stream &out, const segment_tree<T, F> &seg){
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
	int n;
	cin >> n;
	vector<string> a(3);
	for(auto i = 0; i < 3; ++ i){
		cin >> a[i];
	}
	using T = array<int, 7>;
	vector<T> init(n);
	for(auto i = 0; i < n; ++ i){
		int type = 0;
		for(auto j = 0; j < 3; ++ j){
			type |= (a[j][i] - '0') << j;
		}
		if(type){
			init[i][0] = 1;
			for(auto j = 0; j < 3; ++ j){
				if(type & 1 << j){
					init[i][j + 1] = init[i][j + 1 + 3] = i * 2 + 1;
				}
			}
			if(type == 5){
				init[i][0] = 2;
				init[i][1] = init[i][4] = i * 2 + 1;
				init[i][3] = init[i][6] = i * 2 + 2;
			}
		}
	}
	auto TT = [&](T x, T y)->T{
		if(x[1] == -1){
			return y;
		}
		if(y[1] == -1){
			return x;
		}
		T z{x[0] + y[0]};
		while(true){
			bool update = false;
			for(auto i = 1; i <= 3; ++ i){
				if(x[i + 3] && y[i] && x[i + 3] != y[i]){
					update = true;
					-- z[0];
					int to = x[i + 3], from = y[i];
					for(auto i = 1; i <= 6; ++ i){
						if(x[i] && x[i] == from){
							x[i] = to;
						}
						if(y[i] && y[i] == from){
							y[i] = to;
						}
					}
				}
			}
			if(!update){
				break;
			}
		}
		for(auto i = 1; i <= 3; ++ i){
			z[i] = x[i];
			z[i + 3] = y[i + 3];
		}
		return z;
	};
	T T_id = {0, -1};
	segment_tree seg(init, TT, T_id);
	int qn;
	cin >> qn;
	for(auto qi = 0; qi < qn; ++ qi){
		int l, r;
		cin >> l >> r, -- l;
		cout << seg.query(l, r)[0] << "\n";
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