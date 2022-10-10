#include <bits/stdc++.h>
using namespace std;

template<class B, class C> // coordinate type, color type
struct color_processor{
	map<array<B, 2>, C> intervals;
	color_processor(C init = {}): intervals({{{numeric_limits<B>::min(), numeric_limits<B>::max()}, init}}){ }
	auto belongs(B p){
		return prev(intervals.upper_bound({p, numeric_limits<B>::max()}));
	}
	void paint(B l, B r, C c, auto process){ // paint the range [l, r) with the color c, amortized O(1) process calls
		array<B, 2> I{l, l};
		auto it = intervals.lower_bound(I);
		if(it != intervals.begin() && l < prev(it)->first[1]){
			-- it;
			auto x = *it; intervals.erase(it);
			intervals.insert({{x.first[0], l}, x.second});
			it = intervals.insert({{l, x.first[1]}, x.second}).first;
		}
		while(it != intervals.end() && it->first[0] < r){
			if(r < it->first[1]){
				auto x = *it; intervals.erase(it);
				it = intervals.insert({{x.first[0], r}, x.second}).first;
				intervals.insert({{r, x.first[1]}, x.second});
			}
			process(max(l, it->first[0]), min(r, it->first[1]), it->second, c);
			// process(l, r, pc, c): color of range [l, r) is changed from pc to c
			I = {min(I[0], it->first[0]), max(I[1], it->first[1])};
			it = intervals.erase(it);
		}
		intervals.insert({I, c});
	}
};

template<class U>
struct reverse_segment_tree{
	int n, size, log;
	vector<U> updates;
	function<U(U, U)> UU; // semigroup operation (superset, subset)
	function<U(int, int)> U_init; // semigroup default element for the interval [l, r)
	reverse_segment_tree(int n, function<U(U, U)> UU, function<U(int, int)> U_init){
		vector<U> a(n);
		for(auto i = 0; i < n; ++ i) a[i] = U_init(i, i + 1);
		*this = reverse_segment_tree(a, UU, U_init);
	}
	reverse_segment_tree(int n, U init, function<U(U, U)> UU, function<U(int, int)> U_init): reverse_segment_tree(vector<U>(n, init), UU, U_init){ }
	reverse_segment_tree(const vector<U> &a, function<U(U, U)> UU, function<U(int, int)> U_init): n((int)a.size()), UU(UU), U_init(U_init){
		log = __lg(n + 1) + 1, size = 1 << log;
		updates = vector<U>(size << 1);
		copy(a.begin(), a.end(), updates.begin() + size);
		for(auto i = 1; i < size; ++ i){
			int h = log - __lg(i);
			updates[i] = U_init((i << h) - size, (i + 1 << h) - size);
		}
	}
	void update(int l, int r, U x){
		if(l >= r) return;
		l += size, r += size;
		for(auto i = log; i >= 1; -- i){ // for non-commutative operations
			if(l >> i << i != l) push(l >> i);
			if(r >> i << i != r) push(r - 1 >> i);
		}
		for(; l < r; l >>= 1, r >>= 1){
			if(l & 1) updates[l ++] = UU(x, updates[l]);
			if(r & 1) updates[r] = UU(x, updates[-- r]);
		}
	}
	U query(int p){
		U res = U_init(p, p + 1);
		for(p += size; p > 0; p >>= 1) res = UU(updates[p], res);
		return res;
	}
	void push(int i){
		updates[i << 1] = UU(updates[i], updates[i << 1]);
		updates[i << 1 | 1] = UU(updates[i], updates[i << 1 | 1]);
		int h = log - __lg(i);
		updates[i] = U_init((i << h) - size, (i + 1 << h) - size);
	}
	void push_all(){
		for(auto i = 1; i < n; ++ i) push(i);
	}
};

// DEBUG BEGIN
#ifdef LOCAL
template<class L, class R> ostream &operator<<(ostream &out, const pair<L, R> &p){
	return out << "(" << p.first << ", " << p.second << ")";
}
template<class Tuple, size_t N> struct TuplePrinter{
	static ostream &print(ostream &out, const Tuple &t){ return TuplePrinter<Tuple, N-1>::print(out, t) << ", " << get<N-1>(t); }
};
template<class Tuple> struct TuplePrinter<Tuple, 1>{
	static ostream &print(ostream &out, const Tuple& t){ return out << get<0>(t); }
};
template<class... Args> ostream &print_tuple(ostream &out, const tuple<Args...> &t){
	return TuplePrinter<decltype(t), sizeof...(Args)>::print(out << "(", t) << ")";
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
void debug_out(){ cerr << "\b\b " << endl; }
template<class Head, class... Tail>
void debug_out(Head H, Tail... T){ cerr << H << ", ", debug_out(T...); }
void debug2_out(){ cerr << "\n"; }
template<class Head, class... Tail>
void debug2_out(Head H, Tail... T){ cerr << "\n"; for(auto x: H) cerr << x << "\n"; debug2_out(T...); }
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]: ", debug_out(__VA_ARGS__)
#define debug2(...) cerr << "[" << #__VA_ARGS__ << "]", debug2_out(__VA_ARGS__)
#else
#define debug(...) 42
#define debug2(...) 42
#endif
// DEBUG END

int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	int n, qn;
	cin >> n >> qn;
	vector<tuple<int, int, char>> query(qn);
	vector<int> cmpr{0, n + 1};
	for(auto &[i, j, type]: query){
		cin >> i >> j >> type;
		cmpr.push_back(i);
		cmpr.push_back(j);
	}
	sort(cmpr.begin(), cmpr.end());
	cmpr.erase(unique(cmpr.begin(), cmpr.end()), cmpr.end());
	int sz = (int)cmpr.size();
	for(auto &[i, j, type]: query){
		i = lower_bound(cmpr.begin(), cmpr.end(), i) - cmpr.begin();
		j = lower_bound(cmpr.begin(), cmpr.end(), j) - cmpr.begin();
	}
	reverse_segment_tree<int> up(sz, [&](int x, int y){ return max(x, y); }, [&](int, int){ return 0; });
	reverse_segment_tree<int> left(sz, [&](int x, int y){ return max(x, y); }, [&](int, int){ return 0; });
	set<array<int, 2>> rem;
	debug(cmpr);
	for(auto [i, j, type]: query){
		debug(i, j, type);
		if(rem.count({i, j})){
			cout << "0\n";
			continue;
		}
		rem.insert({i, j});
		if(type == 'L'){
			swap(i, j);
			swap(up, left);
		}
		int bound = up.query(i);
		debug(bound, j);
		cout << cmpr[j] - cmpr[bound] << "\n";
		left.update(bound + 1, j + 1, i);
		if(type == 'L'){
			swap(i, j);
			swap(up, left);
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