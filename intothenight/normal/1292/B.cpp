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



int main(){
	cin.tie(0)->sync_with_stdio(0);
	auto dist = [&](const pll &p, const pll &q){
		return abs(p.first - q.first) + abs(p.second - q.second);
	};
	ll x0, y0, ax, ay, bx, by, xs, ys, t;
	cin >> x0 >> y0 >> ax >> ay >> bx >> by >> xs >> ys >> t;
	pll s(xs, ys);
	vpll a{{x0, y0}};
	const ll LIM = 2e16;
	while(1){
		pll np(a.back().first * ax + bx, a.back().second * ay + by);
		if(np.first > LIM || np.second > LIM){
			break;
		}
		a.push_back(np);
	}
	int res = 0;
	for(int i = 0; i < sz(a); ++ i){
		int j = i;
		while(j < sz(a) && dist(s, a[i]) + dist(a[i], a[j]) <= t) ++ j;
		ctmax(res, j - i);
	}
	for(int j = sz(a) - 1; j >= 0; -- j){
		int i = j;
		while(i >= 0 && dist(s, a[j]) + dist(a[i], a[j]) <= t) -- i;
		ctmax(res, j - i);
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