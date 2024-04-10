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
	segment(int N, BO bin_op, T id): N(N), bin_op(bin_op), id(id), val(N << 1, id){
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
	int res = 0;
	segment tr(20000001, plus<int>(), 0);
	vector<int> updates;
	for(int mask = 1; mask <= 20000000; mask <<= 1){
		int cnt = 0;
		for(int i = 0; i < n; ++ i){
			if(a[i] & mask){
				if(i - cnt & 1){
					res ^= mask;
				}
			}
			else{
				if(cnt & 1){
					res ^= mask;
				}
			}
			cnt += !!(a[i] & mask);
			int rem = a[i] & mask - 1;
			if(tr.query(mask - rem, mask) & 1){
				res ^= mask;
			}
			tr.update(rem, 1);
			updates.push_back(rem);
		}
		for(auto x: updates){
			tr.update(x, -1);
		}
		updates.clear();
	}
	cout << res;
	return 0;
}

/*
30 * 30 *  4 * 10^5

*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////