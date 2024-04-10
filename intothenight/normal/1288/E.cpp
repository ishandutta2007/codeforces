#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/rope>
using namespace std;
using namespace __gnu_pbds;
using namespace __gnu_cxx;
template<class L, class R>
istream &operator>>(istream &in, pair<L, R> &arr){
    return in >> arr.first >> arr.second;
}
template<class ...Args, template<class...> class T>
istream &operator>>(enable_if_t<!is_same_v<T<Args...>, string>, istream> &in, T<Args...> &arr){
	for(auto &x: arr) in >> x; return in;
}
template<class L, class R>
ostream &operator<<(ostream &out, const pair<L, R> &arr){
    return out << "(" << arr.first << ", " << arr.second << ")";
}
template<class ...Args, template<class...> class T>
ostream &operator<<(enable_if_t<!is_same_v<T<Args...>, string>, ostream> &out, const T<Args...> &arr){
	for(auto &x: arr) out << x << " "; return out << "\n";
}
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
mt19937_64 rngll(chrono::steady_clock::now().time_since_epoch().count());
#define all(a) a.begin(), a.end()
#define sz(a) (int)a.size()
typedef long long ll;
typedef vector<int> vi; typedef vector<ll> vl; typedef vector<double> vd; typedef vector<string> vs;
typedef pair<int, int> pii; typedef pair<ll, ll> pll; typedef pair<int, ll> pil; typedef pair<ll, int> pli;
typedef vector<pii> vpii; typedef vector<pil> vpil; typedef vector<pli> vpli; typedef vector<pll> vpll;
template<class T> T ctmax(T &x, const T &y){ return x = max(x, y);}
template<class T> T ctmin(T &x, const T &y){ return x = min(x, y);}
template<class T> using Tree = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
typedef tuple<int, int, int> tpl; typedef vector<tpl> vtpl;
 
template<class T>
struct node{
	node *l = 0, *r = 0;
	T val;
	node(T val): val(val){}
	node(node *l, node *r, function<T(T, T)> bin_op, T id): l(l), r(r), val(id){
		if(l) val = bin_op(l->val, val);
		if(r) val = bin_op(val, r->val);
	}
};
template<class T, class BO>
struct persistent_segment: vector<node<T> *>{
	int N;
	BO bin_op;
	const T id;
	persistent_segment(const vector<T> &arr, BO bin_op, T id): N(arr.size()), bin_op(bin_op), id(id){
		this->push_back(build(arr, 0, N));
	}
	node<T> *build(const vector<T> &arr, int left, int right){
		if(left + 1 == right) return new node<T>(arr[left]);
		int mid = left + right >> 1;
		return new node<T>(build(arr, left, mid), build(arr, mid, right), bin_op, id);
	}
	T pq(node<T> *u, int left, int right, int ql, int qr){
		if(qr <= left || right <= ql) return id;
		if(ql <= left && right <= qr) return u->val;
		int mid = left + right >> 1;
		return bin_op(pq(u->l, left, mid, ql, qr), pq(u->r, mid, right, ql, qr));
	}
	T query(node<T> *u, int ql, int qr){
		return pq(u, 0, N, ql, qr);
	}
	node<T> *ps(node<T> *u, int left, int right, int p, int val){
		if(left + 1 == right) return new node<T>(val);
		int mid = left + right >> 1;
		if(mid > p) return new node<T>(ps(u->l, left, mid, p, val), u->r, bin_op, id);
		else return new node<T>(u->l, ps(u->r, mid, right, p, val), bin_op, id);
	}
	void set(node<T> *u, int p, int val){
		this->push_back(ps(u, 0, N, p, val));
	}
	// Below assumes T is an ordered field and node stores positive values
	int plb(node<T> *u, int left, int right, T val){
		if(left + 1 == right) return right;
		int mid = left + right >> 1;
		if(u->l->val < val) return plb(u->r, mid, right, val - u->l->val);
		else return plb(u->l, left, mid, val);
	}
	int lower_bound(node<T> *u, T val){ // min i such that query[0, i) >= val
		if(u->val < val) return N + 1;
		return plb(u, 0, N, val);
	}
	int pub(node<T> *u, int left, int right, T val){
		if(left + 1 == right) return right;
		int mid = left + right >> 1;
		if(u->l->val <= val) return pub(u->r, mid, right, val - u->l->val);
		else return pub(u->l, left, mid, val);
	}
	int upper_bound(node<T> *u, T val){ // min i such that query[0, i) > val
		if(u->val <= val) return N + 1;
		return pub(u, 0, N, val);
	}
};
template<class T>
struct less_than_k_query{ // for less-than-k query, it only deals with numbers in range [0, N)
	int N;
	vector<node<T> *> p;
	persistent_segment<int, plus<int>> tr;
	less_than_k_query(const vector<T> &arr, bool IS_DVQ = true): N(sz(arr)), p(N + 1), tr(vi(N), plus<int>{}, 0){
		vector<pair<T, int>> event(N);
		if(IS_DVQ){
			map<T, int> q;
			for(int i = 0; i < N; ++ i){
				event[i] = {(q.count(arr[i]) ? q[arr[i]] : -1), i};
				q[arr[i]] = i;
			}
		}
		else for(int i = 0; i < N; ++ i) event[i] = {arr[i], i};
		sort(all(event), greater<pii>{});
		tr.reserve(N);
		for(int i = 0; i <= N; ++ i){
			while(!event.empty() && event.back().first < i){
				tr.set(tr.back(), event.back().second, 1);
				event.pop_back();
			}
			p[i] = tr.back();
		}
	}
	// For distinct value query
	int query(int ql, int qr){
		return tr.query(p[ql], ql, qr);
	}
	int lower_bound(int ql, int cnt){ // min i such that # of distinct in [l, l + i) >= cnt
		return tr.lower_bound(p[ql], cnt + tr.query(p[ql], 0, ql));
	}
	int upper_bound(int ql, int cnt){ // min i such that # of distinct in [l, l + i) > cnt
		return tr.upper_bound(p[ql], cnt + tr.query(p[ql], 0, ql));
	}
	// For less-than-k query
	int query(int ql, int qr, int k){
		return tr.query(p[k], ql, qr);
	}
	int lower_bound(int ql, int k, int cnt){ // min i such that ( # of elements < k in [l, l + i) ) >= cnt
		return tr.lower_bound(p[k], cnt + tr.query(p[k], 0, ql));
	}
	int upper_bound(int ql, int k, int cnt){ // min i such that ( # of elements < k in [l, l + i) ) > cnt
		return tr.upper_bound(p[k], cnt + tr.query(p[k], 0, ql));
	}
};

template<class T, class BO, class IO>
struct fenwick: vector<T>{
	int N;
	BO bin_op;
	IO inv_op;
	T id;
	fenwick(const vector<T> &arr, BO bin_op, IO inv_op, T id): N(arr.size()), bin_op(bin_op), inv_op(inv_op), id(id){
		this->resize(N + 1, id);
		for(int i = 0; i < N; ++ i) update(i, arr[i]);
	}
	void update(int p, T val){
		for(p ++; p <= N; p += p & -p) (*this)[p] = bin_op((*this)[p], val);
	}
	T sum(int p){
		T res = id;
		for(p ++; p > 0; p -= p & -p) res = bin_op(res, (*this)[p]);
		return res;
	}
	T query(int l, int r){
		return inv_op(sum(r - 1), sum(l - 1));
	}
};
 
int main(){
	cin.tie(0)->sync_with_stdio(0);
	int n, m;
	cin >> n >> m;
	vi a(m);
	cin >> a;
	for(auto &x: a){
		-- x;
	}
	vector<vi> occur(n);
	for(int t = 0; t < m; ++ t){
		occur[a[t]].push_back(t);
	}
	vi rmin(n), rmax(n);
	iota(all(rmin), 0);
	for(int i = 0; i < n; ++ i){
		if(!occur[i].empty()){
			rmin[i] = 0;
		}
	}
	less_than_k_query q(a);
	vector<tpl> query(n);
	for(int i = 0; i < n; ++ i){
		if(occur[i].empty()){
			query[i] = {m, i + 1, n};
		}
		else{
			int b = occur[i].front();
			query[i] = {b, i + 1, n};
			for(int j = 1; j < sz(occur[i]); ++ j){
				ctmax(rmax[i], q.query(occur[i][j - 1] + 1, occur[i][j]));
			}
			ctmax(rmax[i], q.query(occur[i].back() + 1, m));
		}
	}
	sort(all(query), greater<tpl>());
	fenwick tr(vi(n), plus<int>(), minus<int>(), 0);
	for(int t = 0; t <= m; ++ t){
		while(!query.empty() && get<0>(query.back()) <= t){
			auto [_UNUSED, l, r] = query.back();
			query.pop_back();
			int i = l - 1;
			ctmax(rmax[i], i + tr.query(l, r));
		}
		if(t < m){
			if(!tr.query(a[t], a[t] + 1)) tr.update(a[t], 1);
		}
	}
	for(int i = 0; i < n; ++ i){
		cout << rmin[i] + 1 << " " << rmax[i] + 1 << "\n";
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