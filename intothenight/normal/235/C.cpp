#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/rope>
using namespace std;
using namespace __gnu_pbds;
using namespace __gnu_cxx;
template<typename L, typename R> istream &operator>>(istream &in, pair<L, R> &p){ return in >> p.first >> p.second; }
template<size_t N, typename ...T> typename enable_if<(N >= sizeof...(T))>::type read_tuple(istream &in, tuple<T...> &t){ }
template<size_t N, typename ...T> typename enable_if<(N < sizeof...(T))>::type read_tuple(istream &in, tuple<T...> &t){ in >> get<N>(t); read_tuple<N + 1>(in, t); }
template<typename ...T> istream &operator>>(istream &in, tuple<T...> &t){ read_tuple<0>(in, t); return in; }
template<typename T> istream &operator>>(istream &in, vector<T> &arr){ for(auto &x: arr) in >> x; return in; }
template<typename T> istream &operator>>(istream &in, deque<T> &arr){ for(auto &x: arr) in >> x; return in; }
template<typename L, typename R> ostream &operator<<(ostream &out, const pair<L, R> &p){ return out << "(" << p.first << ", " << p.second << ")"; }
//template<typename L, typename R> ostream &operator<<(ostream &out, const pair<L, R> &p){ return out << p.first << " " << p.second << "\n"; }
template<size_t N, typename ...T> typename enable_if<(N >= sizeof...(T))>::type print_tuple(ostream &out, const tuple<T...> &t){ }
template<size_t N, typename ...T> typename enable_if<(N < sizeof...(T))>::type print_tuple(ostream &out, const tuple<T...> &t){ out << get<N>(t) << " "; print_tuple<N + 1>(out, t); }
template<typename ...T> ostream &operator<<(ostream &out, const tuple<T...> &t){ print_tuple<0>(out, t); return out << "\n"; }
template<typename T> ostream &operator<<(ostream &out, const vector<T> &arr){ for(auto &x: arr) out << x << " "; return out << "\n"; }
template<typename T> ostream &operator<<(ostream &out, const deque<T> &arr){ for(auto &x: arr) out << x << " "; return out << "\n"; }
template<typename T> ostream &operator<<(ostream &out, const set<T> &arr){ for(auto &x: arr) out << x << " "; return out << "\n"; }
template<typename L, typename R> ostream &operator<<(ostream &out, const map<L, R> &arr){ for(auto &x: arr) out << x << " "; return out << "\n"; }
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

template<typename Str>
struct suffix_automaton{
	struct node{
		int len = 0, link = -1, firstpos = -1;
		bool isclone = false;
		map<typename Str::value_type, int> next;
		vector<int> invlink;
		int cnt = -1;
	};
	vector<node> state = vector<node>(1);
	int last = 0;
	suffix_automaton(const Str &s){ state.reserve(s.size()); for(auto c: s) insert(c); }
	void insert(typename Str::value_type c){
		int cur = state.size();
		state.push_back({state[last].len + 1, -1, state[last].len});
		int p = last;
		while(p != -1 && !state[p].next.count(c)){
			state[p].next[c] = cur;
			p = state[p].link;
		}
		if(p == -1) state[cur].link = 0;
		else{
			int q = state[p].next[c];
			if(state[p].len + 1 == state[q].len) state[cur].link = q;
			else{
				int clone = state.size();
				state.push_back({state[p].len + 1, state[q].link, state[q].firstpos, true, state[q].next});
				while(p != -1 && state[p].next[c] == q){
					state[p].next[c] = clone;
					p = state[p].link;
				}
				state[q].link = state[cur].link = clone;
			}
		}
		last = cur;
	}
	void print(){
		for(int u = 0; u < sz(state); ++ u){
			cout << "--------------------------------\n";
			cout << "Node " << u << ": len = " << state[u].len << ", link = " << state[u].link;
			cout << ", firstpos = " << state[u].firstpos << ", cnt = " << state[u].cnt;
			cout << ", isclone = " << state[u].isclone;
			cout << "\ninvlink = " << state[u].invlink << "next = " << state[u].next;
			cout << "--------------------------------" << endl;
		}
	}
	pair<int, int> match(const Str &s){ // (Length of the longest prefix of s, state)
		int u = 0;
		for(int i = 0; i < s.size(); ++ i){
			if(!state[u].next.count(s[i])) return {i, u};
			u = state[u].next[s[i]];
		}
		return {s.size(), u};
	}
	vector<long long> distinct_substr_cnt(){
		vector<long long> dp(state.size());
		function<ll(int)> solve = [&](int u){
			if(dp[u]) return dp[u];
			dp[u] = 1;
			for(auto [c, v]: state[u].next) dp[u] += solve(v);
			return dp[u];
		};
		solve(0);
		return dp;
	}
	vector<long long> distinct_substr_len(){
		vector<long long> res(state.size()), dp(state.size());
		function<long long(int)> solve = [&](int u){
			if(dp[u]) return res[u];
			dp[u] = 1;
			for(auto [c, v]: state[u].next){
				res[u] += solve(v) + dp[v];
				dp[u] += dp[v];
			}
			return res[u];
		};
		solve(0);
		return res;
	}
	pair<Str, int> k_th_substr(ll k){
		vl dp(distinct_substr_cnt());
		assert(dp[0] >= k && k);
		Str res;
		int u = 0;
		for(; -- k; ) for(auto [c, v]: state[u].next){
			if(k > dp[v]) k -= dp[v];
			else{
				res.push_back(c);
				u = v;
				break;
			}
		}
		return {res, u};
	}
	pair<Str, int> smallest_substr(int length){
		Str res;
		int u = 0;
		for(int u = 0; length --; ){
			assert(!state[u].next.empty());
			auto it = state[u].next.begin();
			res.push_back(it->first);
			u = it->second;
		}
		return {res, u};
	}
	pair<int, int> find_first(const Str &s){ // length, pos
		auto [l, u] = match(s);
		return {l, state[u].firstpos - sz(s) + 1};
	}
	void process_invlink(){ for(int u = 1; u < state.size(); ++ u) state[state[u].link].invlink.push_back(u); }
	vector<int> find_all(const Str &s, bool invlink_init = false){
		auto [l, u] = match(s);
		if(l < sz(s)) return{};
		vector<int> res;
		if(!invlink_init) process_invlink();
		function<void(int)> solve = [&](int u){
			if(!state[u].isclone) res.push_back(state[u].firstpos);
			for(auto v: state[u].invlink) solve(v);
		};
		solve(u);
		for(auto &x: res) x += 1 - int(s.size());
		sort(res.begin(), res.end());
		return res;
	}
	Str lcs(const Str &s){
		int u = 0, l = 0, best = 0, bestpos = 0;
		for(int i = 0; i < s.size(); ++ i){
			while(u && !state[u].next.count(s[i])){
				u = state[u].link;
				l = state[u].len;
			}
			if(state[u].next.count(s[i])){
				u = state[u].next[s[i]];
				++ l;
			}
			if(l > best){
				best = l;
				bestpos = i;
			}
		}
		return {s.begin() + bestpos - best + 1, s.begin() + bestpos + 1};
	}
	vector<int> process_lcs(const Str &s){ // list of length ending at the pos
		int u = 0, l = 0;
		vector<int> res(s.size());
		for(int i = 0; i < s.size(); ++ i){
			while(u && !state[u].next.count(s[i])){
				u = state[u].link;
				l = state[u].len;
			}
			if(state[u].next.count(s[i])){
				u = state[u].next[s[i]];
				++ l;
			}
			res[i] = l;
		}
		return res;
	}
	void process_cnt(bool invlink_init = false){
		for(int u = 0; u < state.size(); ++ u) state[u].cnt = (!state[u].isclone && u);
		if(!invlink_init) process_invlink();
		function<void(int)> solve = [&](int u){
			for(auto v: state[u].invlink){
				solve(v);
				state[u].cnt += state[v].cnt;
			}
		};
		solve(0);
	}
	int count(const string &s){
		assert(state[0].cnt != -1);
		return state[match(s).second].cnt;
	}
};
template<typename Str>
Str lcs(vector<Str> a){
	swap(a[0], *min_element(all(a), [](const Str &s, const Str &t){ return s.size() < t.size(); }));
	vector<int> res(a[0].size());
	iota(res.begin(), res.end(), 1);
	for(int i = 1; i < a.size(); ++ i){
		auto t = suffix_automaton(a[i]).process_lcs(a[0]);
		for(int j = 0; j < a[0].size(); ++ j) ctmin(res[j], t[j]);
	}
	int i = max_element(res.begin(), res.end()) - res.begin();
	return {a[0].begin() + i + 1 - res[i], a[0].begin() + i + 1};
}

int main(){
	cin.tie(0)->sync_with_stdio(0);
	string s;
	cin >> s;
	suffix_automaton aut(s);
	aut.process_cnt();
	int n;
	cin >> n;
	vi visited(sz(aut.state)), log;
	while(n --){
		string t;
		cin >> t;
		auto [l, u] = aut.match(t);
		int res = 0;
		rotate(t.begin(), t.begin() + l, t.end());
		for(auto &c: t){
			if(u && l == sz(t)){
				if(aut.state[aut.state[u].link].len + 1 == l){
					u = aut.state[u].link;
					l = aut.state[u].len;
				}
				else{
					-- l;
				}
			}
			while(u && !aut.state[u].next.count(c)){
				u = aut.state[u].link;
				l = aut.state[u].len;
			}
			if(aut.state[u].next.count(c)){
				u = aut.state[u].next[c];
				++ l;
			}
			if(l == sz(t)){
				if(visited[u]){
					break;
				}
				res += aut.state[u].cnt;
				visited[u] = true;
				log.push_back(u);
			}
		}
		for(auto u: log){
			visited[u] = false;
		}
		cout << res << "\n";
	}
	return 0;
}

/*
bbbbbbbbbbbbbbb
5
ba
*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////