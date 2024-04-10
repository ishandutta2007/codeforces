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
	auto __solve_tc = [&](auto __tc_num)->int{
		string s;
		cin >> s;
		vector<array<int, 2>> init((int)s.size());
		for(auto i = 0; i < (int)s.size(); ++ i){
			init[i] = {s[i] == '[' || s[i] == ']', 1};
		}
		auto TT = [&](array<int, 2> x, array<int, 2> y)->array<int, 2>{
			if(x[0] == 2 || y[0] == 2){
				return x[0] == 2 ? y : x;
			}
			if((x[0] ^ x[1] & 1) == y[0]){
				return {x[0], x[1] + y[1]};
			}
			else if(x[1] == y[1]){
				return {2, 0};
			}
			else if(x[1] < y[1]){
				return {y[0] ^ x[1] & 1, y[1] - x[1]};
			}
			else{
				return {x[0], x[1] - y[1]};
			}
		};
		segment_tree seg(init, TT, array{2, 0});
		int qn;
		cin >> qn;
		for(auto qi = 0; qi < qn; ++ qi){
			int l, r;
			cin >> l >> r, -- l;
			auto res = seg.query(l, r);
			cout << res[1] / 2 << "\n";
		}
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