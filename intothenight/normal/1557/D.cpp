#include <bits/stdc++.h>
using namespace std;
template<class T, class U> T &ctmax(T &x, const U &y){ return x = max<T>(x, y); }
template<class T, class U> T &ctmin(T &x, const U &y){ return x = min<T>(x, y); }

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
			process(max(l, it->first[0]), min(r, it->first[1]), it->second);
			// process(l, r, pc): color of range [l, r) is changed from pc to c
			I = {min(I[0], it->first[0]), max(I[1], it->first[1])};
			it = intervals.erase(it);
		}
		intervals.insert({I, c});
	}
};

int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	int n, m;
	cin >> n >> m;
	vector<vector<array<int, 2>>> segments(n);
	for(auto rep = m; rep; -- rep){
		int i, l, r;
		cin >> i >> l >> r, -- i, -- l;
		segments[i].push_back({l, r});
	}
	color_processor<int, array<int, 2>> cp({0, -1});
	vector<int> prev(n, -1);
	for(auto i = 0; i < n; ++ i){
		{
			sort(segments[i].begin(), segments[i].end());
			vector<array<int, 2>> temp;
			for(auto [l, r]: segments[i]){
				if(!temp.empty() && l <= temp.back()[1]){
					ctmax(temp.back()[1], r);
				}
				else{
					temp.push_back({l, r});
				}
			}
			swap(segments[i], temp);
		}
		array<int, 2> mxval{0, -1};
		for(auto [l, r]: segments[i]){
			cp.paint(l, r, {0, i}, [&](int l, int r, array<int, 2> pmax){ ctmax(mxval, array{pmax[0] + 1, pmax[1]}); });
		}
		prev[i] = mxval[1];
		for(auto [l, r]: segments[i]){
			cp.belongs(l)->second[0] = mxval[0];
		}
	}
	array<int, 2> res{numeric_limits<int>::max(), -1};
	for(auto [interval, mxval]: cp.intervals){
		ctmin(res, array{n - mxval[0], mxval[1]});
	}
	cout << res[0] << "\n";
	vector<bool> remove(n, true);
	for(auto i = res[1]; ~i; i = prev[i]){
		remove[i] = false;
	}
	for(auto i = 0; i < n; ++ i){
		if(remove[i]){
			cout << i + 1 << " ";
		}
	}
	cout << "\n";
	return 0;
}

/*

*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////