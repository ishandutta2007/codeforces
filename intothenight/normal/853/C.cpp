#include "bits/stdc++.h"
using namespace std;

// DEBUG BEGIN
template<typename L, typename R>
ostream &operator<<(ostream &out, pair<L, R> p){
	return out << "(" << p.first << ", " << p.second << ")";
}
template<typename Tuple, size_t ...Is>
void print_tuple(ostream &out, Tuple t, index_sequence<Is...>){
	((out << (Is ? ", " : "") << get<Is>(t)), ...);
}
template<typename ...Args>
ostream &operator<<(ostream &out, tuple<Args...> t){
	out << "(", print_tuple(out, t, index_sequence_for<Args...>{}); return out << ")";
}
template<typename ...Args, template<typename...> typename T>
ostream &operator<<(enable_if_t<!is_same_v<T<Args...>, string>, ostream> &out, T<Args...> arr){
	out << "{"; for(auto &x: arr) out << x << ", ";
	return out << (arr.size() ? "\b\b" : "") << "}";
}
template<typename T, size_t N>
ostream &operator<<(ostream &out, array<T, N> arr){
	out << "{"; for(auto &x: arr) out << x << ", ";
	return out << (arr.size() ? "\b\b" : "") << "}";
}
template<size_t S>
ostream &operator<<(ostream &out, bitset<S> b){
	for(int i = 0; i < S; ++ i) out << b[i];
	return out;
}
void debug_out(){ cerr << "\b\b " << endl; }
template<typename Head, typename... Tail>
void debug_out(Head H, Tail... T){ cerr << H << ", ", debug_out(T...); }
#ifdef LOCAL
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]: ", debug_out(__VA_ARGS__)
#else
#define debug(...) 42
#endif
// DEBUG END

template<typename T>
struct node{
	node *l = 0, *r = 0;
	T val;
	node(T val): val(val){}
	template<typename BO>
	node(node *l, node *r, BO bin_op, T id): l(l), r(r), val(id){
		if(l) val = bin_op(l->val, val);
		if(r) val = bin_op(val, r->val);
	}
};
template<typename T, typename BO>
struct persistent_segment_tree: vector<node<T> *>{
	int n;
	BO bin_op;
	T id;
	template<typename IT>
	persistent_segment_tree(IT begin, IT end, BO bin_op, T id): n(distance(begin, end)), bin_op(bin_op), id(id){
		this->push_back(build(begin, end, 0, n));
	}
	persistent_segment_tree(int n, BO bin_op, T id): n(n), bin_op(bin_op), id(id){
		vector<int> temp(n, id);
		this->push_back(build(temp.begin(), temp.end(), 0, n));
	}
	template<typename IT>
	node<T> *build(IT begin, IT end, int left, int right){
		if(left + 1 == right) return new node<T>(*begin);
		int mid = left + (right - left >> 1);
		IT inter = begin + (end - begin >> 1);
		return new node<T>(build(begin, inter, left, mid), build(inter, end, mid, right), bin_op, id);
	}
	T query(node<T> *u, int ql, int qr, int left, int right){
		if(qr <= left || right <= ql) return id;
		if(ql <= left && right <= qr) return u->val;
		int mid = left + (right - left >> 1);
		return bin_op(query(u->l, ql, qr, left, mid), query(u->r, ql, qr, mid, right));
	}
	T query(node<T> *u, int ql, int qr){ return query(u, ql, qr, 0, n); }
	node<T> *set(node<T> *u, int p, int x, int left, int right){
		if(left + 1 == right) return new node<T>(x);
		int mid = left + (right - left >> 1);
		if(mid > p) return new node<T>(set(u->l, p, x, left, mid), u->r, bin_op, id);
		else return new node<T>(u->l, set(u->r, p, x, mid, right), bin_op, id);
	}
	void set(node<T> *u, int p, int x){ this->push_back(set(u, p, x, 0, n)); }
	// Below assumes T is an ordered field and node stores positive values
	
	// min p such that query[left, p) >= x
	template<typename IO>
	int lower_bound(node<T> *u, T x, IO inv_op, int left, int right){
		if(u->val < x) return right + 1;
		if(left + 1 == right) return right;
		int mid = left + (right - left >> 1);
		if(u->l->val < x) return lower_bound(u->r, inv_op(x, u->l->val), inv_op, mid, right);
		else return lower_bound(u->l, x, inv_op, left, mid);
	}
	// min p such that query[i, p) >= x
	template<typename IO>
	int lower_bound(node<T> *u, int i, T x, IO inv_op){
		return lower_bound(u, bin_op(x, query(u, 0, min(i, n))), inv_op, 0, n);
	}
	// min p such that query[left, p) > x
	template<typename IO>
	int upper_bound(node<T> *u, T x, IO inv_op, int left, int right){
		if(x >= u->val) return n + 1;
		if(left + 1 == right) return right;
		int mid = left + (right - left >> 1);
		if(x < u->l->val) return upper_bound(u->l, x, inv_op, left, mid);
		else return upper_bound(u->r, inv_op(x, u->l->val), inv_op, mid, right);
	}
	// min p such that query[i, p) > x
	template<typename IO>
	int upper_bound(node<T> *u, int i, T x, IO inv_op){
		return upper_bound(u, bin_op(x, query(u, 0, min(i, n))), inv_op, 0, n);
	}
};

template<typename T, int TYPE = 0>
struct less_than_k_query{
	int n;
	vector<node<T> *> p;
	persistent_segment_tree<int, plus<>> tr;
	vector<T> comp;
	template<typename IT>
	less_than_k_query(IT begin, IT end): n(distance(begin, end)), p(n + 1), tr(n, plus<>(), 0){
		vector<pair<T, int>> event(n);
		if(TYPE == 0){
			map<T, int> q;
			for(int i = 0; begin != end; ++ begin, ++ i){
				event[i] = {(q.count(*begin) ? q[*begin] : -1), i};
				q[*begin] = i;
			}
		}
		else if(TYPE == 1) for(int i = 0; begin != end; ++ begin, ++ i) event[i] = {*begin, i};
		else{
			comp = {begin, end};
			sort(comp.begin(), comp.end()), comp.erase(unique(comp.begin(), comp.end()), comp.end());
			for(int i = 0; begin != end; ++ begin, ++ i) event[i] = {std::lower_bound(comp.begin(), comp.end(), *begin) - comp.begin(), i};
		}
		sort(event.begin(), event.end(), greater<>());
		tr.reserve(n);
		for(int i = 0; i <= n; ++ i){
			while(!event.empty() && event.back().first < i){
				tr.set(tr.back(), event.back().second, 1);
				event.pop_back();
			}
			p[i] = tr.back();
		}
	}
	// For distinct value query
	int query(int ql, int qr){
		assert(!TYPE);
		return tr.query(p[ql], ql, qr, 0, n);
	}
	int lower_bound(int ql, int cnt){ // min i such that # of distinct in [l, l + i) >= cnt
		assert(!TYPE);
		return tr.lower_bound(p[ql], ql, cnt, minus<>());
	}
	int upper_bound(int ql, int cnt){ // min i such that # of distinct in [l, l + i) > cnt
		assert(!TYPE);
		return tr.upper_bound(p[ql], ql, cnt, minus<>());
	}
	// For less-than-k query
	int query(int ql, int qr, int k){
		assert(TYPE);
		return tr.query(p[TYPE == 2 ? std::lower_bound(comp.begin(), comp.end(), k) - comp.begin() : k], ql, qr, 0, n);
	}
	int lower_bound(int ql, int k, int cnt){ // min i such that ( # of elements < k in [l, l + i) ) >= cnt
		assert(TYPE);
		return tr.lower_bound(p[TYPE == 2 ? std::lower_bound(comp.begin(), comp.end(), k) - comp.begin() : k], ql, cnt, minus<>());
	}
	int upper_bound(int ql, int k, int cnt){ // min i such that ( # of elements < k in [l, l + i) ) > cnt
		assert(TYPE);
		return tr.upper_bound(p[TYPE == 2 ? std::lower_bound(comp.begin(), comp.end(), k) - comp.begin() : k], ql, cnt, minus<>());
	}
};

int main(){
	cin.tie(0)->sync_with_stdio(0);
	int n, qq;
	cin >> n >> qq;
	vector<int> a(n);
	for(auto i = 0; i < n; ++ i){
		cin >> a[i], -- a[i];
	}
	auto cnt = [&](int x){
		return 1LL * x * (x - 1) / 2;
	};
	less_than_k_query<int, 1> ltk(a.begin(), a.end());
	for(auto i = 0; i < qq; ++ i){
		int l, d, r, u;
		cin >> l >> d >> r >> u, -- l, -- d;
		cout << cnt(n) - cnt(l) - cnt(n - r) - cnt(d) - cnt(n - u)
		+ cnt(ltk.query(0, l, d)) + cnt(l - ltk.query(0, l, u)) + cnt(ltk.query(r, n, d)) + cnt(n - r - ltk.query(r, n, u)) << "\n";
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