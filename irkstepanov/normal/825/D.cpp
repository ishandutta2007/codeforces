
#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef double ld;

const ll inf= 1e6 + 100;

ll a[26];
ll b[26];
ll q = 0;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	//ifstream cin("input.txt");

	string s, t;
	cin >> s >> t;

	for (int i = 0; i < sz(s); ++i) {
		if (s[i] == '?') {
			++q;
			continue;
		}
		++a[s[i] - 'a'];
	}
	for (int i = 0; i < sz(t); ++i) {
		++b[t[i] - 'a'];
	}

	ll lf = 0, rg = inf;
	while (rg - lf > 1) {
		ll md = (lf + rg) >> 1;
		ll sum = 0;
		for (int i = 0; i < 26; ++i) {
			if (a[i] < b[i] * md) {
				sum += b[i] * md - a[i];
			}
		}
		if (sum <= q) {
			lf = md;
		} else {
			rg = md;
		}
	}	
	
	vector<char> put;
	for (int i = 0; i < 26; ++i) {
		if (a[i] < b[i] * lf) {
			for (int j = 0; j < b[i] * lf - a[i]; ++j) {
				put.pb(char(i + 'a'));
			}
		}
	}

	for (int i = 0; i < sz(s); ++i) {
		if (s[i] != '?') {
			cout << s[i];
			continue;
		}
		if (put.empty()) {
			cout << 'a';
		} else {
			cout << put.back();
			put.pop_back();
		}
	}

	cout << "\n";
		
}