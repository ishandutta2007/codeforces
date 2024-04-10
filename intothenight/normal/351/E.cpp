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
	int n;
	cin >> n;
	vector<int> a(n);
	copy_n(istream_iterator<int>(cin), n, a.begin());
	vector<pair<int, int>> t;
	for(int i = 0; i < n; ++ i){
		t.emplace_back(a[i] = abs(a[i]), i);
	}
	sort(t.rbegin(), t.rend());
	segment tr(vector<int>(n), plus<int>(), 0);
	int res = 0;
	for(int x = 0; x <= 100000; ++ x){
		vector<int> ind;
		while(!t.empty() && t.back().first == x){
			ind.push_back(t.back().second);
			t.pop_back();
		}
		if(!ind.empty()){
			int cur_res = numeric_limits<int>::max();
			for(int cnt = 0; cnt <= int(ind.size()); ++ cnt){
				int cur = 0;
				for(int i = 0; i < cnt; ++ i){
					cur += tr.query(0, ind[i]);
				}
				for(int i = cnt; i < int(ind.size()); ++ i){
					cur += tr.query(ind[i], n);
				}
				ctmin(cur_res, cur);
			}
			for(auto i: ind){
				tr.update(i, 1);
			}
			res += cur_res;
		}
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