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

template<typename T, typename C>
struct mcmf{
	static constexpr T eps = (T) 1e-9;
	struct edge{
		int from, to;
		T c, f;
		C cost;
	};
	vector<vi> g;
	vector<edge> edges;
	vector<C> d;
	vector<bool> in_queue;
	vi q, pe;
	int n, source, sink;
	T flow = 0;
	C cost = 0;
	mcmf(int n, int source, int sink): n(n), source(source), sink(sink), g(n), d(n), in_queue(n), pe(n){
		assert(0 <= source && source < n && 0 <= sink && sink < n && source != sink);
	}
	void clear_flow(){
		for(const edge &e: edges) e.f = 0;
		flow = 0;
	}
	void insert(int from, int to, T forward_cap, T backward_cap, C cost){
		assert(0 <= from && from < n && 0 <= to && to < n);
		g[from].push_back((int) edges.size());
		edges.push_back({from, to, forward_cap, 0, cost});
		g[to].push_back((int) edges.size());
		edges.push_back({to, from, backward_cap, 0, -cost});
	}
	bool expath(){
		fill(d.begin(), d.end(), numeric_limits<C>::max());
		q.clear();
		q.push_back(source);
		d[source] = 0;
		in_queue[source] = true;
		int beg = 0;
		bool found = false;
		while(beg < q.size()){
			int i = q[beg ++];
			if(i == sink) found = true;
			in_queue[i] = false;
			for(int id : g[i]){
				const edge &e = edges[id];
				if(e.c - e.f > eps && d[i] + e.cost < d[e.to]){
					d[e.to] = d[i] + e.cost;
					pe[e.to] = id;
					if(!in_queue[e.to]){
						q.push_back(e.to);
						in_queue[e.to] = true;
					}
				}
			}
		}
		if(found){
			T push = numeric_limits<T>::max();
			int v = sink;
			while(v != source){
				const edge &e = edges[pe[v]];
				push = min(push, e.c - e.f);
				v = e.from;
			}
			v = sink;
			while(v != source){
				edge &e = edges[pe[v]];
				e.f += push;
				edge &back = edges[pe[v] ^ 1];
				back.f -= push;
				v = e.from;
			}
			flow += push;
			cost += push * d[sink];
		}
		return found;
	}
	pair<T, C> get_mcmf(){
		while(expath()){ }
		return {flow, cost};
	}
};

int main(){
	cin.tie(0)->sync_with_stdio(0);
	int n;
	string s;
	cin >> n >> s;
	vi a(n), cnt(26);
	cin >> a;
	for(auto c: s){
		++ cnt[c - 'a'];
	}
	const int source = 26 + n / 2, sink = source + 1;
	mcmf<int, int> f(sink + 1, source, sink);
	for(int i = 0; i < 26; ++ i){
		f.insert(source, i, cnt[i], 0, 0);
		for(int j = 0; j < n / 2; ++ j){
			int c;
			if(s[j] == i + 'a' && s[n - 1 - j] == i + 'a'){
				c = -max(a[j], a[n - 1 - j]);
			}
			else if(s[j] == i + 'a'){
				c = -a[j];
			}
			else if(s[n - 1 - j] == i + 'a'){
				c = -a[n - 1 - j];
			}
			else{
				c = 0;
			}
			f.insert(i, 26 + j, 1, 0, c);
		}
	}
	for(int i = 0; i < n / 2; ++ i){
		f.insert(26 + i, sink, 2, 0, 0);
	}
	cout << -f.get_mcmf().second;
	return 0;
}

/*

*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////