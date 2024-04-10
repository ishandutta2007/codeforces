#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/rope>
using namespace std;
using namespace __gnu_pbds;
using namespace __gnu_cxx;
template<typename L, typename R> istream &operator>>(istream &in, pair<L, R> &p){ return in >> p.first >> p.second; }
template<typename Tuple, size_t ...Is> void read_tuple(istream &in, Tuple &t, index_sequence<Is...>){ ((in >> get<Is>(t)), ...); }
template<typename ...Args> istream &operator>>(istream &in, tuple<Args...> &t){ read_tuple(in, t, index_sequence_for<Args...>{}); return in; }
template<typename ...Args, template<typename...> typename T> istream &operator>>(enable_if_t<!is_same_v<T<Args...>, string>, istream> &in, T<Args...> &arr){ for(auto &x: arr) in >> x; return in; }
template<typename L, typename R> ostream &operator<<(ostream &out, const pair<L, R> &p){ return out << "(" << p.first << ", " << p.second << ")"; }
//template<typename L, typename R> ostream &operator<<(ostream &out, const pair<L, R> &p){ return out << p.first << " " << p.second << "\n"; }
template<typename Tuple, size_t ...Is> void print_tuple(ostream &out, const Tuple &t, index_sequence<Is...>){ ((out << (Is ? " " : "") << get<Is>(t)), ...); }
template<typename ...Args> ostream &operator<<(ostream &out, const tuple<Args...> &t){ print_tuple(out, t, index_sequence_for<Args...>{}); return out << "\n"; }
template<typename ...Args, template<typename...> typename T> ostream &operator<<(enable_if_t<!is_same_v<T<Args...>, string>, ostream> &out, const T<Args...> &arr){ for(auto &x: arr) out << x << " "; return out << "\n"; }
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
mt19937_64 rngll(chrono::steady_clock::now().time_since_epoch().count());
#define all(a) a.begin(), a.end()
#define sz(a) (int)a.size()
typedef long long ll;
typedef vector<int> vi; typedef vector<ll> vl; typedef vector<double> vd; typedef vector<string> vs;
typedef pair<int, int> pii; typedef pair<ll, ll> pll; typedef pair<int, ll> pil; typedef pair<ll, int> pli;
typedef vector<pii> vpii; typedef vector<pil> vpil; typedef vector<pli> vpli; typedef vector<pll> vpll;
template<typename T> T ctmax(T &x, const T &y){ return x = max(x, y); }
template<typename T> T ctmin(T &x, const T &y){ return x = min(x, y); }
template<typename T> using Tree = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
typedef tuple<int, int, int> tpl; typedef vector<tpl> vtpl;

pair<vector<int>, vector<int>> linearsieve(int n){
	vector<int> lpf(n + 1), prime;
	prime.reserve(n + 1);
	for(int i = 2; i <= n; ++ i){
		if(!lpf[i]) lpf[i] = i, prime.push_back(i);
		for(int j = 0; j < prime.size() && prime[j] <= lpf[i] && i * prime[j] <= n; ++ j){
			lpf[i * prime[j]] = prime[j];
		}
	}
	return {lpf, prime};
}

int main(){
	cin.tie(0)->sync_with_stdio(0);
	constexpr int mx = 1e6;
	auto [lpf, prime] = linearsieve(mx);
	int n, x, y;
	cin >> n >> x >> y;
	vi cnt(mx + 1);
	for(int i = 0; i < n; ++ i){
		int x;
		cin >> x;
		++ cnt[x];
	}
	vi pcnt(mx + 2);
	vl psum(mx + 2);
	for(int i = 0; i <= mx; ++ i){
		pcnt[i + 1] = pcnt[i] + cnt[i];
		psum[i + 1] = psum[i] + 1LL * cnt[i] * i;
	}
	auto get_cnt = [&](int i, int j){
		return pcnt[min(j, mx + 1)] - pcnt[min(i, mx + 1)];
	};
	auto get_sum = [&](int i, int j){
		return psum[min(j, mx + 1)] - psum[min(i, mx + 1)];
	};
	ll res = 9e18;
	for(auto p: prime){
		ll cur = 0;
		for(int lp = 1, mp = max(p - x / y, 1), rp = p + 1; lp <= mx; lp += p, mp += p, rp += p){
			cur += 1LL * x * get_cnt(lp, mp) + y * (1LL * get_cnt(mp, rp) * (rp - 1) - get_sum(mp, rp));
		}
		ctmin(res, cur);
	}
	cout << res;
	return 0;
}

/*
p-t -> x or yt
t <= x / y  --> yt <= x
*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////