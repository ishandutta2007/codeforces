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

/*
Lazy op: lazy query(ql, qr, x) applied on lazy node(low, high, lazy)
Query op: Calculate combining result of (left, right, left_query_res, right_query_res)
Apply op: Apply to val the lazy node(low, high, lazy)
*/
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
	template<typename Act>
	void print(Act f){
		if(l){
			l->print(f);
			r->print(f);
		}
		cout << "low = " << low << ", high = " << high << "\npval = " << val[0] << " sval = " << val[1] << ", lazy val = " << lazy[0] << ", " << lazy[1] << endl;
		auto p = f(low, high);
		cout << "Real pval = " << p.first << ", real sval = " << p.second << endl;
	}
	// Below assumes T is an ordered field and node stores positive values
	template<typename Compare = less<T>, typename IO = minus<T>>
	int plb(T x, Compare cmp = less<T>(), IO inv_op = minus<T>()){
		if(low + 1 == high) return high;
		push();
		if(cmp(l->val, x)) return r->plb(inv_op(x, l->val), cmp, inv_op);
		else return l->plb(x, cmp, inv_op);
	}
	template<typename Compare = less<T>, typename IO = minus<T>>
	int lower_bound(T x, Compare cmp = less<T>(), IO inv_op = minus<T>()){ // min i such that query[0, i) >= x
		if(cmp(val, x)) return high + 1;
		else return plb(x, cmp, inv_op);
	}
	template<typename Compare = less<T>, typename IO = minus<T>>
	int lower_bound(int i, T x, Compare cmp = less<T>(), IO inv_op = minus<T>()){
		return max(i, lower_bound(qop(low, low + (high - low >> 1), high, x, query(low, min(i, high))), cmp, inv_op));
	}
	template<typename Compare = less<T>, typename IO = minus<T>>
	int pub(T x, Compare cmp = less<T>(), IO inv_op = minus<T>()){
		if(low + 1 == high) return high;
		push();
		if(cmp(x, l->val)) return l->pub(x, cmp, inv_op);
		else return r->pub(inv_op(x, l->val), cmp, inv_op);
	}
	template<typename Compare = less<T>, typename IO = minus<T>>
	int upper_bound(T x, Compare cmp = less<T>(), IO inv_op = minus<T>()){ // min i such that query[0, i) > val
		if(cmp(x, val)) return pub(x, cmp, inv_op);
		else return high + 1;
	}
	template<typename Compare = less<T>, typename IO = minus<T>>
	int upper_bound(int i, T x, Compare cmp = less<T>(), IO inv_op = minus<T>()){
		return max(i, upper_bound(qop(low, low + (high - low >> 1), high, x, query(low, min(i, high))), cmp, inv_op));
	}
};

int main(){
	cin.tie(0)->sync_with_stdio(0);
	int n;
	cin >> n;
	vector<long long> a(n);
	copy_n(istream_iterator<long long>(cin), n, a.begin());
	vector<array<long long, 2>> d(n), k(n);
	for(int i = 0; i < n - 1; ++ i){
		cin >> k[i][1];
		d[i][1] = a[i + 1] - a[i] - k[i][1];
	}
	d[n - 1] = k[n - 1] = {0, numeric_limits<long long>::max() / 2};
	typedef array<long long, 2> T;
	typedef int B;
	auto lop = [&](B low, B high, T lazy, B ql, B qr, T x){
		return T{lazy[0] * x[0], lazy[1] * x[0] + x[1]};
	};
	auto qop = [&](B low, B mid, B high, T lval, T rval){
		return T{lval[0] + lval[1] * (high - mid) + rval[0], lval[1] + rval[1]};
	};
	auto aop = [&](B low, B high, T val, B ql, B qr, T x){
		return T{val[0] * x[0] + x[1] * (high - low) * (high - low - 1) / 2, val[1] * x[0] + x[1] * (high - low)};
	};
	array<T, 2> id{T{1, 0}, T{0, 0}};
	segment trd(lop, qop, aop, id, 0, n, d.begin(), d.end());
	segment trk(lop, qop, aop, id, 0, n, k.begin(), k.end());
	int qq;
	cin >> qq;
	while(qq --){
		char type;
		cin >> type;
		if(type == 's'){
			int l, r;
			cin >> l >> r, -- l;
			cout << (r - l) * (a[0] + trd.query(0, l)[1] + trk.query(0, l)[1]) + trd.query(l, r)[0] + trk.query(l, r)[0] << "\n";
		}
		else{
			int i, x;
			cin >> i >> x, -- i;
			if(i){
				trd.update(i - 1, i, {1, x});
			}
			else{
				a[0] += x;
			}
			int p = trd.lower_bound(i, {0, x}, [&](const T &p, const T &q){ return p[1] < q[1]; }, [&](const T &p, const T &q){ return T{0, p[1] - q[1]}; });
			if(i == p) ++ p;
			long long val = trd.query(i, p)[1];
			trd.update(i, p - 1, {0, 0});
			trd.update(p - 1, p, {0, val - x});
		}
	}
	return 0;
}

/*
10
-100 -88 -84 -47 -31 -4 13 18 18 10
6 -3 5 -6 -4 -8 -2 -6 -10
2
+ 4 18
s 2 10

-177
*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////