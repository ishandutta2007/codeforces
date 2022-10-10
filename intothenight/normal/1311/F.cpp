#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/rope>
using namespace std;
using namespace __gnu_pbds;
using namespace __gnu_cxx;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
mt19937_64 rngll(chrono::steady_clock::now().time_since_epoch().count());
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

typedef tuple<int, int, int, int> tpl;
int main(){
	cin.tie(0)->sync_with_stdio(0);
	int n;
	cin >> n;
	vector<pair<int, int>> a(n);
	for(int i = 0; i < n; ++ i){
		cin >> a[i].first;
	}
	for(int i = 0; i < n; ++ i){
		cin >> a[i].second;
	}
	sort(a.begin(), a.end());
	vector<pair<int, int>> event;
	for(int i = 0; i < n; ++ i){
		event.emplace_back(a[i].second, i);
	}
	sort(event.begin(), event.end());
	segment sumtr(vector<long long>(n, 0), plus<long long>(), 0LL);
	segment cnttr(vector<int>(n, 0), plus<int>(), 0);
	long long res = 0;
	for(auto [_, i]: event){
		res += 1LL * a[i].first * cnttr.query(0, i) - sumtr.query(0, i);
		sumtr.update(i, a[i].first);
		cnttr.update(i, 1);
	}
	cout << res;
	return 0;
}

/*
vi <= vj -> add xj - xi
*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////