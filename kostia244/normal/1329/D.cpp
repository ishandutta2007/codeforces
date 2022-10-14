// Problem: D. Dreamoon Likes Strings
// Contest: Codeforces - Codeforces Round #631 (Div. 1) - Thanks, Denis aramis Shitov!
// URL: https://codeforces.com/contest/1329/problem/D
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2")
#include<bits/extc++.h>
#define all(x) begin(x), end(x)
using namespace std;
using ll = long long;
using ordered_set = __gnu_pbds::tree<int, __gnu_pbds::null_type, less<int>, __gnu_pbds::rb_tree_tag,
	__gnu_pbds::tree_order_statistics_node_update>;

template<typename F>
void multitest(F func) {
	int t;
	cin >> t;
	while(t--) func();
}
void report(int ok) {
	cout << (ok?"YES":"NO") << '\n';
}
const int rg = 0;
	
struct dsu {
	vector<int> e, l, r;
	dsu(int n) : e(n, -1), l(n) {
		iota(all(l), 0);
		r=l;
	}
	bool sameSet(int a, int b) { return find(a) == find(b); }
	int size(int x) { return -e[find(x)]; }
	int find(int x) { return e[x] < 0 ? x : e[x] = find(e[x]); }
	bool join(int a, int b) {
		a = find(a), b = find(b);
		if (a == b) return false;
		if (e[a] > e[b]) swap(a, b);
		l[a] = min(l[a], l[b]);
		r[a] = max(r[a], r[b]);
		e[a] += e[b]; e[b] = a;
		return true;
	}
};
void solve(string s) {
	vector<array<int, 2>> sol;
	ordered_set alive;
	priority_queue<array<int, 3>> q[26];
	int n = s.size(), MX = 0, bad = 0;
	vector<int> _bc(26);
	dsu d(n);
	for(int i = 0; i < n; i++)
		alive.insert(i);
	auto make_range = [&](int v) {
		v = d.find(v);
		int l = d.l[v], r = d.r[v], 
			c = l&&r+1<n&&s[l]!=s[r];
		array<int, 3> T{c, l, r};
		q[s[l]-'a'].push(T);
		q[s[r]-'a'].push(T);
	};
	auto kill = [&](int l, int r) {
		int rL = alive.order_of_key(l+1);
		int rR = alive.order_of_key(r+1);
		sol.push_back({rL, rR});
		for(auto it = alive.lower_bound(l); it != alive.end() && *it <= r;) {
			auto nxt = it;nxt++;
			alive.erase(it);
			it = nxt;
		}
		_bc[s[l]-'a']--;
		if(s[l]!=s[r])
			_bc[s[r]-'a']--;
		//if s[l]=s[r] we still merge something to avoid gaps
		rL = d.l[d.find(l)];
		rR = d.r[d.find(r)];
		if(rL) d.join(rL-1, rL);
		if(s[rR] != s[rL])
			if(rR+1<n) d.join(rR, rR+1);
		make_range(rL);
	};
	for(int i = 1; i < n; i++)
		if(s[i] != s[i-1])
			d.join(i-1, i);
		else {
			MX = max(MX, ++_bc[s[i]-'a']);
			bad++;
		}
	for(int i = 0; i < n; i++) if(d.r[d.find(i)] == i) {
		make_range(i);
	}
	while(true) {
		int qid = max_element(all(_bc))-_bc.begin();
		if(!_bc[qid])
			break;
		auto [_c, l, r] = q[qid].top();
		q[qid].pop();
		if(d.l[d.find(l)] != l || d.r[d.find(r)] != r)
			continue;
		kill(l,r);
	}
	kill(0, n-1);
	if(rg)
		cout << s << endl;
	cout << sol.size() << '\n';
	for(auto [l, r] : sol)
		cout << l << " " << r << endl;
	assert(sol.size() == 1 + max(MX, (bad+1)/2));
}
int main() {
	cin.tie(0)->sync_with_stdio(0);
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
	multitest([&](){
		string s(100, 'a');
		if(rg)
			for(auto &i : s)
				i += (rng()%3);
		else
			cin >> s;
		solve(s);
	});
	
}
//aabbbbbaba
//a-1, b-4
//cbacccaabb
//c-2, a-1,b-1
//cbacccaabb
//