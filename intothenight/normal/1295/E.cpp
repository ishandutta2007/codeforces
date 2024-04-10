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

template<class T, class BO1, class BO2, class BO3>
struct lazy_segment{
	lazy_segment *l = 0, *r = 0;
	int low, high;
	BO1 lop;           // Lazy op(L, L -> L)
	BO2 qop;           // Query op(Q, Q -> Q)
	BO3 aop;           // Apply op(Q, L, len -> Q)
	vector<T> &id;     // Lazy id(L), Query id(Q), Disable constant(Q)
	T lset, lazy, val;
	lazy_segment(int low, int high, BO1 lop, BO2 qop, BO3 aop, vector<T> &id): low(low), high(high), lop(lop), qop(qop), aop(aop), id(id){
		lazy = id[0], val = id[1], lset = id[2];
	}
	lazy_segment(const vector<T> &arr, int low, int high, BO1 lop, BO2 qop, BO3 aop, vector<T> &id)
	: low(low), high(high), lop(lop), qop(qop), aop(aop), id(id){
		lazy = id[0], lset = id[2];
		if(high - low > 1){
			int mid = low + (high - low) / 2;
			l = new lazy_segment(arr, low, mid, lop, qop, aop, id);
			r = new lazy_segment(arr, mid, high, lop, qop, aop, id);
			val = qop(l->val, r->val);
		}
		else val = arr[low];
	}
	void push(){
		if(!l){
			int mid = low + (high - low) / 2;
			l = new lazy_segment(low, mid, lop, qop, aop, id);
			r = new lazy_segment(mid, high, lop, qop, aop, id);
		}
		if(lset != id[2]){
			l->set(low, high, lset);
			r->set(low, high, lset);
			lset = id[2];
		}
		else if(lazy != id[0]){
			l->update(low, high, lazy);
			r->update(low, high, lazy);
			lazy = id[0];
		}
	}
	void set(int ql, int qr, T x){
		if(qr <= low || high <= ql) return;
		if(ql <= low && high <= qr){
			lset = x;
			lazy = id[0];
			val = aop(id[1], x, high - low);
		}
		else{
			push();
			l->set(ql, qr, x);
			r->set(ql, qr, x);
			val = qop(l->val, r->val);
		}
	}
	void update(int ql, int qr, T x){
		if(qr <= low || high <= ql) return;
		if(ql <= low && high <= qr){
			if(lset != 	id[2]) lset = lop(lset, x);
			else lazy = lop(lazy, x);
			val = aop(val, x, high - low);
		}
		else{
			push();
			l->update(ql, qr, x);
			r->update(ql, qr, x);
			val = qop(l->val, r->val);
		}
	}
	T query(int ql, int qr){
		if(qr <= low || high <= ql) return id[1];
		if(ql <= low && high <= qr) return val;
		push();
		return qop(l->query(ql, qr), r->query(ql, qr));
	}
	// Below assumes T is an ordered field and node stores positive values
	template<class IO>
	int plb(T val, IO inv_op){
		if(low + 1 == high) return high;
		push();
		if(l->val < val) return r->plb(inv_op(val, l->val), inv_op);
		else return l->plb(val, inv_op);
	}
	template<class IO>
	int lower_bound(T val, IO inv_op){ // min i such that query[0, i) >= val
		if(this->val < val) return high + 1;
		else return plb(val, inv_op);
	}
	template<class IO>
	int lower_bound(int i, T val, IO inv_op){
		return lower_bound(qop(val, query(low, min(i, high))), inv_op);
	}
	template<class IO>
	int pub(T val, IO inv_op){
		if(low + 1 == high) return high;
		push();
		if(val < l->val) return l->pub(val, inv_op);
		else return r->pub(inv_op(val, l->val), inv_op);
	}
	template<class IO>
	int upper_bound(T val, IO inv_op){ // min i such that query[0, i) > val
		if(val < this->val) return pub(val, inv_op);
		else return high + 1;
	}
	template<class IO>
	int upper_bound(int i, T val, IO inv_op){
		return upper_bound(qop(val, query(low, min(i, high))), inv_op);
	}
};

int main(){
	cin.tie(0)->sync_with_stdio(0);
	int n;
	cin >> n;
	vi a(n);
	vl p(n);
	cin >> a;
	for(int i = 0; i < n; ++ i){
		-- a[i];
		cin >> p[a[i]];
	}
	vl id{0, 0, -1};
	lazy_segment tr(0, n + 1, plus<ll>(), [](ll x, ll y){ return min(x, y); }, [](ll x, ll y, ll z){ return x + y; }, id);
	for(int i = 0; i < n; ++ i){
		tr.update(a[i] + 1, n + 1, p[a[i]]);
	}
	ll res = 9e18;
	for(int i = 0; i < n - 1; ++ i){
		tr.update(a[i] + 1, n + 1, -p[a[i]]);
		tr.update(0, a[i] + 1, p[a[i]]);
		ctmin(res, tr.query(0, n + 1));
	}
	cout << res;
	return 0;
}

/*
4 9
->
  0 1 2 3 4 5 6 7 8
3 X X O X X O X X O
9 X X X X X X X X X
*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////