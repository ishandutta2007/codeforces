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

struct line{
	ll d, k, p;
	ll eval(ll x){ return d * x + k; }
};
template<bool GET_MAX = true>
struct sorted_line_container: deque<line>{
	// (for doubles, use inf = 1/.0, div(a,b) = a/b)
	const ll inf = LLONG_MAX;
	ll div(ll a, ll b){ return a / b - ((a ^ b) < 0 && a % b); }
	bool isect_front(iterator x, iterator y){
		if(y == this->end()){ x->p = inf; return false; }
		else{ x->p = div(y->k - x->k, x->d - y->d); return x->p >= y->p; }
	}
	void insert_front(ll d, ll k){
		if(!GET_MAX) d = -d, k = -k;
		assert(empty() || d < front().d);
		push_front({d, k, 0}), isect_front(begin(), ++ begin());
		while(size() >= 2 && isect_front(begin(), ++ begin())) erase(++ begin());
	}
	bool isect_back(reverse_iterator x, reverse_iterator y){
		if(x == this->rend()) return false;
		else{ x->p = div(y->k - x->k, x->d - y->d); return x->p >= y->p; }
	}
	void insert_back(ll d, ll k){
		if(!GET_MAX) d = -d, k = -k;
		assert(empty() || d > front().d);
		push_back({d, k, inf}); isect_back(++ rbegin(), rbegin());
		while(size() >= 2 && isect_back(++ ++ rbegin(), ++ rbegin())) erase(-- -- end()), isect_back(++ rbegin(), rbegin());
	}
	ll decreasing_query(ll x){
		while(size() >= 2 && rbegin()->eval(x) <= (++ rbegin())->eval(x)) pop_back(); rbegin()->p = inf;
		return rbegin()->eval(x) * (GET_MAX ? 1 : -1);
	}
	ll increasing_query(ll x){
		while(size() >= 2 && begin()->eval(x) <= (++ begin())->eval(x)) pop_front();
		return begin()->eval(x) * (GET_MAX ? 1 : -1);
	}
	ll query(ll x){
		if(size() == 1) return begin()->eval(x) * (GET_MAX ? 1 : -1);
		int low = 0, high = int(size()) - 1;
		if(begin()->eval(x) >= (++ begin())->eval(x)) return begin()->eval(x) * (GET_MAX ? 1 : -1);
		while(high - low > 1){
			int mid = low + high >> 1;
			(*this)[mid].eval(x) < (*this)[mid + 1].eval(x) ? low = mid : high = mid;
		}
		return (*this)[low + 1].eval(x) * (GET_MAX ? 1 : -1);
	}
};

int main(){
	cin.tie(0)->sync_with_stdio(0);
	int n;
	cin >> n;
	vl a(n), b(n);
	cin >> a >> b;
	sorted_line_container<false> lc;
	lc.insert_back(b[0], 0);
	ll cur;
	for(int i = 1; i < n; ++ i){
		lc.insert_back(b[i], cur = lc.increasing_query(a[i]));
	}
	cout << cur;
	return 0;
}

/*
5
1 2 6 7 10 
8 7 6 1 0 
	
good:
	66
bad:
	80
*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////