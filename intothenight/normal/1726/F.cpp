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
	auto cover(B l, B r, C c, auto process){
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
		return intervals.insert({I, c});
	}
	auto cover(B l, B r, C c){
		return cover(l, r, c, [&](B, B, C){  });
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

int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	int n, t;
	cin >> n >> t;
	vector<array<int, 2>> a(n);
	for(auto i = 0; i < n; ++ i){
		cin >> a[i][0] >> a[i][1];
	}
	long long sum = 0;
	for(auto i = 0; i < n - 1; ++ i){
		int x;
		cin >> x;
		sum += x;
		a[i + 1][1] = (a[i + 1][1] + sum % t) % t;
	}
	color_processor<int, pair<int, long long>> cp;
	cp.cover(0, t, {0, 0});
	auto set_red = [&](int l, int r)->void{
		pair<int, long long> c{-1, 0};
		if(r == t){
			c.second = r + cp.belongs(0)->second.second;
		}
		else{
			auto it = cp.belongs(r);
			c.second = r + r * it->second.first + it->second.second;
		}
		cp.cover(l, r, c);
	};
	for(auto [g, init]: a | ranges::views::reverse){
		if(init <= g){
			set_red(g - init, t - init);
		}
		else{
			set_red(0, t - init);
			set_red(t - (init - g), t);
		}
	}
	long long res = numeric_limits<long long>::max();
	for(auto [r, c]: cp.intervals){
		if(0 <= r[0] && r[1] <= t){
			assert(r[0] < r[1]);
			res = min(res, (r[1] - 1) * c.first + c.second);
		}
	}
	res += sum;
	cout << res << "\n";
	return 0;
}

/*

*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////