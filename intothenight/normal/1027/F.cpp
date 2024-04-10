#include "bits/stdc++.h"
using namespace std;
template<typename T, typename U> T &ctmax(T &x, const U &y){ return x = max<T>(x, y); }
template<typename T, typename U> T &ctmin(T &x, const U &y){ return x = min<T>(x, y); }

struct disjoint_set{
	vector<int> p, cycle;
	disjoint_set(int n): p(n, -1), cycle(n){ }
	bool share(int a, int b){ return root(a) == root(b); }
	int sz(int u){ return -p[root(u)]; }
	int root(int u){ return p[u] < 0 ? u : root(p[u]); }
	bool merge(int u, int v){
		u = root(u), v = root(v);
		if(u == v) return false;
		if(p[u] > p[v]) swap(u, v);
		p[u] += p[v], p[v] = u;
		if(cycle[v]) cycle[u] = true;
		return true;
	}
};

template<typename Pred>
long long custom_binary_search(long long low, long long high, Pred p, const bool &is_left = true){
	assert(low < high);
	while(high - low > 1){
		auto mid = low + (high - low >> 1);
		(p(mid) == is_left ? low : high) = mid;
	}
	return is_left ? low : high;
}

int main(){
	cin.tie(0)->sync_with_stdio(0);
	int n;
	cin >> n;
	vector<array<int, 2>> a(n);
	vector<int> cmpr;
	for(auto i = 0; i < n; ++ i){
		cin >> a[i][0] >> a[i][1];
		cmpr.push_back(a[i][0]), cmpr.push_back(a[i][1]);
	}
	sort(cmpr.begin(), cmpr.end()), cmpr.erase(unique(cmpr.begin(), cmpr.end()), cmpr.end());
	auto ind = [&](int x){
		return lower_bound(cmpr.begin(), cmpr.end(), x) - cmpr.begin();
	};
	int LB = 0;
	for(auto &[x, y]: a){
		x = ind(x), y = ind(y);
		ctmax(LB, x);
	}
	auto pred = [&](int d){ // Can he pass before day d? (inclusive)
		disjoint_set dsu(d + 1);
		for(auto [x, y]: a){
			if(y > d){
				y = x;
			}
			if(dsu.share(x, y)){
				int r = dsu.root(x);
				if(dsu.cycle[r]){
					return false;
				}
				dsu.cycle[r] = true;
			}
			else if(dsu.cycle[dsu.root(x)] && dsu.cycle[dsu.root(y)]){
				return false;
			}
			else{
				dsu.merge(x, y);
			}
		}
		return true;
	};
	if(!pred(2 * n)){
		cout << "-1\n";
	}
	else{
		cout << cmpr[custom_binary_search(LB - 1, 2 * n, pred, false)] << "\n";
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