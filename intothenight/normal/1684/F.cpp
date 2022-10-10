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
		assert(0 <= l && l <= n && pred(T_id));
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

// DEBUG BEGIN
#ifdef LOCAL
template<class L, class R> ostream &operator<<(ostream &out, const pair<L, R> &p){
	return out << "{" << p.first << ", " << p.second << "}";
}
template<class Tuple, size_t N> struct TuplePrinter{
	static ostream &print(ostream &out, const Tuple &t){ return TuplePrinter<Tuple, N-1>::print(out, t) << ", " << get<N-1>(t); }
};
template<class Tuple> struct TuplePrinter<Tuple, 1>{
	static ostream &print(ostream &out, const Tuple& t){ return out << get<0>(t); }
};
template<class... Args> ostream &print_tuple(ostream &out, const tuple<Args...> &t){
	return TuplePrinter<decltype(t), sizeof...(Args)>::print(out << "{", t) << "}";
}
template<class ...Args> ostream &operator<<(ostream &out, const tuple<Args...> &t){
	return print_tuple(out, t);
}
template<class T> ostream &operator<<(class enable_if<!is_same<T, string>::value, ostream>::type &out, const T &arr){
	out << "{"; for(auto x: arr) out << x << ", ";
	return out << (arr.empty() ? "" : "\b\b") << "}";
}
template<size_t S> ostream &operator<<(ostream &out, const bitset<S> &b){
	for(auto i = 0; i < S; ++ i) out << b[i];
	return out;
}
ostream &operator<<(ostream &out, const _Bit_reference &bit){
	return out << bool(bit);
}
template<class T, class A, class C>
ostream &operator<<(ostream &out, priority_queue<T, A, C> pq){
	vector<T> a;
	while(!pq.empty()) a.push_back(pq.top()), pq.pop();
	return out << a;
}
void debug_out(){ cerr << "\b\b " << endl; }
template<class Head, class... Tail>
void debug_out(Head H, Tail... T){ cerr << H << ", ", debug_out(T...); }
void debug2_out(){ }
template<class Head, class... Tail>
void debug2_out(Head H, Tail... T){ cerr << "\n"; for(auto x: H) cerr << x << "\n"; debug2_out(T...); }
void debug_frac_out(){ cerr << "\b\b " << endl; }
template<class Head, class... Tail>
void debug_frac_out(Head H, Tail... T){
	for(auto d = 1; ; ++ d){
		if((H * d).value <= 1000000){
			cerr << H * d << "/" << d << ", ";
			break;
		}
		else if((-H * d).value <= 1000000){
			cerr << "-" << -H * d << "/" << d << ", ";
			break;
		}
	}
	debug_frac_out(T...);
}
enum CODE{ CCRED = 31, CCGREEN = 32, CCYELLOW = 33, CCBLUE = 34, CCDEFAULT = 39 };
#define debug(...) cerr << "\033[" << (int)CODE(CCRED) << "m[" << #__VA_ARGS__ << "]: \033[" << (int)CODE(CCBLUE) << "m", debug_out(__VA_ARGS__), cerr << "\33[" << (int)CODE(CCDEFAULT) << "m";
#define debug2(...) cerr << "\033[" << (int)CODE(CCRED) << "m[" << #__VA_ARGS__ << "] \033[" << (int)CODE(CCBLUE) << "m", debug2_out(__VA_ARGS__), cerr << "\33[" << (int)CODE(CCDEFAULT) << "m";
#define debug_frac(...) cerr << "\033[" << (int)CODE(CCRED) << "m[" << #__VA_ARGS__ << "]: \033[" << (int)CODE(CCBLUE) << "m", debug_frac_out(__VA_ARGS__), cerr << "\33[" << (int)CODE(CCDEFAULT) << "m";
#else
#define debug(...) 42
#define debug2(...) 42
#define debug_frac(...) 42
#endif
// DEBUG END

int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	auto __solve_tc = [&](auto __tc_num)->int{
		debug(__tc_num);
		int n, m;
		cin >> n >> m;
		vector<int> a(n);
		copy_n(istream_iterator<int>(cin), n, a.begin());
		{
			vector<int> temp = a;
			ranges::sort(temp);
			for(auto &x: a){
				x = ranges::lower_bound(temp, x) - temp.begin();
			}
		}
		vector<array<int, 2>> distinct(m);
		for(auto &[l, r]: distinct){
			cin >> l >> r, -- l;
		}
		{
			ranges::sort(distinct);
			vector<array<int, 2>> b;
			for(auto [l, r]: distinct){
				if(!b.empty() && b.back()[0] == l){
					b.pop_back();
				}
				if(b.empty() || b.back()[1] < r){
					b.push_back({l, r});
				}
			}
			distinct = b;
		}
		vector<array<int, 4>> req;
		{
			vector<deque<int>> pos(n);
			int l = 0, r = 0;
			for(auto [ql, qr]: distinct){
				while(l != ql || r != qr){
					if(l == r || l == ql){
						int x = a[r];
						pos[x].push_back(r);
						++ r;
						if((int)pos[x].size() >= 2){
							int s = (int)pos[x].size();
							req.push_back({pos[x][0], pos[x][s - 2], pos[x][1], pos[x][s - 1]});
						}
					}
					else{
						int x = a[l];
						pos[x].pop_front();
						++ l;
					}
				}
			}
		}
		debug(req);
		lazy_segment_tree lseg(n + 1, [&](int x, int y){ return max(x, y); }, 0, plus<>(), [&](int, int){ return 0; }, plus<>(), 0);
		auto not_intersect = [&](int d)->bool{
			debug(d);
			ranges::fill(lseg.data, 0);
			ranges::fill(lseg.updates, 0);
			for(auto [r1, l1, r2, l2]: req){
				l1 = max(l1 - d + 1, 0);
				++ r1;
				l2 = max(l2 - d + 1, 0);
				++ r2;
				debug(l1, r1, l2, r2);
				if(r1 <= l1 && r2 <= l2){
					return true;
				}
				if(r2 <= l2){
					lseg.update(l1, r1, 1);
				}
				else if(r1 <= l1){
					lseg.update(l2, r2, 1);
				}
				else if(min(r1, r2) <= max(l1, l2)){
					lseg.update(l1, r1, 1);
					lseg.update(l2, r2, 1);
				}
				else{
					int l3 = max(l1, l2);
					int r3 = min(r1, r2);
					lseg.update(l1, r1, 1);
					lseg.update(l2, r2, 1);
					lseg.update(l3, r3, -1);
				}
			}
			return lseg.query_all() < (int)req.size();
		};
		cout << *ranges::partition_point(ranges::iota_view(0, n), not_intersect) << "\n";
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