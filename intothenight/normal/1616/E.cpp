#include <bits/stdc++.h>
using namespace std;
#if __cplusplus > 201703L
#include <ranges>
using namespace numbers;
#endif
template<class T> T &ctmin(T &x){ return x; }
template<class T, class Head, class ...Tail> T &ctmin(T &x, const Head &h, const Tail &... t){ return ctmin(x = min<T>(x, h), t...); }
template<class T> T &ctmax(T &x){ return x; }
template<class T, class Head, class ...Tail> T &ctmax(T &x, const Head &h, const Tail &... t){ return ctmax(x = max<T>(x, h), t...); }

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
	fenwick_tree(const fenwick_tree &otr): n(otr.n), data(otr.data){
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
	// pred(sum[0, r)) is T, T, ..., T, F, F, ..., F
	// Returns max r with T
	// O(log n)
	int max_pref(auto pred) const{
		assert(pred({}));
		int p = 0;
		T sum{};
		for(auto pw = 1 << __lg(n + 1); pw; pw >>= 1) if(p + pw <= n && f(sum + data[p + pw - 1])){
			sum += data[p + pw - 1];
			p += pw;
		}
		return p;
	}
	template<class output_stream>
	friend output_stream &operator<<(output_stream &out, const fenwick_tree<T> &fw){
		out << "[";
		for(auto i = 0; i < fw.n; ++ i){
			out << fw.query(i, i + 1);
			if(i != fw.n - 1) out << ", ";
		}
		return out << ']';
	}
};

int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	auto __solve_tc = [&](auto __tc_num)->int{
		int n;
		string s, t;
		cin >> n >> s >> t;
		const int mx = 26;
		array<vector<int>, mx> pos;
		for(auto i = 0; i < n; ++ i){
			pos[s[i] - 'a'].push_back(i);
		}
		long long res = numeric_limits<long long>::max() / 2;
		vector<array<long long, mx>> dp(n);
		ranges::fill(dp[0], numeric_limits<long long>::max() / 2);
		for(auto c = 0; c < mx; ++ c){
			if(!pos[c].empty()){
				dp[0][c] = pos[c].front();
			}
		}
		if(t[0] != 'a'){
			ctmin(res, ranges::min(dp[0] | ranges::views::take(t[0] - 'a')));
		}
		if(pos[t[0] - 'a'].empty()){
			if(res == numeric_limits<long long>::max() / 2){
				res = -1;
			}
			cout << res << "\n";
			return 0;
		}
		fenwick_tree<int> rem(n, 1);
		array<int, mx> cnt{};
		++ cnt[t[0] - 'a'];
		rem.update(pos[t[0] - 'a'][0], -1);
		for(auto i = 1; i < n; ++ i){
			ranges::fill(dp[i], numeric_limits<long long>::max() / 2);
			long long prev = dp[i - 1][t[i - 1] - 'a'];
			for(auto c = 0; c < mx; ++ c){
				if(cnt[c] < (int)size(pos[c])){
					ctmin(dp[i][c], prev + rem.query(pos[c][cnt[c]]));
				}
			}
			if(t[i] != 'a'){
				ctmin(res, ranges::min(dp[i] | ranges::views::take(t[i] - 'a')));
			}
			if(cnt[t[i] - 'a'] >= (int)size(pos[t[i] - 'a'])){
				break;
			}
			rem.update(pos[t[i] - 'a'][cnt[t[i] - 'a']], -1);
			++ cnt[t[i] - 'a'];
		}
		if(res == numeric_limits<long long>::max() / 2){
			res = -1;
		}
		cout << res << "\n";
		return 0;
	};
	int __tc_cnt;
	cin >> __tc_cnt;
	for(auto __tc_num = 0; __tc_num < __tc_cnt; ++ __tc_num){
		__solve_tc(__tc_num);
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