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
 
template<class T, class BO>
struct segment: vector<T>{
	int N;
	BO bin_op;
	const T id;
	segment(const vector<T> &arr, BO bin_op, T id): N(sz(arr)), bin_op(bin_op), id(id){
		this->resize(N << 1, id);
		for(int i = 0; i < N; ++ i) (*this)[i + N] = arr[i];
		for(int i = N - 1; i > 0; -- i) (*this)[i] = bin_op((*this)[i << 1], (*this)[i << 1 | 1]);
	}
	void set(int p, T val){
		for((*this)[p += N] = val; p > 1; p >>= 1) (*this)[p >> 1] = bin_op((*this)[p], (*this)[p ^ 1]);
	}
	T query(int l, int r){
		if(l >= r) return id;
		T resl = id, resr = id;
		for(l += N, r += N; l < r; l >>= 1, r >>= 1){
			if(l & 1) resl = bin_op(resl, (*this)[l ++]);
			if(r & 1) resr = bin_op((*this)[-- r], resr);
		}
		return bin_op(resl, resr);
	}
};
 
int main(){
	cin.tie(0)->sync_with_stdio(0);
	int n;
	string s;
	cin >> n >> s;
	string t(s);
	sort(all(t));
	vi to(n);
	vector<vi> pos(26);
	for(int i = 0; i < n; ++ i){
		pos[t[i] - 'a'].push_back(i);
	}
	for(auto &x: pos){
		reverse(all(x));
	}
	for(int i = 0; i < n; ++ i){
		to[i] = pos[s[i] - 'a'].back();
		pos[s[i] - 'a'].pop_back();
	}
	int res = 1;
	vi tt;
	vector<segment<int, plus<int>>> tr(26, segment(vi(n), plus<int>(), 0));
	auto get = [&](int i){
		vi res;
		for(int c = 25; c >= 0; -- c){
			if(tr[c].query(i, n)){
				res.push_back(c);
			}
		}
		return res;
	};
	for(int i = 0; i < n; ++ i){
		vi v = get(to[i]);
		ctmax(res, sz(v) + 1);
		int c = 0;
		while(!v.empty() && v.back() == c){
			v.pop_back();
			++ c;
		}
		tt.push_back(c + 1);
		tr[c].set(to[i], tr[c].query(to[i], to[i] + 1) + 1);
	}
	cout << res << "\n" << tt;
	return 0;
}
 
/*
 
*/
 
////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////