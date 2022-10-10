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



int main(){
	cin.tie(0)->sync_with_stdio(0);
	string s;
	cin >> s;
	int n = sz(s);
	vi cnt(n + 1);
	for(int i = 0; i < n; ++ i){
		cnt[i + 1] = cnt[i] + (s[i] == '?');
	}
	const ll mod = 998244353;
	vl p2(n + 1, 1);
	for(int i = 1; i <= n; ++ i){
		p2[i] = p2[i - 1] * 2 % mod;
	}
	vector<vl> d(n + 1, vl(n + 1, -1));
	function<ll(int, int)> solve = [&](int l, int r){
		if(r - l <= 1) return 0LL;
		if(d[l][r] != -1) return d[l][r];
		if(s[l] == '(' && s[r - 1] == ')') return d[l][r] = (p2[cnt[r] - cnt[l]] + solve(l + 1, r - 1)) % mod;
		if(s[l] == ')') return d[l][r] = solve(l + 1, r);
		if(s[r - 1] == '(') return d[l][r] = solve(l, r - 1);
		if(s[l] == '(') return d[l][r] = (p2[cnt[r] - cnt[l] - 1] + solve(l + 1, r - 1) + solve(l, r - 1)) % mod;
		if(s[r - 1] == ')') return d[l][r] = (solve(l + 1, r) + p2[cnt[r] - cnt[l] - 1] + solve(l + 1, r - 1)) % mod;
		return d[l][r] = (solve(l + 1, r) + solve(l, r - 1) + p2[cnt[r] - cnt[l] - 2]) % mod;
	};
	cout << solve(0, n);
	return 0;
}

/*
????
(((( 0
((() 1
(()( 1
(()) 2

()(( 1
()() 1
())( 1
())) 1

)((( 0
)(() 1
)()( 1
)()) 1

))(( 0
))() 1
)))( 0
)))) 0

*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////