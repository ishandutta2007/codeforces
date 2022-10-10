#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/rope>
using namespace std;
using namespace __gnu_pbds;
using namespace __gnu_cxx;
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
    return out << "(" << arr.first << ", " << arr.second << ")";
}
template<class ...Args, template<class...> class T>
ostream &operator<<(enable_if_t<!is_same_v<T<Args...>, string>, ostream> &out, const T<Args...> &arr){
	for(auto &x: arr) out << x << " "; return out << "\n";
}
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
mt19937_64 rndll(chrono::steady_clock::now().time_since_epoch().count());
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
	ll x;
	cin >> x;
	if(x == 1){
		cout << "1 1";
		return 0;
	}
	vl factor;
	for(ll p = 2; p * p <= x; ++ p){
		if(x % p == 0){
			factor.push_back(1);
			while(x % p == 0) factor.back() *= p, x /= p;
		}
	}
	if(x > 1) factor.push_back(x);
	pll res(9e18, 9e18);
	int n = sz(factor);
	vl a{factor[0]}, b;
	function<void(int)> solve = [&](int i){
		if(i == n){
			pll cur(accumulate(all(a), 1LL, multiplies<ll>()), accumulate(all(b), 1LL, multiplies<ll>()));
			if(max(res.first, res.second) > max(cur.first, cur.second)) res = cur;
			return;
		}
		a.push_back(factor[i]);
		solve(i + 1);
		a.pop_back();
		b.push_back(factor[i]);
		solve(i + 1);
		b.pop_back();
	};
	solve(1);
	cout << res.first << " " << res.second;
	return 0;
}

/*

*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////