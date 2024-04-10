#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/rope>
using namespace std;
using namespace __gnu_pbds;
using namespace __gnu_cxx;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
mt19937_64 rngll(chrono::steady_clock::now().time_since_epoch().count());
template<typename T> T ctmax(T &x, const T &y){ return x = max(x, y); }
template<typename T> T ctmin(T &x, const T &y){ return x = min(x, y); }
template<typename T> using Tree = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

template<typename T, typename LOP, typename QOP, typename AOP, typename INIT = function<T(int, int)>>
struct segment{
	segment *l = 0, *r = 0;
	int low, high;
	LOP lop;                // Lazy op(L, L -> L)
	QOP qop;                // Query op(Q, Q -> Q)
	AOP aop;                // Apply op(Q, L, leftend, rightend -> Q)
	const vector<T> id;     // Lazy id(L), Query id(Q), Disable constant(Q)
	T lset, lazy, val;
	INIT init;
	segment(int low, int high, LOP lop, QOP qop, AOP aop, const vector<T> &id, INIT init): low(low), high(high), lop(lop), qop(qop), aop(aop), id(id), init(init){
		lazy = id[0], lset = id[2], val = init(low, high);
	}
	segment(const vector<T> &arr, int low, int high, LOP lop, QOP qop, AOP aop, const vector<T> &id): low(low), high(high), lop(lop), qop(qop), aop(aop), id(id){
		lazy = id[0], lset = id[2];
		if(high - low > 1){
			int mid = low + (high - low) / 2;
			l = new segment(arr, low, mid, lop, qop, aop, id);
			r = new segment(arr, mid, high, lop, qop, aop, id);
			val = qop(l->val, r->val);
		}
		else val = arr[low];
	}
	void push(){
		if(!l){
			int mid = low + (high - low) / 2;
			l = new segment(low, mid, lop, qop, aop, id, init);
			r = new segment(mid, high, lop, qop, aop, id, init);
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
			val = aop(id[1], x, low, high);
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
			if(lset != id[2]) lset = lop(lset, x);
			else lazy = lop(lazy, x);
			val = aop(val, x, low, high);
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
	int plb(T x, IO inv_op){
		if(low + 1 == high) return high;
		push();
		if(l->val < x) return r->plb(inv_op(x, l->val), inv_op);
		else return l->plb(x, inv_op);
	}
	template<typename IO>
	int lower_bound(T x, IO inv_op){ // min i such that query[0, i) >= x
		if(val < x) return high + 1;
		else return plb(x, inv_op);
	}
	template<typename IO>
	int lower_bound(int i, T x, IO inv_op){
		return lower_bound(qop(x, query(low, min(i, high))), inv_op);
	}
	template<typename IO>
	int pub(T x, IO inv_op){
		if(low + 1 == high) return high;
		push();
		if(x < l->val) return l->pub(x, inv_op);
		else return r->pub(inv_op(x, l->val), inv_op);
	}
	template<typename IO>
	int upper_bound(T x, IO inv_op){ // min i such that query[0, i) > val
		if(x < val) return pub(x, inv_op);
		else return high + 1;
	}
	template<typename IO>
	int upper_bound(int i, T x, IO inv_op){
		return upper_bound(qop(x, query(low, min(i, high))), inv_op);
	}
};

int main(){
	cin.tie(0)->sync_with_stdio(0);
	int n, m, p;
	cin >> n >> m >> p;
	vector<pair<int, int>> w(n), a(m);
	vector<array<int, 3>> mon(p);
	for(int i = 0; i < n; ++ i){
		cin >> w[i].first >> w[i].second;
	}
	for(int i = 0; i < m; ++ i){
		cin >> a[i].first >> a[i].second;
	}
	for(int i = 0; i < p; ++ i){
		cin >> mon[i][0] >> mon[i][1] >> mon[i][2];
	}
	sort(w.begin(), w.end()), sort(a.begin(), a.end()), sort(mon.begin(), mon.end(), greater<array<int, 3>>());
	// Generate a list for armor, then iterate weapons
	vector<long long> t(m);
	for(int i = 0; i < m; ++ i){
		t[i] = -a[i].second;
	}
	segment tr(t, 0, m
		, plus<long long>()
		, [&](long long x, long long y){ return max(x, y); }
		, [&](long long x, long long y, int l, int r){ return x + y; }
		, vector<long long>{0, 0, -(long long)9e18}
	);
	const int inf = numeric_limits<int>::max();
	long long res = numeric_limits<long long>::min();
	for(auto [att, cost]: w){
		while(!mon.empty() && att > mon.back()[0]){
			int matt = mon.back()[1], profit = mon.back()[2];
			tr.update(upper_bound(a.begin(), a.end(), pair<int, int>{matt, inf}) - a.begin(), m, profit);
			mon.pop_back();
		}
		ctmax(res, tr.query(0, m) - cost);
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