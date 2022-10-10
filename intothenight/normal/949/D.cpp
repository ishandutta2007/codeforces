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
	int n, d, b;
	cin >> n >> d >> b;
	vi a(n), SUM(n + 1);
	cin >> a;
	partial_sum(all(a), SUM.begin() + 1);
	auto sum = [&](int i, int j){
		return SUM[j] - SUM[i];
	};
	int L = 0, R = 0;
	if(sum(0, (n + 1) / 2) >= (n + 1) / 2 * b){ // Left should help right
		for(int i = 0, cnt = 1, hid = 0; i < (n + 1) / 2; ++ i, ++ cnt){
			if(sum(0, min(i + 1LL * cnt * d + 1, 1LL * (n + 1) / 2)) - hid >= b){
				hid += b;
			}
			else{
				++ L;
			}
		}
		for(int i = n - 1, cnt = 1, hid = 0; i >= (n + 1) / 2; -- i, ++ cnt){
			if(sum(max(0LL, i - 1LL * cnt * d), n) - hid >= b){
				hid += b;
			}
			else{
				++ R;
			}
		}
	}
	else{ // Right should help left
		for(int i = 0, cnt = 1, hid = 0; i < (n + 1) / 2; ++ i, ++ cnt){
			if(sum(0, min(i + 1LL * cnt * d + 1, 1LL * n)) - hid >= b){
				hid += b;
			}
			else{
				++ L;
			}
		}
		for(int i = n - 1, cnt = 1, hid = 0; i >= (n + 1) / 2; -- i, ++ cnt){
			if(sum(max(1LL * (n + 1) / 2, i - 1LL * cnt * d), n) - hid >= b){
				hid += b;
			}
			else{
				++ R;
			}
		}
	}
	cout << max(L, R);
	return 0;
}

/*

*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////