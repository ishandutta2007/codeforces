#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

// views::zip, ranges::sort

typedef long long ll;
typedef long double ld;

void ProGamerMove() {
	int a[2], b[2]; cin >> a[0] >> a[1] >> b[0] >> b[1];
	string s; cin >> s;
	int na = a[0] + b[0] + b[1];
	if (count(s.begin(), s.end(), 'A') != na) { cout << "NO\n"; return; }
	int n = s.size();
	int x[2] = {0, 0}, y[2] = {0, 0};
	vector<int> cnts[2], both;
	while (s.size()) {
		for (; s.size() >= 2 && s[s.size() - 1] == s[s.size() - 2]; s.pop_back()) {
			++x[s.back() == 'B'];
		}
		if (s.size() == 1) {
			++x[s.back() == 'B'];
			s.pop_back();
			break;
		}
		int i = 0, j = 0;
		int cnt[2] = {0, 0};
		for (; s.size() >= 2 && s[s.size() - 1] != s[s.size() - 2]; s.pop_back()) {
			++cnt[s.back() == 'A'];
		}
		s.pop_back();
		if (cnt[0] == cnt[1]) both.push_back(cnt[0]);
		else {
			cnts[cnt[0] < cnt[1]].push_back(max(cnt[0], cnt[1]));
//			cerr << "pushing to " << (cnt[0] < cnt[1]) << " " << max(cnt[0], cnt[1]) << endl;
		}
	}
	for (int it = 0; it < 2; ++it) {
		sort(cnts[it].rbegin(), cnts[it].rend());
		while (y[it] < b[it] && cnts[it].size()) {
			int del = min(b[it] - y[it], cnts[it].back());
			cnts[it].back() -= del;
			y[it] += del;
			if (cnts[it].back() == 0) cnts[it].pop_back();
		}
	}
//	cerr << y[0] << ' ' << y[1] << endl;
	for (int it = 0; it < 2; ++it) {
		while (y[it] < b[it] && cnts[!it].size()) {
			int del = min(b[it] - y[it], cnts[!it].back() - 1);
			cnts[!it].back() -= del + 1;
			y[it] += del;
			if (cnts[!it].back() == 0) cnts[!it].pop_back();
		}
	}
	for (int it = 0; it < 2; ++it) {
		while (y[it] < b[it] && both.size()) {
			int del = min(b[it] - y[it], both.back());
			both.back() -= del;
			y[it] += del;
			if (both.back() == 0) both.pop_back();
		}
	}
	cout << (y[0] == b[0] && y[1] == b[1] ? "YES\n" : "NO\n");
}

signed main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	cout << setprecision(9) << fixed;
	int tc = 1;
	cin >> tc;
	while (tc--) ProGamerMove();
}