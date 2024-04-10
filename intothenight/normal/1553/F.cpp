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
	int max_pref(auto f) const{
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
	const int mx = 3e5;
	vector<int> a(n);
	vector<long long> pref(n + 1), res(n);
	fenwick_tree<int> fw1(mx + 1);
	fenwick_tree<long long> fw2(mx + 1);
	for(auto i = 0; i < n; ++ i){
		cin >> a[i];
		pref[i + 1] = pref[i] + a[i];
		res[i] = pref[i] + 1LL * a[i] * i;
		for(auto q = 1; q <= mx / a[i]; ++ q){
			res[i] -= 1LL * a[i] * q * fw1.query(a[i] * q, min(a[i] * q + a[i], mx + 1));
		}
		for(auto l = 1, r = 1; l <= a[i]; l = r + 1){
			r = a[i] / (a[i] / l);
			res[i] -= a[i] / l * fw2.query(l, r + 1);
		}
		fw1.update(a[i], 1);
		fw2.update(a[i], a[i]);
	}
	for(auto i = 1; i < n; ++ i){
		res[i] += res[i - 1];
	}
	for(auto x: res){
		cout << x << " ";
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