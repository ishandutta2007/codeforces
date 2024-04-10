#include <bits/stdc++.h>
using namespace std;

template<class T>
struct fenwick_tree{
	int n;
	vector<T> data;
	fenwick_tree(){ }
	// O(n)
	fenwick_tree(int n): n(n), data(n){ }
	// O(n)
	fenwick_tree(int n, T init): fenwick_tree(vector<T>(n, init)){ }
	// O(n)
	fenwick_tree(const vector<T> &v): n((int)v.size()), data(v){
		for(auto i = 1; i <= n; ++ i) if(i + (i & -i) <= n) data[i + (i & -i) - 1] += data[i - 1];
	}
	// O(log n)
	void update(int p, T x){
		assert(0 <= p && p < n);
		for(++ p; p <= n; p += p & -p) data[p - 1] += x;
	}
	// O(log n)
	T query(int r) const{
		T s{};
		for(; r > 0; r -= r & -r) s += data[r - 1];
		return s;
	}
	// O(log n)
	T query(int l, int r) const{
		assert(0 <= l && l <= r && r <= n);
		return query(r) - query(l);
	}
	// f(sum[0, r)) is T, T, ..., T, F, F, ..., F, returns min r with F (n + 1 if no such r)
	// O(log n)
	template<class F> int max_pref(F f) const{
		if(!f({})) return 0;
		int p = 0;
		T pref{};
		for(auto pw = 1 << __lg(n + 1); pw; pw >>= 1) if(p + pw <= n && f(pref + data[p + pw - 1])){
			pref += data[p + pw - 1];
			p += pw;
		}
		return p + 1;
	}
	int lower_bound(T x) const{
		if(x <= T{}) return 0;
		int p = 0;
		T pref{};
		for(auto pw = 1 << __lg(n + 1); pw; pw >>= 1) if(p + pw <= n && pref + data[p + pw - 1] < x){
			pref += data[p + pw - 1];
			p += pw;
		}
		return p + 1;
	}
	int upper_bound(T x) const{
		if(x < T{}) return 0;
		int p = 0;
		T pref{};
		for(auto pw = 1 << __lg(n + 1); pw; pw >>= 1) if(p + pw <= n && pref + data[p + pw - 1] <= x){
			pref += data[p + pw - 1];
			p += pw;
		}
		return p + 1;
	}
};

int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	int n;
	cin >> n;
	vector<int> a(n);
	for(auto i = 0; i < n; ++ i){
		cin >> a[i], a[i] = i - a[i];
	}
	const int SZ = max<int>(sqrt(n * log2(n)) * 0.15, 1);
	const int SZ2 = sqrt(n);
	const int B = n / SZ + 1;
	const int B2 = n / SZ2 + 1;
	vector<vector<int>> next(B);
	vector<vector<int>> next_lazy(B);
	vector<int> pivots(n);
	vector<fenwick_tree<int>> fw(B);
	for(auto b = 0; b < B; ++ b){
		fw[b] = {SZ * b + 1, 1};
		fw[b].update(SZ * b, n << 1);
		next[b].resize(SZ * b);
		next_lazy[b].resize(SZ * b / SZ2 + 1);
		iota(next[b].begin(), next[b].end(), 0);
		for(auto i = b * SZ; i < min(b * SZ + SZ, n); ++ i){
			pivots[i] = b * SZ;
		}
	}
	// O(SZ2 + n / SZ2)
	auto update = [&](int b, int l, int r, int x)->void{
		int bl = l / SZ2, br = r / SZ2;
		if(bl == br){
			for(auto i = l; i < r; ++ i){
				next[b][i] += x;
			}
		}
		else{
			for(auto i = l, ir = bl * SZ2 + SZ2; i < ir; ++ i){
				next[b][i] += x;
			}
			for(auto b2 = bl + 1; b2 < br; ++ b2){
				next_lazy[b][b2] += x;
			}
			for(auto i = br * SZ2; i < r; ++ i){
				next[b][i] += x;
			}
		}
	};
	// O(SZ log n + SZ2 + n / SZ2)
	auto rebuild = [&](int b)->void{
		assert(0 <= b && b < B);
		for(auto i = b * SZ, r = min(b * SZ + SZ, n); i < r; ++ i){
			fw[b].update(pivots[i], -1);
		}
		for(auto i = b * SZ, r = min(b * SZ + SZ, n); i < r; ++ i){
			int pivot_next = fw[b].upper_bound(a[i]) - 1;
			if(pivots[i] != pivot_next){
				if(pivots[i] + 1 == pivot_next){
					-- next[b][pivots[i]];
				}
				else if(pivots[i] - 1 == pivot_next){
					++ next[b][pivot_next];
				}
				else if(pivots[i] < pivot_next){
					update(b, pivots[i], pivot_next, -1);
				}
				else{
					update(b, pivot_next, pivots[i], 1);
				}
			}
			fw[b].update(pivots[i] = pivot_next, 1);
		}
	};
	for(auto b = 0; b < B; ++ b){
		rebuild(b);
	}
	int qn;
	cin >> qn;
	for(auto qi = 0; qi < qn; ++ qi){
		int type;
		cin >> type;
		if(type == 1){
			int p, x;
			cin >> p >> x, -- p, x = p - x;
			a[p] = x;
			rebuild(p / SZ);
		}
		else{ // O(SZ + B / SZ)
			int p;
			cin >> p, -- p;
			int x = a[p];
			for(auto q = p + 1, rep = min(p / SZ * SZ + SZ, n) - q; rep; -- rep){
				if(x >= a[q ++]){
					++ x;
				}
			}
			for(auto b = p / SZ + 1; b < B; ++ b){
				x = next[b][x] + next_lazy[b][x / SZ2];
			}
			cout << x + 1 << "\n";
		}
	}
	// q SZ + q B / SZ + q SZ log n + q SZ2 + q n / SZ2
	return 0;
}

/*
2 sqrt(n log n) -> 14.35
1.5 sqrt(n log n) -> 10.88
sqrt(n log n) -> 7.7
0.5 sqrt(n log n) -> 4.45
0.4 sqrt(n log n) -> 3.9
0.3 sqrt(n log n) -> 3.34
0.25 sqrt(n log n) -> 3.06
0.2 sqrt(n log n) -> 2.81

// DOUBLE QUERYIES

2 sqrt(n log n) -> 
1.5 sqrt(n log n) -> 
sqrt(n log n) -> 
0.5 sqrt(n log n) -> 
0.4 sqrt(n log n) -> 
0.3 sqrt(n log n) -> 
0.25 sqrt(n log n) -> 6.1
0.2 sqrt(n log n) -> 5.76
*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////