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

// O(n log n)
// Requires fenwick_tree
template<class T, class Compare = less<>>
long long count_inversions(const vector<T> &a, bool count_equal = false, Compare cmp = less<>()){
	int n = (int)a.size();
	vector<T> cmpr = a;
	sort(cmpr.begin(), cmpr.end(), cmp);
	fenwick_tree<int> rsumq(n);
	long long res = 0;
	for(auto x: a){
		int i = lower_bound(cmpr.begin(), cmpr.end(), x, cmp) - cmpr.begin();
		res += rsumq.query(i + !count_equal, n);
		rsumq.update(i, 1);
	}
	return res;
}

struct T{
	int a, b;
	bool operator<(const T &otr) const{
		return 1LL * a * otr.b < 1LL * otr.a * b;
	}
	bool operator==(const T &otr) const{
		return 1LL * a * otr.b == 1LL * otr.a * b;
	}
	friend ostream &operator<<(ostream &out, const T &t){
		return out << "(" << t.a << ", " << t.b << ")";
	}
};

int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	int n, w;
	cin >> n >> w;
	vector<array<int, 2>> a(n);
	vector<pair<T, T>> p(n);
	for(auto i = 0; i < n; ++ i){
		auto &[x, v] = a[i];
		cin >> x >> v;
		p[i] = {{abs(x), abs(v + w)}, {abs(x), abs(v - w)}};
	}
	sort(p.begin(), p.end(), [&](auto x, auto y){
		if(x.first == y.first){
			return y.second < x.second;
		}
		else{
			return x.first < y.first;
		}
	});
	vector<T> ps(n);
	for(auto i = 0; i < n; ++ i){
		ps[i] = p[i].second;
	}
	cout << count_inversions(ps, true) << "\n";
	return 0;
}

/*

*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////