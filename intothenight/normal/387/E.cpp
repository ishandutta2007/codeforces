#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace chrono;
using namespace __gnu_pbds;
mt19937 rng(high_resolution_clock::now().time_since_epoch().count());
mt19937_64 rngll(high_resolution_clock::now().time_since_epoch().count());
template<typename T> T ctmax(T &x, const T &y){ return x = max(x, y); }
template<typename T> T ctmin(T &x, const T &y){ return x = min(x, y); }
template<typename T> using Tree = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

template<typename T, typename BO>
struct segment{
	int N;
	BO bin_op;
	const T id;
	vector<T> val;
	segment(const vector<T> &arr, BO bin_op, T id): N(arr.size()), bin_op(bin_op), id(id), val(N << 1, id){
		for(int i = 0; i < N; ++ i) val[i + N] = arr[i];
		for(int i = N - 1; i > 0; -- i) val[i] = bin_op(val[i << 1], val[i << 1 | 1]);
	}
	void set(int p, T x){
		for(p += N, val[p] = x; p > 1; p >>= 1) val[p >> 1] = bin_op(val[p], val[p ^ 1]);
	}
	void update(int p, T x){
		for(p += N, val[p] = bin_op(val[p], x); p > 1; p >>= 1) val[p >> 1] = bin_op(val[p], val[p ^ 1]);
	}
	T query(int l, int r){
		if(l >= r) return id;
		T resl = id, resr = id;
		for(l += N, r += N; l < r; l >>= 1, r >>= 1){
			if(l & 1) resl = bin_op(resl, val[l ++]);
			if(r & 1) resr = bin_op(val[-- r], resr);
		}
		return bin_op(resl, resr);
	}
};

int main(){
	cin.tie(0)->sync_with_stdio(0);
	int n, k;
	cin >> n >> k;
	vector<int> a(n), b(k);
	copy_n(istream_iterator<int>(cin), n, a.begin()), copy_n(istream_iterator<int>(cin), k, b.begin());
	sort(b.begin(), b.end());
	vector<pair<int, int>> t;
	set<int> q{-1, n};
	for(int i = 0; i < n; ++ i){
		if(!binary_search(b.begin(), b.end(), a[i])){
			t.emplace_back(i, 1);
		}
		else{
			t.emplace_back(i, 0);
		}
	}
	sort(t.begin(), t.end(), [&](pair<int, int> x, pair<int, int> y){ return a[x.first] < a[y.first]; });
	long long res = 0;
	segment tr(vector<int>(n), plus<int>(), 0);
	for(auto [i, type]: t){
		auto p = q.lower_bound(i);
		if(type) res += *p - *prev(p) - 1 - tr.query(*prev(p) + 1, *p), tr.update(i, 1);
		else q.insert(i);
	}
	cout << res;
	return 0;
}

/*

*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////