#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define pb push_back
using namespace std;
using ll = long long;
using ld = long double;
const int maxn = 1<<12, mod = 1e9 + 7;
int n, a[maxn], _a[maxn], qry = 0, local = 0;
map<pair<int, int>, int> memo;
int ask(int i, int j) {
	if(i > j) swap(i, j);
	if(memo.count({i, j})) return memo[{i, j}];
	cout << "? " << i+1 << " " << j+1 << endl;
	qry++;
	int t;
	if(local) {
		t = _a[i]|_a[j];
	} else {
		cin >> t;
	}
	return memo[{i, j}] = t;
}
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int get() {
	return rng()%n;
}
int main() {
	cin.tie(0)->sync_with_stdio(0);
	if(local) {
		n = 2048;
		for(int i = 0; i < n; i++) _a[i] = i;
		shuffle(_a, _a+n, rng);
	} else {
		cin >> n;
	}
	int u = 0;
	if(n > 100) {
	while(true) {
		int i = get(), j = get();
		j += i==j;
		if(__builtin_popcount(ask(i, j))<7) {u = i; break;}
	}
	}
	map<int, vector<int>> bl;
	vector<int> x;
	int MX = n;
	for(int i = 0; i < n; i++) if(i != u) x.pb(i);
	x.pb(u);
	while(x.size()>1) {
		bl.clear();
		u = x.back(); x.pop_back();
		int r = 0;
		for(auto i : x) {
			r = max(r, ask(i, u));
			bl[ask(i, u)].pb(i);
		}
		if(bl.size() == x.size() && r < MX) {
			x = {u};
			break;
		}
		x = bl.begin()->second;
		MX = bl.begin()->first;
	}
	int zero = x[0];
	for(int i = 0; i < n; i++) a[i] = i == zero ? 0 : ask(i, zero);
	cout << "! ";
	for(int i = 0; i < n; i++) cout << a[i] << " "; cout << endl;
	if(local) {
		for(int i = 0; i < n; i++) cout << _a[i] << " "; cout << ": " << qry << endl;
		for(int i = 0; i < n; i++) assert(a[i] == _a[i]);
	}
	return 0;
}