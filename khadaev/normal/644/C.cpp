#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

#define forn(i, a, n) for (int i = a; i < n; ++i)
#define fore(i, a, n) for (int i = a; i <= n; ++i)
#define all(a) (a).begin(), (a).end()
#define fs first
#define sn second
#define trace(a)\
	for (auto i : a) cerr << i << ' ';\
	cerr << '\n'

#ifndef M_PI
const ld M_PI = 3.1415926535897932384626433;
#endif
const ld eps = 1e-8;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	map<string, vector<string>> paths;
	map<vector<string>, vector<string>> group;
	cin >> n;
	forn(i, 0, n) {
		string s;
		cin >> s;
		int pos = s.find("/", 7);
		if (pos == string::npos) pos = s.length();
		string hostname = s.substr(0, pos);
		string path = s.substr(pos, s.length() - pos);
		paths[hostname].push_back(path);
	}
	for (auto p : paths) {
		sort(all(p.sn));
		auto it = unique(all(p.sn));
		p.sn.resize(distance(p.sn.begin(), it));
		group[p.sn].push_back(p.fs);
	}
	int cnt = 0;
	for (auto p : group)
		if (p.sn.size() > 1) ++cnt;
	cout << cnt << '\n';
	for (auto p : group) 
		if (p.sn.size() > 1)
			{
			for (auto s : p.sn) cout << s << ' ';
			cout << '\n';
		}
	return 0;
}