#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

#define forn(i, a, n) for (int i = a; i < n; ++i)
#define ford(i, a, n) for (int i = n - 1; i >= a; --i)
#define fore(i, a, n) for (int i = a; i <= n; ++i)
#define all(a) (a).begin(), (a).end()
#define fs first
#define sn second
#define trace(a)\
	for (auto i : a) cerr << i << ' ';\
	cerr << '\n'
#define eb emplace_back

#ifndef M_PI
const ld M_PI = acos(-1.0);
#endif

const ld eps = 1e-9;
const int INF = 2000000000;
const ll LINF = 1ll * INF * INF;
const ll MOD = 1000000007;

string solve1(vector<int> rest, string t, int d) {
	int first = -1;
	forn(i, 1, 10)
		if (rest[i]) {
			first = i;
			break;
		}
	if (first == -1) return "";
	rest[first]--;
	string ans = "";
	ans += ('0' + first);
	forn(i, 0, d)
		forn(j, 0, rest[i])
			ans += ('0' + i);
	ans += t;
	forn(i, d, 10)
		forn(j, 0, rest[i])
			ans += ('0' + i);
	return ans;
}

string solve2(vector<int> rest, string t) {
	if (t[0] == '0') return "";
	string ans = t;
	forn(i, 0, 10)
		forn(j, 0, rest[i])
			ans += ('0' + i);
	return ans;
}

string solve(vector<int> rest, string t) {
	string ans = solve2(rest, t);
	forn(i, 0, 10) {
		string ans1 = solve1(rest, t, i);
		if (ans == "" || ans1 < ans && ans1 != "") ans = ans1;
	}
	return ans;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	string s, t;
	cin >> s >> t;
	if (s == "01" || s == "10") {
		cout << "0\n";
		return 0;
	}
	vector<int> sc(10), tc(10);
	for (char c : s) sc[c - '0']++;
	for (char c : t) tc[c - '0']++;
	for (int l = (int)s.length() - 10; l <= (int)s.length(); ++l) {
		if (l <= 0) continue;
		int l2 = l, cnt = 0;
		vector<int> lc(10);
		while (l) {
			++cnt;
			lc[l % 10]++;
			l /= 10;
		}
		l = l2;
		if (cnt + l != s.length()) continue;
		vector<int> rest(10);
		forn(i, 0, 10) rest[i] = sc[i] - lc[i] - tc[i];
		bool ok = true;
		forn(i, 0, 10) if (rest[i] < 0) ok = false;
		if (!ok) continue;
		string ans = solve(rest, t);
		if (ans != "") {
			cout << ans << '\n';
			return 0;
		}
	}
	return 0;
}