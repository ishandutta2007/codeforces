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
struct sparse_table{
	int N;
	BO bin_op;
	const T id;
	vector<vector<T>> val;
	vector<int> bit;
	template<typename IT>
	sparse_table(IT begin, IT end, BO bin_op, T id): N(distance(begin, end)), bin_op(bin_op), id(id), val(__lg(N) + 1, vector<T>(begin, end)), bit(N + 1){
		for(int i = 1; i <= N; ++ i) bit[i] = __lg(i);
		for(int i = 0; i < __lg(N); ++ i) for(int j = 0; j < N; ++ j){
			val[i + 1][j] = bin_op(val[i][j], val[i][min(N - 1, j + (1 << i))]);
		}
	}
	sparse_table(){ }
	T query(int l, int r){
		if(l >= r) return id;
		int d = bit[r - l];
		return bin_op(val[d][l], val[d][r - (1 << d)]);
	}
};

template<typename Pred>
long long custom_binary_search(long long low, long long high, Pred p, bool is_left = true){
	assert(low < high);
	if(is_left){
		while(high - low > 1){
			long long mid = low + (high - low >> 1);
			p(mid) ? low = mid : high = mid;
		}
		return low;
	}
	else{
		while(high - low > 1){
			long long mid = low + (high - low >> 1);
			p(mid) ? high = mid : low = mid;
		}
		return high;
	}
}

int main(){
	cin.tie(0)->sync_with_stdio(0);
	int n;
	cin >> n;
	vector<int> a(n);
	for(auto i = 0; i < n; ++ i){
		cin >> a[i];
	}
	long long sum = 0;
	map<long long, vector<int>> q;
	q[0].push_back(0);
	for(auto i = 0; i < n; ++ i){
		sum += a[i];
		q[sum].push_back(i + 1);
	}
	vector<int> reach(n, n);
	for(auto &[_, t]: q){
		for(auto i = 0; i < int(t.size()) - 1; ++ i){
			reach[t[i]] = t[i + 1] - 1;
		}
	}
	sparse_table st(reach.begin(), reach.end(), [&](int x, int y){ return min(x, y); }, numeric_limits<int>::max());
	long long res = 0;
	for(auto i = 0; i < n; ++ i){
		res += custom_binary_search(i, n + 1, [&](int p){ return st.query(i, p) >= p; }) - i;
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