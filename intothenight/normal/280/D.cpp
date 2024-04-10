#include <bits/stdc++.h>
using namespace std;
#if __cplusplus > 201703L
#include <ranges>
using namespace numbers;
#endif
template<class T> T &ctmin(T &x){ return x; }
template<class T, class Head, class ...Tail> T &ctmin(T &x, const Head &h, const Tail &... t){ return ctmin(x = min<T>(x, h), t...); }
template<class T> T &ctmax(T &x){ return x; }
template<class T, class Head, class ...Tail> T &ctmax(T &x, const Head &h, const Tail &... t){ return ctmax(x = max<T>(x, h), t...); }

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
	vector<int> a(n);
	copy_n(istream_iterator<int>(cin), n, a.begin());
	#ifdef LOCAL
	const int mxk = 3;
	#else
	const int mxk = 20;
	#endif
	using T = array<array<int, mxk>, 4>;
	const int minf = numeric_limits<int>::min() / 2;
	auto TT = [&](const T &x, const T &y)->T{
		T res{};
		for(auto t = 0; t < 4; ++ t){
			res[t].fill(minf);
		}
		for(auto c = 1; c <= mxk; ++ c){
			ctmax(res[0][c - 1], max(x[0][c - 1], y[0][c - 1]));
			ctmax(res[1][c - 1], x[1][c - 1]);
			ctmax(res[2][c - 1], y[2][c - 1]);
		}
		for(auto tx = 0; tx < 4; ++ tx){
			for(auto ty = 0; ty < 4; ++ ty){
				if((tx >> 1 & 1) == (ty & 1)){
					int tr = tx & 1 | ty & 2, delta = ty & 1;
					for(auto cx = 1; cx <= mxk; ++ cx){
						for(auto cy = 1; cx + cy - delta <= mxk; ++ cy){
							ctmax(res[tr][cx + cy - delta - 1], x[tx][cx - 1] + y[ty][cy - 1]);
						}
					}
				}
			}
		}
		for(auto c = 1; c <= mxk; ++ c){
			for(auto t = 0; t < 4; ++ t){
				for(auto pt = 0; pt < t; ++ pt){
					if((t & pt) == pt){
						ctmax(res[pt][c - 1], res[t][c - 1]);
					}
				}
			}
		}
		return res;
	};
	auto gen = [&](int x)->T{
		T res{};
		for(auto i = 0; i < 4; ++ i){
			for(auto j = 0; j < mxk; ++ j){
				ctmax(res[i][j], x);
			}
		}
		res[3][0] = x;
		return res;
	};
	vector<T> init(n);
	for(auto i = 0; i < n; ++ i){
		init[i] = gen(a[i]);
	}
	segment_tree seg(init, TT, T{});
	int qn;
	cin >> qn;
	for(auto qi = 0; qi < qn; ++ qi){
		int type;
		cin >> type;
		if(type == 0){
			int i, x;
			cin >> i >> x, -- i;
			seg.set(i, gen(x));
		}
		else{
			int l, r, k;
			cin >> l >> r >> k, -- l;
			cout << seg.query(l, r)[0][k - 1] << "\n";
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