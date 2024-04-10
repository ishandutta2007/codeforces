#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/rope>
using namespace std;
using namespace __gnu_pbds;
using namespace __gnu_cxx;
template<class L, class R> istream &operator>>(istream &in, pair<L, R> &p){ return in >> p.first >> p.second; }
template<class Tuple, size_t ...Is> void read_tuple(istream &in, Tuple &t, index_sequence<Is...>){ ((in >> get<Is>(t)), ...); }
template<class ...Args> istream &operator>>(istream &in, tuple<Args...> &t){ read_tuple(in, t, index_sequence_for<Args...>{}); return in; }
template<class ...Args, template<class...> class T> istream &operator>>(enable_if_t<!is_same_v<T<Args...>, string>, istream> &in, T<Args...> &arr){ for(auto &x: arr) in >> x; return in; }
template<class L, class R> ostream &operator<<(ostream &out, const pair<L, R> &p){ return out << "(" << p.first << ", " << p.second << ")"; }
//template<class L, class R> ostream &operator<<(ostream &out, const pair<L, R> &p){ return out << p.first << " " << p.second << "\n"; }
template<class Tuple, size_t ...Is> void print_tuple(ostream &out, const Tuple &t, index_sequence<Is...>){ ((out << (Is ? " " : "") << get<Is>(t)), ...); }
template<class ...Args> ostream &operator<<(ostream &out, const tuple<Args...> &t){ print_tuple(out, t, index_sequence_for<Args...>{}); return out << "\n"; }
template<class ...Args, template<class...> class T> ostream &operator<<(enable_if_t<!is_same_v<T<Args...>, string>, ostream> &out, const T<Args...> &arr){ for(auto &x: arr) out << x << " "; return out << "\n"; }
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
mt19937_64 rngll(chrono::steady_clock::now().time_since_epoch().count());
#define all(a) a.begin(), a.end()
#define sz(a) (int)a.size()
typedef long long ll;
typedef vector<int> vi; typedef vector<ll> vl; typedef vector<double> vd; typedef vector<string> vs;
typedef pair<int, int> pii; typedef pair<ll, ll> pll; typedef pair<int, ll> pil; typedef pair<ll, int> pli;
typedef vector<pii> vpii; typedef vector<pil> vpil; typedef vector<pli> vpli; typedef vector<pll> vpll;
template<class T> T ctmax(T &x, const T &y){ return x = max(x, y); }
template<class T> T ctmin(T &x, const T &y){ return x = min(x, y); }
template<class T> using Tree = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
typedef tuple<int, int, int> tpl; typedef vector<tpl> vtpl;

ll modexp(ll b, ll e, const ll &mod){
	ll res = 1;
	for(; e; b = b * b % mod, e >>= 1) if(e & 1) res = res * b % mod;
	return res;
}
ll modinv(ll b, const ll &mod){
	return modexp(b, mod - 2, mod);
}

int main(){
	cin.tie(0)->sync_with_stdio(0);
	const ll mod = 998244353;
	int n;
	cin >> n;
	vpii a(n);
	cin >> a;
	vi temp;
	for(auto &[l, r]: a){
		temp.push_back(l), temp.push_back(++ r);
	}
	sort(all(temp)), temp.resize(unique(all(temp)) - temp.begin());
	map<int, int> ord;
	int m = sz(temp);
	for(int i = 0; i < m; ++ i){
		ord[temp[i]] = i;
	}
	ll DENOM = 1;
	for(auto &[l, r]: a){
		DENOM =  DENOM * modinv(r - l, mod) % mod;
		l = ord[l], r = ord[r];
	}
	auto H = [&](int n, int r){
		n += r - 1;
		if(n < r) return 0LL;
		ll res = 1;
		for(int k = 1; k <= r; ++ k){
			res = res * (n - k + 1) % mod * modinv(k, mod) % mod;
		}
		return res;
	};
	vector<vl> dp(n + 1, vl(m));
	dp[0] = vl(m, 1);
	for(int i = 1; i <= n; ++ i){
		for(int j = m - 2; j >= 0; -- j){
			dp[i][j] = dp[i][j + 1];
			const ll S = temp[j + 1] - temp[j];
			for(int k = i - 1; k >= 0 && a[k].first <= j && j < a[k].second; -- k){
				dp[i][j] = (dp[i][j] + dp[k][j + 1] * H(S, i - k)) % mod;
			}
		}
	}
	cout << dp[n][0] * DENOM % mod;
	return 0;
}

/*
dp[i][j]: # of poss states, first i elements, last position equal or greater than j,
dp[0][0] = 0
dp[1][0] = 2
dp[2][0] = 3
dp[3][0] = 4
dp[i][j] = dp[i][j + 1] + sum{k= 0 ~ i-1}( dp[k][j+1] * H(k - i, i) )
*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////