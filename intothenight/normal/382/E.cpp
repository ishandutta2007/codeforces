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
	const ll mod = 1e9 + 7;
	combi c(100, mod);
	int n, m;
	cin >> n >> m;
	vector<vl> d(n + 1, vl(m + 1)), e(n + 1, vl(m + 1)); // root unmatched / matched
	d[1][0] = 1;
	for(int i = 2; i <= n; ++ i){
		for(int j = 0; j <= m; ++ j){
			d[i][j] = e[i - 1][j] * (i - 1) % mod;
			for(int k = 1; k < i - 1; ++ k){
				for(int l = 0; l <= j; ++ l){
					d[i][j] = (d[i][j] + e[k][l] * e[i - k - 1][j - l] % mod * c.c(i - 2, k - 1) % mod * k * (i - k - 1)) % mod;
				}
			}
			if(j){
				e[i][j] = d[i - 1][j - 1]  * (i - 1) % mod;
				for(int k = 1; k < i - 1; ++ k){
					for(int l = 0; l < j; ++ l){
						e[i][j] = (e[i][j] + ((d[k][l] + e[k][l]) * (d[i - k - 1][j - l - 1] + e[i - k - 1][j - l - 1]) - e[k][l] * e[i - k - 1][j - l - 1]) % mod * c.c(i - 2, k - 1) % mod * k * (i - k - 1)) % mod;
					}
				}
			}
		}
	}
	cout << (d[n][m] + e[n][m]) % mod;
	return 0;
}

/*

*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////