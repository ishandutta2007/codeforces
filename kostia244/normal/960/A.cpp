#include<bits/stdc++.h>
#define all(x) begin(x), end(x)
#define int ll
using ll = long long;
using namespace std;
const int maxn = 1<<22, mod = 1e9 + 7;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	string s;
	cin >> s;
	string t = s;
	sort(all(t));
	if(t != s) return cout << "NO\n", 0;
	int a, b, c;
	a = count(all(s), 'a');
	b = count(all(s), 'b');
	c = count(all(s), 'c');
	cout << (a && b && (c == a || c == b) ? "YES" : "NO") << endl;
}