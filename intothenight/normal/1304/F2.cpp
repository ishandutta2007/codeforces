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

template<typename T, typename BO1, typename BO2, typename BO3>
struct lazy_segment{
	lazy_segment *l = 0, *r = 0;
	int low, high;
	BO1 lop;           // Lazy op(L, L -> L)
	BO2 qop;           // Query op(Q, Q -> Q)
	BO3 aop;           // Apply op(Q, L, len -> Q)
	const vector<T> id;     // Lazy id(L), Query id(Q), Disable constant(Q)
	T lset, lazy, val;
	lazy_segment(int low, int high, BO1 lop, BO2 qop, BO3 aop, const vector<T> &id): low(low), high(high), lop(lop), qop(qop), aop(aop), id(id){
		lazy = id[0], val = id[1], lset = id[2];
	}
	lazy_segment(const vector<T> &arr, int low, int high, BO1 lop, BO2 qop, BO3 aop, const vector<T> &id): low(low), high(high), lop(lop), qop(qop), aop(aop), id(id){
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
	template<typename IO>
	int plb(T val, IO inv_op){
		if(low + 1 == high) return high;
		push();
		if(l->val < val) return r->plb(inv_op(val, l->val), inv_op);
		else return l->plb(val, inv_op);
	}
	template<typename IO>
	int lower_bound(T val, IO inv_op){ // min i such that query[0, i) >= val
		if(this->val < val) return high + 1;
		else return plb(val, inv_op);
	}
	template<typename IO>
	int lower_bound(int i, T val, IO inv_op){
		return lower_bound(qop(val, query(low, min(i, high))), inv_op);
	}
	template<typename IO>
	int pub(T val, IO inv_op){
		if(low + 1 == high) return high;
		push();
		if(val < l->val) return l->pub(val, inv_op);
		else return r->pub(inv_op(val, l->val), inv_op);
	}
	template<typename IO>
	int upper_bound(T val, IO inv_op){ // min i such that query[0, i) > val
		if(val < this->val) return pub(val, inv_op);
		else return high + 1;
	}
	template<typename IO>
	int upper_bound(int i, T val, IO inv_op){
		return upper_bound(qop(val, query(low, min(i, high))), inv_op);
	}
};

int main(){
	cin.tie(0)->sync_with_stdio(0);
	int n, m, k;
	cin >> n >> m >> k;
	vector<vi> a(n, vi(m));
	cin >> a;
	a.emplace_back(m);
	vector<vi> sum(n + 1, vi(m + 1));
	for(int i = 0; i < n; ++ i){
		for(int j = 0; j < m; ++ j){
			sum[i][j + 1] = sum[i][j] + a[i][j];
		}
	}
	vi dp(m - k + 1), dp_next(m - k + 1);
	for(int j = 0; j <= m - k; ++ j){
		dp[j] = sum[0][j + k] - sum[0][j] + sum[1][j + k] - sum[1][j];
	}
	for(int i = 1; i < n; ++ i){
		auto qop = [&](int x, int y){
			return max(x, y);
		};
		auto aop = [&](int x, int y, int z){
			return x + y;
		};
		lazy_segment tr(dp, 0, m - k + 1, plus<int>(), qop, aop, {0, 0, -1});
		for(int j = 0; j < k - 1; ++ j){
			tr.update(0, j + 1, -a[i][j]);
		}
		for(int j = 0; j <= m - k; ++ j){
			tr.update(j, min(j + k, m - k + 1), -a[i][j + k - 1]);
			dp_next[j] = tr.query(0, m - k + 1) + sum[i][j + k] - sum[i][j] + sum[i + 1][j + k] - sum[i + 1][j];
			tr.update(max(j - k + 1, 0), j + 1, a[i][j]);
		}
		swap(dp, dp_next);
	}
	cout << *max_element(all(dp));
	return 0;
}

/*

*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////