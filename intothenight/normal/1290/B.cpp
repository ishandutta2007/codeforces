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
template<class T>
struct offline_less_than_k_query{
	int N;
	vector<pair<T, int>> event;
	vector<tuple<T, int, int, int>> queries;
	offline_less_than_k_query(const vector<T> &arr, bool IS_DVQ = true): N(sz(arr)), event(N){
		if(IS_DVQ){
			map<T, int> q;
			for(int i = 0; i < N; ++ i){
				event[i] = {(q.count(arr[i]) ? q[arr[i]] : -1), i};
				q[arr[i]] = i;
			}
		}
		else for(int i = 0; i < N; ++ i) event[i] = {arr[i], i};
	}
	void query(int i, int ql, int qr){ // For distinct value query
		queries.emplace_back(ql, ql, qr, i);
	}
	void query(int i, int ql, int qr, T k){ // For less-than-k query
		queries.emplace_back(k, ql, qr, i);
	}
	template<class Action>
	void solve(Action ans){ // ans(index, answer)
		sort(all(queries)), sort(all(event), greater<pair<T, int>>());
		fenwick tr(vi(N), plus<int>(), minus<int>(), 0);
		for(auto &[k, ql, qr, i]: queries){
			while(!event.empty() && event.back().first < k){
				tr.update(event.back().second, 1);
				event.pop_back();
			}
			ans(i, tr.query(ql, qr));
		}
	}
};
 
int main(){
	cin.tie(0)->sync_with_stdio(0);
	string s;
	cin >> s;
	offline_less_than_k_query dvq(vi(all(s)));
	int n = sz(s), q;
	cin >> q;
	vi res(q);
	for(int i = 0; i < q; ++ i){
		int ql, qr;
		cin >> ql >> qr, -- ql;
		dvq.query(i, ql, qr);
		if(s[ql] != s[qr - 1] || qr - ql == 1){
			res[i] = true;
		}
	}
	dvq.solve([&](int i, int x){
		if(x >= 3){
			res[i] = true;
		}
	});
	for(int i = 0; i < q; ++ i){
		cout << (res[i] ? "Yes" : "No") << "\n";
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