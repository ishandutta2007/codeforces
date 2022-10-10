#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
template<class L, class R>
istream &operator>>(istream &in, pair<L, R> &arr){
    return in >> arr.first >> arr.second;
}
template<class ...Args, template<class...> class T>
istream &operator>>(enable_if_t<!is_same_v<T<Args...>, string>, istream> &in, T<Args...> &arr){
	for(auto &x: arr) in >> x; return in;
}
template<class L, class R>
ostream &operator<<(ostream &out, const pair<L, R> &arr){
    return out << "(" << arr.first << ", " << arr.second << ") ";
}
template<class ...Args, template<class...> class T>
ostream &operator<<(enable_if_t<!is_same_v<T<Args...>, string>, ostream> &out, const T<Args...> &arr){
	for(auto &x: arr) out << x << " "; return out << "\n";
}
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
#define all(a) a.begin(), a.end()
#define sz(a) (int)a.size()
typedef long long ll;
typedef vector<int> vi; typedef vector<ll> vl; typedef vector<double> vd; typedef vector<string> vs;
typedef pair<int, int> pii; typedef pair<ll, ll> pll; typedef pair<int, ll> pil; typedef pair<ll, int> pli;
typedef vector<pii> vpii; typedef vector<pil> vpil; typedef vector<pli> vpli; typedef vector<pll> vpll;
template<class T>
using Tree = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
typedef tuple<int, int, int> tpl; typedef vector<tpl> vtpl;

struct combi{
	const ll N, mod;
	vl inv, fact, invfact;
	combi(ll N, ll mod):
		N(N), mod(mod), inv(N + 1), fact(N + 1), invfact(N + 1){
		inv[1] = 1, fact[0] = fact[1] = invfact[0] = invfact[1] = 1;
		for(ll i = 2; i <= N; i ++){
			inv[i] = (mod - mod / i * inv[mod % i] % mod) % mod;
			fact[i] = fact[i - 1] * i % mod;
			invfact[i] = invfact[i - 1] * inv[i] % mod;
		}
	}
	ll c(int n, int r){
		return n < r ? 0 : fact[n] * invfact[r] % mod * invfact[n - r] % mod;
	}
	ll p(int n, int r){
		return n < r ? 0 : fact[n] * invfact[n - r] % mod;
	}
	ll h(int n, int r){
		return c(n + r - 1, r);
	}
	ll cat(int n, int k, int m){
		if(m <= 0) return 0;
		else if(k >= 0 && k < m) return c(n + k, k);
		else if(k < n + m) return (c(n + k, k) - c(n + k, k - m) + mod) % mod;
		else return 0;
	}
};

int main(){
	cin.tie(0)->sync_with_stdio(0);
	const ll mod = 998244353;
	combi c(4000, mod);
	vl p2(4000, 1);
	for(int i = 1; i < 4000; ++ i){
		p2[i] = p2[i - 1] * 2 % mod;
	}
	vi l(2);
	int n;
	cin >> l >> n;
	vector<vi> flag{vi(l[0], true), vi(l[1], true)};
	while(n --){
		int r1, c1, r2, c2;
		cin >> r1 >> c1 >> r2 >> c2, r1 --, c1 --, r2 --, c2 --;
		flag[0][r1] = flag[0][r2] = flag[1][c1] = flag[1][c2] = false;
	}
	vi s{accumulate(all(flag[0]), 0), accumulate(all(flag[1]), 0)};
	vector<vector<vl>> dp{vector<vl>(l[0] + 1, vl(l[0] / 2 + 1)), vector<vl>(l[1] + 1, vl(l[1] / 2 + 1))};
	vector<vector<vl>> cnt{vector<vl>(l[0] + 1, vl(l[0] / 2 + 1)), vector<vl>(l[1] + 1, vl(l[1] / 2 + 1))};
	for(int k = 0; k < 2; ++ k){
		dp[k][0][0] = 1;
		for(int i = 0; i < l[k]; ++ i){
			for(int j = 0; j <= l[k] / 2; ++ j){
				(dp[k][i + 1][j] += dp[k][i][j]) %= mod;
				if(i + 2 <= l[k] && j + 1 <= l[k] / 2 && flag[k][i] && flag[k][i + 1]){
					(dp[k][i + 2][j + 1] += dp[k][i][j]) %= mod;
				}
			}
		}
		for(int j = 0; 2 * j <= s[k]; ++ j){
			for(int i = 0; i <= s[k] - 2 * j; ++ i){
				cnt[k][i][j] = dp[k][l[k]][j] * c.c(s[k] - 2 * j, i) % mod;
			}
		}
	}
	ll res = 0;
	for(int i = 0; i <= min(l[0], l[1] / 2); ++ i){
		for(int j = 0; j <= min(l[0] / 2, l[1]); ++ j){
			(res += cnt[0][i][j] * cnt[1][j][i] % mod * c.fact[i] % mod * c.fact[j]) %= mod;
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