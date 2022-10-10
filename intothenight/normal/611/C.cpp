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
	vector<T> val;
	int pos(const array<int, K> &x){
		int p = 1, res = 0;
		for(int i = 0; i < K; ++ i){
			res += p * x[i];
			p *= N[i];
		}
		return res;
	}
	template<typename INIT>
	subinterval(const array<int, K> &N, INIT f, BO bin_op = plus<>{}, IO inv_op = minus<>{}, T id = 0LL): N(N), bin_op(bin_op), inv_op(inv_op), id(id), val(accumulate(N.begin(), N.end(), 1, [&](int x, int y){ return x * (y + 1); }), id){
		array<int, K> cur, from;
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
};

int main(){
	cin.tie(0)->sync_with_stdio(0);
	int h, w;
	cin >> h >> w;
	vector<string> a(h);
	copy_n(istream_iterator<string>(cin), h, a.begin());
	auto init_up = [&](const array<int, 2> &x){
		return x[0] && a[x[0]][x[1]] == '.' && a[x[0] - 1][x[1]] == '.';
	};
	auto init_left = [&](const array<int, 2> &x){
		return x[1] && a[x[0]][x[1]] == '.' && a[x[0]][x[1] - 1] == '.';
	};
	subinterval sumup({h, w}, init_up), sumleft({h, w}, init_left);
	int qq;
	cin >> qq;
	while(qq --){
		int lx, ly, hx, hy;
		cin >> lx >> ly >> hx >> hy, -- lx, -- ly;
		cout << sumup.query({lx + 1, ly}, {hx, hy}) + sumleft.query({lx, ly + 1}, {hx, hy}) << "\n";
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