#include <bits/stdc++.h>
using namespace std;

struct wavelet_tree{
	int sigma; // size of the alphabet, all elements lie within [0, sigma)
	vector<vector<int>> data; // data[u][i]: # of elements mapped to left among first i elements
	wavelet_tree(){ }
	wavelet_tree(const vector<int> &a, int sigma): data(sigma << 1), sigma(sigma){
		assert(all_of(a.begin(), a.end(), [&](int x){ return 0 <= x && x < sigma; }));
		auto temp = a;
		auto build = [&](auto build, int u, int l, int r, int low, int high)->void{
			if(r - l == 1) return;
			int m = l + (r - l >> 1);
			data[u].resize(high - low + 1);
			for(auto i = low; i < high; ++ i) data[u][i - low + 1] = data[u][i - low] + (temp[i] < m);
			int mid = stable_partition(temp.begin() + low, temp.begin() + high, [&](int x){ return x < m; }) - temp.begin();
			build(build, u << 1, l, m, low, mid), build(build, u << 1 | 1, m, r, mid, high);
		};
		build(build, 1, 0, sigma, 0, (int)a.size());
	}
	// Count occurrences of x in the interval [0, qr)
	// O(log sigma)
	int count(int qr, int x) const{
		for(auto u = 1, l = 0, r = sigma; r - l >= 2; ){
			auto m = l + (r - l >> 1);
			x < m ? (qr = data[u][qr], r = m, u = u << 1) : (qr -= data[u][qr], l = m, u = u << 1 | 1);
		}
		return qr;
	}
	// Count occurrences of x in the interval [ql, qr)
	// O(log sigma)
	int count(int ql, int qr, int x) const{
		return count(qr, x) - count(ql, x);
	}
	// Count of occurrences of numbers in [xl, xr) in the interval [ql, qr)
	// O(log sigma)
	int count(int ql, int qr, int xl, int xr) const{
		if(qr <= ql || xr <= xl) return 0;
		auto recurse = [&](auto recurse, int u, int l, int r, int cl, int cr){
			if(r <= xl || xr <= l) return 0;
			if(xl <= l && r <= xr) return cr - cl;
			int m = l + (r - l >> 1), lcnt = data[u][cl], rcnt = data[u][cr];
			return recurse(recurse, u << 1, l, m, lcnt, rcnt) + recurse(recurse, u << 1 | 1, m, r, cl - lcnt, cr - rcnt);
		};
		return recurse(recurse, 1, 0, sigma, ql, qr);
	}
	// Find the k-th smallest element in the interval [ql, qr)
	// O(log sigma)
	int find_by_order(int ql, int qr, int k) const{
		assert(0 <= k && k < qr - ql);
		for(auto u = 1, l = 0, r = sigma; ; ){
			if(r - l == 1) return l;
			auto m = l + (r - l >> 1), ri = data[u][ql], rj = data[u][qr];
			if(k < rj - ri) ql = ri, qr = rj, r = m, u = u << 1;
			else k -= rj - ri, ql -= ri, qr -= rj, l = m, u = u << 1 | 1;
		}
		assert(false);
	}
};

int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	int n, qn;
	cin >> n >> qn;
	vector<int> a(n);
	for(auto i = 0; i < n; ++ i){
		cin >> a[i], -- a[i];
	}
	wavelet_tree wave(a, n);
	for(auto qi = 0; qi < qn; ++ qi){
		int l, r;
		cin >> l >> r, -- l;
		cout << max(1, 2 * wave.count(l, r, wave.find_by_order(l, r, r - l >> 1)) - (r - l)) << "\n";
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