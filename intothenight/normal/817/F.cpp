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
	const LOP &lop;              // lop(low, high, lazy, ql, qr, x): apply query to the lazy
	const QOP &qop;              // qop(low, high, lval, rval): merge the value
	const AOP &aop;              // aop(low, high, val, ql, qr, x): apply query to the val
	const INIT &init;            // init(low, high): initialize node representing (low, high)
	const array<T, 2> &id; // lazy id, query id
	segment *l = 0, *r = 0;
	B low, high;
	T lazy, val;
	segment(const LOP &lop, const QOP &qop, const AOP &aop, const array<T, 2> &id, B low, B high, INIT init): lop(lop), qop(qop), aop(aop), id(id), low(low), high(high), lazy(id[0]), init(init), val(init(low, high)){ }
	template<typename IT>
	segment(const LOP &lop, const QOP &qop, const AOP &aop, const array<T, 2> &id, B low, B high, IT begin, IT end): lop(lop), qop(qop), aop(aop), id(id), low(low), high(high), lazy(id[0]){
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
			if(val.first){
				return high;
			}
			else{
				return low;
			}
		}
		push();
		if(l->high - l->low == l->val.first){
			return r->solve();
		}
		else{
			return l->solve();
		}
	}
	// Below assumes T is an ordered field and node stores positive values
	template<typename Compare = less<T>, typename IO = minus<T>>
	B plb(T x, Compare cmp = less<T>(), IO inv_op = minus<T>()){
		if(low + 1 == high) return high;
		push();
		if(cmp(l->val, x)) return r->plb(inv_op(x, l->val), cmp, inv_op);
		else return l->plb(x, cmp, inv_op);
	}
	template<typename Compare = less<T>, typename IO = minus<T>>
	B lower_bound(T x, Compare cmp = less<T>(), IO inv_op = minus<T>()){ // min i such that query[0, i) >= x
		if(cmp(val, x)) return high + 1;
		else return plb(x, cmp, inv_op);
	}
	template<typename Compare = less<T>, typename IO = minus<T>>
	B lower_bound(B i, T x, Compare cmp = less<T>(), IO inv_op = minus<T>()){
		return max(i, lower_bound(qop(low, low + (high - low >> 1), high, x, query(low, min(i, high))), cmp, inv_op));
	}
	template<typename Compare = less<T>, typename IO = minus<T>>
	B pub(T x, Compare cmp = less<T>(), IO inv_op = minus<T>()){
		if(low + 1 == high) return high;
		push();
		if(cmp(x, l->val)) return l->pub(x, cmp, inv_op);
		else return r->pub(inv_op(x, l->val), cmp, inv_op);
	}
	template<typename Compare = less<T>, typename IO = minus<T>>
	B upper_bound(T x, Compare cmp = less<T>(), IO inv_op = minus<T>()){ // min i such that query[0, i) > val
		if(cmp(x, val)) return pub(x, cmp, inv_op);
		else return high + 1;
	}
	template<typename Compare = less<T>, typename IO = minus<T>>
	B upper_bound(B i, T x, Compare cmp = less<T>(), IO inv_op = minus<T>()){
		return max(i, upper_bound(qop(low, low + (high - low >> 1), high, x, query(low, min(i, high))), cmp, inv_op));
	}
};



int main(){
	cin.tie(0)->sync_with_stdio(0);
	int n;
	cin >> n;
	vector<tuple<int, long long, long long>> query(n);
	map<long long, int> q;
	q.emplace(1, 0), q.emplace(2, 0);
	for(auto &[t, l, r]: query){
		cin >> t >> l >> r, ++ r;
		q.emplace(l, 0), q.emplace(l + 1, 0), q.emplace(r, 0), q.emplace(r + 1, 0);
	}
	vector<long long> rev(q.size());
	for(auto &[val, ind]: q){
		static int i = 0;
		rev[ind = i ++] = val;
	}
	typedef pair<int, int> T;
	typedef int B;
	auto lop = [&](B low, B high, T lazy, B ql, B qr, T x)->T{
		return {lazy.first * x.first, lazy.second * x.first + x.second};
	};
	auto qop = [&](B low, B mid, B high, T lval, T rval)->T{
		return {lval.first + rval.first, 0};
	};
	auto aop = [&](B low, B high, T val, B ql, B qr, T x)->T{
		return {val.first * x.first + (high - low) * x.second, 0};
	};
	array<T, 2> id{T{1, 0}, T{0, 0}};
	auto init = [&](B low, B high)->T{
		return {0, 0};
	};
	const int mx = q.size() + 10;
	segment tr(lop, qop, aop, id, 0, mx, init);
	for(auto [t, l, r]: query){
		if(t == 1){
			tr.update(q[l], q[r], {0, 1});
		}
		else if(t == 2){
			tr.update(q[l], q[r], {0, 0});
		}
		else{
			tr.update(q[l], q[r], {-1, 1});
		}
		cout << rev[tr.solve()] << "\n";
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