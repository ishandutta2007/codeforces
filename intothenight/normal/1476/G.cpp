#include <bits/stdc++.h>
using namespace std;

struct unital_sorter{
	// n: # of items
	// m: maximum possible freq
	// order: list of items sorted by freq (tie broken arbitrarily)
	// freq[x]: frequency of the item x
	// fpos[f]: starting position of items for freqeuncy f
	int n, m;
	vector<int> order, pos, freq, fpos;
	// O(n + m)
	unital_sorter(int n, int m): n(n), m(m), order(n), pos(n), freq(n), fpos(m + 2, n){
		fpos[0] = 0;
		iota(order.begin(), order.end(), 0);
		iota(pos.begin(), pos.end(), 0);
	}
	// O(n + m)
	unital_sorter(int n, int m, const vector<int> &freq): n(n), m(m), pos(n), freq(freq), fpos(m + 2, n){
		assert((int)freq.size() == n && *max_element(freq.begin(), freq.end()) <= m);
		iota(order.begin(), order.end(), 0);
		vector<vector<int>> occur(m + 1);
		for(auto i = 0; i < n; ++ i) occur[freq[i]].push_back(i);
		for(auto f = 0; f <= m; ++ f){
			fpos[f] = (int)order.size();
			order.insert(order.end(), occur[f].begin(), occur[f].end());
			for(auto t = fpos[f]; t < (int)order.size(); ++ t) pos[order[t]] = t;
		}
	}
	// O(1)
	void insert(int x){
		assert(freq[x] + 1 <= m);
		-- fpos[++ freq[x]];
		int y = order[fpos[freq[x]]];
		swap(pos[x], pos[y]);
		swap(order[pos[x]], order[pos[y]]);
	}
	// O(1)
	void erase(int x){
		assert(freq[x]);
		int y = order[fpos[freq[x]]];
		swap(pos[x], pos[y]);
		swap(order[pos[x]], order[pos[y]]);
		++ fpos[freq[x] --];
	}
};

// Reorder N 3D points with max_x - min_x <= X, max_y - min_y <= Y, max_z - min_z <= Z
// so that sum(abs(xi - x(i+1)) + abs(yi - y(i+1)) + abs(zi - z(i+1)))) is small
// and process queries on the new order.
// N * BX inc_x and dec_x calls, N * BY + X * Y / BX inc_y and dec_y calls, and N * X * Y / BX / BY inc_z and dec_z calls
// set BX = BY = cbrt(X Y) to achieve N cbrt(X Y) calls
template<int BX, int BY>
struct mo_3d{
	vector<array<int, 4>> points; // x, y, z, ind
	void insert(int x, int y, int z, int id){
		points.push_back({x, y, z, id});
	}
	// starting from (0, 0, 0), access each points and execute queries
	void solve(auto inc_x, auto dec_x, auto inc_y, auto dec_y, auto inc_z, auto dec_z, auto process){
		auto cmp = [&](const auto &p, const auto &q)->bool{
			return p[0] / BX != q[0] / BX ? p[0] < q[0] : p[1] / BY != q[1] / BY ? p[1] < q[1] : p[2] < q[2];
		};
		sort(points.begin(), points.end(), cmp);
		int x = 0, y = 0, z = 0;
		for(auto &[qx, qy, qz, id]: points){
			while(qx < x) dec_x(), -- x;
			while(y < qy) inc_y(), ++ y;
			while(x < qx) inc_x(), ++ x;
			while(qy < y) dec_y(), -- y;
			while(qz < z) dec_z(), -- z;
			while(z < qz) inc_z(), ++ z;
			process(id);
		}
	}
};

int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	int n, qn;
	cin >> n >> qn;
	vector<int> a(n);
	const int mx = 1e5;
	for(auto i = 0; i < n; ++ i){
		cin >> a[i], -- a[i];
	}
	auto a_copy = a;
	vector<array<int, 3>> modify(qn, {-1, -1, -1});
	vector<int> kval(qn, -1);
	mo_3d<(int)pow(mx, 2.0 / 3), (int)pow(mx, 2.0 / 3)> mo;
	for(auto qi = 0; qi < qn; ++ qi){
		int type;
		cin >> type;
		if(type == 1){
			int l, r, k;
			cin >> l >> r >> k, -- l;
			kval[qi] = k;
			mo.insert(l, r, qi, qi);
		}
		else{
			int p, x;
			cin >> p >> x, -- p, -- x;
			modify[qi] = {p, a[p], x};
			a[p] = x;
		}
	}
	a = a_copy;
	unital_sorter sorter(mx, mx);
	int l = 0, r = 0, t = 0;
	auto inc_x = [&]()->void{
		sorter.erase(a[l ++]);
	};
	auto dec_x = [&]()->void{
		sorter.insert(a[-- l]);
	};
	auto inc_y = [&]()->void{
		sorter.insert(a[r ++]);
	};
	auto dec_y = [&]()->void{
		sorter.erase(a[-- r]);
	};
	auto inc_z = [&]()->void{
		if(~modify[t][0]){
			auto [p, x, y] = modify[t];
			if(l <= p && p < r){
				sorter.erase(x);
				sorter.insert(y);
			}
			a[p] = y;
		}
		++ t;
	};
	auto dec_z = [&]()->void{
		-- t;
		if(~modify[t][0]){
			auto [p, x, y] = modify[t];
			if(l <= p && p < r){
				sorter.erase(y);
				sorter.insert(x);
			}
			a[p] = x;
		}
	};
	vector<int> res(qn, -2);
	auto process = [&](int qi)->void{
		int k = kval[qi], dif = numeric_limits<int>::max();
		for(auto i = sorter.fpos[1]; i < sorter.n; i = sorter.fpos[sorter.freq[sorter.order[i]] + 1]){
			if(i + k > sorter.n){
				break;
			}
			dif = min(dif, sorter.freq[sorter.order[i + k - 1]] - sorter.freq[sorter.order[i]]);
		}
		res[qi] = dif == numeric_limits<int>::max() ? -1 : dif;
	};
	mo.solve(inc_x, dec_x, inc_y, dec_y, inc_z, dec_z, process);
	for(auto x: res){
		if(x >= -1){
			cout << x << "\n";
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