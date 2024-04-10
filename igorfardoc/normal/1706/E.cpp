#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<long long> vl;
int n, m, q;
vi when;
vi p;
vector<set<int>> need;

int get_par(int a) {
	if(p[a] == a) return a;
	int par = get_par(p[a]);
	p[a] = par;
	return par;
}

bool eq(int a, int b) {
	return get_par(a) == get_par(b);
}

void join(int a, int b, int num) {
	a = get_par(a);
	b = get_par(b);
	if(need[a].size() > need[b].size()) swap(a, b);
	vi add;
	for(const auto& el : need[a]) {
		auto it = need[b].find(el);
		if(it == need[b].end()) {
			add.push_back(el);
		} else {
			when[el] = num;
			need[b].erase(it);
		}
	}
	set<int> tmp;
	swap(tmp, need[a]);
	for(const auto& el : add) need[b].insert(el);
	p[a] = b;
}


void solve() {
	cin >> n >> m >> q;
	when.resize(n - 1);
	p.resize(n);
	need.assign(n, {});
	for(int i = 0; i < n; i++) {
		p[i] = i;
		need[i].insert(i);
		if(i != 0) need[i].insert(i - 1);
	}
	for(int i = 0; i < m; i++) {
		int v, u;
		cin >> v >> u;
		--v;
		--u;
		if(!eq(v, u)) {
			join(v, u, i + 1);
		}
	}
	vi p1(n);
	p1[1] = 0;
	for(int i = 2; i < n; i++) {
		p1[i] = p1[i / 2] + 1;
	
	}
	vvi table(n - 1, vi(p1[n - 1] + 1));
	for(int i = 0; i < n - 1; i++) {
		table[i][0] = when[i];
	}
	for(int st = 1; st <= p1[n - 1]; st++) {
		for(int i = 0; i + (1 << st) <= n - 1; i++) {
			table[i][st] = max(table[i][st - 1], table[i + (1 << (st - 1))][st - 1]);
		}
	}
	for(int i = 0; i < q; i++) {
		int l, r;
		cin >> l >> r;
		--l;
		--r;
		if(l == r) {
			cout << 0 << ' ';
		} else {
			--r;
			int len = r - l + 1;
			int st = p1[len];
			cout << max(table[l][st], table[r - (1 << st) + 1][st]) << ' ';
		}
	}
	cout << '\n';
}


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	#ifdef _FILE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif
	int t;
	cin >> t;
	while(t--) {
		solve();
	}
}