#include <bits/stdc++.h>
using namespace std;
template<class T, class U> T &ctmax(T &x, const U &y){ return x = max<T>(x, y); }
template<class T, class U> T &ctmin(T &x, const U &y){ return x = min<T>(x, y); }

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
		if(l == n) return n + 1;
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
		if(r == 0) return -1;
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
	const int mx = 13;
	array<array<int, 4>, mx> state{{
		{0, 0, 0, 0},
		{0, 0, 1, 0},
		{0, 1, 0, 0},
		{0, 1, 1, 0},
		{0, 2, 1, 0},
		{1, 0, 0, 0},
		{1, 0, 1, 0},
		{1, 1, 0, 0},
		{1, 1, 1, 0},
		{1, 2, 1, 0},
		{2, 1, 0, 0},
		{2, 1, 1, 0},
		{2, 2, 1, 0}
	}};
	array<int, 27> rstate;
	rstate.fill(-1);
	for(auto i = 0; i < mx; ++ i){
		rstate[state[i][0] + 3 * state[i][1] + 9 * state[i][2]] = i;
	}
	using T = array<int, mx>;
	const int inf = numeric_limits<int>::max() / 4;
	auto generate = [&](char c)->T{
		T res;
		res.fill(inf);
		res[0] = 1;
		if(c == 'a'){
			res[rstate[1]] = 0;
		}
		else if(c == 'b'){
			res[rstate[3]] = 0;
		}
		else{
			res[rstate[9]] = 0;
		}
		return res;
	};
	auto TT = [&](const T &x, const T &y)->T{
		T res;
		res.fill(inf);
		for(auto p = 0; p < mx; ++ p){
			for(auto q = 0; q < mx; ++ q){
				array<int, 4> final{};
				for(auto t = 0; t < 3; ++ t){
					int i = t + state[p][t];
					final[t] = i + state[q][i] - t;
				}
				if(final[0] < 3){
					int mask = final[0] + 3 * final[1] + 9 * final[2];
					assert(~rstate[mask]);
					ctmin(res[rstate[mask]], x[p] + y[q]);
				}
				NEXT:;
			}
		}
		return res;
	};
	T T_id;
	T_id.fill(inf);
	T_id[0] = 0;
	int n, qn;
	string s;
	cin >> n >> qn >> s;
	vector<T> init(n);
	for(auto i = 0; i < n; ++ i){
		init[i] = generate(s[i]);
	}
	segment_tree seg(init, TT, T_id);
	for(auto qi = 0; qi < qn; ++ qi){
		int i;
		char c;
		cin >> i >> c, -- i;
		seg.set(i, generate(c));
		auto res = seg.query_all();
		cout << *min_element(res.begin(), res.end()) << "\n";
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