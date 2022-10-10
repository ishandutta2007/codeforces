#include <bits/stdc++.h>
using namespace std;
#if __cplusplus > 201703L
#include <ranges>
using namespace numbers;
#endif

// B: coordinate type, C: color type
template<class B, class C>
struct color_processor{
	map<array<B, 2>, C> intervals;
	color_processor(C initial_color = {}): intervals({{{numeric_limits<B>::min(), numeric_limits<B>::max()}, initial_color}}){ }
	auto belongs(B p){
		return prev(intervals.upper_bound({p, numeric_limits<B>::max()}));
	}
	// Cover the range [l, r) with the color c
	// process(l, r, pc): color of range [l, r) is changed from pc to c
	// Amortized O(1) process calls
	void cover(B l, B r, C c, auto process){
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
			process(max(l, it->first[0]), min(r, it->first[1]), it->second);
			I = {min(I[0], it->first[0]), max(I[1], it->first[1])};
			it = intervals.erase(it);
		}
		intervals.insert({I, c});
	}
	void cover(B l, B r, C c){
		cover(l, r, c, [&](B, B, C){  });
	}
	// new_color(l, r, c): returns the new color for the range [l, r), previously colored with c
	// O(Number of color ranges affected)
	void recolor(B l, B r, auto new_color){
		auto left = intervals.lower_bound({l, l});
		if(l < left->first[0]){
			-- left;
			auto [range, c] = *left;
			left = intervals.erase(left);
			left = intervals.insert(left, {{range[0], l}, c});
			left = intervals.insert(left, {{l, range[1]}, c});
		}
		auto right = intervals.lower_bound({r, r});
		if(r < right->first[0]){
			-- right;
			auto [range, c] = *right;
			right = intervals.erase(right);
			right = intervals.insert(right, {{range[0], r}, c});
			right = intervals.insert(right, {{r, range[1]}, c});
		}
		for(auto it = left; it != right; ++ it) it->second = new_color(it->first[0], it->first[1], it->second);
	}
};

template<class U, class F1, class F2>
struct reverse_segment_tree{
	int n, size, log;
	vector<U> updates;
	F1 UU; // semigroup operation (superset, subset)
	F2 U_init; // semigroup default element for the interval [l, r)
	reverse_segment_tree(int n, F1 UU, F2 U_init){
		vector<U> a(n);
		for(auto i = 0; i < n; ++ i) a[i] = U_init(i, i + 1);
		*this = reverse_segment_tree(a, UU, U_init);
	}
	reverse_segment_tree(int n, U init, F1 UU, F2 U_init): reverse_segment_tree(vector<U>(n, init), UU, U_init){ }
	reverse_segment_tree(const vector<U> &a, F1 UU, F2 U_init): n((int)a.size()), UU(UU), U_init(U_init){
		log = __lg(max(n - 1, 1)) + 1, size = 1 << log;
		updates = vector<U>(size << 1);
		copy(a.begin(), a.end(), updates.begin() + size);
		for(auto i = 1; i < size; ++ i){
			int h = log - __lg(i);
			updates[i] = U_init((i << h) - size, (i + 1 << h) - size);
		}
	}
	void update(int l, int r, U x){
		assert(0 <= l && l <= r && r <= n);
		if(l == r) return;
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
		assert(0 <= p && p < n);
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
	template<class output_stream>
	friend output_stream &operator<<(output_stream &out, const reverse_segment_tree<U, F1, F2> &seg){
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
	int n, qn;
	cin >> n >> qn;
	color_processor<int, int> cp;
	reverse_segment_tree base(n, 0LL, plus<>(), [&](int, int){ return 0LL; });
	vector<long long> delta(n);
	for(auto qi = 0; qi < qn; ++ qi){
		string type;
		cin >> type;
		if(type == "Color"){
			int l, r, c;
			cin >> l >> r >> c, -- l, -- c;
			cp.cover(l, r, c, [&](int l, int r, int old_c){
				base.update(l, r, delta[old_c] - delta[c]);
			});
		}
		else if(type == "Add"){
			int c, x;
			cin >> c >> x, -- c;
			delta[c] += x;
		}
		else{
			int p;
			cin >> p, -- p;
			cout << base.query(p) + delta[cp.belongs(p)->second] << "\n";
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