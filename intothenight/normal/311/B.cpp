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

template<int K = 2, typename T = long long, typename BO = plus<>, typename IO = minus<>>
struct subinterval{
	const array<int, K> N;
	BO bin_op;
	IO inv_op;
	const T id;
	vector<T> val, p;
	int pos(const array<int, K> &x){
		int res = 0;
		for(int i = 0; i < K; ++ i) res += p[i] * x[i];
		return res;
	}
	template<typename INIT>
	subinterval(const array<int, K> &N, INIT f, BO bin_op = plus<>{}, IO inv_op = minus<>{}, T id = 0LL): N(N), bin_op(bin_op), inv_op(inv_op), id(id), val(accumulate(N.begin(), N.end(), 1, [&](int x, int y){ return x * (y + 1); }), id), p(K + 1, 1){
		array<int, K> cur, from;
		partial_sum(N.begin(), N.end(), p.begin() + 1, multiplies<>{});
		cur.fill(1);
		while(1){
			T &c = val[pos(cur)];
			for(int i = 0; i < K; ++ i) -- cur[i];
			c = f(cur);
			for(int i = 0; i < K; ++ i) ++ cur[i];
			for(int mask = 1; mask < 1 << K; ++ mask){
				from = cur;
				for(int bit = 0; bit < K; ++ bit) if(mask & 1 << bit) -- from[bit];
				c = __builtin_popcount(mask) & 1 ? bin_op(c, val[pos(from)]) : inv_op(c, val[pos(from)]);
			}
			for(int i = 0; i < K; ++ i){
				if(++ cur[i] <= N[i]) break;
				if(i == K - 1) return;
				cur[i] = 1;
			}
		}
	}
	T query(const array<int, K> &low, const array<int, K> &high){
		T res = id;
		array<int, K> cur;
		for(int mask = 0; mask < 1 << K; ++ mask){
			for(int bit = 0; bit < K; ++ bit) cur[bit] = mask & 1 << bit ? low[bit] : high[bit];
			res = __builtin_popcount(mask) & 1 ? inv_op(res, val[pos(cur)]) : bin_op(res, val[pos(cur)]);
		}
		return res;
	}
	T query(const array<int, K> &high){
		return val[pos(high)];
	}
};

struct line{
	long long d, k, p;
	long long eval(long long x){ return d * x + k; }
};
template<bool GET_MAX = true>
struct sorted_line_container: deque<line>{
	static constexpr long long inf = numeric_limits<long long>::max();
	// (for doubles, use inf = 1/.0, div(a,b) = a/b)
	long long div(long long a, long long b){ return a / b - ((a ^ b) < 0 && a % b); }
	bool isect_front(iterator x, iterator y){
		if(y == end()){ x->p = inf; return false; }
		else{ x->p = div(y->k - x->k, x->d - y->d); return x->p >= y->p; }
	}
	bool isect_back(reverse_iterator x, reverse_iterator y){
		if(x == rend()) return false;
		else{ x->p = div(y->k - x->k, x->d - y->d); return x->p >= y->p; }
	}
	void push(line L){
		if(!GET_MAX) L.d = -L.d, L.k = -L.k;
		if(empty() || L.d < front().d){
			L.p = 0, push_front(L), isect_front(begin(), ++ begin());
			while(int(size()) >= 2 && isect_front(begin(), ++ begin())) erase(++ begin());
		}
		else if(L.d > back().d){
			L.p = inf, push_back(L); isect_back(++ rbegin(), rbegin());
			while(int(size()) >= 2 && isect_back(++ ++ rbegin(), ++ rbegin())) erase(-- -- end()), isect_back(++ rbegin(), rbegin());
		}
		else assert(false);
	}
	long long dec_query(long long x){
		while(int(size()) >= 2 && rbegin()->eval(x) <= (++ rbegin())->eval(x)) pop_back(); rbegin()->p = inf;
		return rbegin()->eval(x) * (GET_MAX ? 1 : -1);
	}
	long long inc_query(long long x){
		while(int(size()) >= 2 && begin()->eval(x) <= (++ begin())->eval(x)) pop_front();
		return begin()->eval(x) * (GET_MAX ? 1 : -1);
	}
	long long query(long long x){
		if(int(size()) == 1) return begin()->eval(x) * (GET_MAX ? 1 : -1);
		int low = 0, high = int(size()) - 1;
		if(begin()->eval(x) >= (++ begin())->eval(x)) return begin()->eval(x) * (GET_MAX ? 1 : -1);
		while(high - low > 1){
			int mid = low + high >> 1;
			(*this)[mid].eval(x) < (*this)[mid + 1].eval(x) ? low = mid : high = mid;
		}
		return (*this)[low + 1].eval(x) * (GET_MAX ? 1 : -1);
	}
};

int main(){
	cin.tie(0)->sync_with_stdio(0);
	int n, m, p;
	cin >> n >> m >> p;
	vector<int> d(n - 1);
	copy_n(istream_iterator<int>(cin), n - 1, d.begin());
	subinterval<1, int> sum_d({n - 1}, [&](auto x){ return d[x[0]]; });
	vector<int> a(m);
	for(int i = 0; i < m; ++ i){
		int pos;
		cin >> pos >> a[i], -- pos;
		a[i] -= sum_d.query({pos});
	}
	if(p == 1){
		cout << 1LL * m * max(0, a.back()) - accumulate(a.begin(), a.end(), 0LL);
		return 0;
	}
	sort(a.begin(), a.end());
	subinterval<1> sum({m}, [&](auto x){ return a[x[0]]; });
	sorted_line_container<false> lc;
	vector<long long> dp(m + 1), dp_next(m + 1);
	for(int i = 1; i <= m; ++ i){
		dp[i] = 1LL * i * a[i - 1] - sum.query({i});
	}
	for(int REP = 1; REP < p; ++ REP){
		lc.clear();
		lc.push({0, 0});
		for(int i = 1; i <= m; ++ i){
			lc.push({-i, dp[i] + sum.query({i})});
			dp_next[i] = lc.inc_query(a[i - 1]) + 1LL * i * a[i - 1] - sum.query({i});
		}
		swap(dp, dp_next);
	}
	cout << dp.back();
	return 0;
}

/*
dp[i][j]: min time when first j cat handled by first i feeder
dp[i][j] = min{k <= j}( dp[i - 1][k] + (j - k) * a[j - 1] - sum[j] + sum[k] )
         = min{k <= j}( dp[i - 1][k] - k * a[j - 1] + sum[k] ) + j * a[j - 1] - sum[j]

         insert line of form (-k, dp[i - 1][k] - sum[k])

dp_next[i] = min{j <= i}( dp[j] + (i - j) * a[i - 1] - sum[i] + sum[j] )
                           0    +    1    * 
         = min{j <= i}( dp[j] - j * a[i - 1] + sum[j] ) + i * a[i - 1] - sum[i]
                         0    - 3 * 8          0        + 4 * 8        + 8
         insert line of form (-j, dp[j] + sum[j])
*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////