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

const ll MOD = 1000000007;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, k;
	cin >> n >> k;
	string s;
	cin >> s;
	int m = s.length();
	vector<char> ss(n + m);
	forn(i, 0, m) ss[i] = s[i];
	vector<pair<int, char> > last(k);
	forn(i,  0, k) last[i] = {-1, 'a' + i};
	forn(i, 0, m) {
		int d = s[i] - 'a';
		last[d] = {i, s[i]};
	}
	sort(all(last));
	forn(i, 0, n) {
		ss[i + m] = last[i % k].sn;
	}
	vector<int> sum(k);
	ll cursum = 1;
	for(char c : ss) {
		int d = c - 'a';
		ll x = cursum - sum[d];
		if (x < 0) x += MOD;
		sum[d] = cursum;
		cursum += x;
		if (cursum >= MOD) cursum -= MOD;
	}	
	//for(char c : ss) cout << c;
	//cout << '\n';

	cout << cursum << '\n';
	return 0;
}