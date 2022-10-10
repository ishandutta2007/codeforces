#include <bits/stdc++.h>
using namespace std;

template<class T>
struct segment_tree{
	int n;
	const T inf = numeric_limits<T>::max();
	vector<T> data_sum, data_max;
	segment_tree(const vector<int> &a): n((int)a.size()), data_sum(n << 1), data_max(n << 1){
		build(a, 0, 0, n);
	}
	void build(const vector<int> &a, int u, int l, int r){
		if(l + 1 == r) data_sum[u] = data_max[u] = a[l];
		else{
			int m = l + (r - l >> 1), v = u + 1, w = u + (m - l << 1);
			build(a, v, l, m), build(a, w, m, r);
			data_sum[u] = data_sum[v] + data_sum[w];
			data_max[u] = max(data_max[v], data_max[w]);
		}
	}
	void refresh(int u, int l, int r){
		int v = u + 1, w = u + (r - l >> 1 << 1);
		data_sum[u] = data_sum[v] + data_sum[w];
		data_max[u] = max(data_max[v], data_max[w]);
	}
	void update_mod(int ql, int qr, int mod){
		auto recurse = [&](auto self, int u, int l, int r)->void{
			if(qr <= l || r <= ql || data_max[u] < mod) return;
			if(ql <= l && r <= qr && r - l == 1){
				data_max[u] = data_sum[u] %= mod;
				return;
			}
			int m = l + (r - l >> 1);
			self(self, u + 1, l, m), self(self, u + (m - l << 1), m, r);
			refresh(u, l, r);
		};
		recurse(recurse, 0, 0, n);
	}
	void set(int p, int x){
		auto recurse = [&](auto self, int u, int l, int r)->void{
			if(p < l || r <= p) return;
			if(r - l == 1){
				data_max[u] = data_sum[u] = x;
				return;
			}
			int m = l + (r - l >> 1);
			self(self, u + 1, l, m), self(self, u + (m - l << 1), m, r);
			refresh(u, l, r);
		};
		recurse(recurse, 0, 0, n);
	}
	T query(int ql, int qr){
		auto recurse = [&](auto self, int u, int l, int r)->T{
			if(qr <= l || r <= ql) return 0;
			if(ql <= l && r <= qr) return data_sum[u];
			int m = l + (r - l >> 1);
			return self(self, u + 1, l, m) + self(self, u + (m - l << 1), m, r);
		};
		return recurse(recurse, 0, 0, n);
	}
};

int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	int n, qn;
	cin >> n >> qn;
	vector<int> a(n);
	for(auto &x: a){
		cin >> x;
	}
	segment_tree<long long> seg(a);
	for(auto qi = 0; qi < qn; ++ qi){
		int type;
		cin >> type;
		if(type == 1){
			int l, r;
			cin >> l >> r, -- l;
			cout << seg.query(l, r) << "\n";
		}
		else if(type == 2){
			int l, r, mod;
			cin >> l >> r >> mod, -- l;
			seg.update_mod(l, r, mod);
		}
		else{
			int p, x;
			cin >> p >> x, -- p;
			seg.set(p, x);
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