#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace chrono;
using namespace __gnu_pbds;
mt19937 rng(high_resolution_clock::now().time_since_epoch().count());
mt19937_64 rngll(high_resolution_clock::now().time_since_epoch().count());
template<typename T> T ctmax(T &x, const T &y){ return x = max(x, y); }
template<typename T> T ctmin(T &x, const T &y){ return x = min(x, y); }
template<typename T> using Tree = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

template<typename B, typename T, typename LOP, typename QOP, typename AOP, typename INIT = function<T(B, B)>>
struct segment{
	LOP lop;              // lop(low, high, lazy, ql, qr, x): apply query to the lazy
	QOP qop;              // qop(low, high, lval, rval): merge the value
	AOP aop;              // aop(low, high, val, ql, qr, x): apply query to the val
	INIT init;            // init(low, high): initialize node representing (low, high)
	const array<T, 2> id; // lazy id, query id
	segment *l = 0, *r = 0;
	B low, high;
	T lazy, val;
	segment(LOP lop, QOP qop, AOP aop, const array<T, 2> &id, B low, B high, INIT init): lop(lop), qop(qop), aop(aop), id(id), low(low), high(high), lazy(id[0]), init(init), val(init(low, high)){ }
	template<typename IT>
	segment(LOP lop, QOP qop, AOP aop, const array<T, 2> &id, B low, B high, IT begin, IT end): lop(lop), qop(qop), aop(aop), id(id), low(low), high(high), lazy(id[0]){
		assert(end - begin == high - low);
		if(high - low > 1){
			IT inter = begin + (end - begin >> 1);
			B mid = low + (high - low >> 1);
			l = new segment(lop, qop, aop, id, low, mid, begin, inter);
			r = new segment(lop, qop, aop, id, mid, high, inter, end);
			val = qop(low, mid, high, l->val, r->val);
		}
		else val = *begin;
	}
	void push(){
		if(!l){
			B mid = low + (high - low >> 1);
			l = new segment(lop, qop, aop, id, low, mid, init);
			r = new segment(lop, qop, aop, id, mid, high, init);
		}
		if(lazy != id[0]){
			l->update(low, high, lazy);
			r->update(low, high, lazy);
			lazy = id[0];
		}
	}
	void update(B ql, B qr, T x){
		if(qr <= low || high <= ql) return;
		if(ql <= low && high <= qr){
			lazy = lop(low, high, lazy, ql, qr, x);
			val = aop(low, high, val, ql, qr, x);
		}
		else{
			push();
			l->update(ql, qr, x);
			r->update(ql, qr, x);
			val = qop(low, low + (high - low >> 1), high, l->val, r->val);
		}
	}
	T query(B ql, B qr){
		if(qr <= low || high <= ql) return id[1];
		if(ql <= low && high <= qr) return val;
		push();
		return qop(max(low, ql), clamp(low + (high - low >> 1), ql, qr), min(high, qr), l->query(ql, qr), r->query(ql, qr));
	}
	int solve(){
		if(low + 1 == high){
			return low;
		}
		push();
		if(r->val < 0){
			return r->solve();
		}
		else{
			return l->solve();
		}
	}
};

int main(){
	cin.tie(0)->sync_with_stdio(0);
	const int mx = 1e6 + 2;
	int n, m;
	cin >> n >> m;
	vector<int> a(n), b(m);
	copy_n(istream_iterator<int>(cin), n, a.begin());
	copy_n(istream_iterator<int>(cin), m, b.begin());
	vector<int> grid(mx);
	for(auto &x: a){
		-- grid[++ x];
	}
	for(auto &x: b){
		++ grid[++ x];
	}
	for(int i = mx - 2; i >= 0; -- i){
		grid[i] += grid[i + 1];
	}
	typedef long long T;
	typedef int B;
	auto lop = [&](B low, B high, T lazy, B ql, B qr, T x)->T{
		return lazy + x;
	};
	auto qop = [&](B low, B mid, B high, T lval, T rval)->T{
		return min(lval, rval);
	};
	auto aop = [&](B low, B high, T val, B ql, B qr, T x)->T{
		return val + x;
	};
	array<T, 2> id{0, numeric_limits<int>::max()};
	segment tr(lop, qop, aop, id, 0, mx, grid.begin(), grid.end());
	tr.update(1, 2, -2 * n);
	int qq;
	cin >> qq;
	while(qq --){
		int type, i, x;
		cin >> type >> i >> x, -- i, ++ x;
		if(type == 1){
			tr.update(0, a[i] + 1, 1);
			tr.update(0, (a[i] = x) + 1, -1);
		}
		else{
			tr.update(0, b[i] + 1, -1);
			tr.update(0, (b[i] = x) + 1, 1);
		}
		int res = tr.solve();
		if(res == 1){
			cout << "-1\n";
		}
		else{
			cout << res - 1 << "\n";
		}
	}
	return 0;
}

/*

*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////